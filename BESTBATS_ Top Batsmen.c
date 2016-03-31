/**
A cricket team consists of 11 players and some are good at batting, others are good at bowling and some of them are good at both batting and bowling. The batting coach wants to select exactly K players having maximum possible sum of scores. Given the batting score of each of the 11 players, find the number of ways in which we can select exactly K players such that the sum of their scores is the maximum possible. Two ways are different if there is a player who is selected in one of them is not in the other. See explanation of sample cases for more clarity.
Input

First line contains T, number of test cases ( 1 ≤ T ≤ 100 ). T cases follow, each having 2 lines. First line of each case contains scores of 11 players ( 1 ≤ score ≤ 100 ) and the second line contains K (1 ≤ K ≤ 11)
Output

For each test case, output the answer in a new line.
Example

Input:
2
1 2 3 4 5 6 7 8 9 10 11
3
2 5 1 2 4 1 6 5 2 2 1
6

Output:
1
6


Explanation:
Case 1 : Maximum possible sum of scores = 11 + 10 + 9 = 30 and can be achieved only by selecting the last 3 players. Only one possible way.

Case 2 : Maximum possible sum of scores = 6 + 5 + 5 + 4 + 2 + 2 = 24 and considering the players as p1 p2 p3 ... p11 in that order, the ones with maximum possible sum of scores is as follows
{p1, p2, p4, p5, p7, p8 }
{p10, p2, p4, p5, p7, p8 }
{p1, p2, p10, p5, p7, p8 }
{p9, p2, p4, p5, p7, p8 }
{p1, p2, p9, p5, p7, p8 }
{p10, p2, p9, p5, p7, p8 }

**/

#include <stdio.h>

int greatscore = 0, total_possibilities = 0;

void find_possibilities(int *players, int k, int index, int total) {
	if(k == 0) {
		if(total > greatscore) {
			greatscore = total;
			total_possibilities = 1;
		} else if(total == greatscore) {
			total_possibilities += 1;
		} else {
			return;
		}
	} else {
		for(; index <= (11 - k); index++) {
			find_possibilities(players, k - 1, index + 1, total + players[index]);
		}
	}
}

int main(void) {
	int t, players[11], k, x, y;
	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		for(y = 0; y < 11; y++) {
			scanf("%d", &players[y]);
		}
		scanf("%d", &k);
		greatscore = 0, total_possibilities = 0;
		find_possibilities(players, k, 0, 0);
		printf("%d\n", total_possibilities);
	}
	return 0;
}
