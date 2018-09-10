//Permuted Multiples, Euler Project Problem 52
/*
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits. */
#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);

int shareDigits(int, int);
int countDigits(int*, int);
int lastDigit(int);

int main(){
	int solution = 0;
	
	for (int x = 0 ; !solution ; x++)
		if ( shareDigits(x,2*x) &&
		     shareDigits(x,3*x) &&
		     shareDigits(x,4*x) &&
		     shareDigits(x,5*x) &&
		     shareDigits(x,6*x) )
			solution = x;

	print(solution)

	return 0;
}

int shareDigits(int num1, int num2){
	int digits1[10]={0};
	int digits2[10]={0};
	
	if( countDigits(digits1,num1) != countDigits(digits2,num2) )return 0;

	for (int i = 0; i < 10 ; i++)
		if ( digits1[i] != digits2[i]) return 0;

	return 1;
}

int countDigits(int*digits,int number){
	int length = 0;
	while( number ){
		digits[lastDigit(number)]++;
		number /= 10;
		length++;
	}
	return length;
}

int lastDigit(int number){
	if( number < 10 ) return number;
	return number%10;
}
