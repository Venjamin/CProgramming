/*
 ============================================================================
 Name        : cpr8.c
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
#define MAX_DIGITS_AMOUNT 9
#define PARTS_AMOUNT 4
#define MAX_MESSAGE_LEN 40

/*
 * Get power of 10 (0 <= power <= 9)
 */
long getPow10(int iPower) {
	long lMul = 1;
	int i = 0;
	if ((iPower < 0) || (iPower > 9))
		return -1;
	for (i = 0; i < iPower; i++) {
		lMul *= 10;
	}
	return lMul;
}

/*
 * Set minus for second part of number if first part is negative
 */
void setMinus(long *lAfter1, long *lAfter2, long lBefore1, long lBefore2, char *sBefore1, char *sBefore2) {
	if ((lBefore1 < 0) || (strncmp(sBefore1, "-0", 2) == 0))
		(*lAfter1) = -(*lAfter1);
	if ((lBefore2 < 0) || (strncmp(sBefore2, "-0", 2) == 0))
		(*lAfter2) =  -(*lAfter2);
}

/*
 * Enter parts of numbers from keyboard
 */
int enterNumbers(char *sBefore1, char *sBefore2, char *sAfter1, char *sAfter2) {
	int iResScanf = 0, i = 0;
	char sForPrint[PARTS_AMOUNT][MAX_MESSAGE_LEN] =
										{"Enter a first part of first number\n",
										"Enter a second part of first number\n",
										"Enter a first part of second number\n",
										"Enter a second part of second number\n"};
	char *sForScan[PARTS_AMOUNT] = {sBefore1, sAfter1, sBefore2, sAfter2};
	for (i = 0; i < PARTS_AMOUNT; i++) {
		printf(sForPrint[i]);
		iResScanf = scanf_s("%s", sForScan[i], LEN_STR);
		if (iResScanf == 0) {
			printf("Too long number!\n");
			return 0;
		}
	}
	return 1;
}

/*
 * Restore zeros after point those lost during conversion
 */
void restoreZerosAfterPoint(char *sFl, long lSum, int iMaxLA, long lMul) {
	char sSum[LEN_STR], sSum0[LEN_STR], sSum1[LEN_STR];
	int i = 0;
	memset(sSum, 0, LEN_STR);
	memset(sSum0, 0, LEN_STR);
	memset(sSum1, 0, LEN_STR);

	sprintf(sSum, "%li", lSum);
	if (iMaxLA > strnlen(sSum, LEN_STR)) {
		sprintf(sSum0, "%i", abs(lSum));
		sprintf(sSum1, "%i", 0);
		for (i = 1; i < iMaxLA - strnlen(sSum0, LEN_STR); i++)
			strncat(sSum1, "0", 2);
		sprintf(sFl, "%s%i", sSum1, abs(lSum % lMul));
	} else if ((strnlen(sSum, LEN_STR) - iMaxLA == 0) && (sSum[0] == '-')) {
		sprintf(sFl, "0%i", abs(lSum % lMul));
	} else {
		strncpy(sFl, &sSum[strnlen(sSum, LEN_STR) - iMaxLA], LEN_STR);
	}
}

/*
 * Convert string to long
 */
long strToLong(char *str, int maxLen) {
	long n = 0;
	int i = 0, flag = 0;
	if (str[0] == '-') {
		flag = 1;
		i = 1;
	}
	for (; (i < maxLen) && (str[i] >= '0') && (str[i] <= '9'); ++i)
		n = 10 * n + (str[i] - '0');
	if (flag)
		return -n;
	return n;
}

/*
 *Checking of number length
 */
int checkNotTooLong(char *sBefore, int iMaxLA) {
	int len = strnlen(sBefore, LEN_STR) + iMaxLA;
	if (sBefore[0] == '-')
		len--;
	if (len > MAX_DIGITS_AMOUNT)
		return 0;
	return 1;
}

/*
 * Add 2 float numbers those represented as 4 integer numbers
 */
void addFloats() {
	//declaration and initialization of variables
	long lBefore1 = 0, lAfter1 = 0, lBefore2 = 0, lAfter2 = 0, lMul = 0, lFirst = 0, lSecond = 0, lSum = 0;
	char sBefore1[LEN_STR], sBefore2[LEN_STR], sAfter1[LEN_STR], sAfter2[LEN_STR], sFl[LEN_STR], sRes[LEN_STR];
	int iMaxLA = 0;
	memset(sBefore1, 0, LEN_STR);
	memset(sBefore2, 0, LEN_STR);
	memset(sAfter1, 0, LEN_STR);
	memset(sAfter2, 0, LEN_STR);
	memset(sFl, 0, LEN_STR);
	memset(sRes, 0, LEN_STR);

	//enter parts of added numbers
	if (enterNumbers(sBefore1, sBefore2, sAfter1, sAfter2) == 0)
		return;

	lBefore1 = strToLong(sBefore1, MAX_DIGITS_AMOUNT);
	lBefore2 = strToLong(sBefore2, MAX_DIGITS_AMOUNT);
	lAfter1 = strToLong(sAfter1, MAX_DIGITS_AMOUNT);
	lAfter2 = strToLong(sAfter2, MAX_DIGITS_AMOUNT);

	//calculate sum as integer number
	iMaxLA = (strnlen(sAfter1, LEN_STR) > strnlen(sAfter2, LEN_STR)) ? strnlen(sAfter1, LEN_STR) : strnlen(sAfter2, LEN_STR);
	lMul = getPow10(iMaxLA);
	if ((lMul == -1) || (checkNotTooLong(sBefore1, iMaxLA) == 0) || (checkNotTooLong(sBefore2, iMaxLA) == 0)) {
		printf("Too long number!\n");
		return;
	}
	setMinus(&lAfter1, &lAfter2, lBefore1, lBefore2, sBefore1, sBefore2);

	lFirst = lBefore1 * lMul;
	lFirst += lAfter1 * getPow10(iMaxLA - strnlen(sAfter1, LEN_STR));
	lSecond = lBefore2 *lMul;
	lSecond += lAfter2 * getPow10(iMaxLA - strnlen(sAfter2, LEN_STR));
	lSum = lFirst + lSecond;
	if (labs(lSum) > MAX_ABS) {
		printf("Result number too long for float type!\n");
		return;
	}

	restoreZerosAfterPoint(sFl, lSum, iMaxLA, lMul);

	//output of result number
	if ((lSum / lMul == 0) && (lSum < 0))
		sprintf(sRes, "-%li.%s\n", lSum / lMul, sFl);
	else
		sprintf(sRes, "%li.%s\n", lSum / lMul, sFl);
	printf("Sum == %s\n", sRes);
}

/*
 * main function, call addFloats()
 */
int main(int argc, char *argv[]) {
	char sExit[2];
	memset(sExit, 0, 2);
	addFloats();
	scanf_s("%s", sExit, 1);
	return EXIT_SUCCESS;
}
