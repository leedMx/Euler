//Powerful Digit Counts, Euler project Probelm 63
/*
The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.

How many n-digit positive integers exist which are also an nth power?*/

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);

int countSolutionsBase(int);
int length(double);
double power(int,int);

int main(){
	int solution = 0;
	
	for (int base = 1 ; base <= 9 ; base++)
		solution += countSolutionsBase(base);	
	
	print(solution);

	return 0;
}

int countSolutionsBase(int base){
	int solutions = 0;
	for (int exp = 0; exp < 100 ; exp++)
		if ( length(power(base,exp)) == exp )
			solutions++;
	return solutions;
}

int length(double number){
	int result = 0;
	if ( number < 0.0 ) number *= -1.0;

	while ( number > 1){
		result++;
		number /= 10;
	}
	return result + ( number == 1 );
}

double power(int base, int exponent){
	double result = 1;
	while ( exponent ){
		result *= (double)base;
		exponent--;
	}
	return result;
}
