//Powerful Digit Sum, Euler Project Problem 56
/*
A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^200 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum? */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define ARRAY_SIZE 1000

void powerArray(int,int,int*);
void multiplyArray(int*,int);
void digitTimesArray(int,int*,int*,int);
void addArrays(int*,int*);
int sumDigitsInArray(int*);

void copyArray(int*,int*);
void clearArray(int*);
int lastDigit(int);

int solution = 0;

int main(){
	int digitsArray[ARRAY_SIZE]={4};

	for (int a = 1 ; a <=100 ; a++){
		powerArray(a, 100, digitsArray);
		clearArray(digitsArray);
	}

	print(solution);
	return 0;
}

void powerArray(int base, int exponent, int*array){
	int sum;
	array[0] = 1;
	while( exponent ){
		multiplyArray(array,base);
		sum = sumDigitsInArray(array);
		if (sum > solution) solution = sum;
		exponent--;
	}
}

void multiplyArray(int*array,int multiplier){
	int result[ARRAY_SIZE]={};
	int product[ARRAY_SIZE]={};
	int offset = 0;
	
	while (multiplier){
		digitTimesArray(multiplier,array,product,offset);
		addArrays(result,product);

		clearArray(product);
		offset++;
		multiplier /= 10;
	}

	copyArray(array,result);
}

void digitTimesArray(int multiplier, int*array,int*target,int offset){
	int product, digit = lastDigit(multiplier);
	for (int pos = 0 ; pos < ARRAY_SIZE ; pos++){
		product = digit * array[pos];
		for (int carryOffset=0 ; product ; product /= 10)
			target[offset + pos + carryOffset++] += lastDigit(product);
	}
}

void addArrays(int*target,int*summand){
	int temp[ARRAY_SIZE],sum;
	copyArray(temp,summand);
	for (int i = 0 ; i < ARRAY_SIZE ; i++){
		sum = target[i] + temp[i];
		if ( sum > 9 ){
			temp[i+1] += sum/10;
			target[i] = sum%10;
		}else 
			target[i] = sum;
		
	}
}

void copyArray(int*target, int*origin){
	for (int i = 0 ; i < ARRAY_SIZE ; i++ )
		target[i] = origin [i];
}

int sumDigitsInArray(int*array){
	int sum = 0;
	for (int i = 0 ; i < ARRAY_SIZE ; i++)
		sum += array[i];	
	return sum;
}

void clearArray(int*array){
	for (int i = 0 ; i < ARRAY_SIZE; i++)
		array[i] = 0;
}

int lastDigit(int number){
	if ( number < 10 ) return number;
	return number%10;
}
