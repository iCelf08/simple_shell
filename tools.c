#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
/**
 *free_command- function to free command array
 *@command: array to be freed
*/

void free_command(char **command)
{
int i = 0;
if (!command)
return;
for (i = 0; command[i]; i++)
{
free(command[i]);
command[i] = NULL;
}
free(command), command = NULL;
}

/**
 *_printerror - function prints related error
 *@name: name of calling prog
 *@cmd: command name
 *@idx: index of command
*/

void _printerror(char *name, char *cmd, int idx)
{
char *index;
char mssg[] = ": not found\n";
index = _itoa(idx);
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, mssg, _strlen(mssg));
free(index);
}

/**
 *_itoa - function changes integer to character
 *@n:value to be changed
 *Return: character of the integer given
*/

char *_itoa(int n)
{
char buffer[20];
int i = 0;
if (n == 0)
buffer[i++] = '0';
else
{
while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}
}
buffer[i] = '\0';
reverse_string(buffer, i);
return (_strdup(buffer));
}

/**
 *reverse_string - function to reverse string
 *@str: string to reverse
 *@len: lengt of string
 */
void reverse_string(char *str, int len)
{
char tmp;
int start;
int end;
start = 0;
end = len - 1;
while (start < end)
{
tmp = str[start];
str[start] = str[end];
str[end] = tmp;
start++;
end--;
}
}
