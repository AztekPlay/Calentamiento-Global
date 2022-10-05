#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Declarations
void quicksort(int* arr, size_t len);

void threesort(int* arr);

int median(int a, int b, int c);

void swap(int* a, int* b);

void generateArray(int** arr, size_t* len);


//Main
int main() {

	srand((unsigned int) time(NULL));


	size_t len;
	int* arr = NULL;

	generateArray(&arr, &len);

	if (arr != NULL) {

		for (int i = 0; i<len; i++) {
			printf("%i ", arr[i]);
		}
		printf("\n");

		quicksort(arr, len);

		for (int i=0; i<len; i++) {
			printf("%i ", arr[i]);
		}
		printf("\n");

		free(arr);
	}


	return 0;
}


//Definitions
void quicksort(int* arr, size_t len) {

	if (len == 3) {
		threesort(arr);
	}
	else if (len == 2) {
		if (arr[0] > arr[1]) swap(arr, arr+1);
	}
	else if (len > 3) {

		int anchor = median(arr[0], arr[len-1], arr[(len-1)/2]);

		size_t i = 0;
		size_t j = len-1;

		while (i < j) {
			while (arr[i] < anchor) i++;
			while (arr[j] > anchor) j--;

			if (i < j) {
				swap(arr+i, arr+j);

				i++; j--;
			}
		}

		quicksort(arr, j+1);
		quicksort(arr+i, len-i);
	}
}

void threesort(int* arr) {

	if (arr[0] <= arr[1]) {
		if (arr[2] < arr[0]) {

			swap(arr, arr+1);
			swap(arr, arr+2);
		}
		else if (arr[2] < arr[1]) {

			swap(arr+1, arr+2);
		}
	}
	else {
		if (arr[2] < arr[1]) {

			swap(arr, arr+2);
		}
		else if (arr[2] < arr[0]) {

			swap(arr, arr+1);
			swap(arr+1, arr+2);
		}
		else {

			swap(arr, arr+1);
		}
	}
}

int median(int a, int b, int c) {

	if (a <= b) {
		if (b <= c) return b;
		else if (c <= a) return a;
		else return c;
	}
	else {
		if (a <= c) return a;
		else if (c <= b) return b;
		else return c;
	}
}

void swap(int* a, int* b) {
	
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void generateArray(int** arr, size_t* len) {

	*len = rand()%30;
	*arr = (int*) malloc((*len)*sizeof(int));
	
	if (*arr != NULL) {
		for (size_t i = 0; i<*len; i++) {
			(*arr)[i] = ((rand()%2)*2 - 1)*rand();
		}
	}


}