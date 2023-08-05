#include "main.h"

/**
 * _isupper - uppercase letters
 * @o: char to check
 *
 * Return: 0 or 1
 */

int _isupper(int o)
{
	if (o >= 'A' && o <= 'Z')
		return (1);
	else
		return (0);
}
