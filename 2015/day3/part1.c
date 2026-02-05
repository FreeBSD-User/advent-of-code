#include <sys/hash.h>
#include <sys/queue.h>

#include <stdio.h>

#include "advc_utils.h"
#include "def.h"

static constexpr int hashsize = 999983;
static bool hashtbl[hashsize];

void
main_part1()
{
	char *buf = getbuf();
	coord cur = { .x = 0, .y = 0 };
	uint32_t hash;
	long visits = 0;

	hash = hash32_buf(&cur, sizeof(coord), HASHINIT) % hashsize;
	hashtbl[hash] = true;
	visits++;
	while (*buf != '\0') {
		switch (*buf) {
		case '>': cur.x += 1; break;
		case '<': cur.x -= 1; break;
		case '^': cur.y += 1; break;
		case 'v': cur.y -= 1; break;
		}

		hash = hash32_buf(&cur, sizeof(coord), HASHINIT) % hashsize;
		if (!hashtbl[hash]) {
			hashtbl[hash] = true;
			visits++;
		}

		buf++;
	}

	printf("%ld\n", visits);
}
