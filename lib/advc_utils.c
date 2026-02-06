#include <sys/stat.h>

#include <err.h>
#include <stdio.h>

#include "advc_utils.h"
#include "alloc.h"

void
dup2in(const char *path)
{
	if (freopen(path, "r", stdin) == nullptr)
		err(1, "Cannot open: %s", path);
}

bool
sgets(char buf[BUFSIZ])
{
	(void)gets_s(buf, BUFSIZ);
	if (ferror(stdin))
		err(1, "Error reading input");
	return (!feof(stdin));
}

char *
getbuf()
{
	char *buf;
	struct stat sb;
	off_t len;

	fflush(stdin);
	if (fstat(0, &sb) != 0)
		err(1, "fstat()");
	len = sb.st_size;

	buf = s_malloc(len + 1);
	(void)fread(buf, 1, len, stdin);

	if (ferror(stdin))
		err(1, "Error reading input");

	if (buf[len-1] == '\n')
		(len)--;
	buf[len] = '\0';

	return (buf);
}
