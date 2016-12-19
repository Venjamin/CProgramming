#include <iostream>
#include <time.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Введите размерность массива: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for (int k = 0; k < sizeof(arr)/sizeof(int); ++k) {
        arr[k] = 0 + rand() %99;
        printf("%d\n", arr[k]);
    }
    printf("\n");
    int arr99[100];
    for(int i=0;i<sizeof(arr99)/sizeof(int);i++){
        arr99[i]=0;
    }
    for(int i = 0;i < sizeof(arr)/sizeof(int); i++){
       arr99[arr[i]]+=1;
    }
    for(int i=0;i<sizeof(arr99)/sizeof(int);i++){
        if (arr99[i] != 0){
            for (int j = 0; j < arr99[i]; j++){
                printf("%d\n", i);
            }
        }

    }
    return 0;
}