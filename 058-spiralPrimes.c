//Spiral Primes, Project Euler Problem 58
/*
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%? */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define printl(ref) printf(#ref" = %ld\n",ref);
#define NUM_OF_PRIMES 5000

int primesOnThisLevel(int);

void generatePrimes();
int isPrime(int);
int canBeExpressedAsPrime(int);

int primes[NUM_OF_PRIMES] = {2,3,5};
int primesFound = 3;

int main(){
	int numbersInDiagonal = 1;
	int primesInDiagonal = 0;
	int level = 2;

	generatePrimes();
	
	do {	
		primesInDiagonal += primesOnThisLevel(level);
		numbersInDiagonal += 4;
		level++;
	} while ( numbersInDiagonal < primesInDiagonal*10 );

	int sideLenght = (2*(--level))-1;
	print(sideLenght);

	return 0;
}

int primesOnThisLevel(int level){
	int primesCount = 0;
	int sideLenght = (2*level)-1;
	int differenceBetweenCorners = 2*(level-1);
	int cornerValue = sideLenght*sideLenght;
	for (int i = 0 ; i < 3 ; i++){
		cornerValue -= differenceBetweenCorners;
		primesCount += isPrime(cornerValue);
	}
	return primesCount;
}

void generatePrimes(){
	for (int number = 7 ; primesFound < NUM_OF_PRIMES ; number +=2 )
		if ( isPrime(number) )
			primes[primesFound++] = number;
}
	
int isPrime(int prospect){
	if ( prospect == 3 || prospect == 5 ) return 1;
	if ( !canBeExpressedAsPrime(prospect) ) return 0;
	for (int i = 0 ; primes[i]*primes[i] <= prospect ; i++)
		if ( prospect%primes[i] == 0 ) return 0;
	return 1;
}

int canBeExpressedAsPrime(int prospect){
	if ( prospect%6 == 1 ) return 1;
	if ( prospect%6 == 5 ) return 1;
	return 0;
}
