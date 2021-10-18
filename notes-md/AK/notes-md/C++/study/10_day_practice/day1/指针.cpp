#include <iostream>
 
using namespace std;
 
int main ()
{
	//每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。 
   int  var1;
   char var2[10];
 
   cout << "var1 变量的地址： ";
   cout << &var1 << endl;//0x70fe1c
 
   cout << "var2 变量的地址： ";
   cout << &var2 << endl;//0x70fe10
 
   return 0;
}
