//Large Sum, Problem 13 Euler Project
/* Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
	(number saved into separate data file to be read trough sdin)
*/

#include <stdio.h>
#define DIGITS 50 

int readNumber();
int addToResult();
int printResult();
int printNumber();

int number[DIGITS];
int result[DIGITS];

int main(){
	
	while (readNumber()!=EOF){
//		printNumber();
		addToResult();
	}
	
	printResult();
	return 0;
}

int readNumber(){
	int newNumber=0;
	for (int i=1; newNumber!=('\n'-'0'); i++){
		newNumber=getchar();
//		printf("%d ",newNumber);
		if (newNumber==EOF)
			return EOF;
		newNumber=newNumber-'0';
		if ( newNumber>=0 && newNumber<=9 )
			number[i-1]=newNumber;
	}
	return 0;
}

int addToResult(){
	int sum;
	for (int i=1; i<=DIGITS ; i++){
		sum=number[DIGITS-i]+result[DIGITS-i];
//		printf("sum= n[%d] +r[%d]= %d+%d=%d\n",DIGITS-i,DIGITS-i,number[DIGITS-i],result[DIGITS-i],sum);
		if ((sum>9)&& (DIGITS-i)>0){
			result[DIGITS-i]= sum-10 ;				
			result[DIGITS-i-1]++;

		}
		else
			result[DIGITS-i]= sum;
	}
	return 0;
}

int printResult(){
	printf ("Resultado \t");
	for (int i=0;i<DIGITS;i++)
		printf ("%d",result[i]);
	printf ("\n");	
	return 0;
}

int printNumber(){
	printf ("Number \t\t");
	for (int i=0;i<DIGITS;i++)
		printf ("%d",number[i]);
	printf ("\n");	
	return 0;
}

