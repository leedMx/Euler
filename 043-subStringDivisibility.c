//Sub-String Divisibility
/*

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on. In this way, we note the following:

d_2d_3d_4=406 is divisible by 2
d_3d_4d_5=063 is divisible by 3
d_4d_5d_6=635 is divisible by 5
d_5d_6d_7=357 is divisible by 7
d_6d_7d_8=572 is divisible by 11
d_7d_8d_9=728 is divisible by 13
d_8d_9d_10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.*/

#include <stdio.h>
#define printl(ref) printf(#ref"=%ld\n",ref);
#define print(ref) printf(#ref"=%d\n",ref);

int permutePandigitals(int);
int permuteHelper(long,int*,int);
int desiredSubString(long,int);
int subString(long, int, int);
int getNthDigit(long, int);
int length(long);

int primes[8]={2,3,5,7,11,13,17};
long result;

int main(){
	permutePandigitals(10);
	printl(result)
	return 0;
}

int permutePandigitals(int digits){
	int available[digits];
	for (int i = 0 ; i < digits ; i++)
		available[i]=1;

	permuteHelper(0, available, 0);

	return 0;
}

int permuteHelper(long numberSoFar, int*available, int choicesMade){
	if (choicesMade && numberSoFar==0) return 0;
	
	if (choicesMade>=4)
		if(desiredSubString(numberSoFar,choicesMade)==0)return 0;

	if (choicesMade==10){
		printl(numberSoFar)
		result+=numberSoFar;
	}else{
		for (int i=0; i<10 ; i++){
			if (available[i]){
				numberSoFar*=10;
				numberSoFar+=i;
				available[i]=0;

				permuteHelper(numberSoFar, available, choicesMade+1);

				available[i]=1;
				numberSoFar-=i;
				numberSoFar/=10;
			}
		}
	}
	return 0;
}

int desiredSubString(long number, int digits){
	if (subString(number,digits-2,digits)%primes[digits-4])
		return 0;
	return 1;
}

int subString(long number, int startDigit, int endDigit){
	int result=0;
	while(startDigit<=endDigit){
		result*=10;
		result+=getNthDigit(number,startDigit++);
	}
	return result;
}

int getNthDigit(long number, int digit){
	int len=length(number);
	while (len>digit){
		number/=10;
		len--;
	}
	if (number<10)return number;
	return number%10;
}

int length(long number){
	int result=0;
	while (number){
		number/=10;
		result++;
	}
	return result;
}
