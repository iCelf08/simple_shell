#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
extern char **environ;

char *get_line();
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *des, char *src);
char *_strcpy(char *dest, char *src);
char **tok_maker(char *line);
int _execute(char **command, char **argv, int idx);
void free_command(char **command);
char *_getpath(char *command);
char *_getenv(char *variable);
void _printerror(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);
void print_env(char **command, int status);
void handle_builtin(char **command, char **av, int status, int idx);
void exit_shell(char **command, int status);
int is_builtin(char *command);
#endif
