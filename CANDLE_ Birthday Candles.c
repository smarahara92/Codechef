/**
The chef is preparing a birthday cake for one of his guests,
and his decided to write the age of the guest in candles on the cake.
There are 10 types of candles, one for each of the digits '0' through '9'.
The chef has forgotten the age of the guest, however, so doesn't know whether he has enough candles of the right types.
For example, if the guest were 101 years old, the chef would need two '1' candles and one '0' candle.
Given the candles the chef has, your task is to determine the smallest positive integer that cannot be represented with those candles.
Input:

Input will begin with an integer T≤100, the number of test cases.
Each test case consists of a single line with exactly 10 integers, each between 0 and 8, inclusive.
The first integer of each test case represents the number of '0' candles the chef has,
the second integer represents the number of '1' candles the chef has, and so on.
Output:

For each test case, output on a single line the smallest positive integer that cannot be expressed with the given candles.
Sample input:

3
2 1 1 4 0 6 3 2 2 2
0 1 1 1 1 1 1 1 1 1
2 2 1 2 1 1 3 1 1 1
 

Sample output:

4
10
22

**/

#include <stdio.h>

int getindex(int *candles, int length) {
	int ncandles = candles[0], index = 0, x;
	for(x = 1; x < length; x++) {
		if(ncandles > candles[x]) {
			ncandles = candles[x];
			index = x;
		}
	}
	return index;
}

int powerr(int base, int power) {
	int poww = 1, x;
	for(x = 0; x < power; x++) {
		poww = poww * base;
	}
	return poww;
}

int rapvalue(int length) {
	int rapnum = 1, x;
	for(x = 0; x < length; x++) {
		rapnum = (rapnum * 10) + 1;
	}
	return rapnum;
}

int main(void) {
	int t, candles[10], x, y, index, tmp, tmp1;
	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		for(y = 0; y < 10; y++) {
			scanf("%d", &candles[y]);
		}
		index = getindex(candles + 1, 9) + 1;
		if(candles[index] <= candles[0]) {
			printf("%d\n", index * rapvalue(candles[index]));
		} else {
			tmp = powerr(10, candles[0] + 1);
			tmp1 = candles[index] * powerr(10, candles[0] + 1);
			//printf("tmp = %d tmp1 = %d\n", tmp, tmp1);
			if(tmp < tmp1) {
				printf("%d\n", tmp);
			} else {
				printf("%d\n", tmp1);
			}
		}
	}
	return 0;
}
