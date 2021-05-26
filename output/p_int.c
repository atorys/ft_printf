#include "ft_printf.h"

static void	params_parsing(long long c, t_fmt *params, char *sign)
{
	if (params->precision >= 0)
		params->zero = 0;
	if (c == 0 && params->precision == 0)
		params->precision = 0;
	else if (len(c) > params->precision)
		params->precision = len(c);
	if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width *= -1;
	}
	if (params->precision < 0)
		params->precision = 0;
	if (*sign == '-' || (*sign == '+' && params->plus))
		params->space = 1;
	if (*sign == '+' && params->space && !params->plus)
		*sign = ' ';
}

static void	if_minus(long long c, char sign, t_fmt *params, int *printed)
{
	if (params->space)
		*printed += print_char(sign, 1, 1);
	while (params->precision - len(c) > 0)
	{
		params->precision--;
		params->width--;
		*printed += print_char('0', 1, 1);
	}
	if (!(c == 0 && params->precision == 0))
	{
		print_nbr(c, 1);
		*printed += len(c);
	}
	while (params->width - params->precision - params->space > 0)
	{
		params->width--;
		*printed += print_char(' ', 1, 1);
	}
}

static void	if_zero(long long c, char sign, t_fmt *params, int *printed)
{
	if (params->space)
		*printed += print_char(sign, 1, 1);
	while (params->width - len(c) - params->space > 0)
	{
		params->width--;
		*printed += print_char('0', 1, 1);
	}
	print_nbr(c, 1);
	*printed += len(c);
}

static void	if_not_zero(long long c, char sign, t_fmt *params, int *printed)
{
	if (params->width < params->precision)
		params->width = params->precision;
	while (params->width - params->precision - params->space > 0)
	{
		params->width--;
		*printed += print_char(' ', 1, 1);
	}
	if (params->space)
		*printed += print_char(sign, 1, 1);
	while (params->precision - len(c) > 0)
	{
		params->precision--;
		*printed += print_char('0', 1, 1);
	}
	if (!(c == 0 && params->precision == 0))
	{
		print_nbr(c, 1);
		*printed += len(c);
	}
}

void	p_int(va_list arguments, t_fmt *params, int *printed)
{
	long long	c;
	char		sign;

	c = (long long)va_arg(arguments, int);
	sign = '-';
	if (c >= 0)
		sign = '+';
	params_parsing(c, params, &sign);
	if (params->minus)
		if_minus(c, sign, params, printed);
	else
	{
		if (params->zero)
			if_zero(c, sign, params, printed);
		else
			if_not_zero(c, sign, params, printed);
	}
}
