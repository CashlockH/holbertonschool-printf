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
