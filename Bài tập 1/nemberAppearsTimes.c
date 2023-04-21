#include <stdint.h>
#include <stdio.h>
// #include <stdlib.h>
#define MAX_VALUE 10
// int arr[10] = {1, 1, 2, 3, 4, 4}

int count[MAX_VALUE] = {0};

void MemberAppearsTimesCheck(const int* item, int size) {
    for(int i; i < size; i++) {
        (*(count + item[i]))++;
    }
}

void PrintData() {
    for (int i = 0; i < MAX_VALUE; i++) {
        if(*(count + i) > 0) {
            printf("so %d xuat hien %d lan trong mang arr \n", i, *(count + i));
        }
    }
}
int main() {
    //int *arr = (int*) malloc(6 * sizeof(int));
    int arr[] = {1, 1, 2, 3, 4, 4};
    int arr_size = sizeof(arr)/sizeof(int);
    MemberAppearsTimesCheck(arr, arr_size);
    PrintData();
    return 0;
}