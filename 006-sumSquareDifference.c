//Problem 6 Euler Project
/*
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
#include <stdio.h>
#define NATURAL_NUMBERS_AMOUNT 100

int sumNFirstNaturalNumbersAndThenSquare(int n);
int squareAndSumNFirstNaturalNumbers(int n);

int main(){
	int a=squareAndSumNFirstNaturalNumbers(NATURAL_NUMBERS_AMOUNT);
	int b=sumNFirstNaturalNumbersAndThenSquare(NATURAL_NUMBERS_AMOUNT);
	printf("Difference = %d\n",b-a);
	return 0;
}

int squareAndSumNFirstNaturalNumbers(int n){
	int sum=0;
	for (int i=1 ; i<=n; i++)
		sum=sum+(i*i);
	return sum;
}

int sumNFirstNaturalNumbersAndThenSquare(int n){
	int sum=0;
	for (int i=1; i<=n; i++)
		sum=sum+i;
	return sum*sum;
}
