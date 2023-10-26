#include "main.h"

/**
 * flip_bits - Returns the number of bits to flip to get from n to m.
 * @n: first number to be flipped
 * @m: second number to be flipped
 * Return: The number of bits flipped
 */

	unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x_or = n ^ m;
	unsigned int flag = 0;

	while (x_or > 0)
	{
	flag += x_or & 1;
	x_or >>= 1;
	}
	return (flag);
}
