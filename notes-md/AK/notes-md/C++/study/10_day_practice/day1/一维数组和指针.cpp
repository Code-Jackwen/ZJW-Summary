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
	//ʹ��ָ�������ֵ
	//*(p + 0) : 1000
	//*(p + 1) : 2
	//*(p + 2) : 3.4
	//*(p + 3) : 17
	//*(p + 4) : 50
	//ʹ�� runoobAarray ��Ϊ��ַ������ֵ
	//*(runoobAarray + 0) : 1000
	//*(runoobAarray + 1) : 2
	//*(runoobAarray + 2) : 3.4
	//*(runoobAarray + 3) : 17
	//*(runoobAarray + 4) : 50
	
	//p ��һ��ָ�� double �͵�ָ�룬����ζ�������Դ洢һ�� double ���͵ı�����
	//һ���������� p �еĵ�ַ��*p �������洢�� p ����Ӧ��ַ��ֵ����������ʵ��������ʾ�ġ�
	return 0;
}
