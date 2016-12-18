/*
 ============================================================================
 Name        : cpr12.c
 Author      : anna
 Version     :
 Copyright   : -
 Description : OS imitation that launches tasks, tasks run during 5 seconds
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_SIZE 100
#define EXECUTION_DURATION 5
#define LOOP_AMOUNT 5
#define TASK_AMOUNT 2

int share_mem[MEMORY_SIZE];

/*
 * task that writes numbers to array
 */
int write_task(int pos, int duration) {
	int i = 0, val = 0, pos0 = pos;
	time_t start = time(0);
	while (1) {
		for (i = pos0; i < MEMORY_SIZE; i++) {
			val  = (rand() % 100) + 1;
			share_mem[i] = val;
			if (time(0) - start >= duration) {
				return i;
			}
		}
		pos0 = 0;
	}
	return -1;
}

/*
 * task that reads numbers from array
 */
int read_task(int pos, int duration) {
	int i = 0, val = 0, pos0 = pos;
	time_t start = time(0);
	while (1) {
		for (i = pos0; i < MEMORY_SIZE; i++) {
			val = share_mem[i];
			if (time(0) - start >= duration) {
				return i;
			}
		}
		pos0 = 0;
	}
	return -1;
}

/*
 * main function, calls tasks in loop
 */
int main(int argc, char *argv[]) {
	int i = 0, j = 0, pos[TASK_AMOUNT] = {-1, -1};
	int (*tasks[TASK_AMOUNT])(int, int) = {write_task, read_task};
	char *task_name[TASK_AMOUNT] = {"write_task", "read_task"};
	memset(share_mem, 0, MEMORY_SIZE * sizeof(int));

	srand(time(0));
	for (i = 0; i < LOOP_AMOUNT; i++) {
		for (j = 0; j < TASK_AMOUNT; j++) {
			printf("start %s (%i)\n", task_name[j], i);
			fflush(stdout);
			pos[j] =  tasks[j](pos[j] + 1, EXECUTION_DURATION);
			printf("stop %s (%i)\n", task_name[j], i);
			fflush(stdout);
		}
	}
	return EXIT_SUCCESS;
}
