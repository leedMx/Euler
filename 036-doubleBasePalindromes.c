//Double Base Palindromes, Euler Project Problem 36
/* The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
Find the sum of all numbers,less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number in either base, may not include leading zeros.) */

#include <stdio.h>

#define UPPER_LIMIT 1000000
#define dprint(ref) printf(#ref" = %d\n",ref);

int checkPalindromeBothBases(int);
int numberToDigits(int,int,int*);
int isPalindrome(int*,int);

int main(){	
	int result=0;
	
	for(int i=1; i<=UPPER_LIMIT ; i++)
		result+=checkPalindromeBothBases(i);
	
	dprint(result)
	return 0;
}

int checkPalindromeBothBases(int number){
	int digitsArray[20]={0};
	int digits;

	digits = numberToDigits(number,10,digitsArray);
	if(isPalindrome(digitsArray,digits)){
		digits = numberToDigits(number,2,digitsArray);
	}
	return isPalindrome(digitsArray,digits);
}

int numberToDigits(int number,int base,int*array){
	int position=0;
	while(number){
		if (number<base){
			array[position]=number;
			break;
		}
		array[position]=number%base;
		number/=base;
		position++;
	}
	return position+1;
}

int toBinary(int number,int*array){
	int position=0;
	while(number){
		if (number==1 || number==0){
			array[position]=number;
			break;
		}
		array[position]=number%2;
		number/=2;
		position++;
	}
	return position+1;
}

int isPalindrome(int*array,int digits){
	for(int first=0,last=digits-1; first<=last ; first++,last--){
		if(array[first]!=array[last])
			return 0;
	}
	return 1;
}
