//Pandigital products, Euler Project Problem 32.
/* We shal say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5 -digit number, 15234, is 1 through 5 pandigital.
The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier, and products is 1 through 9 pandigital.
Find the sumof all products whose multiplicand/multiplier/product identity can be written as a 1 trough 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.*/

#include <stdio.h>

int permuteDigitsRecursively(int*,int*,int);
int existInArray(int,int*);
int sumArray(int*);

int productsFound=0;
int products[10]={0};

int main(){
	int choicesAvailable[9]={1,2,3,4,5,6,7,8,9};
	int chosenDigits[9]={0};

	permuteDigitsRecursively(chosenDigits,choicesAvailable,0);

	printf("Sum of unique products: %d\n",sumArray(products));

	return 0;
}

int permuteDigitsRecursively(int*chosenDigits,int*choicesAvailable,int choicesMade){
	int multiplicand,multiplier,product;
	if (choicesMade==9){
		multiplicand=                                            (chosenDigits[0]*10)+chosenDigits[1];
		multiplier=	                       (chosenDigits[2]*100)+(chosenDigits[3]*10)+chosenDigits[4];
		product=	(chosenDigits[5]*1000)+(chosenDigits[6]*100)+(chosenDigits[7]*10)+chosenDigits[8];
		
		if ((multiplicand*multiplier)==product){
			printf("%d*%d=%d\n",multiplicand,multiplier,product);
			if(!existInArray(product,products)){
				products[productsFound]=product;
				productsFound++;
			}
		}
		return 0;

	}else{
		for (int i=0 ; i < 9 ; i++){
			if (choicesAvailable[i]!=0){
				
				chosenDigits[choicesMade]=choicesAvailable[i];
				choicesAvailable[i]=0;

				permuteDigitsRecursively(chosenDigits,choicesAvailable,choicesMade+1);

				chosenDigits[choicesMade]='\0';
				choicesAvailable[i]=i+1;
			}
		}
	}
	return 0;
}

int existInArray(int value, int*array){
	for (int i=0 ; i < 10 ; i++)
		if(array[i] == value) return 1;
	return 0;
}

int sumArray(int*array){
	int sum=0;
	for (int i=0 ; i < 10 ; i++)
		sum+=array[i];
	return sum;
}

