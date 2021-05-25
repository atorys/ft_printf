#include "ft_printf.h"

static void	print(va_list arguments, t_fmt *params, int *printed)
{
	char	t;

	t = params->type;
	if (t == 'c' || t == '%')
		p_char(arguments, params, printed);
	else if (t == 's')
		p_str(arguments, params, printed);
	else if (t == 'd' || t == 'i')
		p_int(arguments, params, printed);
	else if (t == 'p')
		p_pointer(arguments, params, printed);
	else if (t == 'u')
		p_unsigned(arguments, params, printed);
	else if (t == 'x')
		p_hex(arguments, params, printed);
	else if (t == 'X')
		p_upper_hex(arguments, params, printed);
//	else if (t == 'n')
//		p_printed(arguments, params, printed);
}

static int	find_flags(t_fmt *params, char *format)
{
	int	i;

	i = 0;
	while (format[i] && (format[i] == '0' || format[i] == '-' || \
	format[i] == '+' || format[i] == ' ' || format[i] == '#')) /** todo: do */
	{
		if (format[i] == '-')
		{
			params->minus = 1;
			params->zero = 0;
		}
		else if (format[i] == '0' && !params->width && !params->minus)
			params->zero = 1;
		else if (format[i] == '#')
			params->sharp = 2;
		i++;
	}
	return (i);
}

static int	find_mods(t_fmt *params, char *format, va_list arguments)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[i]))
	{
		params->width = 0;
		while (ft_isdigit(format[i]))
			params->width = params->width * 10 + (format[i++] - 48);
	}
	while (format[i] == '*' && ++i)
		params->width = va_arg(arguments, int);
	if (format[i] == '.')
	{
		params->precision = 0;
		while (ft_isdigit(format[++i]))
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
			new_params(&params);
			format++;
			while (*format && !is_type(*format))
			{
				format += find_flags(&params, format);
				format += find_mods(&params, format, arguments);
			}
			if (!is_type(*format))
				return ;
			params.type = *format++;
			print(arguments, &params, printed);
			continue ;
		}
		*printed += print_char(*format++, 1, 1);
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
