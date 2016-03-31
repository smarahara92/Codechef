/**
The chef has a recipe he wishes to use for his guests,
but the recipe will make far more food than he can serve to the guests.
The chef therefore would like to make a reduced version of the recipe which has the same ratios of ingredients, but makes less food.
The chef, however, does not like fractions.
The original recipe contains only whole numbers of ingredients,
and the chef wants the reduced recipe to only contain whole numbers of ingredients as well.
Help the chef determine how much of each ingredient to use in order to make as little food as possible.
Input

Input will begin with an integer T, the number of test cases.
Each test case consists of a single line.
The line begins with a positive integer N, the number of ingredients.
N integers follow, each indicating the quantity of a particular ingredient that is used.
Output

For each test case, output exactly N space-separated integers on a line,
giving the quantity of each ingredient that the chef should use in order to make as little food as possible.
Sample Input

3
2 4 4
3 2 3 4
4 3 15 9 6

Sample Output

1 1
2 3 4
1 5 3 2

Constraints

T≤100
2≤N≤50
All ingredient quantities are between 1 and 1000, inclusive.

**/

#include <stdio.h>
#include <stdlib.h>

int getsmallrecipe(int *recipes, int length) {
	int smallrecipe = recipes[0], x;
	for(x = 1; x < length; x++) {
		if(smallrecipe > recipes[x]) {
			smallrecipe = recipes[x];
		}
	}
	return smallrecipe;
}

int dividerecipes(int *recipes, int *lessingradients, int length, int factor) {
	int x;
	for(x = 0; x < length; x++) {
		if(recipes[x] % factor == 0) {
			lessingradients[x] = recipes[x] / factor;
		} else {
			return 0;
		}
	}
	return 1;
}

void findratios(int *recipes, int *lessingradients, int length) {
	int smallfactor = getsmallrecipe(recipes, length);
	int lastfactor = smallfactor / 2, factor = 1, finalfactor = 1, x;
	while(factor <= lastfactor) {
		if(smallfactor % factor == 0) {
			lastfactor = smallfactor / factor;
			if(dividerecipes(recipes, lessingradients, length, lastfactor)) {
				return;
			}
			if(dividerecipes(recipes, lessingradients, length, factor)) {
				finalfactor = factor;
			}
		}
		factor += 1;
	}
	for(x = 0; x < length; x++) {
		lessingradients[x] = recipes[x] / finalfactor;
	}
}

int main(void) {
	int t, n, *recipes, *lessingradients, x, y;
	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		scanf("%d", &n);
		recipes = (int *) malloc (n * sizeof(int *));
		lessingradients = (int *) malloc (n * sizeof(int *));
		for(y = 0; y < n; y++) {
			scanf("%d", &recipes[y]);
		}
		findratios(recipes, lessingradients, n);
		for(y = 0; y < n; y++) {
			printf("%d ", lessingradients[y]);
		}
		printf("\n");
		free(recipes);
		free(lessingradients);
	}
	return 0;
}
