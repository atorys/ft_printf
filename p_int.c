#include "ft_printf.h"
#include "libft/libft.h"

void	print_nbr(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 2147483647)
		ft_putstr_fd("2147483647", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -1 * n;
		}
		if (n >= 0 && n < 10)
			ft_putchar_fd(n + '0', fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}

int len(int c)
{
	int len;

	len = 0;
	while (c > 0)
	{
		c /= 10;
		len++;
	}
	return (len);
}
void p_int(va_list arguments, t_fmt *params, int *printed)
{
	int c;

	c = va_arg(arguments, int);
	if (c == 0 && params->precision == 0)
		return ;
	if (params->precision >= 0)
		params->zero = 0;
	if (len(c) < params->precision)
		params->precision = len(c);
	if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width = -1 * params->width;
	}

	if (params->minus)
	{
		if (c < 0)
			ft_putchar_fd('-', 1);
		while (params->width--)
		{
			while (params->precision - len(c) > 0)
			{
				ft_putchar_fd('0', 1);
				params->precision--;
				params->width--;
			}
			ft_putchar_fd(' ', 1);
		}
	}
	else if (params->zero)
	{
	}
	}












	if (!params->width)
	{
		ft_putchar_fd(c, 1);
		printed++;
	}
	else if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width = -1 * params->width;
	}
	if (params->minus)
	{
		ft_putchar_fd(c, 1);
		while (--params->width > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		if (params->zero)
		{
			while (params->width-- > 1)
				ft_putchar_fd('0', 1);
			ft_putchar_fd(c, 1);
		}
		else{
			while ( params->width-- > 1)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(c, 1);
		}
	}
}