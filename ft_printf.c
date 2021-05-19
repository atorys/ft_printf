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
	int star;
	int	precision;
	char type;
}				t_fmt;

void	ft_new_params(t_fmt *params)
{
	params->minus = 0;
	params->zero = 0;
	params->width = 0;
	params->dot = 0;
	params->star = 0;
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


int	flags_mods_parsing(t_fmt *params, char **format, va_list arguments)
{
	int		printed;

	printed = 0;
	while (**format != '\0' && (**format == '0' || **format == '*' || **format == '.' ||
		**format == '-' || ft_isdigit(**format)))
	{
		if (**format == '-')
		{
			params->minus = 1;
			params->zero = 0;
		}
		else if (**format == '0' && !params->width && !params->minus)
			params->zero = 1;
		else if (**format == '*' && !params->width)
		{
			params->star = 1;
			params->width = va_arg(arguments, int);
		}
		else if (**format == '.' && !params->dot)
		{
			if (!(**format))
				return (-1);
			params->dot = 1;
			while (ft_isdigit(**format))
			{
				params->precision = params->precision * 10 + (**format + 48);
				*format++;
			}
			if (**format == '*')
				params->precision = va_arg(arguments, int);
		}
		*format++;
	}
	if (is_type(**format))
		params->type = **format;
	else if (**format == '%')
	{
		ft_putchar_fd('%', 1);
		printed++;
	}
	return (printed);
}

static void	str_parsing(char *format, va_list arguments, int *printed)
{
	t_fmt	params;
	int 	check;

	format[ft_strlen(format)] = 0;
	while (*format)
	{
		if (*format == '%')
		{
			*format++;
			if (*format == ' ')
			{
				ft_putchar_fd(*format, 1);
				printed++;
			}
			ft_new_params(&params);
			check = flags_mods_parsing(&params, &format, arguments);
			if (check == -1)
			{
				*printed = check;
				return ;
			}
			*printed = *printed + check;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			*printed = *printed + 1;
			*format++;
		}
	}
}

/******************************************************************************\
 * MAIN PART // @param format // @param ... // @return                         *
\******************************************************************************/
int ft_printf(const char *format, ...)
{
	int		printed;
	char 	*copy;
	va_list	arguments;

	printed = 0;
//	copy = (char *)format;
	va_start(arguments, format);
	str_parsing((char *)format, arguments, &printed);
	va_end(arguments);
	return (printed);
}
