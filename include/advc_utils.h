#ifndef ADVC_UTILS_H
#define ADVC_UTILS_H

#include <stdio.h>

void dup2in(const char *);
bool sgets(char buf[BUFSIZ]);
char *getbuf(void);

#endif
