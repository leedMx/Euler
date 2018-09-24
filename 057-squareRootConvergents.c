//Square root convergents, Euler Project problem 57
/*
It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator? */

#include <stdio.h>
#define ARRAY_SIZE 400
#define print(ref) printf(#ref" = %d\n",ref);

void nextNumerator();
void nextDenominator();
void sumArray(int*,int*);
void copyArray(int*,int*);
int digits(int*);

int numerator[ARRAY_SIZE] = {3};
int denominator[ARRAY_SIZE] = {2};
int previousDenominator[ARRAY_SIZE] = {1};

int main (){
	int solution = 0;

	for(int i = 1 ; i <= 1000 ; i++ ){
		nextNumerator();
		nextDenominator();

		solution += digits(numerator) > digits(denominator);
	}
	
	print(solution);

	return 0;
}

void nextNumerator(){
	sumArray(numerator,denominator);
	sumArray(numerator,denominator);
}

void nextDenominator(){
	int temp[ARRAY_SIZE] = {0};
	copyArray(temp,denominator);
	sumArray(denominator,denominator);
	sumArray(denominator,previousDenominator);
	copyArray(previousDenominator,temp);
}

void sumArray(int*array,int*summand){
	int carry[ARRAY_SIZE] = {0};
	int sum;
	for (int i = 0; i < ARRAY_SIZE ; i++){
		sum = array[i] + summand[i] + carry[i];
		if (sum > 9){
			array[i] = sum%10;
			carry[i+1] += sum/10;
		}else{
			array[i] = sum;
		}
	}
}

void copyArray(int*target,int*origin){
	for (int i = 0; i < ARRAY_SIZE ; i++)
		target[i] = origin[i];
}

int digits(int*array){
	int i = ARRAY_SIZE - 1;
	while ( !array[i] ){
		i--;
	}
	return i+1;
}
