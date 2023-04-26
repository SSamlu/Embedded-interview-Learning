#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void printNum(uint8_t num) {  
    const char* numString[] = {"KHONG", "MOT", "HAI", "BA", "BON", "NAM", "SAU", "BAY", "TAM", "CHIN"};
    printf("%s ", numString[num]);
}

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
    uint32_t number = 1234567890;
    readNumber(number);
    printf("\n");
    return 0;
}
