#include <iostream>
using namespace std;

#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

int main() {
//    const double pi;                      //圆周率的值用pi表示
//    pi=3.14159265;//这里报错，不能再被赋值

	const double pi=3.141592;            //圆周率的值用pi表示

	cout<<"圆周率的近似值是"<<pi<<endl;



	//在 C++ 中，有两种简单的定义常量的方式：使用 #define 预处理器。使用 const 关键字。


	//#define LENGTH 10
	int area;
	area = LENGTH * WIDTH;
	cout << area;
	cout << NEWLINE;


	//const
	const int  a = 10;
	const int  s  = 5;
	const char d = '\n';
	int f;

	area = a * s;
	cout << d;
	cout << f;




//宏定义 #define 和常量 const 的区别

//1、类型和安全检查不同
//宏定义是字符替换，没有数据类型的区别，同时这种替换没有类型安全检查，可能产生边际效应等错误；
//const常量是常量的声明，有类型区别，需要在编译阶段进行类型检查

//2、编译器处理不同
//宏定义是一个"编译时"概念，在预处理阶段展开，不能对宏定义进行调试，生命周期结束于编译时期；
//const常量是一个"运行时"概念，在程序运行使用，类似于一个只读行数据


//3、存储方式不同
//宏定义是直接替换，不会分配内存，存储与程序的代码段中；
//const常量需要进行内存分配，存储与程序的数据段中

//4、定义域不同
//void f1 ()
//{
//    #define N 12
//    const int n 12;
//}
//void f2 ()
//{
//    cout<<N <<endl; //正确，N已经定义过，不受定义域限制
//    cout<<n <<endl; //错误，n定义域只在f1函数中
//}

//5、定义后能否取消
//宏定义可以通过#undef来使之前的宏定义失效
//const常量定义后将在定义域内永久有效
//void f1()
//{
//  #define N 12
//  const int n = 12;
//
//  #undef N //取消宏定义后，即使在f1函数中，N也无效了
//  #define N 21//取消后可以重新定义
//}

//6、是否可以做函数参数
//宏定义不能作为参数传递给函数
//const常量可以在函数的参数列表中出现

	return 0;
}
