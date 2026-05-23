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


//yris project headers
#include <yris.h>
#include <user.h>


//other headers and libraries
#include <pwd.h>
#include <ctime>
#include <string>
#include <unistd.h>
#include <sys/resource.h>


using namespace yris;
using namespace std;

string username, fullname, role_str;
uid_t user_id;



int yris_user_t(){
    //username and user_id block
    uid_t uid = getuid();
    struct passwd* pw = getpwuid(uid);
    if(pw){
        username = pw->pw_name;
        user_id = pw->pw_uid;
    } else {
      username = "unknown";
    }

    //fullname block
    if(pw->pw_gecos){
        fullname = pw->pw_gecos;
        size_t comma = fullname.find(',');
        if(comma != string::npos){
            fullname = fullname.substr(0, comma);
        }
    } else {
        fullname = "Unknown";
    }
    
    //account role block
    uid_t role;

    if(pw){
        role = pw->pw_uid;
    }
    switch(role){
        case 0:
            role_str = "Root";
        case 1000:
            role_str = "User";
        default:
            role_str = "Other";
    }            

    return success;
};