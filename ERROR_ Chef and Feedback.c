/**
 Lots of geeky customers visit our chef's restaurant everyday. So, when asked to fill the feedback form, these customers represent the feedback using a binary string (i.e a string that contains only characters '0' and '1'.

Now since chef is not that great in deciphering binary strings, he has decided the following criteria to classify the feedback as Good or Bad :

If the string contains the substring "010" or "101", then the feedback is Good, else it is Bad. Note that, to be Good it is not necessary to have both of them as substring.

So given some binary strings, you need to output whether according to the chef, the strings are Good or Bad.
Input

The first line contains an integer T denoting the number of feedbacks. Each of the next T lines contains a string composed of only '0' and '1'.
Output

For every test case, print in a single line Good or Bad as per the Chef's method of classification.
Constraints

    1 ≤ T ≤ 100
    1 ≤ |S| ≤ 105



Sum of length of all strings in one test file will not exceed 6*106.

Example

Input:
2
11111110
10101010101010


Output:
Bad
Good


Explanation

Example case 1.

The string doesn't contain 010 or 101 as substrings.

Example case 2.

The string contains both 010 and 101 as substrings. 

**/

#include <stdio.h>

int main(void) {
	int t, x, index, count;
	char s[100001], lastchar;
	scanf("%d", &t);
	//printf("t = %d\n", t);
	for(x = 0; x < t; x++) {
		scanf("%s", s);
		index = 0;
		count = 0;
		lastchar = s[0];
		while(s[index] != '\0') {
			if(lastchar != s[index]) {
				count += 1;
				if(count == 2) {
					break;
				}
			} else {
				count = 0;
			}
			lastchar = s[index];
			index++;
		}
		if(count == 2) {
			printf("Good\n");
		} else {
			printf("Bad\n");
		}
		
	}
	return 0;
}
