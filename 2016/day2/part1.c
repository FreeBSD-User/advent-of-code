#include <stdio.h>

#include "advc_utils.h"
#include "def.h"

void
main_part1()
{
	char buf[BUFSIZ];
	coord point = { .x = 1, .y = 1 };
	int code[5], numpad[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int cur = 0;

	while (sgets(buf)) {
		for (char *ptr = buf; *ptr != '\0'; ptr++) {
			if (*ptr == 'U' && point.y > 0)
				point.y--;
			else if (*ptr == 'D' && point.y < 2)
				point.y++;
			else if (*ptr == 'R' && point.x < 2)
				point.x++;
			else if (*ptr == 'L' && point.x > 0)
				point.x--;
		}
		code[cur++] = numpad[point.y*3+point.x];
	}

	for (int i = 0; i < cur; i++)
		printf("%d", code[i]);
	printf("\n");
}
