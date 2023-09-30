#include "main.h"

/**
 * _sqrt_recursion - comp the square root of a non-negative int  using cursion
 * @n: The non-negative integer for which to find the square root.
 *
 * Return: The square root of 'n', or -1 if 'n' is negative.
 *
*/
int _sqrt_recursion(int n)
	{
	if (n < 0)
	return (-1);
	return (sqrt_helper(n, 0));
	}
