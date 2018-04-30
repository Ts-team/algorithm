#include<iostream>
#include<ctime>
#include<cassert>
#include<vector>   

using namespace std;

namespace SortTestHelper{
	//������n��Ԫ�ص�������飬ÿ��Ԫ�������Χ ��rangeL, rangeR�� 
	int *generateRandomArray(int n, int rangeL, int rangeR){
		
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for(int i = 0; i <n; i++){
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		
		return arr;	
	}
	
	//����һ���������������
	int *generateNearlyOrderedArray(int n, int swapTimes){
		
		//������һ��0��n-1�������飬 �������ѡswapTimes�Խ��н��� 
		int *arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = i;
		}
		srand(time(NULL));
		for( int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap( arr[posx], arr[posy] );
		}
		return arr;
	}
	
	//����һ�����������
	int *generateAscendingOrderArray(int n){ 
	
		int *arr = new int[n];

		for(int i = 0; i < n; i++) {
			arr[i] = i;
		}
		return arr;
	}
	//����һ�����������
	int *generateDescendingDisordeArray(int n){
		
		int *arr = new int[n];
		for(int i = n-1; i >= 0; i--) {
			arr[i] = i;
		}
		return arr;
	}
	
	//��ӡ���� 
	template<typename T>
	void printArray(T arr[], int n) {
		
		for(int i = 0; i<n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		
		return;
	}
	
	//�����Ƿ�����ɹ�
	template<typename T>
	bool isSorted(T arr[], int n) {
		
		for(int i = 0; i < n-1; i++){
			if(arr[i] > arr[i+1]){
				return false;
			}
		}
		
		return true;
	} 
	
	//�������� ��ӡִ��ʱ�� 
	//���뺯������ ������������ �������飬 �������鳤�� 
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int n), T arr[], int n ) {
		
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		
		assert( isSorted(arr, n) );
		//CLOCKS_PER_SEC ��ʾÿ����ʱ���������ڵĸ��� 
//		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		cout << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
		return;
	}
	
	//����һ��int�����飬�Ա����ڱȽ�ͬһ�����²�ͬ������Ч��
	int *copyIntArray(int a[], int n) {
		
		int* arr = new int[n];
		copy(a, a+n, arr);
		return arr;
	} 
}
