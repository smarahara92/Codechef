/**
The chef has just finished baking several pies, and it's time to place them on cooling racks.
The chef has exactly as many cooling racks as pies. Each cooling rack can only hold one pie, and each pie may only be held by one cooling rack,
but the chef isn't confident that the cooling racks can support the weight of the pies.
The chef knows the weight of each pie,
and has assigned each cooling rack a maximum weight limit.
What is the maximum number of pies the chef can cool on the racks?
Input:

Input begins with an integer T≤30, the number of test cases.
Each test case consists of 3 lines.
The first line of each test case contains a positive integer N≤30,
the number of pies (and also the number of racks).
The second and third lines each contain exactly positive N integers not exceeding 100.
The integers on the second line are the weights of the pies, and the integers on the third line
are the weight limits of the cooling racks.
Output:

For each test case, output on a line the maximum number of pies the chef can place on the racks.
Sample input:

2
3
10 30 20
30 10 20
5
9 7 16 4 8
8 3 14 10 10
 

Sample output:

3
4

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int t, x, *pies = NULL, *trays = NULL, n, z, count = 0, y, w;
	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		scanf("%d", &n);
		pies = (int *) malloc (n * sizeof(int *));
		trays = (int *) malloc (n * sizeof(int *));
		for(y = 0; y < n; y++) {
			scanf("%d", &pies[y]);
		}
		for(y = 0; y < n; y++) {
			scanf("%d", &trays[y]);
		}
		for(y = 0; y < (n - 1); y++) {
			for(z = y + 1; z < n; z++) {
				if(pies[y] > pies[z]) {
					w = pies[y];
					pies[y] = pies[z];
					pies[z] = w;
				}
				if(trays[y] > trays[z]) {
					w = trays[y];
					trays[y] = trays[z];
					trays[z] = w;
				}
			}
		}
		count = 0;
		for(y = 0, z = 0; (y < n) && (z < n); z++) {
			if(pies[y] <= trays[z]) {
				count += 1;
				y += 1;
			}
		}
		printf("%d\n", count);
		free(pies);
		free(trays);
	}
	return 0;
}
