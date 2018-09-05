//Prime Permutation, Project Euler Problem 49
/*
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: 
(i) each of the three terms are prime, and, 
(ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
What 12-digit number do you form by concatenating the three terms in this sequence? */

#include <stdio.h>
#define NUM_OF_PRIMES 1300

int shareDigits(int,int);
int digitCount(int*,int);
int lastDigit(int);

int generatePrimes();
int isPrime(int);
int canBeExpressedAsPrime(int);

int primes[NUM_OF_PRIMES] = {2,3,5,7};
int primesFound = 4;

int main(){
	int numA,numB,numC;
	generatePrimes();

	for(int i=0 ; i<NUM_OF_PRIMES ; i++){
		if (primes[i] > 1000){
			for (int difference = 1 ; difference*2 < 9999 ; difference++){
				numA = primes[i];
				numB = numA + difference;
				numC = numB + difference;
				if ( isPrime( numB ) && shareDigits( numA,numB ) &&
				     isPrime( numC ) && shareDigits( numA,numC )){ 
					printf ("%d %d %d \n",numA,numB,numC);
				}
			}
		}
	}

	return 0;
}

int shareDigits(int number1, int number2){
	
	int digits1[10]={0};
	int digits2[10]={0};
	
	digitCount(digits1,number1);
	digitCount(digits2,number2);

	for(int i=0 ; i < 10 ; i++){
		if (digits1[i] != digits2[i])
			return 0;
	}
	return 1;
}

int digitCount(int*array,int number){
	while(number){
		array[lastDigit(number)] += 1;
		number /= 10;
	}
	return 0;
}

int lastDigit(int number){
	if (number < 10) return number;
	return number%10;
}

int generatePrimes(){
	for (int prospect=11; prospect < 10000 ; prospect+=2)
		if (isPrime(prospect))
			primes[primesFound++]=prospect;
	return primes[primesFound-1];
}

int isPrime(int prospect){
	if ( ! canBeExpressedAsPrime(prospect) ) return 0;

	for (int i=0; primes[i]*primes[i]<prospect ; i++)
		if ( prospect%primes[i] == 0 )
			return 0;
	return 1;
}

int canBeExpressedAsPrime(int prospect){
	if ( prospect%6 == 5 ) return 1;
	if ( prospect%6 == 1 ) return 1;
	return 0;
}
