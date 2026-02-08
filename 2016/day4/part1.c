#include <stdio.h>
#include <string.h>

#include "advc_utils.h"
#include "def.h"

void
main_part1()
{
	char buf[1024], name[1024], cksum[6];
	int sID, hash, acc = 0;

	while (sgets(buf)) {
		sscanf(buf, "%[^0-9] %d[%[a-z]]", name, &sID, cksum);

		struct {
			int n;
			int c;
		} kp[26] = {0}, prev;

		for (int i = 0; i < strlen(name); i++) {
			if (name[i] == '-')
				continue;
			hash = name[i] - 'a';
			if (kp[hash].n == 0)
				kp[hash].c = name[i];
			kp[hash].n++;
		}

		int i;
		prev = kp[cksum[0]-'a'];
		for (i = 1; i < strlen(cksum); i++) {
			hash = cksum[i] - 'a';
			if (kp[hash].n == 0 || kp[hash].n > prev.n ||
			   (kp[hash].n == prev.n && kp[hash].c < prev.c))
				break;
			prev = kp[hash];
		}

		if (i == strlen(cksum))
			acc += sID;
	}
	printf("%d\n", acc);
}
