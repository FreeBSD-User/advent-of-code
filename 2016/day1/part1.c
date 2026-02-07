#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "advc_utils.h"
#include "def.h"


void
main_part1()
{
	char *bufptr = getbuf(), *endptr;;
	coord point = { .x = 0, .y = 0 };
	int dir = 0;

	while (*bufptr != '\0') {
		if (*bufptr == ' ' || *bufptr == ',') {
			bufptr++;
			continue;
		}

		if (*bufptr == 'R')
			dir++;
		else if (*bufptr == 'L')
			dir+=3;
		else
			exit(1);

		bufptr++;
		int n = strtol(bufptr, &endptr, 10);
		switch (dir%4) {
		case 0: point.y += n; break;
		case 1: point.x += n; break;
		case 2: point.y -= n; break;
		case 3: point.x -= n; break;
		}
		bufptr = endptr;
	}

	printf("%d\n", abs(point.x) + abs(point.y));
}
