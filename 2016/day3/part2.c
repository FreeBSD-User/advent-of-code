#include <stdio.h>
#include <stdlib.h>

#include "advc_utils.h"
#include "alloc.h"
#include "def.h"

void
main_part2()
{
	char buf[BUFSIZ];
	int t[2048][3], count = 0, cur = 0;

	while (sgets(buf)) {
		sscanf(buf, "%d%d%d", &t[cur][0], &t[cur][1], &t[cur][2]);
		cur++;
		if (cur % 3 == 0) {
			for (int j = 0; j < 3; j++) {
				int i, off = cur-3;
				for (i = 0; i < 3; i++)
					if (t[i+off][j] + t[(i+1)%3+off][j] <= t[(i+2)%3+off][j])
						break;
				if (i == 3)
					count++;
			}
		}
	}
	printf("%d\n", count);
}
