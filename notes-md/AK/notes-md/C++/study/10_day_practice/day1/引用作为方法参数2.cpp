#include <iostream>
using namespace std;

//以引用作为参数的函数，可以把变量传入，但不能传入常量数值。

int hls(int& a1, int& a2, int& b1, int& b2) { //定义行列式函数
	int temp;
	temp=a1*b2-a2*b1;
	return temp;
}

int hls2(int a1, int a2, int b1, int b2) { //定义行列式函数
	int temp;
	temp=a1*b2-a2*b1;
	return temp;
}

int main() {
	int x1=11;
	int x2=9;
	int y1=15;
	int y2=14;  //定义矩阵
	int result;  //行列式运算结果
	result=hls(x1,x2,y1,y2);   //result=hls(11,9,15,14)会报错
	cout << result << endl;


	cout <<endl;
	cout <<endl;
	cout <<endl;


	result=hls2(11,9,15,14);//会报错
	cout << result << endl;
	
	return 0;
}
