#include <stdio.h>
#include "ft_printf.h"

int main() {
	int result = 0;

    result = ft_printf("%-10d");
    printf("\n%10s", "abc");
    return 0;
}
