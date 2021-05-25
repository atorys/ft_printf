#include "ft_printf.h"

static void	params_parsing(unsigned int c, t_fmt *params, int hex_len)
{
	if (params->precision >= 0)
		params->zero = 0;
	if (c == 0)
	{
		if (params->precision == 0)
			params->precision = 0;
		params->sharp = 0;
	}
	if (hex_len > params->precision && !(c == 0 && params->precision == 0))
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

static void	if_minus(unsigned int c, t_fmt *params, int *printed, int hex_len)
{
	if (params->sharp)
		*printed += print_char('0', 1, 1) + print_char('x', 1, 1);
	while (params->precision - hex_len > 0)
	{
		params->precision--;
		params->width--;
		*printed += print_char('0', 1, 1);
	}
	if (!(c == 0 && params->precision == 0))
		*printed += print_nbr_16((unsigned long)c, "0123456789abcdef", 1);
	while (params->width - params->precision - params->sharp > 0)
	{
		params->width--;
		*printed += print_char(' ', 1, 1);
	}
}

static void	if_zero(unsigned int c, t_fmt *params, int *printed, int hex_len)
{
	if (params->sharp)
		*printed += print_char('0', 1, 1) + print_char('x', 1, 1);
	while (params->width - hex_len - params->sharp > 0)
	{
		params->width--;
		*printed += print_char('0', 1, 1);
	}
	*printed += print_nbr_16((unsigned long)c, "0123456789abcdef", 1);
}

static void	if_no_zero(unsigned int c, t_fmt *params, int *printed, int hex_len)
{
	if (params->width < params->precision)
		params->width = params->precision;
	while (params->width - params->precision - params->sharp > 0)
	{
		params->width--;
		*printed += print_char(' ', 1, 1);
	}
	if (params->sharp)
		*printed += print_char('0', 1, 1) + print_char('x', 1, 1);
	while (params->precision - hex_len > 0)
	{
		params->precision--;
		*printed += print_char('0', 1, 1);
	}
	if (!(c == 0 && params->precision == 0))
		*printed += print_nbr_16((unsigned long)c, "0123456789abcdef", 1);
}

void	p_hex(va_list arguments, t_fmt *params, int *printed)
{
	unsigned int	c;
	int				hex_len;

	c = va_arg(arguments, unsigned int);
	hex_len = print_nbr_16((unsigned long)c, "0123456789abcdef", 0);
	params_parsing(c, params, hex_len);
	if (params->minus)
		if_minus(c, params, printed, hex_len);
	else
	{
		if (params->zero)
			if_zero(c, params, printed, hex_len);
		else
			if_no_zero(c, params, printed, hex_len);
	}
}
