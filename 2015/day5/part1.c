#include <stdio.h>
#include <string.h>

#include "advc_utils.h"
#include "def.h"

void
main_part1()
{
	char buf[BUFSIZ];
	long nice = 0;

	while (sgets(buf)) {
		bool naugthy = false, rep = false;
		int vowels = 0;

		if (buf[0] == 'a' || buf[0] == 'e' || buf[0] == 'i' ||
		    buf[0] == 'o' || buf[0] == 'u')
			vowels++;
		for (int i = 1; i < strlen(buf); i++) {
			if (buf[i] == 'b' && buf[i-1] == 'a') {
				naugthy = true;
				break;
			} else if (buf[i] == 'd' && buf[i-1] == 'c') {
				naugthy = true;
				break;
			} else if (buf[i] == 'q' && buf[i-1] == 'p') {
				naugthy = true;
				break;
			} else if (buf[i] == 'y' && buf[i-1] == 'x') {
				naugthy = true;
				break;
			} else if (buf[i] == 'a' || buf[i] == 'e' ||
			    buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u')
				vowels++;
			if (buf[i-1] == buf[i])
				rep = true;
		}
		if (!naugthy && vowels >= 3 && rep)
			nice++;
	}

	printf("%ld\n", nice);
}
