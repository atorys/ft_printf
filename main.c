#include <stdio.h>
#include "ft_printf.h"

int main() {
	int result = 0;
//	int a= -2147483648;
    printf("%05.3d\n", -12);
    result = ft_printf("%5c", 'A');
	printf("\n%d", result);
    return 0;
}
