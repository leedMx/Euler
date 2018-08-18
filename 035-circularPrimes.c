//Circular Primes, Project Euler Problem 35
/* The number 197 is called a circular prime because all rotations of the digits: 197, 971, and 719 are themselves prime.
There are thirteen such primes below 100: 2,3,5,7,11,13,17,31,37,71,73,79 and 97.
How many circular primes are there below one million?*/

#include <stdio.h>
#define PRIMES_BOUND 1000000
#define PRIMES_AMOUNT 80000

int isCircular(int);
int rotateDigits(int,int);
int getNthDigit(int,int);
int power(int,int);
int length(int);

int generatePrimes(int);
int isPrime(int);
int canBeExpressedAsPrime(int);

int primes[PRIMES_AMOUNT]={2,3,5};
int primesFound=3;

int main (){
	int sum=0;
	printf("%d primes below %d\n",generatePrimes(PRIMES_BOUND),PRIMES_BOUND);

	for(int i=0 ; i<primesFound ; i++){
		sum+=isCircular(primes[i]);
	}

	printf("Found %d circular primes\n",sum);

	return 0;
}

int isCircular(int number){
	int circularity=1;
	int	digits=length(number);
	int rotation=rotateDigits(number,digits);

	if(number<13) return 1;

	while (rotation!=number){
		if (isPrime(rotation)==0){
			circularity=0;
			break;
		}
		rotation=rotateDigits(rotation,digits);
	}

	return circularity;
}

int rotateDigits(int number,int digits){
	int temp=getNthDigit(number,digits);

	number-=temp*power(10,digits-1);

	return (number*10)+temp;
	
}

int power(int number,int power){
	int result=1;
	while (power>=1){
		result*=number;
		power--;
	}
	return result;
}

int length(int number){
	int result=1;
	while(number/10>=1){
		number/=10;
		result++;
	}
	return result;
}

int getNthDigit(int number,int digit){
	int powerOfTen=1;
	int result;
	while(digit>0){
		powerOfTen*=10;
		digit--;
	}
	result=number%powerOfTen;
	result/=(powerOfTen/10);
	return result;
}

int generatePrimes(int bound){
	for (int prospect=7; prospect<bound ; prospect+=2){
		if (isPrime(prospect)){
			primes[primesFound]=prospect;
			primesFound++;
		}
	}
	return primesFound;
}

int isPrime(int prospect){
	if (canBeExpressedAsPrime(prospect)){
		for (int i=1; primes[i]*primes[i]<=prospect ; i++){
			if (prospect%primes[i]==0){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int canBeExpressedAsPrime(int prospect){
	if (prospect%6==5) return 1;
	if (prospect%6==1) return 1;
	return 0;
}
