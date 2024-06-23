#include <stdio.h>
#include <stdlib.h>

void binary_search(int arr[], int size, int val){

    int lower, upper, mid;

    lower = 0;
    upper = size - 1;

    

    while (lower <= upper) {

        mid = (lower + upper) / 2 ;

        if(val == arr[mid]){
            printf("Element found at index %d.\n", mid);
            return;
        } 
        else if (val > arr[mid]){
            lower = mid + 1;
        }
        else {
            upper = mid - 1;
        }
    }

    printf("Element not present in the array.\n");
    return;

}

int main(){

    int arr[10];

    for (int i = 0; i < 10; i++){

        arr[i] = i + 5;
        printf("%d\n", arr[i]);

    }

    binary_search(arr, 10, 15);

}