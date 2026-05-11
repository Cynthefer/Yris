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


#include <iostream>
#include "../include/nelva.h"
#include "../include/software.h"

using namespace std;

[[maybe_unused]]string hr = "\n--------------------------------------------------\n";

int nelva(){
    intro();
    user();
    operating();
    return 0;
}

int intro(){
    cout << hr;
    cout << "           Nelva";
    cout << hr;
    cout << setw(28) << setiosflags(ios::left) << " Software Version " << ":" << VERSION << endl;
    cout << setw(28) << setiosflags(ios::left) << " Author " << ":" << AUTHOR << endl;
    cout << setw(28) << setiosflags(ios::left) << " Developer " << ":" << DEVELOPER << endl;
    return 0;
}

int help(){
    cout << "Usage: nelva [-h | --help] [-v | --version] [-u | --user] [-o | --operating-system] [-m | --memory] [-n | --network] [--hardware] [-i | --install]\n" << endl;

    cout << "Options:\n" << endl;
    cout << setw(28) << setiosflags(ios::left) << " [-h | --help]" << "Prints this message\n";
    cout << setw(28) << setiosflags(ios::left) << " [-v | --version]" << "Displays the software version\n";
    cout << setw(28) << setiosflags(ios::left) << " [-u | --user]" << "Displays user information\n";
    cout << setw(28) << setiosflags(ios::left) << " [-o | --operating-system]" << "Displays OS information\n";
    return 0;
}

int version(){
    cout << setw(28) << setiosflags(ios::left) << " Version: " << VERSION << endl;
    return 0;
}

int user(){
    cout << hr;
    cout << "                USER INFORMATION        ";
    cout << hr;
    cout << setw(28) << setiosflags(ios::left) << " Username " << ":" << username << endl;
    cout << setw(28) << setiosflags(ios::left) << " Password " << ":" << password << endl;
    cout << setw(28) << setiosflags(ios::left) << " User ID " << ":" << user_id << endl;
    cout << setw(28) << setiosflags(ios::left) << " Group ID " << ":" << group_id << endl;
    cout << setw(28) << setiosflags(ios::left) << " Shell " << ":" << shell << endl;
    cout << setw(28) << setiosflags(ios::left) << " Directory " << ":" << directory << endl;
    return 0;
}

int operating(){
    cout << hr;
    cout << "               Operating System";
    cout << hr;
    oper();
    return 0;
}
