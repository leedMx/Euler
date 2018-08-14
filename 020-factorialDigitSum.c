//Factorial Digit Sum
/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100! */

#include <stdio.h>
#define MAX_DIGITS 300
#define TARGET 100

int initializeResultSpace();
int printDigits(int);
int factorial(int);
int multiplyBy(int);
int writeSingleDigitAndReturnCarry(int, int);
int updateSize();
unsigned long long sumDigitsInResult();

int resultInReverse[MAX_DIGITS];
int resultSize=1;

int main (){
	
	initializeResultSpace();
	factorial(TARGET);
	printDigits(resultSize);
	printf("The sum of all the digits for %d! is %lld\n",TARGET,sumDigitsInResult());
	return 0;
}


int initializeResultSpace(){
	resultInReverse[0]=1;
	for (int i=1;i<MAX_DIGITS;i++)
		resultInReverse[i]=0;
	return 0;
}

int factorial(int n){
	for(int i=2; i<=n ; i++){
		multiplyBy(i);
	}
	return 0;
}

int printDigits(int count){
	printf("printing %d digits: \n",count);
	for(int i=count-1; i>=0; i--){
		printf("%d",resultInReverse[i]);
	}
	printf("\n");
	return 0;
}

int multiplyBy(int number){
	int carry=0,newDigit=0;

	for (int position=0; (newDigit!=0)||(position<resultSize) ; position++){
		newDigit=(resultInReverse[position]*number)+carry;
		carry=writeSingleDigitAndReturnCarry(newDigit,position);
		updateSize(position);
	}
	
	return 0;	
}

int writeSingleDigitAndReturnCarry(int number, int position){
	if(number<10){
		resultInReverse[position]=number;
		return 0;
	}
	resultInReverse[position]=number%10;
	return (int)number/10;
}

int updateSize(int position){
	if (position>MAX_DIGITS){
		printf("Warning: Max Digits overflow, results may not be accurate or system may crash\n");
		printf("Please recompile with a larger MAX_DIGITS\n");
	}
	if (position>resultSize)
		resultSize=position;
	return 0;
}

unsigned long long sumDigitsInResult(){
	unsigned long long sum=0;
	for (int i=0;i<resultSize;i++)
		sum+=resultInReverse[i];
	return sum;
}
