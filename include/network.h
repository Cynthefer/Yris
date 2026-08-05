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

#pragma once

#ifndef NETWORK_H
#define NETWORK_H
#endif

#include <string>

using namespace std;

class Network{
    private:
        string host;
        string local_ip;
        string public_ip;
        string interface;
    
    public:
        Network();
        string get_host(){return host;};
        string get_localIp(){return local_ip;};
        string get_public_ip(){return public_ip;};
        string get_interface(){return interface;};
};