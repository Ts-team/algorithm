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
void heapSort2(T arr[], int n){
	
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);	//��ʽ2������ 
	for( int i = n-1; i >= 0; i--){		//ȡ������ 
		arr[i] = maxheap.extractMax();
	}
}

///////////////////////////////////////////// 
// ����Ϊ������ʵ�ֶ����������ǳ���Ķ����� 
////////////////////////////////////////////
 
template<typename T>
__shiftDown(T arr[], int n, int k){
	
	while( 2*k+1 < n ) {	//ֻҪ�к��Ӿͱ�����ȥ 
		//�ڴ���ѭ���У� arr[k]arr[j]����λ��
		int j = 2*k + 1;	 
		if( j+1 < n && arr[j+1] > arr[j]){	//�ҳ����Һ����������Ǹ� 
		 	j = j + 1;
		}
		if(arr[k] >= arr[j]){		//��� data[k] >= data[j] ˵�����Һ��Ӷ����Լ�С�� �Ѿ�����˵�������Ҫ���� 
			break;
		}
		swap(arr[k], arr[j]);
		k = j;
	}
}

//ԭ�ض��� 
template<typename T>
void heapSort(T arr[], int n){
	//heapify,�Ƚ��������鰴�ն�����Ĺ����ĺ� 
	for( int i = (n-1)/2; i >=0 ; i-- ){
		__shiftDown(arr, n, i); 
	}
	//�����������飬���������һ��Ԫ���뵹����Ԫ�أ�������i������ŵ���i��λ��,
	//��Խ�����ĵ�һ��Ԫ�����µ����� �����Ľ����ǵ���i 
	for(int i = n-1; i>0; i-- ){
		swap( arr[0], arr[i] );
		__shiftDown(arr, i, 0); 
	}
} 





