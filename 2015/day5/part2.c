#include <stdio.h>
#include <string.h>

#include "advc_utils.h"
#include "def.h"

void
main_part2()
{
	char buf[BUFSIZ];
	long nice = 0;

	while (sgets(buf)) {
		bool pivot = false, pair = false;
		int i, pairs[2047] = {0}, h;

		for (i = 1; i < strlen(buf)-1; i++) {
			if (buf[i-1] == buf[i+1])
				pivot = true;

			h = char_hash(2, &buf[i-1]);
			if (pairs[h] == 0)
				pairs[h] = i;
			else if (pairs[h] != i-1)
				pair = true;
		}

		h = char_hash(2, &buf[i-1]);
		if (pivot && (pair || pairs[h] != 0 && pairs[h] != i-1))
			nice++;
	}

	printf("%ld\n", nice);
}
