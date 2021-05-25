#include "ft_printf.h"

static void	params_parsing(unsigned long c, t_fmt *params, int hex_len)
{
	if (params->precision >= 0)
		params->zero = 0;
	if (c == 0 && params->precision == 0)
		params->precision = 0;
	else if (hex_len > params->precision)
		params->precision = hex_len;
	if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width *= -1;
	}
	if (params->precision < 0)
		params->precision = 0;
}

static void	if_minus(unsigned long c, t_fmt *params, int *printed, int hex_len)
{
	*printed += print_char('0', 1, 1) + print_char('x', 1, 1);
	while (params->precision - hex_len > 0)
	{
		params->precision--;
		params->width--;
		*printed += print_char('0', 1, 1);
	}
	if (!(c == 0 && params->precision == 0))
		*printed += print_nbr_16(c, "0123456789abcdef", 1);
	while (params->width - params->precision - 2 > 0)
	{
		params->width--;
		*printed += print_char(' ', 1, 1);
	}
}

static void	if_zero(unsigned long c, t_fmt *params, int *printed, int hex_len)
{
	*printed += print_char('0', 1, 1) + print_char('x', 1, 1);
	while (params->width - hex_len - 2 > 0)
	{
		params->width--;
		*printed += print_char('0', 1, 1);
	}
	*printed += print_nbr_16(c, "0123456789abcdef", 1);
}

static void	if_nozero(unsigned long c, t_fmt *params, int *printed, int hex_len)
{
	if (params->width < params->precision)
		params->width = params->precision;
	while (params->width - params->precision - 2 > 0)
	{
		params->width--;
		*printed += print_char(' ', 1, 1);
	}
	*printed += print_char('0', 1, 1) + print_char('x', 1, 1);
	while (params->precision - hex_len > 0)
	{
		params->precision--;
		*printed += print_char('0', 1, 1);
	}
	if (!(c == 0 && params->precision == 0))
		*printed += print_nbr_16(c, "0123456789abcdef", 1);
}

void	p_pointer(va_list arguments, t_fmt *params, int *printed)
{
	unsigned long	c;
	int				hex_len;

	c = va_arg(arguments, unsigned long);
	hex_len = print_nbr_16(c, "0123456789abcdef", 0);
	params_parsing(c, params, hex_len);
	if (params->minus)
		if_minus(c, params, printed, hex_len);
	else
	{
		if (params->zero)
			if_zero(c, params, printed, hex_len);
		else
			if_nozero(c, params, printed, hex_len);
	}
}
