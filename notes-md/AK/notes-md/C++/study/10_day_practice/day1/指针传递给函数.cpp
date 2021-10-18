#include <iostream>
#include <ctime>

using namespace std;

// ��д����ʱӦϰ���Ե�������������Ȼ���ڶ��庯��
void getSeconds(unsigned long *par);

// ��������
double getAverage(int *arr, int size);

int main () {
	unsigned long sec;


	getSeconds( &sec );

	// ���ʵ��ֵ
	cout << "Number of seconds :" << sec << endl;//1619775112




	//�ܽ���ָ����Ϊ�����ĺ�����Ҳ�ܽ���������Ϊ������������ʾ��
	
	// ���� 5 ��Ԫ�ص���������
	int balance[5] = {1000, 2, 3, 17, 50};
	// ����һ��ָ�������ָ����Ϊ����
	double 	avg = getAverage( balance, 5 ) ;

	// �������ֵ
	cout << "Average value is: " << avg << endl;//214.4


	return 0;
}

void getSeconds(unsigned long *par) {
	// ��ȡ��ǰ������
	*par = time( NULL );
	return;
}


double getAverage(int *arr, int size) {
	int    i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	avg = double(sum) / size;
	return avg;
}
