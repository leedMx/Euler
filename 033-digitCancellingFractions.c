//Digit Cancelling Fractions, Euler Project Problem 33
/*The fraction 49/98 is a curious fraction, as an inecperienced mathematician in attempting to simplify it may incorrectly believe that 49/98=4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like 30/50=3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator. */

#include <stdio.h>

int nonTrivialDigitCancellingFractions();
int containsDigit(int,int);
double removeDigit(int,int);

int numeratorsProduct=1;
int denominatorsProduct=1;

int main(){

	nonTrivialDigitCancellingFractions();
	printf("Product= %d/%d \n",numeratorsProduct,denominatorsProduct);

	return 0;
}

int nonTrivialDigitCancellingFractions(){
	double ammendedDenominator;
	double ammendedNumerator;
	
	for (int digit=1; digit<=9 ; digit++){
		for (int denominator=11 ; denominator<100 ; denominator++){
			for (int numerator=denominator-1 ; numerator>10 ; numerator--){
				if(containsDigit(digit,denominator) && containsDigit(digit,numerator)){

					ammendedDenominator=removeDigit(digit,denominator);
					ammendedNumerator=numerator/(denominator/ammendedDenominator);

					if (removeDigit(digit,numerator)==ammendedNumerator){
						printf("%d/%d",numerator,denominator);
						printf(" = %.0f/%.0f",ammendedNumerator,ammendedDenominator);
						printf("\n");
						numeratorsProduct*=(int)ammendedNumerator;
						denominatorsProduct*=(int)ammendedDenominator;
					}
				}
			}
		}
	}
	return 0;
}

int containsDigit(int digit,int target){
	if (target/10==digit)return 1;
	if (target%10==digit)return 1;
	return 0;
}

double removeDigit(int digit,int target){
	int units=target%10;
	int tens=target/10;

	if (units==digit){
		target-=units;
		return target/10;
	}
	return target-(tens*10);
}
