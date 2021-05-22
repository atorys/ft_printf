#include "ft_printf.h"

void p_char(va_list arguments, t_fmt *params, int *printed)
{
	char	c;

	c = va_arg(arguments, int);
	if (!c)
		return ;
	if (!params->width)
	{
		write(1, &c, 1);
		*printed += 1;
		return ;
	}
	else if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width = -1 * params->width;
	}
	if (params->minus)
	{
		write(1, &c, 1);
		*printed += params->width;
		while (--params->width > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		*printed += params->width;
		if (params->zero)
		{
			while (params->width-- > 1)
				ft_putchar_fd('0', 1);
			write(1, &c, 1);
		}
		else
		{
			while ( params->width-- > 1)
				ft_putchar_fd(' ', 1);
			write(1, &c, 1);
		}
	}
}
