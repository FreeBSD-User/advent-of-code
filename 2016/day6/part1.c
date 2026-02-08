#include <assert.h>
#include <stdio.h>

#include "advc_utils.h"
#include "def.h"

void
main_part1()
{
	char buf[BUFSIZ];
	constexpr int len = 8;
	int rep[len][26] = {0}, ecc[len] = {0};

	while (sgets(buf)) {
		assert(strlen(buf) == len);
		for (int i = 0; i < len; i++)
			rep[i][buf[i]-'a']++;
	}

	for (int i = 0; i < len; i++)
		for (int j = 0; j < 26; j++)
			ecc[i] = (rep[i][j] > rep[i][ecc[i]]) ? j : ecc[i];

	for (int i = 0; i < len; i++)
		printf("%c", ecc[i] + 'a');
	printf("\n");
}
