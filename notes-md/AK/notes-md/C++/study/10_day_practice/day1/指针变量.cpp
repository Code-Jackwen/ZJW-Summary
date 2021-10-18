#include <iostream>
 
using namespace std;
//指针：动态内存分配，没有指针是无法执行的。

//指针是一个变量，其值为另一个变量的地址
//int    *ip;    /* 一个整型的指针 */
//double *dp;    /* 一个 double 型的指针 */
//float  *fp;    /* 一个浮点型的指针 */
//char   *ch;    /* 一个字符型的指针 */
//所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，
//都是一样的，都是一个代表内存地址的长的十六进制数。

//不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。

int main ()
{
	//通过使用一元运算符 * 来返回位于操作数所指定地址的变量的值
	
	//定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值
   int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var variable: ";
   cout << var << endl;//20
 
   // 输出在指针变量中存储的地址，不带*就是访问实际地址 
   cout << "Address stored in ip variable: ";
   cout << ip << endl;//0x70fe14
 
   // 访问指针中地址的值，带上* 
   cout << "Value of *ip variable: ";
   cout << *ip << endl;//20
 
   return 0;
}
