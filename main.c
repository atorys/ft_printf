#include <stdio.h>
#include "ft_printf.h"

int main() {
//	int result = 0;
////	int a= -2147483648;
//    printf("%-09.4x\n", 648715685);
//    result = ft_printf("%.21%");
//	printf("\n%d", result);
//    return 0;


#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)

//		int		a = -4;
//		int		b = 0;
//		char	c = 'a';
//		int		d = 2147483647;
//		int		e = -2147483648;
//		int		f = 42;
//		int		g = 25;
//		int		h = 4200;
//		int		i = 8;
//		int		j = -12;
//		int		k = 123456789;
//		int		l = 0;
//		int		m = -12345678;
//		char	*n = "abcdefghijklmnop";
//		char	*o = "-a";
//		char	*p = "-12";
//		char	*q = "0";
//		char	*r = "%%";
//		char	*s = "-2147483648";
//		char	*t = "0x12345678";
//		char	*u = "-0";

//		a = f;
//		b = g;
//		printf("1]%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
//		ft_printf("1]%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
//		printf("\e[48;2;%i;%i;%imbiba boba\e[m\n", 200, 90, 0, "world");
//		ft_printf("hjjtrtttt%n\n", &a);
//		printf("%d\n", a);
//		ft_printf("%3.7s%7.7s\n", "hello", "world");
//		printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
//		printf("hjjtrtttt%n\n", &a);
//		printf("%d", a);
//		ft_printf("{%*-.1s}\n", 21, "abcdefg");
		printf("{%0*.*x}\n", 1, 0, 8);
		ft_printf("{%0*.*x}\n", 1, 0, 8);

//8, 8, 8, 4294967284, fffffff4, FFFFFFF4, 123456789, 75bcd15, 75BCD15, 0, 0, 0, 4282621618, ff439eb2, FF439EB2, 97, 61, 61, 2147483647, 7fffffff, 7FFFFFFF, 2147483648, 80000000, 80000000 --- Return : 185
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