//Coded Triangle Numbers,Project Euler Problem 42

/*The nth term of the sequence of triangle numbers is given by, t_n = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t_10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt a 16K text file containing nearly two-thousand common English words, how many are triangle words? */

#include <stdio.h>
#define print(ref) printf(#ref"=%d\n",ref);
#define printS(ref) printf(#ref"=%s\n",ref);
#define CHARS 15
#define TRIANGLES 100

int populateWithTriangles(int*);
int readWord(char*i,int);
int weightWord(char*i,int);
int clearWord(char*i,int);
int isInArray(int,int,int*);

int EndOfFile=0;

int main(){
	char word[CHARS]="";
	int triangleArray[TRIANGLES]={0};
	int length=0,weight=0, result=0;
	int	triangles=populateWithTriangles(triangleArray);

	while (!EndOfFile){
		length=readWord(word,CHARS);
		weight=weightWord(word,length);
		if (isInArray(weight,triangles,triangleArray)) result++;
		clearWord(word,length);
	}

	print(result)

	return 0;
}

int populateWithTriangles(int*array){
	int triangle=0, n;
	for (n=1 ; triangle < ('Z'*CHARS) ; n++){
		triangle=(int)(n*((n+1)/2.0));
		array[n-1]=triangle;
	}
	return n-1;
}

int readWord(char*word,int size){
	int nextChar;
	for (int numberOfChars=0; numberOfChars<=size ; numberOfChars++){
		nextChar=getchar();
		if (nextChar=='\"') nextChar=getchar();
		if (nextChar==',') return numberOfChars;
		if (nextChar==EOF){
			EndOfFile=1;
			return numberOfChars;
		}
		word[numberOfChars]=nextChar;
	}
	printf("Error, word longer than expected\n");
	return 0;
}

int weightWord(char*word,int size){
	int sum=0;
	for (int i=0 ; i< size ; i++)
		sum+=word[i]-'A'+1;
	return sum;
}

int clearWord(char*word,int size){
	for (int i=0; i < size ; i++)
		word[i]=0;
	return 0;
}

int isInArray(int value, int maxIndex, int*array){
	for(int i=0; i < maxIndex ; i++)
		if (value==array[i]) return 1;
	return 0; 
}
