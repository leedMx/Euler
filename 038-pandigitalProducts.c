//Pandigital Products, Euler Project problem 38
/*
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1? */

#include <stdio.h>
#define printl(ref) printf(#ref"=%ld\n",ref);

long concatenatedProduct(long);
long concatenate(long,long);
int isPandigital(long);
int length(long);
int lastDigit(long);

int main(){
	long max=0,prospect;

	for (int i=1 ; i<9999 ; i++){
		prospect=concatenatedProduct(i);
		if (isPandigital(prospect))
			if(prospect > max) max=prospect;
	}

	printl(max);

	return 0;
}

long concatenatedProduct(long number){
	long concatenatedProduct=0,product;
	int concatenationLength=0;

	for (int i=1; i<5 ; i++){
	product=number*i;
		if (concatenationLength>9)return 0;

		if (concatenationLength==9){
			return concatenatedProduct;
		}

		concatenatedProduct=concatenate(concatenatedProduct,product);
		concatenationLength+=length(product);
	}

	return 0;
}

int isPandigital(long number){
	int digitsCount[10]={0};

	while(number){
		digitsCount[lastDigit(number)]+=1;
		number/=10;
	}

	for(int i=1; i<=9 ; i++){
		if ((digitsCount[i]==0)||(digitsCount[i]>1))
			return 0;
	}

	return 1;
}

int lastDigit(long number){
	if (number<10) return number;
	return number%10;
}

long concatenate(long number,long suffix){
	int temp=suffix;
	while (temp){
		number*=10;
		temp/=10;
	}
	return number+suffix;
}

int length(long number){
	int result=0;
	while (number){
		result++;
		number/=10;
	}
	return result;
}
