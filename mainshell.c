#include "shell.h"
/**
 *main - simple shell main function
 *@ac: number of arguments
 *@av: arguments vectors
 *Return: (0) success
 */

int main(int ac, char **av)
{
char *line = NULL;
char **command = NULL;
int status = 0;
int idx = 0;
(void) ac;
while (1)
{
line = get_line();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
write(1, "\n", 1);
return (status);
}
idx++;
command = tok_maker(line);
if (!command)
continue;
if (is_builtin(command[0]))
handle_builtin(command, av, status, idx);
else
status = _execute(command, av, idx);
}
}
