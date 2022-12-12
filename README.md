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
`
EJEMPLO 1
`

`
EJEMPLO 2
`

`
EJEMPLO 3
`



### Compilation
Compiled with :  `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c (-o name)`

## Authors
| [<img src="https://avatars.githubusercontent.com/u/105649198?v=4" width=115><br><sub> Kevin Espinoza </sub>](https://github.com/KevinYeff) | [<img src="https://avatars.githubusercontent.com/u/105601547?v=4" width=115><br><sub> John Naduer </sub>](https://github.com/johnNaduer) |
| :---: | :---:|
