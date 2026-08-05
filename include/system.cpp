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


#include <ctype.h>
#include <string>
#include <system.h>

#include <pwd.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

using namespace std;

OS::OS(){
  struct utsname os;
  uname(&os);
  os_name = os.sysname;
  os_release = os.release;
  os_architecture = os.machine;
  os_version = os.version;
  os_domain = os.domainname;

  struct sysinfo info;
  sysinfo(&info);
  os_uptime = info.uptime;

  uid_t uid = getuid();
  struct passwd* pw = getpwuid(uid);
  if(pw){
    shell = basename(pw->pw_shell);
  }
};

