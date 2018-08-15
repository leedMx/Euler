//Digit Fifth Power, Project Euler Problem 30
/*

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.*/

#include <stdio.h>
#define POWER 5

int power(int,int);
int getNthDigit(int,int);

int main(){
	int poweredDigits[10];
	int sum=0;
	int sumTotals=0;
	int upperLimit=0;

	for (int i=0; i<10 ; i++){
		poweredDigits[i]=power(i,POWER);
	}
	
	upperLimit=poweredDigits[9]*6;

	for (int number=2 ; number <= upperLimit ; number++){
		
		for (int i=1; i<=7 ; i++){
			sum+=poweredDigits[getNthDigit(number,i)];
		}
		if (sum==number){
			sumTotals+=sum;
		}
		sum=0;

	}
	printf("Total Sum= %d \n",sumTotals);

	return 0;
}

int power(int base, int power){
	int result=1;
	while(power>0){
		result*=base;
		power--;
	}
	return result;
}

int getNthDigit(int number,int digit){
	int powerOfTen=1;
	while (digit>0){
		powerOfTen*=10;
		digit--;
	}
	return  (number%powerOfTen)/(powerOfTen/10);
}
