//Number Scores, Project Euler problem 22
/*
Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <stdio.h>
#define NUM_OF_NAMES 5200
#define NAME_SIZE 20

int readNames(int);
int readName(int);

int sortNames(int,int);
int quickSort(int,int);
int lessThan(int,int);
int swapPlaces(int,int);

long calculateScoreFor(int);

int printNames();

char names[NUM_OF_NAMES][NAME_SIZE];
char nameHolder[NAME_SIZE];
int actualNames;

int main (){
	long total=0;

	readNames(NUM_OF_NAMES);
	sortNames(0,actualNames-1);
	
	int test=938;
	printf("score for position %dth, names[%d]=%s, is: %ld\n",test,test-1,names[test-1],calculateScoreFor(test-1));
	
	for (int i=0; i<=actualNames ; i++){
		total+=calculateScoreFor(i);
	}
		
	
	printf("Total sum of Scores: %ld\n",total);

	return 0;
}

int readNames(int qty){
	int namesQty=1;
	for ( int i=0 ; i<qty ; i++ ){
		if (readName(i)==EOF){
			actualNames=namesQty;
			return 0;
		}
		namesQty++;
	}
	
	return 0;
}

int readName(int target){
	char c;

	for ( int i=0 ; i<NAME_SIZE ; i++ ){
		c=getchar();
		if ( (c=='\"') || (c==32) )
			c=getchar();
		if (c==',')
			return 0;
		if (c==EOF)
			return EOF;
		names[target][i]=c;
	}
	
	return 0;
}

int sortNames(int lowerBound,int higherBound){
	int partition;
	if(lowerBound<higherBound){
			partition=quickSort(lowerBound,higherBound);
			
			sortNames(lowerBound,partition-1);
			sortNames(partition+1,higherBound);
		}
	return 0;
}

int quickSort(int lowerBound, int higherBound){
	int wall=lowerBound;
	int pivot=higherBound;

	for (int current=lowerBound; current<=higherBound ; current++){
		if (lessThan(current,pivot)){
			swapPlaces(current,wall);
			wall++;
		}
	}
	swapPlaces(wall,pivot);
	
	return wall;
}

int lessThan (int prospectA, int prospectB){
	int i=0;
	if (prospectA==prospectB) return 0;

	int a=(int)names[prospectA][0];
	int b=(int)names[prospectB][0];


	while ( a==b ){
		i++;
		a=(int)names[prospectA][i];
		if (a==0) return 1;
		b=(int)names[prospectB][i];
	}	
	
	return a<b;
}


int swapPlaces(int a, int b){
	if (a==b)return 0;

	for(int i=0 ; i < NAME_SIZE ; i++)
		nameHolder[i]=names[a][i];
	for(int i=0 ; i < NAME_SIZE ; i++)
		names[a][i]=names[b][i];
	for(int i=0 ; i < NAME_SIZE ; i++)
		names[b][i]=nameHolder[i];
	return 0;
}

int printNames(){
	for ( int i=0 ; i< actualNames ; i++ ){
		if(names[i])printf("%s\n",names[i]);
	}
	printf("\n");
	return 0;
}

long calculateScoreFor(int target){
	long sum=0;
	int letter;
	for( int i=0; i<NAME_SIZE ; i++){
		letter=names[target][i];
		if ((letter>='A') && (letter<='Z'))
			sum+=(letter-64);
	}
	return sum*(target+1);
}
