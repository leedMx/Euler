//Problem 7 on the Euler Project
/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/
#include <stdio.h>
#define AMOUNT_OF_PRIMES 10001 

int primes[AMOUNT_OF_PRIMES];
int primesFound=1;

int initializeArray();	
int isPrime(int prospect);
int pushPrimeIntoArray(int newPrime);

int main(){
	initializeArray();
	for (int i=3; primesFound<AMOUNT_OF_PRIMES;i+=2)
		if(isPrime(i)){
			pushPrimeIntoArray(i);
			primesFound++;}
			
	printf("%dst Prime = %d\n",primesFound,primes[primesFound-1]);
	return 0;
}
	
int initializeArray(){	
	primes[0]=2;
	primesFound=1;
	return 0;
}

int isPrime(int prospect){
	for (int i=1;i<=primesFound;i++)
		if ((prospect%(primes[primesFound-i]))==0)
			return 0;			
	
	return 1;
}

int pushPrimeIntoArray(int newPrime){
	primes[primesFound]=newPrime;
	return 0;
}

