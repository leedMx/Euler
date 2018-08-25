//Pandigital Prime, Project Euler Problem 41
/*We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists? */

#include <stdio.h>
#define print(ref) printf(#ref"=%d\n",ref);
#define PRIMES_AMOUNT 520000

int isPrime(int);
int canBeExpressedAsPrime(int);
int isPandigital(int);
int lastDigit(int);
int length(int);

int primes[PRIMES_AMOUNT]={2,3,5,7};
int primesFound=4;

int main(){
	int largestPandigital=0;

	for (int number=11; number < 7654321 ; number+=2){
		if(isPrime(number)){
			primes[primesFound++]=number;
			if ((number>=1234567) && isPandigital(number)){
					largestPandigital=number;
			}
		}
	}
	print(primesFound)
	print(primes[518011])
	print(largestPandigital)			

	return 0;
}

int isPandigital(int number){
	int digitCount[10]={0};
	int n=length(number);

	while (number){
		digitCount[lastDigit(number)]+=1;
		number/=10;
	}

	if (digitCount[0])return 0;

	for (int i=1; i<=n ; i++){
		if( (digitCount[i]==0) || (digitCount[i]>1) )
			return 0;
	}
	return 1;
	
}

int lastDigit(int number){
	if (number<10)return number;
	return number%10;
}

int isPrime(int number){
	if (canBeExpressedAsPrime(number)==0){
		return 0;
	}
	for (int i=1; primes[i]*primes[i] <= number ; i++){
		if (number%primes[i]==0)
			return 0;
	}
	return 1;
}

int canBeExpressedAsPrime(int number){
	if(number%6==1)return 1;
	if(number%6==5)return 5;
	return 0;
}

int length(int number){
	int result=0;
	while (number){
		number/=10;
		result++;
	}
	return result;
}
