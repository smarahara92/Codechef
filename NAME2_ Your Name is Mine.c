/**

All submissions for this problem are available.

In an attempt to control the rise in population, Archer was asked to come up with a plan. This time he is targeting marriages. Archer, being as intelligent as he is, came up with the following plan:

A man with name M is allowed to marry a woman with name W, only if M is a subsequence of W or W is a subsequence of M.

A is said to be a subsequence of B, if A can be obtained by deleting some elements of B without changing the order of the remaining elements.

Your task is to determine whether a couple is allowed to marry or not, according to Archer's rule.
Input

The first line contains an integer T, the number of test cases. T test cases follow. Each test case contains two space separated strings M and W.
Output

For each test case print "YES" if they are allowed to marry, else print "NO". (quotes are meant for clarity, please don't print them)
Constraints

    1 ≤ T ≤ 100
    1 ≤ |M|, |W| ≤ 25000 (|A| denotes the length of the string A.)
    All names consist of lowercase English letters only.

Example

Input:
3
john johanna
ira ira
kayla jayla

Output:
YES
YES
NO

Explanation

Case 1: Consider S = "johanna". So, S[0] = 'j', S[1] = 'o', S[2] = 'h' and so on. If we remove the indices [3, 4, 6] or [3, 5, 6] from S, it becomes "john". Hence "john" is a subsequence of S, so the answer is "YES".

Case 2: Any string is a subsequence of it self, as it is formed after removing "0" characters. Hence the answer is "YES".

Case 3: "jayla" can not be attained from "kayla" as removing any character from "kayla" would make the string length smaller than "jayla", also there is no 'j' in "kayla". Similar reasoning can be applied to see why "kayla" can't be attained from "jayla". Hence the answer is "NO".

**/

#include <stdio.h>

int subsequenceexists(char *m, char *w) {
	int mindex = 0, windex = 0;
	while((m[mindex] != '\0') && (w[windex] != '\0')) {
		//printf("%c %c %d %d\n", m[mindex], w[windex], mindex, windex);
		if(m[mindex] == w[windex]) {
			mindex += 1;
		}
		windex += 1;
	}
	if(m[mindex] == '\0') {
		return 1;
	} else {
		return 0;
	}
}

int main(void) {
	int t, x;
	char m[25001], w[25001];
	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		scanf("%s %s", m, w);
		if((subsequenceexists(m, w)) || (subsequenceexists(w, m))) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
