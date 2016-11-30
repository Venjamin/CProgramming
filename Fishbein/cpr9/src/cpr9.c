/*
 ============================================================================
 Name        : cpr9.c
 Author      : anna
 Version     :
 Copyright   : -
 Description : analogue of strlen
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 31

/*
 * Get string length
 */
int string_length(char *s, int max_len) {
	int res = 0;
	char *s0 = s;
	while ((res < max_len) && (*s0 != '\0')) {
		res++;
		s0++;
	}
	return res;
}

/*
 * main function, call string_length
 */
int main(int argc, char *argv[]) {
	char s[LEN_STR];
	int len = 0;
	memset(s, 0, LEN_STR);
	printf("Enter a string (less or equal %i characters)\n", LEN_STR - 1);
	fflush(stdout);
	//scanf_s("%s", s, 31);//scanf_s read without spaces
	gets(s);
	len = string_length(s, LEN_STR - 1);
	printf("Length of this string: %i\n", len);
	fflush(stdout);
	return EXIT_SUCCESS;
}
