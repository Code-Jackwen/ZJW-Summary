#include <iostream>
using namespace std;
const int MAX = 3;

int main () {
	char  var[MAX] = {'a', 'b', 'c'};
	char  *ptr;
	// ָ���е������ַ
	ptr = var;

	cout<<ptr<<endl;//abc		C++ �У��� char * �� char[] ���ݸ� cout ���������������������ַ���
	ptr = ++ptr;
	cout<<ptr<<endl;//bc
	ptr = ++ptr;
	cout<<ptr<<endl;//c
	

//	for (int i = 0; i < MAX; i++) {
//		cout << "Value of var[" << i << "] = ";
//		cout << *ptr << endl;
//		// �ƶ�����һ��λ��
//		ptr++;
//		//a
//		//b
//		//c
//	}
//�����Ҫ����ַ����ĵ�ַ����һ���ַ����ڴ��ַ������ʹ�����·���
//һ�� 
//	ptr = var;
//	for (int i = 0; i < MAX; i++) {					
//		cout << "Address of var[" << i << "] = ";
//		cout << (int *)ptr << endl;
//		// �ƶ�����һ��λ��
//		ptr++;
//	}
	
	//Address of var[0] = 0x70fe00
	//Address of var[1] = 0x70fe01
	//Address of var[2] = 0x70fe02
	
	//Address of var[0] = 0x70fe03
	//Address of var[1] = 0x70fe04
	//Address of var[2] = 0x70fe05
//���� 	
//C/C++ �� char ��������������涨��ֱ������׵�ַʱ��������������ݡ������õ���ַ���ɲ��� & ��
//  char name[] = {"Zara Ali"};
//  cout << name << endl; // ��� Zara Ali
//  cout << &name << endl; // ��� 0x7ffe08e50977 
	
	cout<<&var[0]<<endl;//abc
	
	
	return 0;
}
//https://www.runoob.com/cplusplus/cpp-pointer-to-an-array.html
//https://www.runoob.com/cplusplus/cpp-arrays.html
