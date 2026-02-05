#include <stdio.h>

#include "advc_utils.h"
#include "def.h"

void
main_part2()
{
	char buf[BUFSIZ];
	int t[3];
	int acc = 0;

	while (sgets(buf)) {
		sscanf(buf, "%dx%dx%d", &t[0], &t[1], &t[2]);
		int min = 1000;
		for (int i = 0; i < 3; i++) {
			int r = 2 * (t[i] + t[(i+1)%3]);
			min = (r < min) ? r : min;
		}
		acc += min + t[0]*t[1]*t[2];
	}
	printf("%d\n", acc);
}
