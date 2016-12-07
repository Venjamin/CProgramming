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
#include <time.h>

#define MEMORY_SIZE 1000
#define POINTERS_MAX_AMOUNT 100
#define POINTERS_TEST_AMOUNT 10

//note about fragment of allocated memory
struct note {
	int address;
	int amount;
};

char mem[MEMORY_SIZE];
struct note allocs[POINTERS_MAX_AMOUNT];
int cur_pointers_amount;

/*
 * initialization of global variables
 */
void init_global_vars() {
	memset(mem, 0, MEMORY_SIZE);
	memset(allocs, 0, sizeof(struct note) * POINTERS_MAX_AMOUNT);
	cur_pointers_amount = 0;
}

/*
 * sort array of notes about allocated memory
 */
void shift_notes_allocs(int ind, int after_malloc) {
	int i = 0, j = 0;
	struct note temp;
	memset(&temp, 0, sizeof(temp));
	if (after_malloc) {
		for (i = 0; i < cur_pointers_amount - 1; i++) {
			if (allocs[i].address > allocs[cur_pointers_amount - 1].address) {
				break;
			}
		}
		if (i < cur_pointers_amount - 1) {
			temp.address = allocs[cur_pointers_amount - 1].address;
			temp.amount = allocs[cur_pointers_amount - 1].amount;
			for (j = cur_pointers_amount - 1; j > i; j--) {
				allocs[j].address = allocs[j - 1].address;
				allocs[j].amount = allocs[j - 1].amount;
			}
			allocs[i].address = temp.address;
			allocs[i].amount = temp.amount;
		}
	} else {
		for (i = ind; i < cur_pointers_amount; i++) {
			allocs[i].address = allocs[i + 1].address;
			allocs[i].amount = allocs[i + 1].amount;
		}
		allocs[cur_pointers_amount].address = 0;
		allocs[cur_pointers_amount].amount = 0;
	}
}

/*
 * find address of free memory
 */
int exists_free_memory(int size) {
	int i = 0;
	for (i = 0; i < cur_pointers_amount - 1; i++) {
		if (allocs[i].address + allocs[i].amount + size < allocs[i + 1].address) {
			return allocs[i].address + allocs[i].amount;
		}
	}
	if (cur_pointers_amount == 0) {
		if (size <= MEMORY_SIZE) {
			return 0;
		}
	} else {
		if (allocs[cur_pointers_amount - 1].address + allocs[cur_pointers_amount - 1].amount + size < MEMORY_SIZE) {
			return allocs[cur_pointers_amount - 1].address + allocs[cur_pointers_amount - 1].amount;
		}
	}
	return -1;
}

/*
 * allocate memory in global array mem[MEMORY_SIZE]
 */
void *my_malloc(int size) {
	if (cur_pointers_amount >= POINTERS_MAX_AMOUNT) {
		return (void *)(-1);
	}
	int addr = exists_free_memory(size);
	if (addr > -1) {
		allocs[cur_pointers_amount].address = addr;
		allocs[cur_pointers_amount].amount = size;
		cur_pointers_amount++;
		shift_notes_allocs(0, 1);
	}
	return (void *)addr;
}

/*
 * free memory, that was allocated with my_malloc
 */
void my_free(void *ptr, int is_set_zero) {
	int i = 0;
	for (i = 0; i < cur_pointers_amount; i++) {
		if (allocs[i].address == (int)ptr) {
			if (is_set_zero) {
				memset(mem + allocs[i].address, 0, allocs[i].amount);
			}
			allocs[i].address = 0;
			allocs[i].amount = 0;
			cur_pointers_amount--;
			shift_notes_allocs(i, 0);
			return;
		}
	}
}

/*
 * testing of my_malloc / my_free
 */
void test() {
	int i = 0, mem_size = 0, addr = 0;
	int address_array[POINTERS_TEST_AMOUNT];
	memset(address_array, 0, POINTERS_TEST_AMOUNT * sizeof(int));

	printf("-----Memory allocation-----\n");
	fflush(stdout);
	srand(time(0));
	for (i = 0; i < POINTERS_TEST_AMOUNT; i++) {
		mem_size = (rand() % 100) + 1;
		addr = (int)my_malloc(mem_size);
		address_array[i] = addr;
		if (addr != -1) {
			memset(mem + address_array[i], 1, mem_size);
			printf("%i) requested memory size: %i; address: %i\n", i, mem_size, addr);
		} else {
			printf("%i) error, memory is not allocated\n", i);
		}
		fflush(stdout);
	}

	printf("-----Free memory-----\n");
	fflush(stdout);
	for (i = 0; i < POINTERS_TEST_AMOUNT; i++) {
		if (address_array[i] != -1) {
			addr = address_array[i];
			my_free((void *)address_array[i], 1);
			address_array[i] = 0;
			printf("%i) memory is free (address: %i, Amount active pointers: %i)\n", i, addr, cur_pointers_amount);
			fflush(stdout);
		}
	}

	address_array[0] = (int)my_malloc(10);
	address_array[1] = (int)my_malloc(20);
	address_array[2] = (int)my_malloc(30);
	my_free((void *)address_array[1], 1);
	address_array[1] = 0;
	address_array[3] = (int)my_malloc(15);
	address_array[4] = (int)my_malloc(20);
	printf("--------------------\nMemory allocated, active pointers: ");
	fflush(stdout);
	for (i = 0; i < cur_pointers_amount; i++) {
		printf("address %i, size %i; ", allocs[i].address, allocs[i].amount);
		fflush(stdout);
	}
	printf("\nAmount active pointers: %i\n", cur_pointers_amount);
	fflush(stdout);
	if (cur_pointers_amount > 0) {
		printf("Memory leaks!\n");
		fflush(stdout);
	}
}

/*
 * main function, call test of my_malloc / my_free
 */
int main(void) {
	init_global_vars();
	test();

	return EXIT_SUCCESS;
}
