//Goldbach's Other Conjecture, Euler Project Problem 46
/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square? */

#include <stdio.h>
#include <math.h>
#define print(ref) printf(#ref"=%d\n",ref);
#define NUM_OF_PRIMES 1000

int compliesWithConjecture(int);
int	generatePrimes(int);
int isPrime(int);
int canBeExpressedAsPrime(int);
int isPerfectSquare(int);

int primes[NUM_OF_PRIMES] = {2,3,5,7};
int primesFound = 4;

int main(){
	int prospect = 1, solution = 0;

	print(generatePrimes(NUM_OF_PRIMES));
	
	while(!solution){
		prospect += 2;
		if(!compliesWithConjecture(prospect))
			solution = prospect;
	}

	print(solution);

	return 0;
}

int compliesWithConjecture(int prospect){

	if( isPrime(prospect) ) return 1;
	else int compositeOdd = prospect;
		
	for(int i =0; primes[i] < compositeOdd && i < primesFound ; i++){
		if ( isPerfectSquare( (compositeOdd - primes[1]) / 2 ) )return 1;
	}
	
	return 0;
}

int isPerfectSquare(int number){
	double root = sqrt(number);
	return root == (int)root;
}

int generatePrimes(int limit){
	for (int i = 11  ; primesFound<limit ; i++)
		if (isPrime(i)){
			primes[primesFound++]=i;
		}
	return primes[primesFound-1];
}

int isPrime(int prospect){
	if (!canBeExpressedAsPrime(prospect)) return 0;

	for (int i = 1; primes[i]*primes[i] < prospect ; i++)
		if (prospect%primes[i] == 0) return 0;

	return 1;
}

int canBeExpressedAsPrime(int prospect){
	if (prospect%6 == 1)return 1;
	if (prospect%6 == 5)return 1;
	return 0;
}
