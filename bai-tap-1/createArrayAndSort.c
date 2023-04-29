#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
// #define MAX_SIZE 4
typedef struct {
    uint16_t *arr;
    int length;
} Array;

void GenerateRandomArray(Array *val) {
    srand(time(NULL));
    val->length = 10 + rand() % (30 + 1 - 10); // random array length from 10 to 30
    uint16_t tmp;
    printf("kich thuoc cua arr la: %d\n", val->length);
    val->arr = (uint16_t *) malloc(val->length * sizeof(uint16_t));

    for (int i = 0; i < val->length; i++) {
        tmp = rand() % 50;
        val->arr[i] = tmp;
    }
}
void Swap(uint16_t* i, uint16_t* j) {
  uint16_t temp = *i;
  *i = *j;
  *j = temp;
}
void SortArray(uint16_t* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                Swap((arr + i), (arr + j));
            }
        }
    }
}
int main () {
    Array arr;
    GenerateRandomArray(&arr);
    printf("Mang ngau nhien: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.arr[i]);
    }

    SortArray(arr.arr, arr.length);
    printf("\nMang da sap xep: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.arr[i]);
    }
    free(arr.arr);
    return 0;
}