//Summation of primes, Problem 10 on the Euler Project
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
/*reusing problem 007 code to find primes 
but adding a much faster algorithm knowing now that:
-primes above 3 can be expressed as = 6k (+/- 1)
-If we cannot find a number less than or equal than sqrt(n),
    then n is probably prime.
*/

#include <stdio.h>
#include <math.h>
#define AMOUNT_OF_PRIMES 1000000
#define PRIMES_UPPER_BOUND 2000000

int primes[AMOUNT_OF_PRIMES];
int primesFound=0;

int generateArrayOfPrimes();
int initializeArray();	
int isPrime(int prospect);
int canBeExpressedAsPrime(int prospect);
int getSqrtRoundedDown(int prospect);
int pushPrimeIntoArray(int newPrime);

int main(){
	long long sum=0;
	printf("%d\n",primes[4]);
	generateArrayOfPrimes();
	printf("%dst Prime = %d\n",primesFound,primes[primesFound-1]);
		for (int i=0; i<primesFound;i++)
			sum+=primes[i];
	printf("The sum of %d primes up to %d is %lld\n",primesFound,primes[primesFound-1],sum);
	return 0;
}

int generateArrayOfPrimes(){
	initializeArray();
	for (int i=7; i<PRIMES_UPPER_BOUND && primesFound<AMOUNT_OF_PRIMES; i+=2)
		if(isPrime(i)){
			pushPrimeIntoArray(i);
			primesFound++;}
	return primesFound;
}

int initializeArray(){	
	primes[0]=2;
	primes[1]=3;
	primes[2]=5;
	primesFound=3;
	return 0;
}

int isPrime(int prospect){
//	printf("Considerando nuevo prospecto \t%d\n",prospect);
	if(canBeExpressedAsPrime(prospect)){
//		printf("puede ser expresado como Primo\n");
		int limit=getSqrtRoundedDown(prospect);
		for (int i=1,nextDivisor=0; nextDivisor<=limit ;i++){
			nextDivisor=primes[i+1];
//			printf("iter: %d Dividir %d por primos menores a %d; actual/siguiente:%d/%d\n",i,prospect,limit,primes[i],nextDivisor);
			if ((prospect%(primes[i]))==0){
//				printf("divisor encontrado %d************\n",primes[i]);
				return 0;}
		}
		return 1;
	}
	return 0;
}

int canBeExpressedAsPrime(int prospect){
	if((prospect)%6==5){
		return 1;}
	if((prospect)%6==1){
		return 1;}
	return 0;
}

int getSqrtRoundedDown(int prospect){
	double root=sqrt(prospect);
//	printf ("raiz %0.4f %d\n",root, (int)root);
	return (int)root;
}

int pushPrimeIntoArray(int newPrime){
//	printf("Primo Encontrado numero %d \tprimes[%d]:\t%d\n",primesFound+1,primesFound,newPrime);
	primes[primesFound]=newPrime;
	return 0;
}
