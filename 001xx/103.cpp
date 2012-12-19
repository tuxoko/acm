/*
 * acm 103 Stacking Boxes
 * idea:
 *   1. sort dimension
 *   2. sort according to a certain dim (each will do)
 *   now the boxes are topologically sorted (why? can you prove it? :)
 *   3. DP ( len[i]=max{ len[j]+1 | j>i } )
 *
 *   Time complexity = kn log n + k*k*n
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

struct box {
	int dim[11];
	int len;
	int next;
};

struct box boxes[31];

bool boxcmp(int a, int b)
{
	return boxes[a].dim[0] < boxes[b].dim[0];
}

int main(int argc, char *argv[])
{
	int n, d;
	int i, j, m;
	int tag[31];
	int maxl, head, jump;
	while (scanf("%d%d",&n,&d) == 2) {
		for (i=0; i < n; i++) {
			for (j=0; j < d; j++) {
				scanf("%d", &boxes[i].dim[j]);
			}
			boxes[i].len = 1;
			boxes[i].next = -1;
			tag[i] = i;
			sort(boxes[i].dim, boxes[i].dim + d);
		}
		sort(tag, tag + n, boxcmp);
		maxl = 1;
		head = n - 1;
		for (i = n - 2; i >= 0; i--) {
			jump = -1;
			for (j = i + 1; j < n; j++) {
				if(jump == j) {
					jump = boxes[tag[j]].next;
					continue;
				}
				for(m = 0; m < d; m++) {
					if(boxes[tag[j]].dim[m] <= boxes[tag[i]].dim[m])
						break;
					if(m == d-1) {
						if(boxes[tag[i]].len < boxes[tag[j]].len + 1) {
							boxes[tag[i]].len = boxes[tag[j]].len + 1;
							boxes[tag[i]].next = j;
							jump = boxes[tag[j]].next;
							if(boxes[tag[i]].len > maxl) {
								maxl = boxes[tag[i]].len;
								head = i;
							}
						}
					}
				}
				if(boxes[tag[i]].len >= n - i)
					break;
			}
		}
		printf("%d\n%d", maxl--, tag[head] + 1);
		for(i = boxes[tag[head]].next; maxl > 0; i = boxes[tag[i]].next, maxl--) {
			printf(" %d", tag[i] + 1);
		}
		printf("\n");
	}
	return 0;
}
