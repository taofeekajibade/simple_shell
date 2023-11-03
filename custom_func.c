#include "shell.h"
/**
 * _strlen - A Function to find the length a string.
 * @str: string to count.
 *
 * Return: Number of characters.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcopy - A Function to copy a string.
 * @dest: Pointer to newly made string.
 * @src: Pointer to string being copied.
 *
 * Return: Number of characters.
 */
char *_strcopy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - A Function to concatenate a string
 * @dest: String to modify.
 * @src: String to modify with.
 *
 * Return: Newly modified string.
 */
char *_strcat(char *dest, char *src)
{
	int i, len1, len2;

	len1 = _strlen(dest);
	len2 = _strlen(src);

	for (i = 0; i <= len2; i++)
	{
		dest[len1 + i] = src[i];
	}
	return (dest);
}
