/**
 * File: stringappearsTimes.c
 * Author: Dien Nguyen
 * Date: 09/05/2023
 * Description: Check the appearance of numbers in the array
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD 100
#define MAX_LENGTH 50

typedef struct {
  /* data */
  char *word[MAX_WORD];
  int length;
  int count[MAX_WORD];

} word;

/**
 * Function: CreateString
 * Description: Enter a series of characters and save trong input with length is MAX_LEN 
 * Input:
 *      input - an char value
 * Output:
 *      none
*/

void CreatString(char *input) {
  printf("nhap chuoi: ");
  // scanf("%[^\n]", input);
  fgets(input, MAX_LENGTH, stdin);
}

/**
 * Function: CreateString
 * Description: Enter a series of characters and save trong input with length is MAX_LEN 
 * Input:
 *      input - an char value
 * Output:
 *      none
*/

void SplitString(char *input, word *words) {
  words->length = 0;
  char *ptr = input;
  while(*ptr != '\0') { // dùng loop while để kiểm tra có kí tự null không
    //check khi có space ở đầu chuỗi
    while (*ptr == ' ') { //dùng loop while để kiểm tra có kí tự là `space` không
      ptr++; // có thì tăng con trỏ 
    }
    if (*ptr != '\0') {
      words->word[words->length] = ptr; // assign cả string vào mảng word
      words->count[words->length] = 1; //
      words->length++;//length in word array
    }
    //loop while, check *ptr is different `sapce` or `null`
    while (*ptr != ' ' && *ptr != '\0') {
      ptr++; //tăng lên 1 đơn vị, việc tăng dể đếm số kí tự trong 1 word
    }
    if (*ptr == ' ' || *ptr == '\n') {
      /* code */
      *ptr = '\0'; // gắn `\0` tại kí tự `space` sẽ thành `Ex: i\0am dien`-> cắt từ `i` và lưu trong word
      ptr++; //tăng lên 1 đơn vị
    } 
  }
}

/**
 * Function: compareWords
 * Description: compare Words
 * Input:
 *      word - 
 *      key - 
 * Output:
*        none
*/
bool compareWords(char* word, char* key) {
  uint8_t i = 0, j = 0;
  while (*(word + i) != '\0' && *(key + j) != '\0'){
    int wordAscii = (int)(*(word + i));
    int keyAscii = (int)(*(key + j));
    if (wordAscii > keyAscii){
      return true;
    } else if (wordAscii < keyAscii) {
      return false;
    }
    i++; j++;
  }
  return false;
}

/**
 * Function: SortWords
 * Description: Arranging words that increases the value
 * Input:
 *      words - an Word value with datatype by user define
 * Output:
 *      none
*/

void SortWords(word *words) {
  //Đây là insertion sort
  //quét những từ trong `words` với chiều dài là word->length 
  for (int i = 1; i < words->length; i++) { //xét tại vị trí thứ 1
    char *key = words->word[i]; // tạo một biến phụ để chưa 1 word ở vị trí thứ i
    int j = i - 1; //xét tại vị trí thứ 0 và giảm dần
    // loop while move các element [0,.. j-1] ra phía sau (j+1) nếu lớn hơn `*key` 
    while (j >= 0 && compareWords(words->word[j] , key)) {
      words->word[j+1] = words->word[j];
      j--;
    }
    words->word[j + 1] = key; // gắn đại chỉ key vào word ở index 0
  }
};

/**
 * Function: CountWords
 * Description: Count the appearance of the words in the array pointer
 * Input:
 *      words - an Word value with datatype by user define
 * Output:
 *      none
*/

void CountWords(word *words) {
  for (int i = 0; i < words->length; i++) {
    for (int j = i + 1; j < words->length; j++) {
      uint8_t k = 0, m = 0;
      while(1) {
        if(*((words->word[i]) + k) == '\0' || (*(words->word[j]) + m) == '\0' || *((words->word[i]) + k) != (*(words->word[j]) + m)) {
          if(*((words->word[i]) + k) == (*(words->word[j]) + m)) {
            words->count[i]++;
            words->count[j] = 0;
          }
          break;
        }
      }
    }
  }
}

/**
 * Function: PrintData
 * Description: print data
 * Input:
 *      words - an Word value with datatype by user define
 * Output:
 *      none
*/

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