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


#pragma once

#ifndef NELVA_H
#define NELVA_H
#endif //NELVA_H

#ifndef VERSION
#define VERSION "1.0.1"
#endif //VERSION

#ifndef AUTHOR
#define AUTHOR "Ntando Khanyile"
#endif //AUTHOR

#ifndef DEVELOPER
#define DEVELOPER AUTHOR
#endif //DEVELOPER

#ifndef OUTPUT
#define success 0
#endif //OUTPUT

struct uservariables{};

namespace yris { //functions to initialise variables for various information

    int yris_init_t();

    int yris_user_t();

    int yris_system_t();

    int yris_network_t();

    int yris_battery_t();

    int yris_cpu_t();

    int yris_memory_t();

}