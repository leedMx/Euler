//Euler project problem 3
/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include <stdio.h>
#define print(ref) printf("%ld\n",ref);
#define HACKERRANK 0


long largestPrimeFactor(long);
void hackerrank();

int main(){
	if(!HACKERRANK){
		long solution = 0, number = 600851475143;

		solution = largestPrimeFactor(number);

		print(solution)
	}
	if(HACKERRANK) hackerrank();
	return 0;
}

long largestPrimeFactor(long number){
	long factor = 3, temp = number;
	while (( number > 1 ) && (number %2 == 0)){
		number /= 2;
	}
	if (number == 1) return 2;

	while ( factor*factor <= temp ){
		while(number % factor == 0){
			number /= factor;
		}
		if (number == 1) return factor;
		factor+=2;
	}
	if (number>2) return number;

	return factor-2;
}

void hackerrank(){
	long solution = 0, number = 0;
	int testCases = 0;
	scanf("%d",&testCases);
	for (int test = 0 ; test < testCases ; test++ ){
		scanf("%ld\n",&number);
		solution = largestPrimeFactor(number);
		print(solution);
	}
}

