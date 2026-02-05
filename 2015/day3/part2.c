#include <sys/hash.h>
#include <sys/queue.h>

#include <stdio.h>

#include "advc_utils.h"
#include "def.h"

static constexpr int hashsize = 99999989;
static bool hashtbl[hashsize];

void
main_part2()
{
	char *buf = getbuf();
	coord santa = { .x = 0, .y = 0 };
	coord robot = { .x = 0, .y = 0 };
	coord *cur;
	uint32_t hash;
	long visits = 0, i = 0;

	hash = hash32_buf(&cur, sizeof(coord), HASHINIT) % hashsize;
	hashtbl[hash] = true;
	visits++;
	while (*buf != '\0') {
		if (i % 2 == 0)
			cur = &santa;
		else
			cur = &robot;

		switch (*buf) {
		case '>': cur->x += 1; break;
		case '<': cur->x -= 1; break;
		case '^': cur->y += 1; break;
		case 'v': cur->y -= 1; break;
		}

		hash = hash32_buf(cur, sizeof(coord), HASHINIT) % hashsize;
		if (!hashtbl[hash]) {
			hashtbl[hash] = true;
			visits++;
		}

		buf++;
		i++;
	}

	printf("%ld\n", visits);
}
