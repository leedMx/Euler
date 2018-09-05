//Self Powers, Project Euler Problem 48
/*
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000. */

#include <stdio.h>
#define printl(ref) printf(#ref" = %ld\n",ref);
#define MODULO 10000000000

long trimmedPower(int,int);

int main (){
	long solution=0;

	for (int i=1 ; i <= 1000 ; i++)
		solution += trimmedPower(i,i);

	solution %= MODULO;

	printl(solution)
	return 0;
}

long trimmedPower(int base, int power){
	long result=1;
	while (power){
		result *= base;
		result %= MODULO;
		power--;
	}
	
	return result;
}
