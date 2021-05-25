#include "ft_printf.h"

void	p_printed(va_list arguments, t_fmt *params, int *printed)
{
	int	*c;

	c = va_arg(arguments, void *);
	*c = *printed;
}
