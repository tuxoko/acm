/* [100] The 3n + 1 problem
 *
 * This problem is solvable using straight forward method.
 * However, in order to speed up the program, I use some tricks:
 * The first one is using a table to store calculated LENGTH to prevent
 * recalculations.
 * The second one is dividing all possible input into regions,
 * and precaculate the max LENGTHs of the regions. So when input i, j
 * are across multiple regions, the program can lookup quickly.
 */

#include <stdio.h>
#include <stdlib.h>

#define TABLE_LEN 6000000
unsigned int table[TABLE_LEN] = {};

#define INPUT_MAX 1000000
#define PRECALC_WIDTH 256
#define PRECALC_MASK (PRECALC_WIDTH - 1)
#define PRETABLE_LEN (INPUT_MAX/PRECALC_WIDTH + 1)
unsigned int pretable[PRETABLE_LEN];

unsigned int stack[550];

unsigned int calc(unsigned int k)
{
	unsigned int ret, sn = 0;
	if (k < TABLE_LEN && table[k])
		return table[k];
	while (k != 1) {
		stack[sn++] = k;
		if (k & 1)
			k = 3*k + 1;
		else
			k /= 2;
		if (k < TABLE_LEN && table[k])
			break;
	}
	ret = table[k];
	for (;sn !=0; sn--) {
		ret++;
		k = stack[sn - 1];
		if(k < TABLE_LEN)
			table[k] = ret;
	}
	return ret;
}

void precalc()
{
	unsigned int i,j,k,n;
	table[1] = 1;
	for(i = 2; i < INPUT_MAX; i++)
		calc(i);
	for(i = 0, j = 0; i < PRETABLE_LEN; i++, j+=PRECALC_WIDTH)
	{
		n = 0;
		for(k = 0; k < PRECALC_WIDTH; k++) {
			if(j + k >= INPUT_MAX)
				break;
			if(n < table[j+k])
				n = table[j+k];
		}
		pretable[i] = n;
	}
}

int main(int argc, char *argv[])
{
	unsigned int i,j,oi,oj,n,t;
	unsigned int a,b;
	precalc();
	while(scanf("%d%d", &i, &j) == 2) {
		oi = i;
		oj = j;
		if(i > j) {
			t = i;
			i = j;
			j = t;
		}
		n = 0;

		a = i/PRECALC_WIDTH;
		b = j/PRECALC_WIDTH;
		if(a == b) {
			if((i & PRECALC_MASK) == 0 && ((j & PRECALC_MASK) == PRECALC_MASK || j == (INPUT_MAX - 1)))
				n = pretable[a];
			else {
				for(t = i; t <= j; t++) {
					if(n < table[t])
						n = table[t];
				}
			}
		} else {
			if((i & PRECALC_MASK) == 0)
				n = pretable[a];
			else {
				for(t = i; t < (a + 1)*PRECALC_WIDTH; t++) {
					if(n < table[t])
						n = table[t];
				}
			}
			if((j & PRECALC_MASK) == PRECALC_MASK || j == (INPUT_MAX - 1)) {
				if(n < pretable[b])
						n = pretable[b];
			} else {
				for(t = b*PRECALC_WIDTH; t <= j; t++) {
					if(n < table[t])
						n = table[t];
				}
			}
		}
		for(t = a + 1; t < b; t++) {
			if(n < pretable[t])
				n = pretable[t];
		}
		printf("%d %d %d\n", oi, oj, n);
	}
	return 0;
}
