#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define I_ARR  10
#define ALGO_TYPE BIN_SEARCH

enum {
    BIN_SEARCH,
    SELEC_SORT
} algo_t;

typedef unsigned int uint;
int gRandArr[I_ARR] = {0};
int gSortArr[I_ARR] = {0};

void randArrGen(int *arr, uint size){
    srand ((uint)time(NULL));
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 100;
        printf("%d\n", arr[i]);
    }
}

void sortArrGen(int *arr, uint size){
    srand ((uint)time(NULL));
    arr[0] = rand() % 100;
    printf("%d\n", arr[0]);

    for (int i = 1; i < size; i++){
        arr[i] = rand() % 100;
        if (arr[i - 1] >= arr[i]){
            while (arr[i] < arr [i -1]) arr[i] =  arr[i] + (rand() % 100);
        }
        printf("%d\n", arr[i]);
    }
}

int bin_search(uint number, int *arr, uint size){
    uint res = 0;
    uint low = 0; 
    uint high = size - 1;
    uint mid = (high + low) / 2;
    while(low <= high){
        if(arr[mid] < number)
            low = mid + 1;
        else if (arr[mid] > number)
            high = mid - 1;
        else{
            res = 1;
            break;
        }
        mid = (high + low) / 2;
    }
    if (res == 1)
        return mid; 
    else
        return -1; 
}

int main (){
    #if ALGO_TYPE == BIN_SEARCH
    sortArrGen(gSortArr, I_ARR);
    uint number = 555;              //number needed is added here
    printf ("\n%d\n",number);
    printf ("\n%d\n",bin_search(number, gSortArr, I_ARR));
    // preStart(gExamArr, I_ARR);
    #endif

    #if ALGO_TYPE == SELEC_SORT
    //  why is it 
    //  not 
    //  color selected
    #endif
    return 0;
}

