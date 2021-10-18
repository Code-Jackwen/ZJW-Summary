#include <iostream>
#include <ctime>

using namespace std;

// 在写函数时应习惯性的先声明函数，然后在定义函数
void getSeconds(unsigned long *par);

// 函数声明
double getAverage(int *arr, int size);

int main () {
	unsigned long sec;


	getSeconds( &sec );

	// 输出实际值
	cout << "Number of seconds :" << sec << endl;//1619775112




	//能接受指针作为参数的函数，也能接受数组作为参数，如下所示：
	
	// 带有 5 个元素的整型数组
	int balance[5] = {1000, 2, 3, 17, 50};
	// 传递一个指向数组的指针作为参数
	double 	avg = getAverage( balance, 5 ) ;

	// 输出返回值
	cout << "Average value is: " << avg << endl;//214.4


	return 0;
}

void getSeconds(unsigned long *par) {
	// 获取当前的秒数
	*par = time( NULL );
	return;
}


double getAverage(int *arr, int size) {
	int    i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	avg = double(sum) / size;
	return avg;
}
