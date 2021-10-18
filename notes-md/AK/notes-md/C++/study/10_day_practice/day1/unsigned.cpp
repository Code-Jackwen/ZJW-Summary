#include <iostream>
using namespace std;

/*
 * 这个程序演示了有符号整数和无符号整数之间的差别
*/
int main() {
	short int i;           // 有符号短整数
	short unsigned int j;  // 无符号短整数

	j = 50000;

	i = j;
	cout << i << " " << j;

	return 0;
	//当上面的程序运行时，会输出下列结果：
	//-15536 50000
}
