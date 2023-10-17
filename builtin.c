#include "shell.h"

/**
 *is_builtin - function verifies if command is builtin
 *@command: to be verified
 *Return: 1 to yes , 0 to no
 */
int is_builtin(char *command)
{
char *builtins[] = {"exit", "env", "setenv", "cd", NULL};
int i;
for (i = 0; builtins[i]; i++)
{
if (_strcmp(command, builtins[i]) == 0)
return (1);
}
return (0);
}
/**
 *handle_builtin - function to handle builtin commands
 *@command: to be handled
 *@av:a
 *@status:a
 *@idx:a
 */
void handle_builtin(char **command, char **av, int status, int idx)
{
(void) av;
(void) idx;
if (_strcmp(command[0], "exit") == 0)
exit_shell(command, status);
else if (_strcmp(command[0], "env") == 0)
print_env(command, status);
}
/**
 *exit_shell - function exits from shell
 *@command:a
 *@status:a
 */

void exit_shell(char **command, int status)
{
free_command(command);
exit(status);
}
/**
 *print_env - prints the envirement
 *@command: to get the envirement for
 *@status:a
 */
void print_env(char **command, int status)
{
int i;
(void) status;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
free_command(command);
}
