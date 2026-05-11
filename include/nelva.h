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


#ifndef NELVA_H
#define NELVA_H
#define VERSION "1.0.1"
#define AUTHOR "Ntando Khanyile"
#define DEVELOPER AUTHOR
    #include <cstdlib>
    #include <string>
    #include <iomanip>

    using namespace std;

    int help(), version(), user(), operating(), nelva(), oper(), intro();

#endif//NELVA_H
