#include "ft_printf.h"

void	p_nvalues(va_list arguments, int *printed)
{
	int	*c;

	c = va_arg(arguments, void *);
	*c = *printed;
}
