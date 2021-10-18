//引用很容易与指针混淆，它们之间有三个主要的不同：
//
//1、不存在空引用。引用必须连接到一块合法的内存。
//2、一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
//3、引用必须在创建时被初始化。指针可以在任何时间被初始化。

//引用就是，一个具备常量特点的指针！

#include <iostream>

using namespace std;

int main () {
	// 声明简单的变量
	int    i;
	double d;

	// 声明引用变量			& 读作引用
	int&    r = i;
	double& s = d;			//读作 "s 是一个初始化为 d 的 double 型引用

	i = 5;
	cout << "Value of i : " << i << endl;//5
	cout << "Value of i reference : " << r  << endl;//5


	return 0;
}
