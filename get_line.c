#include "shell.h"
#include <stdio.h>
/**
 *get_line - function gets line from user input
 *Return: pointer to a line
 */
char *get_line()
{
char *line = NULL;
size_t len = 0;
ssize_t n;
if (isatty(STDIN_FILENO))
write(1, "$ ", 2);
n = getline(&line, &len, stdin);
if (n == -1)
{
free(line), line = NULL;
return (NULL);
}
return (line);
}
