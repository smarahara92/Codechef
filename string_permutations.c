#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int arr[], int length) {
	int x = 0;
	for(; x < length; x++) {
		printf("%d ", arr[x]);
	}
	printf("\n");
}

void generate_permutations(char *string) {
	int len = strlen(string);
	int nextSwap[len], x;
	char tmp;
	for(x = 0; x < len; x++) {
		nextSwap[x] = x;
	}
	for(x = (len - 2); x > -1; x--) {
		if(nextSwap[x] < (len - 1)) {
			tmp = string[nextSwap[x]];
			string[nextSwap[x]] = string[x];
			string[x] = string[nextSwap[x] + 1];
			string[nextSwap[x] + 1] = tmp;
			nextSwap[x] = nextSwap[x] + 1;
			x = len - 1;
			printf("%s\n", string);
		} else {
			tmp = string[x];
			string[x] = string[nextSwap[x]];
			string[nextSwap[x]] = tmp;
			nextSwap[x] = x;
		}
	}
}

int main(void) {
	char string[7] = {'A', 'B', 'C', 'D', 'E', 'F', '\0'};
	generate_permutations(string);
	return 0;
}