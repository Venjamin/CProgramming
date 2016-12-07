
#include <stdio.h>
#include "myAtoi.h"


int sizeInt(int a) {
    int size = 0;
    switch (a) {
        case 2: {
            size = 32767;
            break;
        }
        case 4: {
            size = 2147483647;
            break;
        }
        default: {
            break;
        }
    }
    return size;
}

int myAtoi(char *str) {
    if (str == NULL) {
        return 0;
    }
    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit
    int a = sizeof(int);
    int maxSizeOfInt = sizeInt(a);
    // If number is negative, then update sign
    if (str[0] == '-') {
        sign = -1;
        i++;  // Also update index of first digit
    }

    // Iterate through all digits and update the result
    for (; '\0' != str[i]; ++i) {
        if (res <= maxSizeOfInt / 10) { // check for Integer x32 max size -1
            if ((sign == 1 && i == 9) || ((sign == -1 && i == 10))) { // check for last digit max size
                if ((sign == 1 && str[i] <= '7') || (sign == -1 && str[i] <= '8')) {
                    res = res * 10 + str[i] - '0';
                    break;
                } else {
                    printf("Too long for int \n");
                    return 0;
                }
            }
            if (str[i] >= '0' && str[i] <= '9') {
                res = res * 10 + str[i] - '0';
            } else {
                break;
            }
        } else {
            printf("Too long for int \n");
            return 0;
        }
    }
    // Return result with sign
    return sign * res;
}

