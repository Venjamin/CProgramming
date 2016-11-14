/*
 * Massive.c
 *
 *  Created on: Nov 4, 2016
 *      Author: j2ck
 */

#include <stdio.h>

int sort(void) {
    int arr[] = {0, 32, 53, 71, 24, 61, 75, 61, 99 };
    int len_arr2 = 100;
    int arr2[100] = {0};

    for (int var = 0; var < sizeof(arr)/ sizeof(int); ++var) {
        arr2[arr[var]]++;
    }
    for (int var = 0; var < len_arr2; ++var) {
        if (arr2[var] > 0 && arr2[var] < 100) {
            for (int i = 0; i < arr2[var]; ++i) {
                printf("%d\n",var);
            }
        }
    }
    return 0;
}
