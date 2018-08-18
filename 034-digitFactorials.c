//Digit Factorials, project Euler Problem 34
/* 145 is a curious number, as 1!+4!+5!= 1+24+120 = 145.
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: as 1! and 2! are not sums they are not included. */

#include <stdio.h>

int factorial(int);
int length(int);
int getNthDigit(int,int);

int factorials[10]={0};

int main(){
	int sum=0;
	int totalSum=0;
	int limit;	

	for (int i=0 ; i<10 ; i++){
		factorials[i]=factorial(i);
	}

	for (int number=3 ; number < 999999 ; number++){
		limit=length(number);
		for (int digit=1 ; digit <= limit ; digit++){
			sum+=factorials[getNthDigit(number,digit)];
		}
		if (sum == number){
			printf("digits of %d sum %d\n",number,sum);
			totalSum+=sum;
		}
		sum=0;
	}
	
	printf("Total sum of numbers equal to the sum of the factorial of their digits= %d\n",totalSum);
	return 0;
}

int factorial(int number){
	if (number==0){
		return 1;
	}else{
		return number*factorial(number-1);
	}
}

int length(int number){
	int result=1;
	while (number/10>0){
		number/=10;
		result++;
	}
	return result;
}

int getNthDigit(int number, int digit){
	int powerOfTen=1;
	while(digit>0){
		powerOfTen*=10;
		digit--;
	}
	return (number%powerOfTen)/(powerOfTen/10);
}
