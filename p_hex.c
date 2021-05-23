#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long n, size_t b_len, char *base, int mod)
{
	if (n < b_len)
		return (ft_putchar_mod(base[n], 1, mod));
	return (ft_putnbr_base(n / b_len, b_len, base, mod) + ft_putchar_mod(base[n % b_len], 1, mod));
}

static void	params_parsing(unsigned long long c, t_fmt *params, int hex_len)
{
	if (params->precision >= 0)
		params->zero = 0;
	if (c == 0 && params->precision == 0)
		params->precision = 0;
	else if (hex_len > params->precision)
		params->precision = hex_len;
	if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width *= -1;
	}
	if (params->precision < 0)
		params->precision = 0;
}

static void	if_minus(unsigned long long c, t_fmt *params, int *printed, int hex_len)
{
	while (params->precision - hex_len > 0)
	{
		ft_putchar_fd('0', 1);
		params->precision--;
		params->width--;
		*printed += 1;
	}
	if (!(c == 0 && params->precision == 0))
	{
		hex_len = ft_putnbr_base(c, 16, "0123456789abcdef", 1);
		*printed += hex_len;
	}
	while (params->width - params->precision > 0)
	{
		ft_putchar_fd(' ', 1);
		params->width--;
		*printed += 1;
	}
}

static void	if_zero(unsigned long long c, t_fmt *params, int *printed, int hex_len)
{
	while (params->width - hex_len > 0)
	{
		ft_putchar_fd('0', 1);
		params->width--;
		*printed += 1;
	}
	hex_len = ft_putnbr_base(c, 16, "0123456789abcdef", 1);
	*printed += hex_len;
}

static void	if_not_zero(unsigned long long c, t_fmt *params, int *printed, int hex_len)
{
	if (params->width < params->precision)
		params->width = params->precision;
	while (params->width - params->precision > 0)
	{
		ft_putchar_fd(' ', 1);
		params->width--;
		*printed += 1;
	}
	while (params->precision - hex_len > 0)
	{
		ft_putchar_fd('0', 1);
		params->precision--;
		*printed += 1;
	}
	if (!(c == 0 && params->precision == 0))
	{
		hex_len = ft_putnbr_base(c, 16, "0123456789abcdef", 1);
		*printed += hex_len;
	}
}

void	p_hex(va_list arguments, t_fmt *params, int *printed)
{
	unsigned long long	c;
	int 			hex_len;

	c = va_arg(arguments, unsigned long long);
	hex_len = ft_putnbr_base(c, 16, "0123456789abcdef", 0);
	params_parsing(c, params, hex_len);
	if (params->minus)
		if_minus(c, params, printed, hex_len);
	else
	{
		if (params->zero)
			if_zero(c, params, printed, hex_len);
		else
			if_not_zero(c, params, printed, hex_len);
	}
}
