#include <stdio.h>
#include <stdlib.h>

#include "advc_utils.h"
#include "def.h"

void
main_part1()
{
	char buf[BUFSIZ];
	int t[3], count = 0;

	while (sgets(buf)) {
		sscanf(buf, "%d%d%d", &t[0], &t[1], &t[2]);
		int i;
		for (i = 0; i < 3; i++)
			if (t[i] + t[(i+1)%3] <= t[(i+2)%3])
				break;
		if (i == 3)
			count++;
	}
	printf("%d\n", count);
}
