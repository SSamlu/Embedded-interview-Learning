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

void reverseString(struct Word* words, uint8_t word_count) {
    for (uint8_t i = 0; i < word_count / 2; i++) {
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
    for (uint8_t i = 0; i < word_count; i++) {
        printf("%s ", words[i].arr);
        free(words[i].arr); 
    }
    printf("\n");

    return 0;
}
