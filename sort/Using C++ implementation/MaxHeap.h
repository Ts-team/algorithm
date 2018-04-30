#include<cassert>
using namespace std;

template<typename Item>
class MaxHeap{
	
private:
	Item* data;
	int count;
	int capacity;
	
	void shiftUp(int k){	//���Խ�k���Ԫ�����ϵ���˳�� 
		while(k > 1 && data[k/2] < data[k] ){
			swap( data[k/2], data[k] );
			k /= 2;
		} 
	}
	
	void shiftDown(int k) {	//���Խ�k���Ԫ�����µ���˳�� 
		
		while( 2*k <= count ) {	//ֻҪ�к��Ӿͱ�����ȥ 
			//�ڴ���ѭ���У� data[k]��data[j]����λ��
			int j = 2*k;	 
			if( j+1 <= count && data[j+1] > data[j]){	//�ҳ����Һ����������Ǹ� 
			 	j = j + 1;
			}
			if(data[k] >= data[j]){		//��� data[k] >= data[j] ˵�����Һ��Ӷ����Լ�С�� �Ѿ�����˵�������Ҫ���� 
				break;
			}
			swap(data[k], data[j]);
			k = j;
		} 
	}
	
	
public:
	//���캯���� ����������ʵ�� 
	MaxHeap(int capacity){	
		data = new Item[capacity+1];
		count = 0;
		this->capacity = capacity;
	}
	
	//���캯��������������ʵ�ַ��� 
	//ȱ�㣺�ķѶ���ռ䣬
	//�ŵ㣺�����ѵ�ʱ�临�Ӷ��½��� O(n) 
	MaxHeap(Item arr[], int n){	
		data = new Item[n+1];
		capacity = n;
		for(int i = 0; i <n; i++) {	//���� 
			data[i+1] = arr[i];
		}
		count = n;
		for( int i = count/2; i >= 1; i--){	//�������µ��� 
			shiftDown(i);
		}
	}
	
	~MaxHeap(){		//���� 
		delete[] data;
	}
	
	int size(){		//���ضѴ�С 
		return count;
	}
	
	bool isEmpty(){	//���Ƿ�Ϊ�� 
		return count == 0;
	}
	
	void insert(Item item) {
		
		assert( count + 1 <= capacity );
		data[count+1] = item;
		count++;
		shiftUp( count );
	}
	
	Item extractMax(){	//ȡ������������ 
		
		assert( count > 0 );
		Item max = data[1];
		
		swap( data[1], data[count]);	
		count--; 
		shiftDown(1);
		return max;
	}
};
