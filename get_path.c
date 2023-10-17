#include "shell.h"
/**
 *_getpath - function gets a command full path
 *@command: comand to get its the path
 *Return: full path
 */
char *_getpath(char *command)
{
char *path_env, *full_path, *dir;
int i;
struct stat st;

for (i = 0; command[i]; i++)
{
if (command[i] == '/')
{
if (stat(command, &st) == 0)
return (_strdup(command));
return (NULL);
}
}
path_env = _getenv("PATH");
if (!path_env)
return (NULL);
dir = strtok(path_env, ":");
while (dir)
{
full_path = malloc(_strlen(dir) + _strlen(command) + 2);
if (full_path)
{
_strcpy(full_path, dir);
_strcat(full_path, "/");
_strcat(full_path, command);
if (stat(full_path, &st) == 0)
{
free(path_env);
return (full_path);
}
free(full_path), full_path = NULL;
dir = strtok(NULL, ":");
}
}
free(path_env);
return (NULL);
}
