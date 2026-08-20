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

#include <yris.h>
#include <user.h>
#include <system.h>
#include <memory.h>
#include <network.h>

#include <iomanip>
#include <iostream>

using namespace std;

bool yris::yris_init(){
    for(int i = 0; i < MAX_HR; i++){
        yris::hr = "-";
        i;
    }

    return true;
}

void yris::yris_user(){
    User user;
    cout << setw(30) << "Fullname" << ":" << user.get_fullname() << endl;
    cout << setw(30) << "Username" << ":" << user.get_username() << endl;

}