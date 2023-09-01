#include "main.h"


/**
 * get_endianness - function that checks the endianness.
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int endianness = 1;
	char *the_ptr = (char *)&endianness;

	return (*the_ptr);
}
