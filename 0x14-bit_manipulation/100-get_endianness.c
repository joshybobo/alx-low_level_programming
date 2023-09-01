#include <stdio.h>

int get_endianness(void)
{
    unsigned int j = 1;
    char *c = (char *)&j;

    // If the first byte (lowest address) contains 1, it's little-endian; otherwise, it's big-endian.
    return (int)(*c);
}

int main()
{
    int endianness = get_endianness();
    
    if (endianness == 0)
        printf("This machine is big-endian.\n");
    else
        printf("This machine is little-endian.\n");
    
    return 0;
}
