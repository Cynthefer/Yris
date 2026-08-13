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

#ifndef YRIS_H
#define YRIS_H
#endif

#include "user.h"
#include "system.h"
#include "memory.h"
#include "network.h"

#include <string>

using namespace std;

namespace yris{
    User u;
    namespace user{
        string username = u.get_username();
        string fullname = u.get_fullname();
        uid_t userID = u.get_userId();
        gid_t groupID = u.get_groupId();
        time_t created = u.get_creationDate();
    }

    OS s;
    namespace system{
        string name = s.get_osname();
        string shell = s.get_osshell();
        long uptime = s.get_osuptime();
        string release = s.get_osrelease();
        string architecture = s.get_osarchitecture();
        string version = s.get_osversion();
        string domain = s.get_osdomain();
    }
    Memory mem;
    namespace memory{
        int Total_RAM = mem.get_RAM_Total();
        int Free_RAM = mem.get_RAM_Free();
        int Total_Capacity = mem.get_Capacity_Total();
        int Available_Capacity = mem.get_Capacity_Available();
        int Free_Capacity = mem.get_Capacity_Free();

    }
}