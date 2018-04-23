using namespace std;

//��·���� 
//��arr[l, r]���ֽ���patition����
//����p��ʹ��arr[l,p-1]С��arr[p], arr[p+1, r]����arr[p] 
template<typename T>
int __patition(T arr[], int l, int r) {
	
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
void __quickSort(T arr[], int l, int r) {
	if(l >= r){
		return;
	}
//	if(r - l <= 15){
//		InsertionSort::insertionSort(arr, l, r);
//		return;
//	}
	int p = __patition(arr, l, r);
	__quickSort(arr, l, p-1);
	__quickSort(arr, p+1, r); 
}

template<typename T>
void quickSort(T arr[], int n) {
	
	srand(time(NULL)); 	//��������ӣ� Ϊ���Ż������������ 
	__quickSort(arr, 0, n-1);
}

