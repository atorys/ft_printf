//
// Created by Achiote Tory on 5/16/21.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_flags_modifications_type
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	char type;
}				t_fmt;


int		ft_printf(const char *format, ...);
void	p_char(va_list arguments, t_fmt *params, int *printed);
void	p_int(va_list arguments, t_fmt *params, int *printed);
#endif
