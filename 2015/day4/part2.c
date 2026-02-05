#include <md5.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "advc_utils.h"
#include "def.h"

void
main_part2()
{
	MD5_CTX ctx;
	char buf[BUFSIZ], digest[33];
	int len;

	sgets(buf);
	len = strlen(buf);

	uint32_t i;
	for (i = 0; i < UINT32_MAX; i++) {
		snprintf(buf+len, BUFSIZ-len, "%d", i);
		MD5Init(&ctx);
		MD5Update(&ctx, buf, strlen(buf));
		MD5End(&ctx, digest);
		if (strncmp(digest, "000000", 6) == 0)
			break;
	}
	printf("%d\n", i);
}
