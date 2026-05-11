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


#include "include/nelva.h"
#include <initializer_list>

using namespace std;

struct initializer {
    initializer(){
        //nelva();
    }
} initializer;

int main(int argc, char* argv[]){
    bool main = false;
    
    for(int i = 1; i < argc; ++i){
        string arg = argv[i];
        main = true;

        if(arg == "-h" || arg == "--help"){
            help();
        } else if( arg == "-v" || arg == "--version"){
            version();
        } else if( arg == "-u" || arg == "--user"){
            user();
        } else if (arg == "-o" || arg == "--operating-system"){
            operating();
        }
    };
    
    if(!main){
        //default program
        nelva();
    }
    return EXIT_SUCCESS;
}
