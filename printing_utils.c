#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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

void	print_nbr(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else if (n == 2147483647)
		ft_putstr_fd("2147483647", fd);
	else
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
}

int	len(int c)
{
	int	len;

	len = 0;
	if (c < 0 && c > -2147483648)
		c *= -1;
	if (c == -2147483648 || c == 2147483647)
		len = 10;
	while (c > 0 && c != 2147483647)
	{
		c /= 10;
		len++;
	}
	return (len);
}
