#ifndef DEF_H
#define DEF_H

typedef struct coord coord;

void main_part1(void);
void main_part2(void);

struct coord
{
	int x;
	int y;
};

#ifndef min
#define min(x, y) ((y) < (x) ? (y) : (x))
#endif
#ifndef max
#define max(x, y) ((y) > (x) ? (y) : (x))
#endif


#endif
