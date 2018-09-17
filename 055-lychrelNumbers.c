//Lychrel numbers, Project Euler Problem 55
/*If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.*/

#include <stdio.h>
#define ITERATIONS 50
#define print(ref) printf(#ref" = %d\n",ref);

int isLychrel(int*,int);
int sumReverse(int*,int);
int isPalindrome(int*,int);

void fillDigits(int*,int,int);
void clearArray(int*);
int length(int);
int lastDigit(int);

int main(){
	int digitsArray[ITERATIONS],digits;
	
	int prospect = 0, solution = 0;

	for (prospect = 1 ; prospect <= 10000 ; prospect++){
		digits = length(prospect);
		fillDigits(digitsArray, prospect, digits);
		if( isLychrel(digitsArray, digits) ) solution ++;
		clearArray(digitsArray);
	}
	
	print(solution);
	return 0;
}

int isLychrel(int*array, int digits){
	int resultingDigits;
	for (int i = 1 ; i <= ITERATIONS; i++){
		resultingDigits = sumReverse(array, digits);
		if ( isPalindrome(array, resultingDigits) )	return 0;
		digits = resultingDigits;
	}
	return 1;
}

int sumReverse(int*array, int digits){
	int reverseArray[ITERATIONS]={0}, newDigit ,resultingDigits = digits;
	int lastDigit = ITERATIONS-1;

	for ( int i = 0 ; i < digits ; i++ )
		reverseArray[i] = array[ITERATIONS-digits+i];

	for ( int i = 0 ; i < digits ; i++ ){
		newDigit = array[ lastDigit-i ] + reverseArray[i];
		if ( newDigit > 9 ){
			array [ lastDigit-i ] = newDigit%10;
			array [ lastDigit-i-1 ] += newDigit/10;
		}else{
			array [ lastDigit-i ] = newDigit;
		}
		if ( i == (digits-1) && array[ lastDigit-i-1 ] )
			resultingDigits++;
	}
	
	return resultingDigits;
}

int isPalindrome(int*array, int digits){
	int lastDigit = ITERATIONS - 1;
	int firstDigit = ITERATIONS - digits;
	
	while ( firstDigit <= lastDigit ){
		if ( array[firstDigit] != array[lastDigit] ) return 0;
		firstDigit++;
		lastDigit--;
	}
	return 1;
}

void fillDigits(int*array, int number, int digits){
	for (int i = 1 ; i <= digits ; i++){
		array[ ITERATIONS-i ] = lastDigit( number );
		number /= 10;
	}
}

void clearArray(int*array){
	for (int i = 0 ; i<ITERATIONS ; i++)
		array[i] = 0;
}

int length(int number){
	int length = 0;
	while (number){
		length++;
		number /= 10;
	}
	return length;
}

int lastDigit(int number){
	if (number < 10) return number;
	return number%10;
}
