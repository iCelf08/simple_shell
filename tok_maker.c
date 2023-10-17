 #include "shell.h"
/**
 *tok_maker - tokenizes line
 *@line: line to be tokenized
 *Return: pointer to tokens pointer
*/

char **tok_maker(char *line)
{
int i = 0;
char *token = NULL, *dup = NULL;
char **command = NULL;
int cont = 0;
char delim[] = {" \t\n"};

if (!line)
return (NULL);
dup = _strdup(line);
token = strtok(dup, delim);
if (token == NULL)
{
free(line), line = NULL;
free(dup), dup = NULL;
return (NULL);
}
while (token)
{
cont++;
token = strtok(NULL, delim);
}
free(dup), dup = NULL;
command = malloc(sizeof(char *) * (cont + 1));
if (!command)
{
free(line), line = NULL;
return (NULL);
}
token = strtok(line, delim);
while (token)
{
command[i] = _strdup(token);
token = strtok(NULL, delim);
i++;
}
free(line), line = NULL;
command[i] = NULL;
return (command);
}
