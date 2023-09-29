#include "main.h"
/**
 * factorial - Computes the factorial of a non-negative integer.
 * @n: The non-negative integer for which to compute the factorial.
 *
 * Return: The factorial of the input integer, or -1 if the input is negative.
 */
int factorial(int n)
{
	if (n < 0)
	return (-1);
	if (n == 0)
	return (1);
	return (n * factorial(n - 1));
}
