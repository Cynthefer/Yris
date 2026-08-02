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


//system based headers
#if defined(_WIN32) || defined(_WIN64)
    #include <lm.h>
    #include <Lmcons.h>
    #include <windows.h>
    #pragma comment(lib, "netapi32.lib")
#elif defined(__linux__) || defined(__unix__)
    #include <pwd.h>
    #include <sys/unistd.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <pwd.h>
    #include <unistd.h>
#endif

//Tool headers
#include <user.h>

//language headers & libraries
#include <ctime>
#include <string>

using namespace std;

User::User(){
    set_username();
    set_fullname();
    set_user_id();
    set_group_id();
    set_creationDate();
}

void User::set_username(){
    #ifdef defined(__linux__ ) || defined(__unix__)

        uid_t uid = getuid();
        struct passwd* pw = getpwuid(uid);
        if(pw){
            username = pw->pw_name;
        }
    
    #elif defined(_WIN32) || defined(_WIN64)
        
        char winUsername[UNLEN + 1];
        DWORD size = UNLEN + 1;
        if(GetUserNameA(winUsername, &size)){
            username = winUsername;
        }

    #else

        username = "unknown";

    #endif
}

void User::set_fullname(){
    #ifdef defined(__linux__) || defined(__unix__)

        uid_t uid = getuid();
        struct passwd* pw = getpwuid(uid);
        if(pw){
            fullname = pw->pw_gecos;
        }

    #elif defined(_WIN32) || defined(_WIN64)
        
        char name[256];
        DWORD size = 256;
        GetUserNameA(name, &size);

        LPUSER_INFO_2 info;
        NetUserGetInfo(NULL, name, 2, (LBYTE*)&info);

        char buffer[256];
        WideCharToMultiByte(CP_ACP, 0, info->usri2_full_name, -1, buffer, 256, NULL, NULL);
        fullname = buffer;

        NetApiBufferFree(info);
    #endif
}

void User::set_user_id(){
    #ifdef defined(__linux__) || defined(__unix__)

        uid_t uid = getuid();
        struct passwd* pw = getpwuid(uid);
        if(pw){
            user_id = pw->pw_uid;
        }
    #elif defined(_WIN32) || defined(_WIN64)

        
    #endif
}

void User::set_group_id(){
    #ifdef defined(__linux__) || defined(__unix__)

        uid_t uid = getuid();
        struct passwd* pw = getpwuid(uid);
        if(pw){
            group_id = pw->pw_gid;
        }
    #elif defined(_WIN32) || defined(_WIN64)

        
    #endif
}

void User::set_creationDate(){
    #ifdef defined(__linux__) || defined(__unix__)

    #elif defined(_WIN32) || defined(_WIN64)

    #endif
}