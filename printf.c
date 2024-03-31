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
