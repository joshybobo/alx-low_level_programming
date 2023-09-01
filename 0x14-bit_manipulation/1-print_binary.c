#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to be printed in binary
 * Return: no return
 */

void print_binary(unsigned long int n)
{
int count = sizeof(unsigned long int) * 8 - 1;
int test = 0;

while (count >= 0)
{
int bit = (n >> count) & 1;
if (bit || test)
{
_putchar(bit + '0');
flag = 1;
}

count--;
}
if (!test)
_putchar('0');
}
