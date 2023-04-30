#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX_LEN 100
struct Word {
    char* arr;
    uint8_t length;
};
void CreateString(char* input) {
    printf("Nhap chuoi: ");
    fgets(input, MAX_LEN, stdin);
}
void ReverseString(char* input, struct Word* words, uint8_t* word_count, uint8_t len) {
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
int main() {
    char input[MAX_LEN];
    struct Word words[MAX_LEN];
    uint8_t word_count = 0;
    CreateString(input);
    uint8_t len = 0;
    ReverseString(input, words, &word_count, len);
    for (uint8_t i = word_count; i > 0; i--) {
        printf("%s ", words[i-1].arr);
        free(words[i-1].arr); 
    }
    printf("\n");

    return 0;
}
