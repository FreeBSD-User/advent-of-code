#include <stdio.h>

#include "advc_utils.h"

void
main_part2()
{
	char *buf = getbuf();
	size_t i = 0;
	long x = 0;

	while (*buf != '\0') {
		i++;
		if (*buf == '(')
			x++;
		else
			x--;
		if (x == -1)
			break;
		buf++;
	}

	printf("%ld\n", i);
}
