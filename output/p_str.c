#include "ft_printf.h"

static void	params_parsing(char *c, t_fmt *params)
{
	if (ft_strlen(c) < params->precision)
		params->precision = ft_strlen(c);
	if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width *= -1;
	}
	if (params->precision < 0)
		params->precision = ft_strlen(c);
}

static void	if_minus(char *c, t_fmt *params, int *printed)
{
	if (params->precision != 0)
	{
		while (*c && params->precision-- > 0)
		{
			*printed += print_char(*c++, 1, 1);
			params->width--;
		}
	}
	while (params->width-- > 0)
		*printed += print_char(' ', 1, 1);
}

static void	if_zero(char *c, t_fmt *params, int *printed)
{
	while (params->width - params->precision > 0)
	{
		params->width--;
		*printed += print_char('0', 1, 1);
	}
	while (*c && params->precision-- > 0)
		*printed += print_char(*c++, 1, 1);
}

static void	if_not_zero(char *c, t_fmt *params, int *printed)
{
	if (params->width < params->precision)
		params->width = params->precision;
	while (params->width - params->precision > 0)
	{
		params->width--;
		*printed += print_char(' ', 1, 1);
	}
	if (params->precision != 0)
	{
		while (*c && params->precision-- > 0)
			*printed += print_char(*c++, 1, 1);
	}
}

void	p_str(va_list arguments, t_fmt *params, int *printed)
{
	char	*c;

	c = (char *)va_arg(arguments, void *);
	if (!c)
		c = "(null)";
	params_parsing(c, params);
	if (params->minus)
		if_minus(c, params, printed);
	else
	{
		if (params->zero)
			if_zero(c, params, printed);
		else
			if_not_zero(c, params, printed);
	}
}
