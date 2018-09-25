//XOR Decryption, Project Euler Problem 59
/*
Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text. */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define DATA "059-xorDecryption.txt"
#define ARRAY_SIZE 1205
void decipher(int*,int,int,int,int*);
void splitNthLettersIntoArray(int*,int,int*);
int mostFrequentChar(int*);
int readIntoArray(int*,FILE*);
int readNumber(FILE*);

int finished;
int readChars;

int main(){
	FILE *file = fopen(DATA,"r");
	int cipheredText[ARRAY_SIZE] = {0};
	int decipheredText[ARRAY_SIZE] = {0};
	int solution = 0;
	readChars = readIntoArray(cipheredText, file);
	
	int sameKeyLetters[ARRAY_SIZE/3] = {0};

	splitNthLettersIntoArray(cipheredText,0,sameKeyLetters);
	int keyA = mostFrequentChar(sameKeyLetters) ^ 32;
	splitNthLettersIntoArray(cipheredText,1,sameKeyLetters);
	int keyB = mostFrequentChar(sameKeyLetters) ^ 32;
	splitNthLettersIntoArray(cipheredText,2,sameKeyLetters);
	int keyC = mostFrequentChar(sameKeyLetters) ^ 32;
	
	decipher(cipheredText, keyA, keyB, keyC, decipheredText);
	
	for (int i = 0 ; i < readChars-1 ; i++){
		printf("%c", decipheredText[i]);
		solution += decipheredText[i];
	}
	printf("\n");

	print(solution);

	return 0;
}

void decipher(int*array, int A, int B, int C, int*target){
	for (int i = 0 ; i < readChars-1 ; i++){
		if ( i%3 == 0 ) target[i] = array[i]^A;
		if ( i%3 == 1 ) target[i] = array[i]^B;
		if ( i%3 == 2 ) target[i] = array[i]^C;
	}
}

void splitNthLettersIntoArray(int*originArray,int index,int*targetArray){
	for (int i = index, j = 0; i < readChars ; j++, i+=3)
		targetArray[j] = originArray[i];
}

int mostFrequentChar(int*array){
	int charCount[255] = {0};
	int character = 0;
	for (int i = 0 ; i < ARRAY_SIZE/3 ; i++){
		character = array[i];
		charCount[character]++;
	}
	
	int highestCount = 0;
	int mostFrequent = 0;
	for (int i = 0 ; i < 255 ; i++){
		if ( charCount[i] > highestCount ){
			highestCount = charCount[i];
			mostFrequent = i;
		}
	}
	return mostFrequent;
}

int readIntoArray(int*array,FILE*data){
	int charNumber = readNumber(data);
	int count = 0;
	for (int i = 0  ; charNumber != EOF ; i++){
		array[i] = charNumber;
		charNumber = readNumber(data);
		count++;
	}
	return count;
}

int readNumber(FILE*data){
	if ( finished ) return EOF;
	int number = 0;
	char character = getc(data);
	while ( character != 44 && character != '\n' && character != EOF){
		number *= 10;
		character -= '0';
		number += character;
		character = getc(data);
	}
	if ( character == EOF){
		finished++;
		return number;
	}
	return number;
}
