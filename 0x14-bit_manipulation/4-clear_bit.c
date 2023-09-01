#include "main.h"

/**
 * set_bit_to_zero - Sets the value of a bit to 0 at a specified index.
 * @n: A pointer to the number whose bit is to be cleared.
 * @index: The index of the bit to be cleared.
 *
 * Return: 1 if the operation was successful, or -1 on error.
 */
int set_bit_to_zero(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    *n &= ~(1UL << index);
    return (1);
}
