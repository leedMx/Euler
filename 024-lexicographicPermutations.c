//Lexicographic Permutations, Project Euler Problem 24
/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? */

#include <stdio.h>
#define TARGET 1000000 

int permute(char*,int);
int indent(int);

int available[10]={1,1,1,1,1,1,1,1,1,1};
int iteration=0;

int main(){
	char selected[10]={0};
	permute(selected,0);
}

int permute(char selectedSoFar[],int position){
//	indent(position);
//	printf("permute(%s, %d)\n",selectedSoFar,position);

	if (position==10){
		iteration++;
		if(iteration==TARGET) printf ("iteration %3d: %s\n",iteration, selectedSoFar);

	}else{
		for (int i=0 ; i<10 ; i++){
			if (available[i]==1){
				available[i]=0;
				selectedSoFar[position]=i+'0';
				permute(selectedSoFar,position+1);
				selectedSoFar[position]='\0';
				available[i]=1;
			}
		}
	}	
	return 0;
}

int indent(int level){
	while (level>0){
		printf("  ");
		level--;
	}
	return 0;
}
