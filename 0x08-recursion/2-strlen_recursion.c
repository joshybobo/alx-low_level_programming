#include "main.h"
/**
 * _strlen_recursion - Returns lenght of string
 * @s;string to be measured
 *
 * Return: The length of the input string 's'
 */
int _strlen_recursion(char *s)
{
	int longit = 0;

	if (*s)
	{
	longit++;
	longit += _strlen_recursion(s + 1);
	}

	return (longit);
}
