#ifndef ADVC_UTILS_H
#define ADVC_UTILS_H

#include <ctype.h>
#include <stdio.h>

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

#endif
