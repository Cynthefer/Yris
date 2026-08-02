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


#include <ctype.h>
#include <string>
#include <system.h>

#ifdef defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#elif defined(__linux__) || defined(__unix__)
    #include <sys/utsname.h>
#endif

using namespace std;

OS::OS(){
    set_os;
    set_version;
    set_release;
    set_architecture;
};

void set_os(){
    #ifdef defined(_WIN32) || defined(_WIN64)

    #elif defined(__linux__) || defined(__unix__)
        struct utsname os;
        uname(&os);
        os_name = to_string(os.sysname);
    #endif
}