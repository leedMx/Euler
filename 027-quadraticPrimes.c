//Quadratic Primes, Euler Project Problem 27
/*Euler discovered the remarkable quadratic formula:
n^2+n+41

It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39
. However, when n=40,40^2+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,41^2+41+41
is clearly divisible by 41.
The incredible formula n^2−79n+1601
was discovered, which produces 80 primes for the consecutive values 0≤n≤79

. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n^2+an+b

, where |a|<1000 and |b|≤1000 
where |n| is the modulus/absolute value of n 
e.g. |11|=11 and |−4|=4
Find the product of the coefficients, a and b, 
for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.*/

#include <stdio.h>
#define HIGHEST_PRIME 1000

int generatePrimes(int*);
int canBeExpressedAsPrime(int);
int divisibleByPrimes(int,int*);
int isInArray(int,int*);
int countPrimesFor(int,int);
int computeFunction(int,int,int);


int primes[HIGHEST_PRIME]={0,0,2,3,0,5};

int main(){
	int totalPrimes=0;
	int highestPrimeCount=0;
	int product=0;

	printf("%d primes generated\n",generatePrimes(primes));

	for(int a=-999; a<1000 ; a+=2){
		for (int b=0; b<1000 ; b++){
			if (primes[b])
				totalPrimes=countPrimesFor(a,b);
			
			if (totalPrimes>highestPrimeCount){
				highestPrimeCount=totalPrimes;
				product=a*b;
				printf("highest count %d at n^2 + n(%d) + %d\n",totalPrimes,a,b);
			}

			if (a>b)break;
		}
	}
	

	printf("Product of a*b= %d\n",product);
	return 0;
}	

int countPrimesFor(int a, int b){
	int count=0;
	int n=0;
	int primeResult=1;

	while(primeResult){
		if(isInArray(computeFunction(n,a,b),primes)){
			count++;
		}else{
			primeResult=0;
		}
		n++;
	}
	return count;
}

int computeFunction(int n, int a , int b){
	return (n*n) + (a*n) + b;
}

int generatePrimes(int*primes){
	int count=3;
	for (int prospect=3; prospect<HIGHEST_PRIME ; prospect+=2){
		if ( (canBeExpressedAsPrime(prospect)) && (!divisibleByPrimes(prospect,primes)) ){
			primes[prospect]=prospect;
			count++;
		}
	}
	return count;
}

int canBeExpressedAsPrime(int prospect){
	if (prospect%6 == 5)return 1;
	if (prospect%6 == 1)return 1;
	return 0;
}

int divisibleByPrimes(int prospect,int*primes){
	for (int i=3 ; i<HIGHEST_PRIME ; i+=2){
		if (primes[i]){
			if ((prospect%primes[i])==0)return 1;
			if ( (primes[i] * primes[i]) > prospect )break;
		}
	}
	return 0;
}

int isInArray(int term,int*array){
	for (int i=0; i<HIGHEST_PRIME ; i++)
		if (term==array[i])
			return 1;
	return 0;
}

