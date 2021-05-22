//
// Created by Achiote Tory on 5/16/21.
//

#include "ft_printf.h"

static void	print(va_list arguments, t_fmt *params, int *printed)
{
	char	t;

	t = params->type;
	if (t == 'c')
		p_char(arguments, params, printed);
//	else if (t == 's')
//		;
	else if (t == 'd' || t == 'i')
		p_int(arguments, params, printed);
//	else if (t == 'p')
//		;
//	else if (t == 'u')
//		;
//	else if (t == 'x')
//		;
//	else if (t == 'X')
//		;
//	else if (t == '%')
//		;
}

static int	find_flags(t_fmt *params, char *format)
{
	int	i;

	i = 0;
	while (format[i] && (format[i] == '0' || format[i] == '-'))
	{
		if (format[i] == '-')
		{
			params->minus = 1;
			params->zero = 0;
		}
		if (format[i] == '0' && !params->width && !params->minus)
			params->zero = 1;
		i++;
	}
	return (i);
}

static int	find_mods(t_fmt *params, char *format, va_list arguments)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]))
		params->width = params->width * 10 + (format[i++] - 48);
	if (format[i] == '*' && !params->width)
	{
		params->width = va_arg(arguments, int);
		i++;
	}
	if (format[i] == '.')
	{
		params->precision = 0;
		while (ft_isdigit(format[++i])) /** todo: проверка не пролетает ли значение с .* */
			params->precision = params->precision * 10 + (format[i] - 48);
		if (format[i] == '*' && !params->precision)
		{
			params->precision = va_arg(arguments, int);
			i++;
		}
	}
	return (i);
}

static void	str_parsing(char *format, va_list arguments, int *printed)
{
	t_fmt	params;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			new_params(&params);
			format += find_flags(&params, format);
			format += find_mods(&params, format, arguments);
			if (!is_type(*format))
			{
				*printed = -1;
				return ;
			}
			params.type = *format++;
			print(arguments, &params, printed);
			continue ;
		}
		write(1, &(*format), 1);
		*printed = *printed + 1;
		format++;
	}
}

/******************************************************************************\
 * MAIN PART // @param format // @param ... // @return                         *
\******************************************************************************/

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	arguments;

	printed = 0;
	va_start(arguments, format);
	str_parsing((char *)format, arguments, &printed);
	va_end(arguments);
	return (printed);
}
