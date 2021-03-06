#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;
/**
 * 原地堆排序
 */

/**
 * shiftDown 沿着树不断调整位子 
 * 比较左右子树，是否有比自己大的，如果有就和大的那个交换位置
 * 使得大的再上，小的在下
 * 为了维持堆的特性，还得把那个交换到子树上的较小元素拿去尝试对他进行shiftDown
 */
template <typename T>
void __shiftDown(T arr, int pos, int len) {
  // 索引以0开始，左节点： 2 * pos + 1 这里pos会变化，不要提变量
  while(2 * pos + 1 < len){ 
    int j = pos * 2 + 1;  //默认左孩子
    if(j + 1 < len) { //如果有右孩子
      if(arr[j + 1] > arr[j]) {
        j += 1;
      }
    }
    if(arr[pos] < arr[j]) {
      swap(arr[pos], arr[j]);
      pos = j;  //--这步容易忘，因为是循环，所以每次都要对pos进行shiftDown--
    } else {
      break;
    }
  }
}

/**
 * 通用堆排序
 */
template <typename T>
void heapSort(T arr[], int n)
{
  //Heapify
  for(int i = (n-1)/2; i >= 0; i-- ) {
    __shiftDown(arr, i, n);
  }
  //出堆，放到数组末尾
  for(int i = n - 1; i > 0; i--){
    swap(arr[i], arr[0]);
    __shiftDown(arr, 0, i);
  }
}



int main()
{
  int n = 100000;
  cout << "随机数" << endl;
  int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
  SortTestHelper::testSort("heapSort     ", heapSort, arr1, n);

  cout << "近乎有序数" << endl;
  int *arr2 = SortTestHelper::generateNearlyOrderedArray(n, 10);
  SortTestHelper::testSort("heapSort     ", heapSort, arr2, n);

  cout << "大量重复数" << endl;
  int *arr3 = SortTestHelper::generateRandomArray(n, 0, 10);
  SortTestHelper::testSort("heapSort     ", heapSort, arr3, n);
  return 0;
}