#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "advc_utils.h"
#include "def.h"

void
main_part2()
{
	MD5_CTX ctx;
	char buf[BUFSIZ], digest[33], decrypted[9] = {0};
	int len, cur = 0;

	sgets(buf);
	len = strlen(buf);

	uint32_t i;
	for (i = 0; i < UINT32_MAX; i++) {
		snprintf(buf+len, BUFSIZ-len, "%d", i);
		MD5Init(&ctx);
		MD5Update(&ctx, buf, strlen(buf));
		MD5End(&ctx, digest);
		if (strncmp(digest, "00000", 5) == 0) {
			int pos = digest[5]-'0';
			if (pos >= 0 && pos < 8 && decrypted[pos] == 0) {
				decrypted[pos] = digest[6];
				cur++;
				if (cur == 8)
					break;
			}
		}
	}
	printf("%s\n", decrypted);
}
