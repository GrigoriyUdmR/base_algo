#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define I_ARR  10
// #define ALGO_TYPE BIN_SEARCH
#define BIN_SEARCH  0
#define SELEC_SORT  1
#define LEETCODE_BS 2

#define ALGO_TYPE LEETCODE_BS

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
int my_sqrt(int x){  // uncorrect ver
    int low = 0, high = x/2;
    int mid = (high + low) / 2;

    if (x < 2) return x;
    else {
        while(high - low > 1){
            if (mid * mid > x) high = mid;
            else if (mid * mid < x) low = mid;
            else break;
            mid = (high + low) / 2;
        }
        return mid;
    }
    return -1;
}

int main (){
    #if ALGO_TYPE == BIN_SEARCH
    sortArrGen(gSortArr, I_ARR);
    uint number = 555;              //number needed is added here
    printf ("\n%d\n",number);
    printf ("\n%d\n",bin_search(number, gSortArr, I_ARR));
    // preStart(gExamArr, I_ARR);
    #elif ALGO_TYPE == SELEC_SORT
    //  
    //
    //
    #elif ALGO_TYPE == LEETCODE_BS
    my_sqrt(9);
    my_sqrt(2);
    my_sqrt(4);
    #endif

    return 0;
}

