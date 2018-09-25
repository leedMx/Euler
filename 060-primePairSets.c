//Prime Pair Sets, Project Euler Problem 60
/* 
The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime. */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define NUM_OF_PRIMES 5000

int exploreSolutions(int*,int,int,int);
int isThisChoiceValid(int*,int);
int isValidPair(int,int);
int concatenationIsPrime(int,int);

int generatePrimes();
int isPrime(int);
int canBeExpressedAsPrime(int);

int primes[NUM_OF_PRIMES] = {2,3,5};
int primesFound = 3;
int largestPrime;

int solution = 0;

int main(){
	largestPrime = generatePrimes();
	
	int solutionSet[5] = {0};

	exploreSolutions(solutionSet,0,5,0);

	return 0;
}

int exploreSolutions(int*selection, int choices, int index, int sum){
	if ( index >= NUM_OF_PRIMES || solution ) return 0;

	if ( choices == 5 ){
		
		for (int i = 0 ; i < 5 ; i++)
			printf("%d ",selection[i]);
		printf("\n");
		solution++;
		print(sum);
		return 0;

	} else {
		
		for (int i = index ; i < NUM_OF_PRIMES ; i++){
			if ( isThisChoiceValid(selection,primes[i]) ){
				selection[choices] = primes[i];
				choices++;
				sum += primes[i];
				
				exploreSolutions(selection, choices, i+1,sum);
				
				sum -= primes[i];
				choices--;
				selection[choices] = 0;
			}
		}
	}
	return 0;
}

int isThisChoiceValid(int*solutionSet, int prospect){
	for (int i = 0 ; i < 5 ; i++)
		if ( !isValidPair(prospect,solutionSet[i]) ) return 0;
	return 1;
}

int isValidPair(int prime1, int prime2){
	if (!concatenationIsPrime(prime1,prime2)) return 0;
	return concatenationIsPrime(prime2,prime1);
}

int concatenationIsPrime(int prime1, int prime2){
	if ( prime1 == 0 || prime2 == 0) return 1;
	int temp =  prime2;
	while ( temp ){
		prime1 *= 10;
		temp /= 10;
	}
	return isPrime(prime1+prime2);
}

int generatePrimes(){
	for (int number = 7 ; primesFound < NUM_OF_PRIMES ; number += 2)
		if ( isPrime(number) )
			primes[primesFound++] = number;
	return primes[primesFound-1];
}

int isPrime(int prospect){
	if ( prospect == 3 || prospect == 5 ) return 1;
	if ( !canBeExpressedAsPrime(prospect) ) return 0;
	for ( int i = 0 ; primes[i]*primes[i] <= prospect ; i++)
		if ( prospect%primes[i] == 0 ) return 0;
	return 1;
}

int canBeExpressedAsPrime(int prospect){
	if ( prospect%6 == 5 ) return 1;
	if ( prospect%6 == 1 ) return 1;
	return 0;
}
