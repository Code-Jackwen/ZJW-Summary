#include <iostream>

using namespace std;

int main () {
	//C++ 提供了以下两种类型的字符串表示形式：
	//C 风格字符串，这是这个类展示的。 
	//C++ 引入的 string 类类型
	char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};

	cout << "菜鸟教程: ";
	cout << site << endl;//菜鸟教程: RUNOOB

	char a[] = "RUNOOB";
	cout << a << endl;//RUNOOB

	return 0;
}
