#include "shell.h"

/**
 *_execute - function executes commmand
 *@command: to be exucted
 *@argv: arguments
 *@idx: indx of commands
*Return: Status
 */

int _execute(char **command, char **argv, int idx)
{
char *full_cmd;
pid_t child;
int status;
full_cmd = _getpath(command[0]);
if (!full_cmd)
{
_printerror(argv[0], command[0], idx);
free_command(command);
return (127);
}
child = fork();
if (child == 0)
{
if (execve(full_cmd, command, environ) == -1)
{
free(full_cmd), full_cmd = NULL;
free_command(command);
}
}
else
{
waitpid(child, &status, 0);
free_command(command);
free(full_cmd), full_cmd = NULL;
}
return (WEXITSTATUS(status));
}
