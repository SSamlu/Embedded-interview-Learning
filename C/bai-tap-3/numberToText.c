/**
 * File: Date.c
 * Author: Dien Nguyen
 * Date: 09/05/2023
 * Description: nhập số và in ra nó thành chữ số
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// typedef enum {KHONG, MOT, HAI, BA, BON, NAM, SAU, BAY, TAM, CHIN} numString;
// typedef enum {NGAN , TRIEU , TY } unitString;
// typedef enum {MUOI , TRAM } positionString;

/**
 * Function: printNum
 * Description: 
 * Input: 
 *      num - an integer value with 4-byte length
*/

void printNum(uint8_t num) {  
    const char* numString[] = {"KHONG", "MOT", "HAI", "BA", "BON", "NAM", "SAU", "BAY", "TAM", "CHIN"};
    printf("%s ", numString[num]);
}

/**
 * Function: DayOfMonth
 * Description: 
 * Input: 
 *      num    - an integer value with 4-byte length
 *      vitri  - an integer value with 1-byte length
*/

void printUnit(uint8_t num, uint8_t vitri) {
    const char* unitString[] = {"NGAN ", "TRIEU ", "TY "};
    const char* positionString[] = {"", "MUOI ", "TRAM "};

    if (num > 0 || vitri % 3 == 0) {
        printNum(num);
        printf("%s", positionString[vitri % 3]);
    }

    if (vitri % 3 == 0) {
        printf("%s", unitString[vitri / 3 - 1]);
    }
}

/**
 * Function: readNumber
 * Description: Print the number of days of the month includes leap and not leap year
 * Input: 
 *      num - an integer value with 4-byte length
*/

void readNumber(uint32_t num) {
    if (num == 0) {
        printf("KHONG");
        return;
    }

    uint8_t size = 0;
    uint8_t digits[12] = {0};

    while (num > 0) {
        digits[size++] = num % 10;
        num /= 10;
    }

    for (int i = size - 1; i >= 0; i--) {
        printUnit(digits[i], i);
    }
}

int main() {
    uint32_t number = 12345680;
    readNumber(number);
    printf("\n");
    return 0;
}
