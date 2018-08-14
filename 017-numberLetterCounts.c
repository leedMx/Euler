//Number Letter Counts, Project Euler Problem 17
/* 
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <stdio.h>
#define LIMIT 1000
#define VERBOSE 1 

int composeNameFor(int);
int getNthCharacter(int, int);
int printAndCount(char*);
int hundredsName(int, int, int);
int tensName(int);
int unitsName(int);
int specialTeenName(int);

int totalCharCount;

int main(){

	for (int i=1;i<=LIMIT;i++)
		composeNameFor(i);
	printf("Total char count= %d\n",totalCharCount);

return 0;
}

int composeNameFor(int number){
	int units=getNthCharacter(number,1);
	int tens=getNthCharacter(number,2);
	int hundreds=getNthCharacter(number,3);
	
	hundredsName(hundreds,tens,units);
	if (tens==1){
		specialTeenName(units);
	}else{
		tensName(tens);
		unitsName(units);
	}

	if(number==LIMIT){
		printAndCount("one thousand");

	}

	if(VERBOSE)printf("\n");
	return 0;
}

int getNthCharacter(int number,int n){
	int i=1;
	while(n>0){
		i=i*10;
		n--;}
	return (number%i)/(i/10);
}

int hundredsName(int hundreds,int tens,int units){
	if (hundreds){
		unitsName(hundreds);
		printAndCount(" hundred");
		if(units||tens)
			printAndCount(" and ");
	}
	return 0;
}

int tensName(int number){
	char *nameArray[10]={"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
	printAndCount(nameArray[number]);
	return 0;
}

int unitsName(int number){
	char *nameArray[10]={"","one","two","three","four","five","six","seven","eight","nine"};
	printAndCount(nameArray[number]);
	return 1;
}

int specialTeenName(int number){
	switch (number){
		case 0:	printAndCount("ten"); break;
		case 1:	printAndCount("eleven"); break;
		case 2:	printAndCount("twelve"); break;
		case 3:	printAndCount("thirteen"); break;
		case 4:	printAndCount("fourteen"); break;
		case 5:	printAndCount("fifteen"); break;
		case 6:	printAndCount("sixteen"); break;
		case 7:	printAndCount("seventeen"); break;
		case 8:	printAndCount("eighteen"); break;
		case 9:	printAndCount("nineteen"); break;
	}
	return 0;
}
int printAndCount(char* text){
	int i=0;

	while (text[i]!=0){
		if (text[i]!=32)
		totalCharCount++;	
		i++;
		}

	if(VERBOSE) printf ("%s",text);
	return 0;
}
