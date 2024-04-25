/* STACK CIPHER CODE (commented out because of conflicting main statements
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	//set variables
	char cipher[100];
	char input[20];
	char type[10];

	//choosing encryption/decryption
	printf("Would you like to Encrypt or Decrypt: ");
	scanf("%s", type);
	for (int i = 0; i < strlen(type); i++) {
		type[i] = toupper(type[i]);
	}

	if (strcmp(type, "ENCRYPT") != 0 && strcmp(type, "DECRYPT") != 0) { //compares strings to determine if input is valid
		printf("Invalid Input");
		return 0;
	}

	//input cipher code (verifies it as well)
	printf("Enter the Cipher: ");
	scanf("%s", cipher);
	FILE* file = fopen(cipher, "r");
	if (file == NULL) {
		printf("The file does not exist");
		return 0;
	}

	int counter = 0; //counter to count # of letters placed in the arrays
	char initialArray[26];
	printf("Initial Array Memory Location: %p\n", &initialArray);
	char replacementArray[26];
	printf("Replacement Array Memory Location: %p\n", &replacementArray);

	//valid cipher - C:\Users\student\source\repos\CipherAssignment\ValidCipher.txt
	//duplicate cipher - C:\Users\student\source\repos\CipherAssignment\DuplicateCipher.txt
	//missing character cipher - C:\Users\student\source\repos\CipherAssignment\MissingCharacterCipher.txt
	//short cipher - C:\Users\student\source\repos\CipherAssignment\ShortCipher.txt

	while(fscanf(file, "%c,%c\n", &initialArray[counter], &replacementArray[counter]) == 2) { //iterates through the cipherfile and places the letters into char arrays
		initialArray[counter] = toupper(initialArray[counter]);
		//printf("%c\n", initialArray[counter]);
		replacementArray[counter] = toupper(replacementArray[counter]);
		//printf("%c\n", replacementArray[counter]);
		for (int j = 0; j < counter; j++) { //checks for duplicates in both arrays
			if (initialArray[j] == toupper(initialArray[counter]) || replacementArray[j] == toupper(replacementArray[counter])) {
				printf("Duplicate Cipher Formatting");
				fclose(file);
				return 0;
			}
		}

		counter++;
		//printf("%d\n", counter);
	}

	if (counter != 26) { //checks for length of file and for missing arguments
		printf("Cipher Formatting is Invalid");
		fclose(file);
		return 0;
	}

	printf("Initial Array Memory Location: %p\n", &initialArray);
	printf("Replacement Array Memory Location: %p\n", &replacementArray);

	fclose(file);
	printf("Enter the Input Text: "); //inputs text that will be converted
	scanf("%s", input);

	for (int k = 0; k < strlen(input); k++) { //converting to ciphertext/plaintext
		input[k] = toupper(input[k]);
		for (int l = 0; l < 26; l++) {
			if (strcmp(type, "ENCRYPT") == 0) { //encrypt
				if (initialArray[l] == input[k]) {
					input[k] = replacementArray[l];
					break;
				}
			}
			else {
				if (replacementArray[l] == input[k]) {
					input[k] = initialArray[l];
					break;
				}
			}
		}
	}

	printf("%s", input);
}
*/