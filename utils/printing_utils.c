#include "ft_printf.h"

int	print_char(char c, int fd, int mod)
{
	if (mod == 1)
	{
		write(fd, &c, 1);
		return (1);
	}
	else if (!mod)
		return (1);
	else if (mod == -1)
		write(fd, &c, 1);
	return (0);
}

void	print_nbr(long long n, int fd)
{
	if (n < 0)
		n = -1 * n;
	if (n >= 0 && n < 10)
		print_char(n + '0', 1, -1);
	else
	{
		print_nbr(n / 10, fd);
		print_nbr(n % 10, fd);
	}
}

int	len(long long c)
{
	int	len;

	len = 0;
	if (c < 0)
		c *= -1;
	if (c == 0)
		len = 1;
	while (c > 0)
	{
		c /= 10;
		len++;
	}
	return (len);
}

int	print_nbr_16(unsigned long n, char *base, int mod)
{
	if (n < 16)
		return (print_char(base[n], 1, mod));
	return (print_nbr_16(n / 16, base, mod) + print_char(base[n % 16], 1, mod));
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}
