#include <stdio.h>
#include "ft_printf.h"

int main() {
	int result = 0;

    result = ft_printf("%0-0-00-4c\n", 'A');
    printf("%-04.1c", 'A');
    return 0;
}
