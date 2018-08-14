//Euler Project Problem 4
/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
#include <stdio.h>
#define LOWEST 101
#define HIGHEST 999

int pickMax(int new,int current);
int findPalindrome(int number);
int compareDigits(int number, int a, int b);
int getNthDigit(int number, int n);

int main (){
	int max=0;

	for (int i=LOWEST; i<=HIGHEST; i++)
		for(int j=LOWEST; j<=HIGHEST; j++)
			max=pickMax(findPalindrome(i*j),max);
	
	printf("Maximum Palindrome Found: %d\n",max);
	return 0;
}

int pickMax(int new,int current){
	if (new>=current)
		return new;
	return current;
}

int findPalindrome(int number){
	if(compareDigits(number,1,6)
	&&compareDigits(number,2,5)
	&&compareDigits(number,3,4))
		return number;
	return 0;
}

int compareDigits(int number,int a, int b){
	if (getNthDigit(number,a)==getNthDigit(number,b))
		return 1;
	return 0;
}

int getNthDigit(int number,int n){
	int i=1;
	for ( ;n>0;n--)
	i=i*10;
	return (number%i)/(i/10);
}
