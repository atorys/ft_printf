#include "ft_printf.h"
#include "libft/libft.h"

void p_char(va_list arguments, t_fmt *params, int *printed)
{
	char	c;
	int		field;

	c = va_arg(arguments, int);
	if (!c)
		return ;
	field = 1;
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
	if (params->width >= field)
	{
		field = params->width;
		if (params->minus)
		{
			ft_putchar_fd(c, 1);
			while (--field > 0)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			if (params->zero)
			{
				while (field-- > 1)
					ft_putchar_fd('0', 1);
				ft_putchar_fd(c, 1);
			}
			else
			{
				while (field-- > 1)
					ft_putchar_fd(' ', 1);
				ft_putchar_fd(c, 1);
			}
		}
	}
}
