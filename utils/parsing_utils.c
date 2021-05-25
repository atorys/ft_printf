#include "ft_printf.h"

void	new_params(t_fmt *params)
{
	params->minus = 0;
	params->zero = 0;
	params->width = 0;
	params->precision = -10;
	params->type = 0;
}

int	is_type(char format)
{
	if (format == 'd' || format == 'i' || format == 's' || format == 'c' || \
		format == 'p' || format == 'u' || format == 'x' || format == 'X' || \
		format == '%' || format == 'n')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
