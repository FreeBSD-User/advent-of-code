#include <md5.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "advc_utils.h"
#include "def.h"

void
main_part1()
{
	MD5_CTX ctx;
	char buf[BUFSIZ], digest[33], decrypted[9] = {0};
	int len, cur = 0;

	sgets(buf);
	len = strlen(buf);

	uint32_t i;
	for (i = 0; i < UINT32_MAX; i++) {
		snprintf(buf+len, BUFSIZ-len, "%d", i);
		md5_digest(buf, digest);
		if (strncmp(digest, "00000", 5) == 0) {
			decrypted[cur++] = digest[5];
			if (cur == 8)
				break;
		}
	}
	printf("%s\n", decrypted);
}
