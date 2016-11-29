//
// Created by j2ck on 07/11/16.
//
#include <stdio.h>
#include "myAtoi/myAtoi.h"

int main(void) {
//    calcFloat();
//    sort();
//    test();
    char *p_str;
    char str[] = "-2147483649";
//    char str[24] = "213 342";
    char str2[24] = "21wer323342433";
    p_str = str;
    int res = myAtoi(p_str);
    printf("%d\n", res);
    printf("%s\n", str2);
    return 0;
}