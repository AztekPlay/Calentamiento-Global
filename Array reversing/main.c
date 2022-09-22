#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Declarations
int input(int** arr, size_t* count);

void output(int arr[], size_t count);

void reverse(int arr[], size_t count);

int append(int* arr[], size_t* count, int value);

int strToInt(int* value, char str[]);


//Main
int main() {

	size_t count;
	int* arr = NULL;

	int status = input(&arr, &count);
	if (status == 1) {
		printf("Wrong input!\n");

		return 1;
	}
	else if (status == 2) {
		fprintf(stderr, "Allocation error!");

		return 1;
	}

	reverse(arr, count);

	printf("Reversed sequence: ");
	output(arr, count);

	free(arr);

	return 0;
}


//Definitions
int input(int** arr, size_t* count) {
	printf("Enter sequence of integers separated by spaces.\n>>");

	int status = 0;

	*arr = NULL;
	size_t arrSize = 0;

	char str[20];
	int strIndex = 0;
	int strValue;

	int inputChar;

	while (1) {
		inputChar = getchar();

		if ((inputChar == 32) || (inputChar == 10)) {  // char(32) = ' '; char(10) = '\n'	
			if (strIndex == 0) {
				if (inputChar == 32) {
					continue;
				}
				else {
					break;
				}
			}

			str[strIndex] = '\0';
			strIndex = 0;

			if (strToInt(&strValue, str)) {
				status = 1;  // Wrong input!

				free(*arr);
				*arr = NULL;
				break;
			}

			if (append(arr, &arrSize, strValue)) {
				status = 2; //Allocation error!

				free(*arr);
				*arr = NULL;
				break;
			}

			if (inputChar == 10) break;
		}
		else {
			str[strIndex] = inputChar;
			strIndex++;
		}
	}

	*count = arrSize;
	return status;
}

void output(int arr[], size_t count) {

	for (int i=0; i<count; i++) {
		printf("%i ", arr[i]);
	}
	printf("\b.");
}

void reverse(int arr[], size_t count) {

	int temp;

	for (int i=0; i<count/2; i++) {
		temp = arr[i];
		arr[i] = arr[count-i-1];
		arr[count-i-1] = temp;
	}
}

int append(int* arr[], size_t* count, int value) {

	int status = 0;
	int* tmp;

	tmp = (int*) realloc(*arr, ((*count)+1)*sizeof(int));

	if (tmp != NULL) {
		*arr = tmp;
		(*arr)[*count] = value;
		(*count)++;
	}
	else {
		status = 1;
	}

	return status;
}

int strToInt(int* value, char str[]) {

	int status = 0;
	int val;
	char* endStr;

	val = (int) strtol(str, &endStr, 10);
	if (strlen(endStr) == 0) {
		*value = val;
	}
	else {
		status = 1;
	}

	return status;
}