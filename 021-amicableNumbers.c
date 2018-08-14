//Amicable Numbers, Project Euler problem 21
/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.*/

#include <stdio.h>
#include <math.h>
#define UPPER_LIMIT 10000
#define AMICABLES 100

int findAmicable(int);
int sumDivisors(int);
int cropSqrt(int);
int isAlreadyAmicable(int);
int	sumAmicables();

int amicables[AMICABLES];
int numberOfPairs;

int main(){

	for (int i=2 ; i<=UPPER_LIMIT ; i++)
		if (!(isAlreadyAmicable(i)))
			findAmicable(i);

	printf("%d amicables found up to %d, sum = %d\n",numberOfPairs,UPPER_LIMIT,sumAmicables());
	return 0;
}

int sumDivisors(int number){
	int squareRoot=cropSqrt(number),total=1;
	for (int i=2;i<=squareRoot;i++){
		if (number==squareRoot){
			total+=i;
			return total;
		}
		if (number%i==0)
			total+=(i)+(number/i);
	}
	return total;
}

int cropSqrt(int number){
	return (int)sqrt(number);
}

int findAmicable(int number){
	int possibleAmicable;	
	possibleAmicable=sumDivisors(number);
	if (possibleAmicable==number)
		return 0;
	if (sumDivisors(possibleAmicable)==number){
		printf ("number %d is amicable with %d\n",number,possibleAmicable);
		amicables[numberOfPairs*2]=number;
		amicables[(numberOfPairs*2)+1]=possibleAmicable;
		numberOfPairs++;
	}
	return 0;
}

int isAlreadyAmicable(int number){
	for (int i=1 ; i<AMICABLES ; i+=2)
		if (amicables[i]==number)
			return 1;
	return 0;
}

int sumAmicables(){
	int total=0;
	for(int i=0; i<AMICABLES ; i++)
		total+=amicables[i];
	return total;
}
