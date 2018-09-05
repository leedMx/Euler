//Consecutive Prime Sum, Project Euler Problem 50
/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes? */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define NUM_OF_PRIMES 80000

int generatePrimes();
int isPrime(int);
int canBeExpressedAsPrime(int);

int primes[NUM_OF_PRIMES]={2,3,5};
int primesFound=3;

int main(){
	int sum=0,chain=0,maxChain=0,solution=0;
	generatePrimes();
	
	for (int startingIndex=0; startingIndex < NUM_OF_PRIMES ; startingIndex++){
		for( int i = startingIndex ; i < NUM_OF_PRIMES && primes[i] != 0 && sum < 1000000; i++){
			sum += primes[i];
			chain++;
			if (isPrime(sum) && chain>maxChain){
				maxChain = chain;
				solution = sum;
			}
		}
		sum=0;
		chain=0;
	}

	print(solution)
	print(maxChain)

	return 0;
}

int generatePrimes(){
	for (int prospect = 7 ; prospect < 1000000 ; prospect+=2)
		if(isPrime(prospect))
			primes[primesFound++] = prospect;
	return primes[primesFound-1];
}

int isPrime(int prospect){
	if ( (prospect == 2) || (prospect == 3) || (prospect == 5) )return 1;
	
	if ( ! canBeExpressedAsPrime(prospect) ) return 0;

	for (int i=0; primes[i]*primes[i] <= prospect ; i++)
		if ( prospect%primes[i] == 0 ) return 0;
	
	return 1;
}

int canBeExpressedAsPrime(int prospect){
	if ( prospect%6 == 1 ) return 1; 
	if ( prospect%6 == 5 ) return 1;
	return 0;
}
