
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calcFloat(void) {

    int first_N2, first_N1, temp1, temp2, second_result, firstResult;
    int str_len = 6;
    char second_N2[str_len];
    char second_N1[str_len];
    char secondCharResult[6] = {0};
//    sscanf();
    printf("Enter first part of N1:\n");
    scanf("%d", &first_N1);
    printf( "Enter second part of N1:\n");
    scanf("%s", second_N1);
    printf( "Enter first part of N2:\n");
    scanf("%d", &first_N2);
    printf( "Enter second part of N2:\n");
    scanf("%s", second_N2);
//    strlen(second_N2);
//    atoi(second_N2);
    printf( "\nYou entered first part N1: %d\n", first_N1);
    printf( "\nYou entered second part N1: %s\n", second_N1);
    printf( "\nYou entered first part N2: %d\n", first_N2);
    printf( "\nYou entered second part N2: %s\n", second_N2);

    firstResult = first_N1 + first_N2;


    for (int i = str_len-1; i >= 0; --i) {
        if (second_N1[i] != 0 && second_N2[i] != 0) {
            temp1 = second_N1[i] - 48;
            temp2 = second_N2[i] - 48;
            second_result = temp1+temp2;
            if (i != 0 && second_result > 9) {
                secondCharResult[i-1]++;
                secondCharResult[i] += (char)(second_result-10);
            }
            else if (i == 0 && second_result > 9) {
                firstResult++;
                secondCharResult[i] += (char)(second_result-10);
            } else
                secondCharResult[i] += (char)(second_result);

        } else if (second_N1[i] != 0) {
            secondCharResult[i] = second_N1[i];
        } else if (second_N2[i] != 0) {
            secondCharResult[i] = second_N2[i];
        } else
            secondCharResult[i] = 48;
    }
    printf("Результат - %d.%s", firstResult, secondCharResult);

    return 0;
}