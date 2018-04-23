using namespace std;

namespace SelectionSort{

	//ѡ������ 
	template<typename T>
	void selectionSort(T *arr, int n){
		
		//ÿ�ζ��Ѻ�����С���Ǹ�ֵ�����ڵĵ�i��λ�ý�������ô��ɺ��i��λ�þ��ǵ�iС��Ԫ�أ����ź����� 
		for(int i = 0; i < n; i++) {
			// Ѱ��[i, n)�����ڵ���Сֵ 
			int minIndex = i;
			for(int j = i+1; j <n; j++) {
				if(arr[j] < arr[minIndex]){
					minIndex = j;
				}
			}
			swap(arr[i], arr[minIndex]);
		}
	}

}
