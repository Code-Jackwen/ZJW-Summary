//sizeof 是一个关键字，用于判断变量或数据类型的字节大小。
//sizeof 运算符可用于获取类、数据类型、结构、共用体和其他用户自定义数据类型的大小。

#include <iostream>
using namespace std;
 
int main()
{
   cout << "Size of char : " << sizeof(char) << endl;//1
   cout << "Size of short int : " << sizeof(short int) << endl;//2
   
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;//2
   
   cout << "Size of int : " << sizeof(int) << endl;//4
   cout << "Size of long int : " << sizeof(long int) << endl;//4
   cout << "Size of float : " << sizeof(float) << endl;//4
   cout << "Size of double : " << sizeof(double) << endl;//8
   return 0;
}
