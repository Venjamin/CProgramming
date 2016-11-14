#define MIN 0
#define MAX 100
#define ARRAY_LENGTH 100
#define SUCCESS 0

#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, int n, int min, int max);
int get_rand_from_range(int min, int max);

int main(int argc, const char * argv[]) {
    int arr[ARRAY_LENGTH], i;
    
    for(i = 0; i < ARRAY_LENGTH; i++){
        arr[i] = get_rand_from_range(MIN, MAX);
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    counting_sort(arr,ARRAY_LENGTH, MIN, MAX);
    
    for(i = 0; i < ARRAY_LENGTH; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return SUCCESS;
}

int get_rand_from_range(int min, int max){
    int random = rand() % (min + 1 - max) + min;
    return random;
}

void counting_sort(int *arr, int n, int min, int max)
{
    int i, j, c;
    
    int range = max - min + 1;
    int *count = malloc(range * sizeof(*arr));
    
    for(i = 0; i < range; i++)
        count[i] = 0;
    for(i = 0; i < n; i++)
        count[arr[i] - min]++;
    
    for(i = min, c = 0; i <= max; i++) {
        for(j = 0; j < count[i - min]; j++)
            arr[c++] = i;
    }
    
    free(count);
}

