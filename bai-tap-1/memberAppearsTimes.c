#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 10
// int arr[10] = {1, 1, 2, 3, 4, 4}
typedef struct {
    uint16_t *arr;
    int length;
} Array;

int count[MAX_VALUE] = {0};

void GenerateRandomArray(Array *val) {
    srand(time(NULL));
    val->length = 10 + rand() % (30 + 1 - 10); // random array length from 10 to 30
    uint16_t tmp;
    printf("kich thuoc cua arr la: %d\n", val->length);
    val->arr = (uint16_t *) malloc(val->length * sizeof(uint16_t));

    for (int i = 0; i < val->length; i++) {
        tmp = rand() % 10;
        val->arr[i] = tmp;
    }
}

void MemberAppearsTimesCheck(Array *arr) {
    for(int i; i < arr->length; i++) {
        (*(count + arr->arr[i]))++;
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
    Array arr;
    GenerateRandomArray(&arr);
    printf("Mang ngau nhien:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("arr[%d] = %d \n", i, arr.arr[i]);
    }
    MemberAppearsTimesCheck(&arr);
    PrintData();
    return 0;
}