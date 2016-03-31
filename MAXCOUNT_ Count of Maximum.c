/**
Given an array A of length N, your task is to find the element which repeats in A maximum number of times as well as the corresponding count. In case of ties, choose the smaller element first.
Input

First line of input contains an integer T, denoting the number of test cases. Then follows description of T cases. Each case begins with a single integer N, the length of A. Then follow N space separated integers in next line. Assume that 1 <= T <= 100, 1 <= N <= 100 and for all i in [1..N] : 1 <= A[i] <= 10000
Output

For each test case, output two space separated integers V & C. V is the value which occurs maximum number of times and C is its count.
Example

Input:
2
5
1 2 3 2 5
6
1 2 2 1 1 2

Output:
2 2
1 3

Description:
In first case 2 occurs twice whereas all other elements occur only once. 
In second case, both 1 and 2 occur 3 times but 1 is smaller than 2.

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int t, n, *A, x, y, freqchar, num, frequency;
	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		scanf("%d", &n);
		A = (int *) calloc (10000, sizeof(int *));
		num = 10000, frequency = -1;
		for(y = 0; y < n; y++) {
			scanf("%d", &freqchar);
			A[freqchar - 1] += 1;
			if(frequency < A[freqchar - 1]) {
				num = freqchar;
				frequency = A[freqchar - 1];
			} else if((frequency == A[freqchar - 1]) && (num > freqchar)) {
				num = freqchar;
			}
		}
		printf("%d %d\n", num, frequency);
		free(A);
	}
	return 0;
}
