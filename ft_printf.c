//
// Created by Achiote Tory on 5/16/21.
//

#include "libft/libft.h"
#include "ft_printf.h"

/******************************************************************************\
 * TOOLS
 ******************************************************************************/
typedef struct s_flags_modifications_type
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	precision;
	char type;
}				t_fmt;

void	new_params(t_fmt *params)
{
	params->minus = 0;
	params->zero = 0;
	params->width = 0;
	params->dot = 0;
	params->precision = 0;
	params->type = 0;

}

int	is_type(char format)
{
	if (format == 'd' || format == 'i' || format == 's' || format == 'c' ||
		format == 'p' || format == 'u' || format == 'x' || format == 'X')
		return (1);
	return (0);
}
/******************************************************************************\
 * FORMAT STRING PARSING
 * @param params
 * @param format
 * @param arguments
 * @return
 ******************************************************************************/

static void	find_flags(t_fmt *params, char **format)
{
	while (**format && (**format == '0' || **format == '-'))
	{
		if (**format == '-')
		{
			params->minus = 1;
			params->zero = 0;
		}
		if (**format == '0' && !params->width && !params->minus)
			params->zero = 1;
		*format++;
	}
}

static void	find_mods(t_fmt *params, char **format, va_list arguments)
{
	while (**format && (**format == '*' || **format == '.' ||
			ft_isdigit(**format)))
	{
		if (**format == '*' && !params->width)
			params->width = va_arg(arguments, int);
		if (ft_isdigit(**format) && !params->width)
		{
			while (ft_isdigit(**format))
			{
				params->width = params->width * 10 + (**format - 48);
				*format++;
			}
		}
		if (**format == '.' && !params->dot)
		{
			*format++;
			params->dot = 1;
			while (ft_isdigit(**format))
			{
				params->precision = params->precision * 10 + (**format - 48);
				*format++;
			}
			if (**format == '*')
				params->precision = va_arg(arguments, int);
		}
	}
}

static void print(va_list arguments, t_fmt *params, int *printed)
{

}

static void	str_parsing(char *format, va_list arguments, int *printed)
{
	t_fmt	params;

	while (*format) /** todo: add index */
	{
		if (*format == '%' && ++(*format)!= '%')
		{
			new_params(&params);
			find_flags(&params, &format);
			find_mods(&params, &format, arguments);
			if (is_type(*format))
				params.type = *format++;
			print(arguments, &params, printed);
			continue ;
		}
		ft_putchar_fd(*format, 1);
		*printed = *printed + 1;
		format++;
	}
}

/******************************************************************************\
 * MAIN PART // @param format // @param ... // @return                         *
\******************************************************************************/
int ft_printf(const char *format, ...)
{
	int		printed;
	va_list	arguments;

	printed = 0;
	va_start(arguments, format);
	str_parsing((char *)format, arguments, &printed);
	va_end(arguments);
	return (printed);
}
