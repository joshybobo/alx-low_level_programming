# include "main.h"

/**
*function that prints a string in reverse
 * the string to be printed
 */
	void_print_rev_recursion(char *r)
{
	if (*r)
	{
		void_print_rev_recursion(r + 1);
		_putchar(*r);
	}
}
