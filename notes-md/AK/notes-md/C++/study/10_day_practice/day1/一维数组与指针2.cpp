#include <iostream>
using namespace std;
const int MAX = 3;

int main () {
	char  var[MAX] = {'a', 'b', 'c'};
	char  *ptr;
	// 指针中的数组地址
	ptr = var;

	cout<<ptr<<endl;//abc		C++ 中，将 char * 或 char[] 传递给 cout 进行输出，结果会是整个字符串
	ptr = ++ptr;
	cout<<ptr<<endl;//bc
	ptr = ++ptr;
	cout<<ptr<<endl;//c
	

//	for (int i = 0; i < MAX; i++) {
//		cout << "Value of var[" << i << "] = ";
//		cout << *ptr << endl;
//		// 移动到下一个位置
//		ptr++;
//		//a
//		//b
//		//c
//	}
//如果想要获得字符串的地址（第一个字符的内存地址），可使用以下方法
//一、 
//	ptr = var;
//	for (int i = 0; i < MAX; i++) {					
//		cout << "Address of var[" << i << "] = ";
//		cout << (int *)ptr << endl;
//		// 移动到下一个位置
//		ptr++;
//	}
	
	//Address of var[0] = 0x70fe00
	//Address of var[1] = 0x70fe01
	//Address of var[2] = 0x70fe02
	
	//Address of var[0] = 0x70fe03
	//Address of var[1] = 0x70fe04
	//Address of var[2] = 0x70fe05
//二、 	
//C/C++ 对 char 型数组做了特殊规定，直接输出首地址时，会输出数组内容。如果想得到地址，可采用 & 。
//  char name[] = {"Zara Ali"};
//  cout << name << endl; // 输出 Zara Ali
//  cout << &name << endl; // 输出 0x7ffe08e50977 
	
	cout<<&var[0]<<endl;//abc
	
	
	return 0;
}
//https://www.runoob.com/cplusplus/cpp-pointer-to-an-array.html
//https://www.runoob.com/cplusplus/cpp-arrays.html
