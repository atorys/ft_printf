#include "ft_printf.h"

void p_int(va_list arguments, t_fmt *params, int *printed)
{
	int c;
	int minus;

	c = va_arg(arguments, int);
	minus = 0;
	if (c == 0 && params->precision == 0)
		return ;
	if (params->precision >= 0)
		params->zero = 0;
	if (len(c) > params->precision)
		params->precision = len(c);
	if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width = -1 * params->width;
	}
	if (params->precision < 0)
		params->precision = 0;

	if (params->minus)
	{
		if (c < 0)
		{
			ft_putchar_fd('-', 1);
			*printed += 1;
			minus = 1;
		}
		while (params->precision - len(c) > 0)
		{
			ft_putchar_fd('0', 1);
			params->precision--;
			params->width--;
			*printed += 1;
		}
		print_nbr(c, 1);
		*printed += len(c);
		while (params->width - params->precision - minus > 0)
		{
			ft_putchar_fd(' ', 1);
			params->width--;
			*printed += 1;
		}
	}
	else
	{
		if (c < 0)
			minus = 1;
		if (params->zero)
		{
			if (minus)
				ft_putchar_fd('-', 1);
			*printed += minus;
			while (params->width - len(c) - minus > 0)
			{
				ft_putchar_fd('0', 1);
				params->width--;
				*printed += 1;
			}
			print_nbr(c, 1);
			*printed += len(c);
		}
		else
		{
			if (params->width < params->precision)
				params->width = params->precision;
			while (params->width - params->precision - minus > 0)
			{
				ft_putchar_fd(' ', 1);
				params->width--;
				*printed += 1;
			}
			if (minus)
				ft_putchar_fd('-', 1);
			*printed += minus;
			while (params->precision - len(c) > 0)
			{
				ft_putchar_fd('0', 1);
				params->precision--;
				*printed += 1;
			}
			print_nbr(c, 1);
			*printed += len(c);
		}
	}
}