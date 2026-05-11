<<<<<<< HEAD
//  Yris is a recreation of the unfinished Nelva project which prints
//  system and hardware informatin for unix systems
//
//           Copyright (C) 2026  Ntando khanyile
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.


=======
>>>>>>> origin/main
#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>

#ifdef _WIN32
    #include <windows.h>
    #include <tchar.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <process.h>
    #include <direct.h>
#else
    #include <pwd.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/utsname.h>
    #include <sys/sysinfo.h>
#endif// OS Detection

using namespace std; 

//User Information
extern const string username;
extern const string password;
extern const unsigned int user_id;
extern const unsigned int group_id;
extern const string shell;
extern const string hostname;
extern const string directory;

#endif// SOFTWARE_H

