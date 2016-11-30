/*
 ============================================================================
 Name        : cpr10.c
 Author      : anna
 Version     :
 Copyright   : -
 Description : comparision if-else and switch, for and while
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * to compare if-else and switch operators
 */
void compareIfElseAndSwitch() {
	int n = 0, n0 = 0;
	printf("Enter a number\n");
	fflush(stdout);
	scanf_s("%d", &n, 2);
	n0 = n;
	if (n == 0) {
		n0 += 1;
	} else if (n == 1) {
		n0 += 2;
	} else if (n == 2) {
		n0 += 3;
	} else if (n == 3) {
		n0 += 4;
	} else if (n == 4) {
		n0 += 5;
	} else if (n == 5) {
		n0 += 6;
	} else {
		n0 += 7;
	}
	printf("Result 1: %d\n", n0);
	fflush(stdout);

	n0 = n;
	switch (n) {
		case 0:
			n0 += 1;
			break;
		case 1:
			n0 += 2;
			break;
		case 2:
			n0 += 3;
			break;
		case 3:
			n0 += 4;
			break;
		case 4:
			n0 += 5;
			break;
		case 5:
			n0 += 6;
			break;
		default:
			n0 += 7;
			break;
	}
	printf("Result 2: %d\n", n0);
	fflush(stdout);
}

/*
 * to compare for and while operators
 */
void compareForAndWhile() {
	int n = 0, n0 = 0, i = 0;
	printf("Enter a number\n");
	fflush(stdout);
	scanf_s("%d", &n, 2);
	for (i = 0; i < n; i++) {
		n0 += i;
	}
	printf("Result 1: %d\n", n0);
	fflush(stdout);

	n0 = i = 0;
	while (i < n) {
		n0 += i;
		i++;
	}
	printf("Result 2: %d\n", n0);
	fflush(stdout);
}

/*
 * main function, call compareIfElseAndSwitch and compareForAndWhile
 */
int main(void) {
	compareIfElseAndSwitch();
	compareForAndWhile();

	return EXIT_SUCCESS;
}
