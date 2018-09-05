//Distinct Prime Factors, Euler Project Problem 47
/*
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers? */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define NUM_OF_PRIMES 100000

int countPrimeFactorsOf(int);
int generatePrimes();
int isPrime(int);
int canBeExpressedAsPrime(int);

int primes[NUM_OF_PRIMES] = {2,3,5,7};
int primesFound = 4;

int main(){
	int solution=0;

	generatePrimes();
	
	for (int number=2*3*5*7 ; !solution ; number++){
		if((countPrimeFactorsOf(number+0) == 4) &&
		   (countPrimeFactorsOf(number+1) == 4) &&
		   (countPrimeFactorsOf(number+2) == 4) &&
		   (countPrimeFactorsOf(number+3) == 4)){
				solution = number;
		}
	}

	print (solution);

	return 0;
}

int countPrimeFactorsOf(int number){
	int count = 0;
	
	for(int i = 0 ; number > 1 ; i ++){
		if ( number%primes[i] == 0 ){
			count++;
		}
		while ( number%primes[i] == 0 ){
			number /= primes[i];
		}
	}

	return count;
}

int generatePrimes(){
	for (int i=11; primesFound < NUM_OF_PRIMES ; i++)
		if ( isPrime(i) )
			primes[primesFound++] = i;
	return primes[primesFound-1];
}

int isPrime(int prospect){
	if( ! canBeExpressedAsPrime(prospect) )return 0;

	for (int i=1; primes[i]*primes[i] < prospect ; i++)
		if ( prospect%primes[i] == 0 ) return 0;

	return 1;
}

int canBeExpressedAsPrime(int prospect){
	if ( prospect%6 == 1 ) return 1;
	if ( prospect%6 == 5 ) return 1;
	return 0;
}
