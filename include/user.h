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

#ifndef USER_H
#define USER_H
#endif

#include <string>

class User{
    public:
        std::string username, fullname;

        uid_t user_id;

        gid_t group_id;

        time_t created;

    public:
        std::string get_username(){return username;}
        std::string get_fullname(){return fullname;}
        uid_t get_userId(){return user_id;}
        gid_t get_groupId(){return group_id;}
        time_t get_creationDate(){return created;}
};
