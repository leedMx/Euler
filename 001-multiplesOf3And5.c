//Primer problema de project Euler
/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <stdio.h>

int xEsMultiploDeN(int x,int N);
int imprimirDosColumnas(int i,int total);

int main(){
	int total=0;
	printf("iteracion:\t\tTotal:\n");
	
	for (int i=1; i<1000; i++)
	if(xEsMultiploDeN(i,3)||xEsMultiploDeN(i,5)){
		total=total+i;
		imprimirDosColumnas(i,total);}
	return 0;
}

int xEsMultiploDeN(int x,int N){
	if (x%N==0)
		return 1;
	return 0;
}

int imprimirDosColumnas(int a,int b){
	printf("%d\t\t\t%d\n",a,b);
	return 0;
}
