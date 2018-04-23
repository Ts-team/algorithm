#include"MaxHeap.h"
using namespace std;

//��0��ʼ�����ӽ��ѣ������ȡ����ɾ���� 
template<typename T>
void heapSort1(T arr[], int n) {
	
	MaxHeap<T> maxheap = MaxHeap<T>(n); 
	for( int i = 0; i < n; i++){
		maxheap.insert(arr[i]);
	}
	
	for(int i = n - 1; i >= 0; i--){
		arr[i] = maxheap.extractMax();
	}
}

// ֱ�ӽ������ϴ� length / 2���ֿ�ʼ��ǰ���µ��� 
template<typename T>
void heapSort2(T arr[], int n) {
	
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);	//��ʽ2������ 
	for( int i = n-1; i >= 0; i--){		//ȡ������ 
		arr[i] = maxheap.extractMax();
	}
}
