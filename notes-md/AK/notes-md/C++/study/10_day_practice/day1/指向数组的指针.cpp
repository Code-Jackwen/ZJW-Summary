#include <iostream>
using namespace std;

int main () {
	// ���� 5 ��Ԫ�ص�˫���ȸ���������
	double runoobAarray[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
	double *p;

	p = runoobAarray;

	// ���������ÿ��Ԫ�ص�ֵ
	cout << "ʹ��ָ�������ֵ " << endl;
	for ( int i = 0; i < 5; i++ ) {
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}

	cout << "ʹ�� runoobAarray ��Ϊ��ַ������ֵ " << endl;
	for ( int i = 0; i < 5; i++ ) {
		cout << "*(runoobAarray + " << i << ") : ";
		cout << *(runoobAarray + i) << endl;
	}

	return 0;
}
