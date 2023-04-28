#include<stdint.h>
#include<stdio.h>
// typedef struct {

// };
void merge(int arr[], int left[], int lengthLeft, int right[], int lengthRight) {
  int i = 0, j = 0, k = 0;
  while (i < lengthLeft && j < lengthRight) {
    if(left[i] < right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }
  while (i < lengthLeft) {
    /* code */
    arr[k++] = left[i++];
  }
  while(j < lengthRight) {
    arr[k++] = right[j++];
  }
}

void sortArray(int arr[], int length){
  if (length < 2) {
    return;
  }
  int middle  = length / 2;
  int left[middle], right[length - middle];
  for (int i = 0; i < middle; i++) {
      left[i] = arr[i];
  }

  for (int i = middle; i < length; i++) {
    right[i - middle] = arr[i];
  }
  sortArray(left, middle);
  sortArray(right, length - middle);
  merge(arr, left, middle, right, length - middle);
};

int binarySearch(int arr[], int left, int right, int target) {
  if(right >= left) {
    int middle = left+ (right - left) / 2;
    if(arr[middle] == target) {
      return middle;
    } else if(arr[middle] > target) {
      return binarySearch(arr, left, middle - 1, target);
    } else {
      return binarySearch(arr, middle + 1, right, target);
    }
  }
  return -1;
}
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