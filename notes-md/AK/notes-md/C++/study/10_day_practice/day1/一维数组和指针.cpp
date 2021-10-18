#include <iostream>
using namespace std;

int main () {
	// 带有 5 个元素的双精度浮点型数组
	double runoobAarray[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
	double *p;

	p = runoobAarray;

	// 输出数组中每个元素的值
	cout << "使用指针的数组值 " << endl;
	for ( int i = 0; i < 5; i++ ) {
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}

	cout << "使用 runoobAarray 作为地址的数组值 " << endl;
	for ( int i = 0; i < 5; i++ ) {
		cout << "*(runoobAarray + " << i << ") : ";
		cout << *(runoobAarray + i) << endl;
	}
	//使用指针的数组值
	//*(p + 0) : 1000
	//*(p + 1) : 2
	//*(p + 2) : 3.4
	//*(p + 3) : 17
	//*(p + 4) : 50
	//使用 runoobAarray 作为地址的数组值
	//*(runoobAarray + 0) : 1000
	//*(runoobAarray + 1) : 2
	//*(runoobAarray + 2) : 3.4
	//*(runoobAarray + 3) : 17
	//*(runoobAarray + 4) : 50
	
	//p 是一个指向 double 型的指针，这意味着它可以存储一个 double 类型的变量。
	//一旦我们有了 p 中的地址，*p 将给出存储在 p 中相应地址的值，正如上面实例中所演示的。
	return 0;
}
