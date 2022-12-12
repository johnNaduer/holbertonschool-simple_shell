<p align="center">
  <img  src="https://ml.globenewswire.com/Resource/Download/a08e6c28-55be-44c8-8461-03544f094b38">
</p>


# Making a simple shell.

`simple_shell`  This project is part of the Holberton School Peru curriculum; It is also the final project of the first quarter.
This project pushes us to try to simulate the functionalities of a shell.

This function prints to the standard output using a format string that includes instructions for mixing multiple strings into the final string to display on the screen.

## Prototype.
```c
int main(int ac __attribute__((unused)), char **av)
```
## In order to run this program:

### Requirements:
simple_shell is designed to run in the `Ubuntu 20.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 9.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

### Clone this repository with the following command:

#### SSH: `git@github.com:KevinYeff/holbertonschool-simple_shell.git`

#### HTTPS: `https://github.com/KevinYeff/holbertonschool-simple_shell.git`

### Compile the program using he next command:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Structure:
### Files used for this project:

Functions | Description:
------------- | -------------
shell.c| description.
shell.h| Main header file.
cargarTexto.c| description.
procesoHijo.c| description.
localizarPath.c| description.
signal_handler.c| description.
contar_separador.c|  description.
evaluar.c|  description.
environ.c| description.
freeArgumentos.c| description.
tokenizarLectura.c| description.

### Allowed functions that we could use in the `simple_shell` project.
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror`(man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__ xstat) (man 2 stat)
* `lstat` (__ lxstat) (man 2 lstat)
* `fstat` (__ fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)

## Usage
The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):

#### Basic Examples:

**ls Function**

    #cisfun$ ls
    README.md           environ.c         hsh              shell.c                 tokenizarLectura.c
    cargarTexto.c       evaluar.c         localizarPath.c  shell.h
    contar_separador.c  freeArgumentos.c  procesoHijo.c    signal_handler.c
    #cisfun$

**ls -al Function.**

    #cisfun$ ls -al
    total 80
    drwxr-xr-x 3 root root  4096 Dec 11 20:15 .
    drwxr-xr-x 9 root root  4096 Dec 11 12:14 ..
    drwxr-xr-x 8 root root  4096 Dec 11 20:07 .git
    -rw-r--r-- 1 root root    10 Dec 11 11:02 README.md
    -rw-r--r-- 1 root root   773 Dec 11 12:26 cargarTexto.c
    -rw-r--r-- 1 root root   365 Dec 11 12:19 contar_separador.c
    -rw-r--r-- 1 root root   208 Dec 11 12:28 environ.c
    -rw-r--r-- 1 root root  1314 Dec 11 17:10 evaluar.c
    -rw-r--r-- 1 root root   379 Dec 11 12:28 freeArgumentos.c
    -rwxr-xr-x 1 root root 18488 Dec 11 20:15 hsh
    -rw-r--r-- 1 root root   405 Dec 11 11:14 localizarPath.c
    -rw-r--r-- 1 root root   948 Dec 11 20:07 procesoHijo.c
    -rw-r--r-- 1 root root  1250 Dec 11 11:58 shell.c
    -rw-r--r-- 1 root root   554 Dec 11 20:07 shell.h
    -rw-r--r-- 1 root root   188 Dec 11 11:58 signal_handler.c
    -rw-r--r-- 1 root root  1053 Dec 11 11:58 tokenizarLectura.c
    #cisfun$

**env function**

    #cisfun$ env
    SHELL=/bin/bash
    WSL_DISTRO_NAME=Ubuntu-20.04
    WT_SESSION=ab65f92f-615e-4137-9789-f4771b64d44b
    NAME=DESKTOP-J9A2Q81
    PWD=/root/holberton/holbertonschool-simple_shell
    LOGNAME=root
    HOME=/root
    LANG=C.UTF-8
    WSL_INTEROP=/run/WSL/10_interop
    LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33
    ;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=3
    4;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31
    :*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31
    :*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz
    =01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01
    ;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31
    :*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31
    :*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31
    :*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35
    :*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01
    ;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35
    :*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35
    :*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35
    :*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35
    :*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35
    :*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35
    :*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35
    :*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36
    :*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36
    :*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
    LESSCLOSE=/usr/bin/lesspipe %s %s
    TERM=xterm-256color
    LESSOPEN=| /usr/bin/lesspipe %s
    USER=root
    SHLVL=1
    WSLENV=WT_SESSION::WT_PROFILE_ID
    XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
    PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:
    /usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/WINDOWS/system32:/mnt/c
    /WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32
    /WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/c/Program 
    Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/Program Files (x86)
    /dotnet/:/mnt/c/Users/Yeff/AppData/Local/Microsoft/WindowsApps:/snap/bin
    HOSTTYPE=x86_64
    WT_PROFILE_ID={59b72ad2-09f7-55ec-af87-65d062af8472}
    _=./hsh
    OLDPWD=/root/holberton
    #cisfun$

**Holds exit**

    #cisfun$ exit
    root@DESKTOP-J9A2Q81:~/holberton/holbertonschool-simple_shell#

### Compilation
Compiled with :  `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c (-o name)`

## Authors
| [<img src="https://avatars.githubusercontent.com/u/105649198?v=4" width=115><br><sub> Kevin Espinoza </sub>](https://github.com/KevinYeff) | [<img src="https://avatars.githubusercontent.com/u/105601547?v=4" width=115><br><sub> John Naduer </sub>](https://github.com/johnNaduer) |
| :---: | :---:|
