using namespace std;

//��·���� 
//��arr[l, r]���ֽ���patition����
//����p��ʹ��arr[l,p-1]С��arr[p], arr[p+1, r]����arr[p] 
template<typename T>
int __patition1(T arr[], int l, int r) {
	
	
	//�Ż��� ���ѡ���׼���� ��ֹ�����������ʱ�临�Ӷ��˻���n^2 
	swap( arr[l] , arr[rand()%(r-l+1)+l] );

	T v = arr[l];
	//arr[l+1, j] < v, arr[j+1, i] > v
	int j = l;
	for(int i = l+1; i <= r; i++){
		if(arr[i] < v){
			swap(arr[i], arr[j+1]);
			j++;
		}
	} 
	swap(arr[l], arr[j]);
	
	return j;
}


//��arr[l, r]���ֽ��п������� 
template<typename T>
void __quickSort1(T arr[], int l, int r) {
//	if(l >= r){
//		return;
//	}
	if(r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}
	int p = __patition1(arr, l, r);
	__quickSort1(arr, l, p-1);
	__quickSort1(arr, p+1, r); 
}

template<typename T>
void quickSort1(T arr[], int n) {
	
	srand(time(NULL)); 	//��������ӣ� Ϊ���Ż������������ 
	__quickSort1(arr, 0, n-1);
}

