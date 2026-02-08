#include <stdio.h>
#include <string.h>

#include "advc_utils.h"
#include "def.h"

constexpr char alpha[] = "abcdefghijklmnopqrstuvwxyz";
constexpr char storage[] = "northpole object storage";

static inline void
print_decrypt(int sID, const char *buf)
{
	char bufcp[BUFSIZ];
	for (int i = 0; i < strlen(buf); i++)
		if (buf[i] == '-')
			bufcp[i] = ' ';
		else
			bufcp[i] = alpha[(buf[i]-'a'+sID)%26];
	if (strncmp(bufcp, storage, sizeof(storage)-1) == 0)
		printf("%d\n", sID);
}

void
main_part2()
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
			print_decrypt(sID, name);
	}
}
