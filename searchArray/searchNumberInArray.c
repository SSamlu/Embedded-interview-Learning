/**
 * File: memberAppearsTimes.c
 * Author: Dien Nguyen
 * Date: 09/05/2023
 * Description: tìm kiếm số cho trước trong một mảng
*/

#include<stdint.h>
#include<stdio.h>
// typedef struct {

// };

/**
 * Function: merge
 * Description:  ghép hai mảng con đã được sắp xếp thành một mảng con mới đã được sắp xếp
 * Input:
 *      arr    - an array with datatype integer
 *      left   - an array with datatype integer
 *      lengthLeft  - an integer value
 *      right - an array with datatype integer
 *      lengthRight - an integer value
*/

void merge(int arr[], int left[], int lengthLeft, int right[], int lengthRight) {
  int i = 0, j = 0, k = 0;
  // loop while, so sánh i, j
  while (i < lengthLeft && j < lengthRight) {
    if(left[i] < right[j]) { 
      arr[k++] = left[i++]; // assign `arr[k++]` bằng giá trị của `left[i++]` và tăng k, i lên một đơn vị
    } else {
      arr[k++] = right[j++]; // assign `arr[k++]` bằng giá trị của `right[i++]` và tăng k, j lên một đơn vị
    }
  }
  //
  while (i < lengthLeft) {
    /* code */
    arr[k++] = left[i++];
  }
  while(j < lengthRight) {
    arr[k++] = right[j++];
  }
}

/**
 * Function: sortArray
 * Description: Create a array RaNdom with length random
 * Input:
 *      arr - an array value with datatype integer
 *      length - an integer value
*/

void sortArray(int arr[], int length){
  //nếu length < 2 thì mảng chỉ còn 1 hoặc không còn phần tử nào nên kết thúc hàm
  if (length < 2) {
    return;
  }
  int middle  = length / 2; //tính miiddle để lấy vị trí trung tâm của mảng
  int left[middle], right[length - middle]; // toạn hai mảng điển lưu trữ giá trị ở mảng ban đầu
  for (int i = 0; i < middle; i++) {
    left[i] = arr[i]; //assign giá trị arr vào left
  }

  for (int i = middle; i < length; i++) {
    right[i - middle] = arr[i]; //assign giá trị arr vào right
  }
  sortArray(left, middle); // đệ quy nhằm tách ra thành hai mảng con nhỏ hơn ở bên vị trí bên trái middle
  sortArray(right, length - middle); // đệ quy nhằm tách ra thành hai mảng con nhỏ hơn ở bên vị trí bên phải middle
  merge(arr, left, middle, right, length - middle); //merge và sắp xếp lại mảng
};

/**
 * Function: binarySearch
 * Description: Create a array RaNdom with length random
 * Input:
 *      arr    - an array with datatype integer
 *      left   - an integer value
 *      right  - an integer value
 *      target - an integer value
*/

int binarySearch(int arr[], int left, int right, int target) {
  // kiểm tra xem `left` >= `right` không, không thì return -1;
  if(right >= left) {
    int middle = left+ (right - left) / 2; // tính middile bằng cách xét giá trị trung bình của `left` và `right`
    if(arr[middle] == target) { // nếu giá trị arr tại vị trí middle  bằng với target muốn tìm thì
      return middle; // return về middle
    } else if(arr[middle] > target) { //nếu giá trị arr tại vị trí middle lớn hơn với target muốn tìm thì xét nữa bên trái của middle
      return binarySearch(arr, left, middle - 1, target); // gọi hàm đệ quy  với tham sô từ là left, arr, target như lúc đầu nhưng right là thì là (middle - 1)
    } else { //nếu giá trị arr tại vị trí middle nhỏ hơn với target muốn tìm thì ta xét nữa bên phải của middle
      return binarySearch(arr, middle + 1, right, target); // gọi hàm đệ quy  với tham sô từ là right, arr, target như lúc đầu nhưng left là thì là (middle + 1)
    }
  }
  return -1;
}

/**
 * Function: printData
 * Description: print Data
 * Input:
 *      arr    - an array with datatype integer
 *      length   - an integer value
*/

void printData(int arr[], int length) {
  printf("Sorted array: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[] = { 10, 7, 8, 9, 1, 5 };
  int length = sizeof(arr) / sizeof(arr[0]);
  int target = 10;
  sortArray(arr, length);
  printData(arr, length);
  int index = binarySearch(arr, 0, length - 1, target);
  if(index == -1) {
    printf("\nso %d khong tim thay", target);
  } else {
    printf("\nso %d duoc tim thay o vi tri thu %d", target, index);
  }
  return 0;
}