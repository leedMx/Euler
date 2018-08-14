//Special Pythagorean Triplet, Euler project problem 9
/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <stdio.h>
#include <math.h>
#define TARGET_TRIPLET_SUM 1000

int attemptUsingThisA(int a);
int solveForC(int a,int b);
int saveResults(int a,int b,int c);

int foundA=0;
int foundB=0;
int foundC=0;

int main (){
	for (int i=2;foundA==0;i++){
	if(attemptUsingThisA(i)){
		printf("Solution Found %d^2 + %d^2 = %d^2 ,\n",foundA,foundB,foundC);
		printf("and %d+%d+%d=%d\n",foundA,foundB,foundC,TARGET_TRIPLET_SUM);
		printf("abc = %d\n",foundA*foundB*foundC);
		return 0;}
	}
	return 0;
}

int attemptUsingThisA(int a){
	int sum=0;
	
	for (int b=a+1;sum<TARGET_TRIPLET_SUM;b++){
		solveForC(a,b);
		sum=a+b+foundC;		
		if((sum==TARGET_TRIPLET_SUM)&&(foundC!=0)){
			saveResults(a,b,foundC);
			return 1;}
	}
	return 0;
}

int solveForC(int a,int b){
	double c=0,c2=(a*a)+(b*b);
	c=sqrt(c2);
	if(c2==(((int)c)*((int)c))){
		foundC=(int)c;
		return (int)c;}
	foundC=0;	
	return 0;
}

int saveResults(int a,int b,int c){
	foundA=a;
	foundB=b;
	foundC=c;
	return 1;
}
