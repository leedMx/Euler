//Truncatable Primes, Project Euler Problem 37
/*The number 3797 has an interesting property, being Prime itself, it is possible to continuously remove digits fromf left to right, and remain prime at each stage 3797, 797, 97, 7. Similarly we can work from right to left 3797, 379, 37, 3.

Find the sum of the only 11 primes that are both truncatable form left to tight and right to left.
Note: 2,3,5 and 7 are not considered to be truncatable primes. */

#include <stdio.h>

#define PRIMES_AMOUNT 1000000
#define dprint(ref) printf(#ref" = %d\n",ref);

int isPrime(int);
int isExpressableAsPrime(int);
int isTruncatable(int);
int cropLastDigit(int);
int power(int,int);

int primes[PRIMES_AMOUNT]={2,3,5,7};
int primesFound=4;
int truncatablePrimes;

int main(){
	int sum=0;

	for (int number = 11 ; truncatablePrimes<11; number+=2){
		if (isPrime(number)){
			primes[primesFound]=number;
			primesFound++;
			if(isTruncatable(number)){
				truncatablePrimes++;
				sum+=number;
			}
		}
	}
	dprint(primesFound)
	dprint(truncatablePrimes)
	dprint(sum)

	return 0;
}

int isTruncatable(int number){
	int truncatableProspect=number;
	
	while(number){
		if(isPrime(number)==0)return 0;
		number/=10;
	}
	
	number=truncatableProspect;

	while(number){
		if(isPrime(number)==0)return 0;
		number=cropLastDigit(number);
	}

	dprint(truncatableProspect)
	
	return 1;
}

int cropLastDigit(int number){
	int originalNumber=number;
	int length=0;
	int lastDigit=0;
	
	while(number){
		if(number<10)lastDigit=number;
		number/=10;
		length++;
	}
	return originalNumber-(lastDigit*power(10,length-1));
}

int power(int number,int exponent){
	int result=1;
	while(exponent){
		result*=number;
		exponent--;
	}
	return result;
}

int isPrime(int number){
	if (number<2)
		return 0;

	if (number==2 || number==3 )
		return 1;
	
	if (isExpressableAsPrime(number)==0)
		return 0;
	
	for (int i=0 ; primes[i]*primes[i]<=number ; i++)
			if (number%primes[i]==0)
				return 0;
	
	return 1;
}

int isExpressableAsPrime(int number){
	if (number%6==5) return 1;
	if (number%6==1) return 1;
	return 0;
}
