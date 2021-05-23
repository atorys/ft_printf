#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_putchar_mod(char c, int fd, int mod)
{
	if (mod == 1)
	{
		write(fd, &c, 1);
		return (1);
	}
	else if (!mod)
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	print_nbr(long long n, int fd)
{
	if (n < 0)
		n = -1 * n;
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
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
