#include<iostream>
#include<string>
using namespace std;

struct Student{
	string name;
	int score;
	//�Ƚ��������
	bool operator<(const Student &otherStudent){
		return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
	}
	//���������
	friend ostream& operator<<(ostream &os, const Student &student){
		os << "Student: " << student.name << " " << student.score<< endl;
		return os;
	} 
};
//Student d[4] = {{"D", 90},{"C", 100},{"B", 80},{"A", 80}, };
//selectionSort(d, 4);
//for(int i = 0; i<4; i++) {
//	cout << d[i];
//}
