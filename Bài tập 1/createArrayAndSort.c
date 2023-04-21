#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_SIZE 4
void GenerateRamdomArray(uint16_t* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
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
    uint16_t *arr = (uint16_t*) malloc(MAX_SIZE * sizeof(uint16_t));
  
    GenerateRamdomArray(arr, MAX_SIZE);
    int n = sizeof(arr) / sizeof(*arr);
    printf("Mang ngau nhien: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    SortArray(arr, n);
    printf("\nMang da sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}