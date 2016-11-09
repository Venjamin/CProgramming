#include <studio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    int arr1[100] = {0};
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%99;
        printf("%d\n", arr[i]);
    }
    for (int i = 0; i < 100; i++) {
      arr1[arr[i]]++;
    }
    for (int i = 0; i < 100; i++) {
        if(arr1[i] != 0) {
            for (int j = 0; j < arr[i]; j++) {
                printf("%d",&i);
            }
        }
    }
    return 0;
}