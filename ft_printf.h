#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags_modifications_type
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
}				t_fmt;

int		ft_printf(const char *format, ...);

void	new_params(t_fmt *params);
int		is_type(char format);
int		ft_isdigit(int c);

void	p_char(va_list arguments, t_fmt *params, int *printed);
void	p_int(va_list arguments, t_fmt *params, int *printed);
void	p_unsigned(va_list arguments, t_fmt *params, int *printed);
void	p_hex(va_list arguments, t_fmt *params, int *printed);
void	p_upper_hex(va_list arguments, t_fmt *params, int *printed);
void	p_str(va_list arguments, t_fmt *params, int *printed);
void	p_pointer(va_list arguments, t_fmt *params, int *printed);
void	p_printed(va_list arguments, t_fmt *params, int *printed);

int		print_char(char c, int fd, int mod);
void	print_nbr(long long n, int fd);
int		len(long long c);
int		ft_strlen(const char *s);
int		print_nbr_16(unsigned long n, char *base, int mod);

#endif
