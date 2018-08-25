//Chapernowne's Constant, Project Euler
/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the nth digit of the fractional part, find the value of the following expression.

d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000 */

#include <stdio.h>
#define print(ref) printf(#ref"=%d\n",ref);

int digitAtPosition(int);
int getNthDigit(int,int);
int length(int);

int main(){
	int result=1;

	for(int i=1 ; i<=1000000; i*=10){
		print(i)
		print(digitAtPosition(i))
		result*=digitAtPosition(i);
	}
	print(result);

	return 0;
}

int digitAtPosition(int position){
	if (position<10) return position;
	int offset, numbersWithinOffset, numberWithResult, digitNumber;

	int	numberLength=1;
	int lengthStartPosition=0;
	int lengthStartingNumber=1;
	int numbersThisLength=9;
	int lengthEndPosition=9;

	while (position > lengthEndPosition){
		numberLength++;
		lengthStartPosition= lengthEndPosition+1;
		lengthStartingNumber+= numbersThisLength;
		numbersThisLength*= 10;
		lengthEndPosition+= numbersThisLength * numberLength;
	}

	offset = position - lengthStartPosition;
	numbersWithinOffset = offset / numberLength;
	numberWithResult = lengthStartingNumber + numbersWithinOffset;
	digitNumber = (offset%numberLength)+1 ;

	return getNthDigit(numberWithResult,digitNumber);
}

int getNthDigit(int number,int digit){
	int len=length(number);
	
	while (len>digit){
		number/=10;
		len--;
	}

	if (number<10)return number;

	return number%10;
}

int length(int number){
	int result=0;
	while (number){
		number/=10;
		result++;
	}
	return result;
}
