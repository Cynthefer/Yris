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

#ifndef SYSTEM_H
#define SYSTEM_H
#endif

#pragma once

#include <string>

using namespace std;

class OS{
    private:
        long os_uptime;
        char *os_name;
        string os_version;
        string os_release;
        string os_domain;
        string os_architecture;
    
    public:
        OS();
        string get_osname(){return os_name;}
        long get_osuptime(){return os_uptime;};
        string get_osrelease(){return os_release;}
        string get_osversion(){return os_version;};
        string get_osdomain(){return os_domain;};
        string get_osarchitecture(){return os_architecture;};

};