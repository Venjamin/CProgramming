#include <stdio.h>
#include <time.h>

int test(void) {

    long int n = 1000000000, t = 0;
    time_t now = time(0);
    printf("Current local time: %li\n", now);
    for (int i = 0; i < n; ++i) {
        t++;
    }
    printf("%li\n", t);
    time_t now2 = time(0);
    printf("Current local time: %li\n", now2);
    printf("Spent time in for loop: %li\n", now2 - now);

    int i = 0;
    now = time(0);
    printf("Current local time: %li\n", now);
    while (i <= n) {
        i++;
    }
    now2 = time(0);
    printf("Current local time: %li\n", now2);
    printf("Spent time in while loop: %li\n", now2 - now);
    return 0;
}
