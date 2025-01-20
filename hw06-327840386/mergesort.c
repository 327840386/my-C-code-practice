//Compile the source code with: gcc mergesort.c -o mergesort
//Run the source code with: ./mergesort

// Task: Implement the 'sortIntegers' function below, live and while recording
//You must use merge and mergesort with the given function signatures

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int temp[], int l, int m, int r) {
  //TODO: implement merge.
  // You must use all those parameters in your implementation, including temp array 
  int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}


// TODO: Implement your mergeSort function here
void mergeSort(int arr[], int temp[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, temp, l, m);
        mergeSort(arr, temp, m + 1, r);
        merge(arr, temp, l, m, r);
    }
}

void sortIntegers(int* array, unsigned int size){
    // TODO: make a call to your mergeSort function here
    int* temp = (int*)malloc(size * sizeof(int));
    mergeSort(array, temp, 0, size - 1);
    free(temp);
}

void printIntArray(int* array, unsigned int size){
  unsigned int i; 
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(int argc, char** argv){
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);

  return 0;
}
