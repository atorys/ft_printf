#include <stdio.h>
#include "ft_printf.h"

int main() {
	int result = 0;
//	int a= -2147483648;
    printf("%-09.4x\n", 648715685);
    result = ft_printf("%-09.4x\n", 648715685);
	printf("\n%d", result);
    return 0;
}


#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//#include "libft.h"

//int main()
//{
//	int		a = -4;
//	int		b = 0;
//	char	c = 'a';
//	int		d = 2147483647;
//	int		e = -2147483648;
//	// int		f = 42;
//	//int		g = 25;
//	//int		h = 4200;
//	int		i = 8;
//	int		j = -12;
//	int		k = 123456789;
//	int		l = 0;
//	int		m = -12345678;
//	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	// char	*s = "-2147483648";
//	// char	*t = "0x12345678";
//	// char	*u = "-0";
//
//	ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
//	printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
//	ft_printf("%2s, %2s, %2s, %2s, %2s\n", n, o, p, q, r);
//	printf("%2s, %2s, %2s, %2s, %2s\n", n, o, p, q, r);
//	ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
//	printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
//	ft_printf("%-*.*u, %-*.*x\n", a, b, i, a, b, i);
//	printf("%-*.*u, %-*.*x\n", a, b, i, a, b, i);
//}