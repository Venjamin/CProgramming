#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int arrLength = 15;		//Задаем длину исходного массива							
	//значения элементов массива задаются рандомно числами из промежутка [a,b]
	const int a = 0;
	const int b = 99;
	const int n = b + 1;
	int* arr99 = malloc(n * sizeof(int));
	int* arr = malloc(arrLength * sizeof(int));
	for (int i = 0; i < arrLength; i++) {
		arr[i] = a + rand() % (b - a);
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i<n; i++) {
		arr99[i] = 0;
	}
	for (int i = 0; i <arrLength; i++) {
		arr99[arr[i]] = arr99[arr[i]] + 1;
	}
	for (int i = 0; i<n; i++) {
		if (arr99[i] != 0) {
			for (int j = 0; j < arr99[i]; j++) {
				printf("%d ", i);
			}
		}
	}
	free(arr99);
	free(arr);
	getchar();
	return 0;

}
