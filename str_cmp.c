#include "shell.h"
/**
 *_strcmp - Function that that compares two character strings
 *@str1: string 1
 *@str2: string 2
 *Return: 0 if strings are same or -1 on failure
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
