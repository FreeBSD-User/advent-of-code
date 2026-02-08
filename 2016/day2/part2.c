#include <stdio.h>
#include <stdlib.h>

#include "advc_utils.h"
#include "def.h"

void
main_part2()
{
	char buf[BUFSIZ];
	int code[5], numpad[25] = {
		' ', ' ', '1', ' ', ' ',
		' ', '2', '3', '4', ' ',
		'5', '6', '7', '8', '9',
		' ', 'A', 'B', 'C', ' ',
		' ', ' ', 'D', ' ', ' ',
	};
	constexpr int side = 5;
	constexpr int limit = side/2;
	int cur = 0;
	coord point = { .x = -2, .y = 0 };

	while (sgets(buf)) {
		for (char *ptr = buf; *ptr != '\0'; ptr++) {
			if (*ptr == 'U' && abs(point.x) + abs(point.y-1) <= limit)
				point.y--;
			else if (*ptr == 'D' && abs(point.x) + abs(point.y+1) <= limit)
				point.y++;
			else if (*ptr == 'R' && abs(point.x+1) + abs(point.y) <= limit)
				point.x++;
			else if (*ptr == 'L' && abs(point.x-1) + abs(point.y) <= limit)
				point.x--;
		}
		code[cur++] = numpad[(point.y+limit)*side+point.x+limit];
	}

	for (int i = 0; i < 5; i++)
		printf("%c", code[i]);
	printf("\n");
}
