/*
 ============================================================================
 Name        : cpr11.c
 Author      : anna
 Version     :
 Copyright   : -
 Description : imitation of memory allocation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SYZE 1000
#define POINTERS_MAX_AMOUNT 100

struct note {
	int address;
	int amount;
};

char mem[MEMORY_SYZE];
struct note allocs[POINTERS_MAX_AMOUNT];

void *my_malloc(int size) {
	//
	return 0;
}

void my_free(void *ptr) {
	//
}

int main(void) {
	memset(mem, 0, MEMORY_SYZE);
	memset(allocs, 0, sizeof(struct note) * POINTERS_MAX_AMOUNT);
	//
	return EXIT_SUCCESS;
}
