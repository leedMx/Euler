//Prime Digits Replacements, Project Euler Problem 51
/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family. */

#include <stdio.h>
#define print(ref) printf(#ref"=%d\n",ref);
#define NUM_OF_PRIMES 79000
#define SIX_DIGITS 100000
#define SEVEN_DIGITS 1000000

int generatePrimes(int);
int isPrime(int);
int canBeExpressedAsPrime(int);

int isSolution(int);
int countDigitWithin(int,int);
int patternForDigit(int,int);
int countPrimeFamily(int,int,int);
int lastDigit(int);
int cropLastDigit(int);

int primes[NUM_OF_PRIMES] = {2,3,5,7};
int primesFound = 4;

int main(){
	int solution=0;

	generatePrimes(SEVEN_DIGITS);
		
	for (int i = 0 ; i < primesFound && !solution ; i++)
		if ( primes[i] > SIX_DIGITS )
			if( isSolution(primes[i]) ) 
				solution = primes[i];
	
	print(solution);
	
	return 0;
}

int isSolution(int prospect){

	for(int digit = 0 ; digit < 3 ; digit ++){
		if ( countDigitWithin(digit, cropLastDigit(prospect) ) == 3 ){
			int digitChangingSum = patternForDigit(digit, prospect);
			int family = countPrimeFamily(prospect, digitChangingSum, 9-digit);
			if ( family == 8 ) return 1;
		}
	}

	return 0;
}

int countPrimeFamily(int number, int digitChangingSum, int attempts){
	int count = 1;
	while ( number < SEVEN_DIGITS && attempts){
		number += digitChangingSum;
		if ( isPrime(number) ) count++;
		attempts--;
	}
	return count;
}

int countDigitWithin(int digit, int number){
	int digits[10]={0};
	while (number){
		digits[lastDigit(number)]++;
		number /= 10;
	}
	return digits[digit];
}

int patternForDigit(int digit, int number){
	int result = 0;
	int value = 1;
	number = cropLastDigit(number);
	while ( number ){
		if ( lastDigit(number) == digit ) 
			result += 1*value;
		number /= 10;
		value *= 10;
	}
	return result*10;
}

int cropLastDigit(int number){
	return number/10;
}

int lastDigit(int number){
	if ( number < 10 ) return number;
	return number%10;
}


int generatePrimes(int upperBound){
	for (int prospect = 11 ; prospect < upperBound ; prospect+=2 )
		if ( isPrime(prospect) )
			primes[primesFound++] = prospect;
	return primesFound-1;
}

int isPrime(int prospect){
	if ( !canBeExpressedAsPrime(prospect) ) return 0;

	for (int i=0 ; primes[i]*primes[i] <= prospect ; i++)
		if ( prospect%primes[i] == 0) return 0;

	return 1;
}

int canBeExpressedAsPrime(int prospect){
	if ( prospect%6 == 1 ) return 1;
	if ( prospect%6 == 5 ) return 1;
	return 0;
}
