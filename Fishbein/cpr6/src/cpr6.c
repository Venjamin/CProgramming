/*
 ============================================================================
 Name        : cpr6.c
 Author      : anna
 Version     :
 Copyright   : -
 Description : adding 2 float numbers without using float types
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 12
#define MAX_ABS 999999999


long getPow10(int power) {
	long mul = 1;
	for (int i = 0; i < power; i++) {
		mul *= 10;
	}
	return mul;
}


void addFloats() {
	long before1, after1, before2, after2;
	char sBefore1[LEN_STR], sBefore2[LEN_STR], sAfter1[LEN_STR], sAfter2[LEN_STR];
	printf("Enter a first part of first number\n");
	scanf("%s", sBefore1);
	printf("Enter a second part of first number\n");
	scanf("%s", sAfter1);
	printf("Enter a first part of second number\n");
	scanf("%s", sBefore2);
	printf("Enter a second part of second number\n");
	scanf("%s", sAfter2);

	int maxLA = (strlen(sAfter1) > strlen(sAfter2)) ? strlen(sAfter1) : strlen(sAfter2);
	before1 = atoi(sBefore1);
	before2 = atoi(sBefore2);
	after1 = atoi(sAfter1);
	after2 = atoi(sAfter2);
	long mul = getPow10(maxLA);
	if ((before1 < 0) || (strcmp(sBefore1, "-0") == 0))
		after1 = -after1;
	if ((before2 < 0) || (strcmp(sBefore2, "-0") == 0))
		after2 =  -after2;
	long first = before1 * mul;
	first += after1 * getPow10(maxLA - strlen(sAfter1));
	long second = before2 *mul;
	second += after2 * getPow10(maxLA - strlen(sAfter2));
	long sum = first + second;
	if (abs(sum) > MAX_ABS) {
		printf("Result number too long for float type!\n");
		return;
	}

	char sSum[LEN_STR], sFl[LEN_STR], sRes[LEN_STR];
	sprintf(sSum, "%li", sum);
	if (maxLA > strlen(sSum)) {
		char sSum0[LEN_STR];
		sprintf(sSum0, "%i", abs(sum));
		sprintf(sFl, "%i", 0);
		for (int i = 1; i < maxLA - strlen(sSum0); i++)
			strcat(sFl, "0");
		sprintf(sFl, "%s%i", sFl, abs(sum % mul));
	} else if ((strlen(sSum) - maxLA == 0) && (sSum[0] == '-')) {
		sprintf(sFl, "0%i", abs(sum % mul));
	} else {
		strcpy(sFl, &sSum[strlen(sSum) - maxLA]);
	}
	if ((sum / mul == 0) && (sum < 0))
		sprintf(sRes, "-%li.%s\n", sum / mul, sFl);
	else
		sprintf(sRes, "%li.%s\n", sum / mul, sFl);
	printf("Sum == %s\n", sRes);
}

int main(int argc, char *argv[]) {
	addFloats();
	int x = 0;
	scanf("%i", &x);
	return EXIT_SUCCESS;
}
