/**
 * File: array_createAndSort.c
 * Author: Dien Nguyen
 * Date: 09/05/2023
 * Description: Create and sort an array 
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
// #define MAX_SIZE 4

typedef struct {
    uint8_t *arr; // Do chỉ ramdom từ 1->50 nên kích 2^8 là phù hợp
    uint8_t length;// Độ dài chỉ ramdom từ 10->30 nên uint8_t là phù hợp
} Array;

/**
 * Function: randomArrayGenerate
 * Description: Create a array RaNdom with length random
 * Input:
 *      val - an Array value with datatype by user define
 * Output:
 *      none
*/

void randomArrayGenerate(Array *val) {
    srand(time(NULL));
    val->length = 10 + rand() % (30 + 1 - 10); // random array length from 10 to 30
    uint8_t tmp;
    printf("kich thuoc cua arr la: %d\n", val->length);
    val->arr = (uint8_t *) malloc(val->length * sizeof(uint8_t));// cấp phát động cho mảng thuộc struct

    // loop random value into an array
    for (uint8_t i = 0; i < val->length; i++) {
        tmp = rand() % 50; //random value of an array from 0 to 50
        val->arr[i] = tmp; // assign tmp value into arr array with index i
    }
}
/**
 * Function: Swap
 * Description: swap two values ​​for each other
 * Input:
 *      i - an pointer with integer and 1-byte length
 *      j - an pointer with integer and 1-byte length
 * Output:
 *      none
*/
void Swap(uint8_t* i, uint8_t* j) {
  uint8_t temp = *i; // create an variable `temp` and assign `j` value into `temp`
  *i = *j;
  *j = temp;
}

/**
 * Function: SortArray
 * Description: Sort an array with increasing value
 * Input:
 *      val - an Array value with datatype by user define
 * Output:
 *      none
*/
void SortArray(Array *val) {
    for (int i = 0; i < val->length - 1; i++) {
        for (int j = i + 1; j < val->length; j++) {
            //check if index i is langer than index j then swap to values for each other
            if (val->arr[j] < val->arr[i]) { 
                Swap((val->arr + i), (val->arr + j));
            }
        }
    }
}
int main () {
    Array arr;
    randomArrayGenerate(&arr);
    printf("Mang ngau nhien: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.arr[i]);
    }

    SortArray(&arr);
    printf("\nMang da sap xep: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.arr[i]);
    }
    free(arr.arr);
    return 0;
}