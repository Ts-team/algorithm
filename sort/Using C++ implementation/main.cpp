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
	int n = 100000;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);	//������� 
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	
	SortTestHelper::testSort("Heap Sort           ", heapSort2, arr1, n);
	SortTestHelper::testSort("merge Sort          ", mergeSort, arr2, n);
	SortTestHelper::testSort("Double quick Sort   ", quickSort3, arr3, n);
	
//	for(int n = 20000; n <= 500000; n+= 20000){
//	
//		cout  << endl << endl << "n = " << n << endl;
//		
//	//	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);	//������� 
//	//	int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 100);		//�������� 
//	//  int *arr1 = SortTestHelper::generateRandomArray(n, 0, 10);			//�����ظ� 
//		
//		cout << "�������" <<endl; 
//		int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);	//�������
//		
//		//���鿽�� 
//		int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//		
//		SortTestHelper::testSort("merge Sort          ", mergeSort, arr1, n);
//		SortTestHelper::testSort("Double quick Sort   ", quickSort3Ways, arr2, n);
//		
//		delete[] arr1;
//		delete[] arr2;
//		
//		cout << "��������" <<endl; 
//		arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10);	//��������
//		
//		//���鿽�� 
//		arr2 = SortTestHelper::copyIntArray(arr1, n);
//		
//		SortTestHelper::testSort("merge Sort          ", mergeSort, arr1, n);
//		SortTestHelper::testSort("Double quick Sort   ", quickSort2, arr2, n);
//		
//		delete[] arr1;
//		delete[] arr2;
//		
//		cout << "�ظ�����" <<endl; 
//		arr1 = SortTestHelper::generateRandomArray(n, 0, 10);			//�����ظ� 
//		
//		//���鿽�� 
//		arr2 = SortTestHelper::copyIntArray(arr1, n);
//		
//		SortTestHelper::testSort("merge Sort          ", mergeSort, arr1, n);
//		SortTestHelper::testSort("Double quick Sort   ", quickSort2, arr2, n);
//		
//		delete[] arr1;
//		delete[] arr2;
//	}
	return 0;
}

