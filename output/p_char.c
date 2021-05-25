#include "ft_printf.h"

static void	if_minus(char c, t_fmt *params)
{
	write(1, &c, 1);
	while (--params->width > 0)
		print_char(' ', 1, -1);
}

static void	if_not_minus(char c, t_fmt *params)
{
	char	flag;

	flag = ' ';
	if (params->zero)
		flag = '0';
	while (params->width-- > 1)
		print_char(flag, 1, -1);
	write(1, &c, 1);
}

void	p_char(va_list arguments, t_fmt *params, int *printed)
{
	char	c;

	if (params->type == '%')
		c = '%';
	else
		c = va_arg(arguments, int);
	if (!params->width)
	{
		*printed += print_char(c, 1, 1);
		return ;
	}
	else if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width = -1 * params->width;
	}
	*printed += params->width;
	if (params->minus)
		if_minus(c, params);
	else
		if_not_minus(c, params);
}
