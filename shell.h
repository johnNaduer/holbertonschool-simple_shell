#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Funciones */

extern char **environ;

char *cargar_texto();
char **toukenizar_lectura(char *line, char *delims);
int proceso_hijo(char *_line, char **_args, char **av);
void sig_handler(int signo);
int contar_separador(char *line, char sep);
int validar_espacios(char *input);
char *evaluar(char *exe);
char *localizar_path();
void imprimir_env(void);
void free_argumentos(char **arg);

#endif
