/**

All submissions for this problem are available.

Let's consider a triangle of numbers in which a number appears in the first line, two numbers appear in the second line, three in the third line, etc. Develop a program which will compute the largest of the sums of numbers that appear on the paths starting from the top towards the base, so that:

    on each path the next number is located on the row below, more precisely either directly below or below and one place to the right;
    the number of rows is strictly positive, but less than 100
    all numbers are positive integers between O and 99.

Input

In the first line integer n - the number of test cases (equal to about 1000).
Then n test cases follow. Each test case starts with the number of lines which is followed by their content.
Output

For each test case write the determined value in a separate line.
Example

Input:
2
3
1
2 1
1 2 3
4 
1 
1 2 
4 1 2
2 3 1 1 

Output:
5
9

**/

#include <stdio.h>
#include <stdlib.h>

int bigsum(int **, int, int, int, int);

//unsigned int currentsum = 0, totalsum = 0;

int main(void) {
	int t, **arr, trilen, x, y, z;
	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		scanf("%d", &trilen);
		arr = (int **) malloc (trilen * sizeof(int **));
		for(y = 0; y < trilen; y++) {
			arr[y] = (int *) malloc ((y + 1) * sizeof(int *));
		}
		for(y = 0; y < trilen; y++) {
			for(z = 0; z <= y; z++) {
				scanf("%d", &arr[y][z]);
			}
		}
		
		//bigsum(arr, 0, 0, trilen);
		printf("%u\n", bigsum(arr, 0, 0, trilen, 0));
		for(y = 0; y < trilen; y++) {
			free(arr[y]);
		}
		free(arr);
		//totalsum = currentsum = 0;
	}
	return 0;
}

/*void bigsum(int **arr, int x, int y, int trilen) {
	if(x < trilen) {
		currentsum += arr[x][y];
		bigsum(arr, x + 1, y, trilen);
		bigsum(arr, x + 1, y + 1, trilen);
		currentsum -= arr[x][y];
	} else {
		if(totalsum < currentsum) {
			totalsum = currentsum;
		}
	}
}*/

int bigsum(int **arr, int x, int y, int trilen, int colindex) {
	if(x < trilen) {
		int leftsum = 0, rightsum = 0;
		if((y != colindex) || (y == 0)) {
			leftsum = bigsum(arr, x + 1, y, trilen, y);
		} else {
			return arr[x][y];
		}
		rightsum = bigsum(arr, x + 1, y + 1, trilen, y);
		if(leftsum > rightsum) {
			arr[x][y] += leftsum;
		} else {
			arr[x][y] += rightsum;
		}
		return arr[x][y];
	} else {
		return 0;
	}
}
