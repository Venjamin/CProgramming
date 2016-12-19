/*
 ============================================================================
 Name        : cpr5.c
 Author      : anna
 Version     :
 Copyright   : -
 Description : string initialization and output
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char ch0[] = "string";
	char *ch1 = "string";
	char ch2[] = {'s', 't', 'r', 'i', 'n', 'g', '\0'};
	printf("%s\n", ch0);
	printf("%s\n", ch1);
	printf("%s\n", ch2);
	return EXIT_SUCCESS;
}
