#include <stdio.h>

#include "advc_utils.h"

void
main_part1()
{
	char *buf = getbuf();
	long x = 0;

	while (*buf != '\0') {
		if (*buf == '(')
			x++;
		else
			x--;
		buf++;
	}

	printf("%ld\n", x);
}
