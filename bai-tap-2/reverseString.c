/**
 * File: reverseString.c
 * Author: Dien Nguyen
 * Date: 09/05/2023
 * Description: Check the appearance of numbers in the array
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX_LEN 100

struct Word {
    char* arr;
    uint8_t length;
};

/**
 * Function: CreateString
 * Description: Enter a series of characters and save trong input with length is MAX_LEN 
 * Input:
 *      input - an char value
*/

void CreateString(char* input) {
    printf("Nhap chuoi: ");
    fgets(input, MAX_LEN, stdin);
}

/**
 * Function: splitWordsInString
 * Description: split into Words in String
 * Input:
 *      input      - an char value
 *      words      - an Word value with datatype by user define
 *      word_count - an integer value with 1-byte length
*/

void splitWordsInString(char* input, struct Word* words, uint8_t* word_count) {
    uint8_t len = 0;
    for (uint8_t i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\n') {
            words[*word_count].arr = (char*)malloc(len + 1);
            for (uint8_t j = 0; j < len; j++) {
                words[*word_count].arr[j] = input[i - len + j]; 
            }
            words[*word_count].arr[len] = '\0';
            words[*word_count].length = len;
            (*word_count)++;
            len = 0;
        }
        else {
            len++;
        }
    }
}

/**
 * 
 * Function: reverseString
 * Description: reverse words in a string
 * Input:
 *      words      - an Word value with datatype by user define
 *      word_count - an integer value with 1-byte length
*/

void reverseString(struct Word* words, uint8_t word_count) {
    //loop for with length is word_count/2
    for (uint8_t i = 0; i < word_count / 2; i++) {
        // swap first index and last index
        struct Word temp = words[i];
        words[i] = words[word_count - i - 1]; 
        words[word_count - i - 1] = temp;
    }
}

int main() {
    char input[MAX_LEN];
    struct Word words[MAX_LEN];
    uint8_t word_count = 0;
    CreateString(input);
    splitWordsInString(input, words, &word_count);
    reverseString(words, word_count);
    // Print Data
    for (uint8_t i = 0; i < word_count; i++) {
        printf("%s ", words[i].arr);
        free(words[i].arr); 
    }
    printf("\n");

    return 0;
}
