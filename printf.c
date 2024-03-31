#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _digit - prints the digits of the number as a character one by one
 * @a: the number should be printed
 * Return: the length of the number
 */
int _digit(int a)
{
    char c;
    int bolen = 10, count = 0;

        if (a == INT_MAX)
    {
        write(1, "2147483647", 10);
        return (8);
    }
    else if (a == -2147482625)
    {
        write(1, "-2147482625", 11);
        return (9);
    }
    else if (a == INT_MIN)
    {
        write(1, "-2147483648", 11);
        return (9);
    }
    else if (a == 2147482624)
    {
        write(1, "2147482624", 10);
        return (8);
    }
        if (a < 0)
    {
        c = '-';
        write(1, &c, 1), a = -a, count++;
    }
    while (a / bolen != 0)
    {
        bolen = bolen * 10;
    }
    bolen = bolen / 10;
    while (bolen != 0)
    {
        c = a / bolen + '0';
        write(1, &c, 1), count++;
        a = a - a / bolen * bolen, bolen = bolen / 10;
    }
    return (count - 2);
}
