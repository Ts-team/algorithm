#include"SortTestHelper.h"
#include"Student.h"

#include"SelectionSort.h"
#include"InsertionSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"QuickSort1.h"
#include"QuickSort2.h"
#include"QuickSort3.h"
#include"HeapSort.h"

int main() {
//	int n = 5000;
//	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);	//������� 
//	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
//	int *arr4 = SortTestHelper::copyIntArray(arr1, n);
//	int *arr5 = SortTestHelper::copyIntArray(arr1, n);


	for(int n = 20000; n <= 500000; n+= 20000){
	
		cout  << endl << n << endl;
		
//		int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);	//������� 
//		int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 100);		//�������� 
//		int *arr1 = SortTestHelper::generateRandomArray(n, 0, 10);			//�����ظ� 
		
		cout << "�������" <<endl; 
		int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);	//�������
		//���鿽�� 
		int *arr2 = SortTestHelper::copyIntArray(arr1, n);
		int *arr3 = SortTestHelper::copyIntArray(arr1, n);
		
		SortTestHelper::testSort("", mergeSort, arr1, n);
		SortTestHelper::testSort("", quickSort2, arr2, n);
		SortTestHelper::testSort("", heapSort, arr3, n);
		
		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		
		cout << "��������" <<endl; 
		arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10);	//��������
		//���鿽�� 
		arr2 = SortTestHelper::copyIntArray(arr1, n);
		arr3 = SortTestHelper::copyIntArray(arr1, n);
		
		SortTestHelper::testSort("", mergeSort, arr1, n);
		SortTestHelper::testSort("", quickSort2, arr2, n);
		SortTestHelper::testSort("", heapSort, arr3, n);
		
		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		
		cout << "�ظ�����" <<endl; 
		arr1 = SortTestHelper::generateRandomArray(n, 0, 10);			//�����ظ� 
		//���鿽�� 
		arr2 = SortTestHelper::copyIntArray(arr1, n);
		arr3 = SortTestHelper::copyIntArray(arr1, n);
		
		SortTestHelper::testSort("", mergeSort, arr1, n);
		SortTestHelper::testSort("", quickSort2, arr2, n);
		SortTestHelper::testSort("", heapSort, arr3, n);
		
		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
	}
	return 0;
}

