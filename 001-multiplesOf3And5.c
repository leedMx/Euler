//Multiples of 3 and 5, Project Euler Problem 1
/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#define printl(ref) printf(#ref" = %lld\n",ref);

#define HACKERRANK 0
int hackerrank();

long long int triangle(long long int);

int main(){

	if(!HACKERRANK){
		long long target = 1000, solution = 0;
		target--;
		solution = 3*(triangle(target/3)) + 5*(triangle(target/5)) - 15*(triangle(target/15));
		printl(solution);
	}
	
	if(HACKERRANK)hackerrank();
	
	return 0;
}

long long int triangle(long long int n){
	return n * (n+1)/2;
}

int hackerrank(){
	int testCases=0;
	long long int target=0,solution=0;
	scanf("%d",&testCases);
	
	for (int test = 1; test <= testCases ; test++){
		scanf("%lld",&target);
		target--;
		solution = 3*(triangle(target/3)) + 5*(triangle(target/5)) - 15*(triangle(target/15));
		printf("%lld\n",solution);
	}
	return 0;
}
