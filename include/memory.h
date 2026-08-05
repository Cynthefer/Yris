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

#ifndef MEMORY_H
#define MEMORY_H
#endif

class Memory{
    private:
        int RAM_Total;
        int RAM_Free;
        int ROM;
        int HDD;
        int SSD;
    
        public:
            Memory();
            int get_RAM_Total(){return RAM_Total;};
            int get_RAM_Free(){return RAM_Free;};
            int get_ROM(){return ROM;};
            int get_HDD(){return HDD;};
            int get_SSD(){return SSD;};
};