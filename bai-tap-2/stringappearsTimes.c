#include <stdint.h>
#include <stdio.h>

#define MAX_WORD 100
#define MAX_LENGTH 50

typedef struct {
  /* data */
  char *word[MAX_WORD];
  int length;
  int count[MAX_WORD];

} word;
void CreatString(char *input) {
  printf("nhap chuoi: ");
  // scanf("%[^\n]", input);
  fgets(input, MAX_LENGTH, stdin);
}
void SplitString(char *input, word *words) {
  words->length = 0;
  char *ptr = input;
  while(*ptr != '\0') {
    while (*ptr == ' ') {
      ptr++;
    }
    if (*ptr != '\0') {
      words->word[words->length] = ptr;
      words->count[words->length] = 1;
      words->length++;
    }
    while (*ptr != ' ' && *ptr != '\0') {
      ptr++;
    }
    if (*ptr == ' ') {
      /* code */
      *ptr = '\0';
      ptr++;
    } 
  }
}

void SortWords(word *words) {
  for (int i = 1; i < words->length; i++) {
    char *key = words->word[i];
    int j = i - 1;
    while (j >= 0 && *(words->word[j]) > *key) {
      words->word[j+1] = words->word[j];
      j--;
    }
    words->word[j + 1] = key;
  }
  
};

void CountWords(word *words) {
  for (int i = 0; i < words->length; i++) {
    for (int j = i + 1; j < words->length; j++) {
      if (*(words->word[i]) == *(words->word[j])) {
          words->count[i]++;
          words->count[j] = 0;
      }
    }
  }
}

void PrintData(word words) {
  printf("Ket qua:\n");
  for (int i = 0; i < words.length; i++) {
    if (words.count[i] > 0) {
      printf("%s xuat hien %d lan\n", words.word[i], words.count[i]);
    }
  }
}
int main(){
  char input[MAX_LENGTH];
  word words;
  CreatString(input);
  SplitString(input, &words);
  SortWords(&words);
  CountWords(&words);
  PrintData(words);
  return 0;
}