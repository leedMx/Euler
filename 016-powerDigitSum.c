//Power Digit Sum, Problem 16 Euler Project
/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?
*/

#include <stdio.h>
#include <time.h>
#define DIGITS 350
#define POWER 1000

int doubleNumber();
int printNumber();
unsigned long sumDigitsInNumber();

int number[DIGITS];
int powerCount=1;

int main(){
	clock_t start=clock();
	
	number[DIGITS-1]=2;	
	for (int i=1; i<POWER ; i++)
		doubleNumber();

	clock_t stop=clock();
	double clocked=stop-start;
	printf("Sum of latest Digits:%ld, time:%f\n",sumDigitsInNumber(),clocked/CLOCKS_PER_SEC);
	printNumber();
	
	return 0;
}


int doubleNumber(){
	int doubled;
	int carry;
	for (int i=1; i<DIGITS ; i++){
		doubled= number[i]*2;
		carry=0;
		if(doubled>=10){
			carry=(doubled-(doubled%10))/10;
			doubled=doubled%10;
		}
		number[i]=doubled;
		number[i-1]+=carry;
	}
	return 0;
}

int printNumber(){
	printf ("Number \t\t");
	for (int i=0;i<DIGITS;i++)
		printf ("%d",number[i]);
	printf ("\n");	
	return 0;
}

unsigned long sumDigitsInNumber(){
	unsigned long result=0;
	for(int i=0; i<DIGITS ; i++)
		result+=number[i];
	return result;
}
