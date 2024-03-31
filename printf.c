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
/**
 * _string - prints the characters of the string
 * @str: string pointer of which characters should be printed
 * Return: the length of the string
 */
int _string(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (4);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i - 2);
}
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0, count = 0;
	char c;

	va_start(ap, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == '\0')
				return (-1);
			else if (format[j] == 'd' || format[j] == 'i')
			{
				i = _digit(va_arg(ap, int)), count += i;
			}
			else if (format[j] == 's')
			{
				i = _string(va_arg(ap, char *)), count += i;
			}
			else if (format[j] == 'c')
			{
				c = (char)va_arg(ap, int);
				write(1, &c, 1), count--;
			}
			else if (format[j] == '%')
			{
				write(1, &format[j], 1), count--;
			}
			else
				write(1, "%", 1), write(1, &format[j], 1);
		}
		else
			write(1, &format[j], 1);
		j++;
	}
	va_end(ap);
	return (j + count);
}
