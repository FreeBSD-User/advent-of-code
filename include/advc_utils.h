#ifndef ADVC_UTILS_H
#define ADVC_UTILS_H

#include <ctype.h>
#include <md5.h>
#include <stdio.h>
#include <string.h>

void dup2in(const char *);
bool sgets(char buf[BUFSIZ]);
char *getbuf(void);

static inline unsigned
char_hash(int count, const char *chars)
{
	unsigned r = 0;
	const unsigned char *p = (const unsigned char *)chars;
	while (count-- > 0)
		r |= (tolower(*p++) - 'a') << (5*count);
	return (r);
}

static inline void
md5_digest(const char *buf, char digest[33])
{
	MD5_CTX ctx;
	MD5Init(&ctx);
	MD5Update(&ctx, buf, strlen(buf));
	MD5End(&ctx, digest);
}

#endif
