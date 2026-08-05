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

#include <memory.h>

#include <cstdlib>
#include <filesystem>
#include <sys/sysinfo.h>

using namespace std;

Memory::Memory(){
    struct sysinfo info;
    if(sysinfo(&info) == 0){
        unsigned long long total_ram = (unsigned long long)info.totalram * info.mem_unit;
        unsigned long long free_ram = (unsigned long long)info.freeram * info.mem_unit;
        double totalRam = (double)total_ram / 1024 / 1024 / 1024;
        double freeRam = (double)free_ram / 1024 / 1024 / 1024;
        RAM_Total = totalRam;
        RAM_Free = freeRam;
    } else {
        RAM_Total = -1;
        RAM_Free = -1;
    }

    filesystem::space_info cap = filesystem::space("/");
    Capacity_Total = cap.capacity / 1024 / 1024 / 1024;
    Capacity_Available = cap.available / 1024 / 1024 / 1024;
    Capacity_Free = cap.free / 1024 / 1024 / 1024;
}