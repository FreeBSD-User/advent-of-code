#include <stdio.h>

#include "advc_utils.h"
#include "def.h"

int
main(int argc, char *argv[])
{
	if (argc > 1)
		dup2in(argv[1]);

	main_part1();
	// fseek(stdin, 0, SEEK_SET);
	// main_part2();

	return (0);
}
