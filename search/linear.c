#include <stdio.h>
#include <stdlib.h>


void linear_search(int arr[], int size, int val){

    for (int i = 0; i < size; i++){

        if(val == arr[i]){
            printf("Found %d at index %d\n", val, i);
            return;
        } 
    }

    printf("Could not find %d in the array", val);
}


int main(){

    int size;
    scanf("%d", &size);

    int *arr;
    arr = (int *)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++){

        *(arr + i) = 1000 - (i * 3);

    }

    for(int i = 0; i < size; i++){
        printf("%d\n", *(arr + i));
    }

    linear_search(arr, size, 952);

    return 0;
}