//
// Created by Achiote Tory on 5/16/21.
//

#include "libft/libft.h"
#include "ft_printf.h"

typedef struct s_flags_modifications_type
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	width;
	int	dot;
	int star;
	int	precision;
	int type;
}				t_fmt;

t_fmt	ft_new_params(void)
{
	t_fmt	params;

	params.minus = 0;
	params.plus = 0;
	params.space = 0;
	params.zero = 0;
	params.width = 0;
	params.dot = 0;
	params.star = 0;
	params.precision = 0;
	params.type = 0;
	return (params);
}

int	flags_mods_parsing(t_fmt params, const char *format, va_list arguments)
{
	while (*format == '0' || *format == '*' || *format == '.' ||
		*format == '-' || (*format >= '0' && *format <= '9'))

}

static void	str_parsing(const char *format, va_list arguments, int *printed)
{
	int		status;
	t_fmt	params;

	status = 0;
	while (*format && !status)
	{
		if (*format == '%')
		{
			*format++;
			if (*format == ' ')
			{
				ft_putchar_fd(*format, 1);
				*format++;
				printed++;
			}
			params = ft_new_params();
			status = flags_mods_parsing(params, format, arguments);
		}
		ft_putchar_fd(*format, 1);
		printed++;
	}
}

int ft_printf(const char *format, ...)
{
	int		printed;
	va_list	arguments;

	printed = 0;
	va_start(arguments, format);
	str_parsing(format, arguments, &printed);
	va_end(arguments);
	return (printed);
}
