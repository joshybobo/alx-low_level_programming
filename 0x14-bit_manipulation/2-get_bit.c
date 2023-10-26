#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number from which to extract the bit.
 * @index: The index of the bit to be retrieved.
 *
 * Return: The value of the bit at index, or -1 if an error occurred.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;

	if (index >= 64
			)
	{
	return (-1);
	}
	i = 1 << index;

	if (n & i)
	return (1);
	else
	return (0);

}
