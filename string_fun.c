#include "shell.h"

/**
*_strdup - function duplicate string
*@str: constante to be duplicated
*Return: pointer to duplicated string
*/

char *_strdup(const char *str)
{
char *ptr;
int i = 0;
int len = 0;
if (str == NULL)
return (NULL);
while (*str != '\0')
{
len++;
str++;
}
str = str - len;
ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
return (NULL);
for (i = 0; i <= len; i++)
ptr[i] = str[i];
return (ptr);
}

/**
 *_strcmp - fonction that compaires two strings
 *@s1: string 1 pointer
 *@s2: string 2 pointer
 *Return: 0 (success)
 */

int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s2 != '\0')
{
if (*s1 != *s2)
{
return (*s1 - *s2);
}
s1++;
s2++;
}
if (*s1 == '\0' && *s2 == '\0')
{
return (0);
}
else if (*s1 == '\0')
{
return (-1);
}
return (1);
}

/**
 * char *_strcpy - a function that copies the string pointed to\
 by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
int l = 0;
int x = 0;
while (*(src + l) != '\0')
{
l++;
}
for ( ; x < l ; x++)
{
dest[x] = src[x];
}
dest[l] = '\0';
return (dest);
}
/**
 *_strcat - function that concatenates two strings
 *@dest: pointer type char
 *@src: pointer type char
 *Return: 'dest'
 */
char *_strcat(char *dest, char *src)
{
char *app = dest;
while (*app != '\0')
{
app++;
}
while (*src != '\0')
{
*app = *src;
app++;
src++;
}
*app = '\0';
return (dest);
}
/**
* _strlen - function that returns length of a string
*@s: pointer type char
*Return: length
*/
int _strlen(char *s)
{
int l = 0;
while (*s != '\0')
{
l++;
s++;
}
return (l);
}
