#include <algorithm>
using namespace std;

/*
	O(nlogn)���ö��ֵ�˼�뽫���⻯�⵽logn�㼶��֮��ÿ���㼶�� O(n)������㷨������
 */ 

 
//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢  
template<typename T>
void __merge(T arr[], int l, int mid, int r){
	T aux[r - l + 1];	//��ʱ�ݴ����� 
	//��arr[l, r] ��ֵ�ŵ�aux[0, r-l] 
	for(int i = l; i <= r; i++){
		aux[i - l] = arr[i];
	}
	// i Ϊǰһ���������ʼ�㣬 j = m+1 Ϊ��һ���������ʼ�� 
	int i = l, j = mid + 1;
	
	for(int k = l; k <= r; k++) {
		// �߽��жϣ� �����߽綼������߽�Ӧ�еĽ��޾��������丳ֵ 
		if(i > mid){
			arr[k] = aux[j - l];
			j++; 
		} else if(j > r){		//����ұ߽�������ұ߽�Ӧ�еı߽���������丳ֵ 
			arr[k] = aux[i - l];
			i++;
		} else if(aux[i - l] < aux[j - l]){	//��������, �ڴ�֮ǰ��ÿ���Խ������ 
			arr[k] = aux[i - l];
			i++;
		} else {
			arr[k] = aux[j - l];
			j++;
		}
	}
}
 
 //�ݹ�ʹ�ù鲢���򣬶�arr[l..r]�ķ�Χ�������� 
template<typename T>
void __mergeSort(T arr[], int l, int r){
	
//	if(l >= r) {	//��ʾ��������ݼ�Ϊ�ջ򲻴��� 
//		return; 
//	}
	//�Ż�����ΧС��16ʱʹ�ò������� ��Ϊnlogn��nС��ʱ��û̫������ 
	if(r - l <= 15){
		InsertionSort::insertionSort(arr, l, r);
		return;
	}
	
	
	int mid = (l + r) / 2; //����ݹ���ص� 
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	//������һ���Ƚϴ�ĸĽ�����ǰһ�����ֵ����ֵС�ں�һ�����ֵ���Сֵ��ʱ����ʼ�����Ѿ������� �� ��������������жϻ���������������ÿ�ܶ�
	if(arr[mid] > arr[mid+1]){
		__merge(arr, l, mid, r);	//�鲢 
	}
}

/**
 	�鲢����
 	O(nlogn)
	ȱ��: ��Ҫ����ʹ��n�洢�ռ� 
 */ 
template<typename T>
void mergeSort(T arr[], int n){
	
	__mergeSort(arr, 0, n-1);
}


//�Ե����ϵĹ鲢���� 
//�ɶ��������nlogn�������� 
template<typename T>
void mergeSortBU(T arr[], int n){
	
	for(int sz = 1; sz <= n; sz += sz){	//�Խ��������������б���  (ȷ��ÿ�ι鲢���ٸ��� ��һ��ÿ��2���� �ڶ���4��....ֱ��ÿ�ֹ鲢n��)
		for(int i = 0; i + sz < n; i += sz + sz){	//ÿ�ΰ��������鰴��sz��С�鲢��һ�� ���������0��Ԫ�أ� ���� sz+sz��������ÿ��������ȥ�鲢��
			//��arr[i, i+sz-1]��arr[i+sz, i+sz*2-1]  
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n-1) );
		}
	} 
}





