    /*
    Yris ; a commandline tool that displays hardware and software information
    Copyright (C) 2026  Ntando Khanyile

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#include <network.h>

#include <pwd.h>
#include <ctype.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/utsname.h>

using namespace std;

Network::Network(){
    //hostname
    struct utsname n;
    uname(&n);
    host = n.nodename;

    //local ip
    struct ifaddrs *ifaddr;
    getifaddrs(&ifaddr);
    struct ifaddrs *ifa = ifaddr;
    while(ifa && !(ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET && string(ifa->ifa_name) != "lo")){
        ifa = ifa->ifa_next;
    }
    if(ifa){
        local_ip = inet_ntoa(((struct sockaddr_in*)ifa->ifa_addr)->sin_addr);
    }

    //public ip
    public_ip = "offline";
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){}
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    inet_pton(AF_INET, "34.160.111.145", &server.sin_addr);
    
    connect(sock, (sockaddr *)&server, sizeof(server));
    char *request = "Get /ip HTTP/1.1\r\nHost: ifconfig.me\r\nConnection: close\r\n\r\n";
    
    send(sock, request, strlen(request), 0);
    char buffer[1024];
    string response;
    int bytes;

    while((bytes = recv(sock, buffer, sizeof(buffer)-1, 0)) > 0){
        buffer[bytes] = '\0';
        response += buffer;
    }
    size_t pos = response.find("\r\n\r\n");
    if(pos != string::npos){
        public_ip = response.substr(pos + 4);
        while(!public_ip.empty() && (public_ip.back() == '\n' || public_ip.back() == '\r')){
            public_ip.pop_back();
        }
    }

    close(sock);
}