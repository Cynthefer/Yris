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


#include <../include/hardware.h>

#include <iostream>
#include <fstream>
#include <string>

bool getMemoryStats(long &Total_Ram, long &Avail_Ram, long &Used_Ram) {
    std::ifstream meminfo("/proc/meminfo");
    if (!meminfo.is_open()) {
        return false;
    }

    std::string key, unit;
    long value;

    long memTotal = 0;
    long memAvailable = 0;

    while (meminfo >> key >> value >> unit) {
        if (key == "MemTotal:") {
            memTotal = value;           
        }
        else if (key == "MemAvailable:") {
            memAvailable = value;       
        }
        if (memTotal && memAvailable)
            break;
    }

    // Convert from kB to MB
    Total_Ram = memTotal / 1024;
    Avail_Ram = memAvailable / 1024;
    Used_Ram  = Total_Ram - Avail_Ram;

    return true;
}