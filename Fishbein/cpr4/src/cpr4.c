/*
 ============================================================================
 Name        : cpr4.c
 Author      : anna
 Version     :
 Copyright   : -
 Description : sorting and output of array by 2 traverse
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 99
#define ARRAY_SIZE 16

void printOrder(int *arr, int amount) {
	int arr0[MAX_VALUE + 1];
	for (int i = 0; i <= MAX_VALUE; i++)
		arr0[i] = 0;
	for (int i = 0; i < amount; i++)
		arr0[*(arr + i)]++;
	for (int i = 0; i <= MAX_VALUE; i++)
		for (int j = 1; j <= arr0[i]; j++)
			printf("%i ", i);
}

int main(int argc, char *argv[]) {
	int arr[ARRAY_SIZE] = {1, 3, 4, 3, 8, 12, 21, 8, 3, 19, 52, 0, 7, 31, 99, 29};
	printOrder(arr, ARRAY_SIZE);
	return EXIT_SUCCESS;
}
