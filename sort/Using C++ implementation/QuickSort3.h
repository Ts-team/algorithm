using namespace std;

//��·���� 
// ��arr[l, r]��Ϊ  <v; ==v; >v�������� ��֮���ֻ�� < v; >v; �������ֽ��еݹ� 


template<typename T>
void __quickSort3(T arr[], int l, int r) {
//	if(l >= r){
//		return;
//	}
	if(r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}
	
	//patition
	swap(arr[l], arr[rand()%(r-l+1)+l] );
	T v = arr[l];
	 
	//�����黮�ֳ�3������ 
	int lt = l; 	//arr[l+1, lt] < v
	int gt = r + 1;	//arr[gt,r]>v
	int i = l + 1;	//arr[lt+1,i) == v	
	while( i < gt){
		if(arr[i] < v){	//���С�ڻ�׼���� �ͽ����ŵ�С���������ң��ŵķ�ʽ���Ǻ͵�������ĵ�һ��Ԫ�ؽ��н��� 
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		} else if( arr[i] > v){	//������ڻ�׼�����ͽ����ŵ����������ǰһ��λ�� �� �ŵķ������Ǻ��Ǹ�Ԫ�ؽ��н��� 
			swap(arr[i], arr[gt - 1]);
			gt--;
		} else {	//���ڻ�׼�� 
			i++;
		} 
	}

	swap(arr[l], arr[lt]);	//����׼ֵ��С���������ҵ�Ԫ�ؽ��н���
	
	__quickSort3(arr, l, lt-1);
	__quickSort3(arr, gt, r);
}

template<typename T>
void quickSort3(T arr[], int n) {
	srand(time(NULL)); 	//��������ӣ� Ϊ���Ż������������ 
	__quickSort3(arr, 0, n-1);
}

