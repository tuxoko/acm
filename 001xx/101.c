/* [101] The Blocks Problem
 *
 * Straight forward simulation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pos_struct {
	int first;
	int end;
};

struct block_struct {
	int pos;
	int next;
	int prev;
};

struct block_struct blocks[25];
struct pos_struct pos[25];

void reset_blocks_on(int a)
{
	int p, t;
	for (t = p = blocks[a].next; p != -1; p = t) {
		t = blocks[p].next;

		blocks[p].pos = p;
		blocks[p].next = -1;
		blocks[p].prev = pos[p].end;
		if (pos[p].end >= 0)
			blocks[pos[p].end].next = p;
		else
			pos[p].first = p;
		pos[p].end = p;
	}
	blocks[a].next = -1;
	pos[blocks[a].pos].end = a;
}

void pile_over(int a, int b)
{
	int p, end;
	b = pos[blocks[b].pos].end;
	end = pos[blocks[a].pos].end;

	if (blocks[a].prev >= 0)
		blocks[blocks[a].prev].next = -1;
	else
		pos[blocks[a].pos].first = -1;
	pos[blocks[a].pos].end = blocks[a].prev;

	pos[blocks[b].pos].end = end;
	blocks[b].next = a;
	blocks[a].prev = b;

	for (p = a; p != -1; p = blocks[p].next)
		blocks[p].pos = blocks[b].pos;
}

int main(int argc, char *argv[])
{
	int i, j, a, b, n;
	char cmd1[8], cmd2[8];

	j = scanf("%d", &n);

	for (i = 0; i < n; i++) {
		blocks[i].pos = i;
		blocks[i].next = -1;
		blocks[i].prev = -1;
		pos[i].first = i;
		pos[i].end = i;
	}

	while (scanf("%s", cmd1) == 1) {
		if (cmd1[0] == 'q')
			break;
		j = scanf("%d%s%d", &a, cmd2, &b);
		if (a == b || blocks[a].pos == blocks[b].pos)
			continue;
		/* move */
		if (cmd1[0] == 'm')
			reset_blocks_on(a);
		/* onto */
		if (cmd2[1] == 'n')
			reset_blocks_on(b);

		pile_over(a, b);
	}

	for (i = 0; i < n; i++) {
		printf("%d:", i);
		for (j = pos[i].first; j != -1; j = blocks[j].next)
			printf(" %d", j);
		printf("\n");
	}
	return 0;
}
