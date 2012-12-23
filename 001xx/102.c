/* [102] Ecological Bin Packing
 * Straignt forward calculation for all cases
 * ans = sum - max{a_i + b_j + c_k}
 *          perm(i,j,k)
 */

#include <stdio.h>
#include <stdlib.h>

#define NOR(a, b) ((~((a)|(b)))&3)
char table[3] = {'B', 'C', 'G'};

int main(int argc, char *argv[])
{
	int num[9];
	int *a = &num[0];
	int *b = &num[3];
	int *c = &num[6];
	int i, j, k, max, sum;
	char res[4] = {'B', 'C', 'G', 0};
	/* a little reordering to justify the answer */
	while(scanf("%d%d%d%d%d%d%d%d%d",a,a+2,a+1,b,b+2,b+1,c,c+2,c+1)==9) {
		max = 0;
		sum = 0;
		for(i = 0; i < 9; i++) {
			sum += num[i];
		}
		for(i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
				if(i == j)
					continue;
				k = NOR(i, j);
				if(max < a[i] + b[j] + c[k]) {
					max = a[i] + b[j] + c[k];
					res[0] = table[i];
					res[1] = table[j];
					res[2] = table[k];
				} 
			}
		}
		printf("%s %d\n", res, sum - max);
	}
	return 0;
}
