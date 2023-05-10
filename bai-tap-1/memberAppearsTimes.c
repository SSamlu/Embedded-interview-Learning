/**
 * File: memberAppearsTimes.c
 * Author: Dien Nguyen
 * Date: 09/05/2023
 * Description: Check the appearance of numbers in the array
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 10
// int arr[10] = {1, 1, 2, 3, 4, 4}
typedef struct {
    uint8_t *arr; // Do chỉ ramdom từ 1->50 nên kích 2^8 là phù hợp
    uint8_t length;// Độ dài chỉ ramdom từ 10->30 nên uint8_t là phù hợp
} Array;

int count[MAX_VALUE] = {0};

/**
 * Function: randomArrayGenerate
 * Description: Create a array RaNdom with length random
 * Input:
 *      val - an Array value with datatype by user define
*/

void randomArrayGenerate(Array *val) {
    srand(time(NULL));
    val->length = 10 + rand() % (30 + 1 - 10); // random array length from 10 to 30
    uint8_t tmp;
    printf("kich thuoc cua arr la: %d\n", val->length);
    val->arr = (uint8_t *) malloc(val->length * sizeof(uint8_t));

    // loop random value into an array
    for (int i = 0; i < val->length; i++) {
        tmp = rand() % 10; //random value of an array from 0 to 50
        val->arr[i] = tmp; // assign tmp value into arr array with index i
    }
}

/**
 * Function: MemberAppearsTimesCheck
 * Description: Check the appearance of numbers in the array
 * Input:
 *      val - an Array value with datatype by user define
*/

void MemberAppearsTimesCheck(Array *arr) {
    //loop for and increase one with the index is the values in the array of arr
    for(int i; i < arr->length; i++) {
        (*(count + arr->arr[i]))++;
    }
}

/**
 * Function: PrintData
 * Description: print data
*/

void PrintData() {
    for (int i = 0; i < MAX_VALUE; i++) {
        if(*(count + i) > 0) {
            printf("so %d xuat hien %d lan trong mang arr \n", i, *(count + i));
        }
    }
}
int main() {
    Array arr;
    randomArrayGenerate(&arr);
    printf("Mang ngau nhien:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("arr[%d] = %d \n", i, arr.arr[i]);
    }
    MemberAppearsTimesCheck(&arr);
    PrintData();
    return 0;
}