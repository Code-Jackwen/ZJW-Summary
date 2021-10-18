#include <iostream>
#include <iomanip>
using namespace std;


//C++ 的 I/O 发生在流中，流是字节序列。如果字节流是从设备（如键盘、磁盘驱动器、网络连接等）流向内存，这叫做输入操作。
//如果字节流是从内存流向设备（如显示屏、打印机、磁盘驱动器、网络连接等），这叫做输出操作。
int main() {

	
//	cout<<setiosflags(ios::left|ios::showpoint);  // 设左对齐，以一般实数方式显示
//	cout.precision(5);       // 设置除小数点外有五位有效数字
//	cout<<123.456789<<endl;
//	cout.width(10);          // 设置显示域宽10
//	cout.fill('*');          // 在显示区域空白处用*填充
//	cout<<resetiosflags(ios::left);  // 清除状态左对齐
//	cout<<setiosflags(ios::right);   // 设置右对齐
//	cout<<123.456789<<endl;
//	cout<<setiosflags(ios::left|ios::fixed);    // 设左对齐，以固定小数位显示
//	cout.precision(3);    // 设置实数显示三位小数
//	cout<<999.123456<<endl;
//	cout<<resetiosflags(ios::left|ios::fixed);  //清除状态左对齐和定点格式
//	cout<<setiosflags(ios::left|ios::scientific);    //设置左对齐，以科学技术法显示
//	cout.precision(3);   //设置保留三位小数
//	cout<<123.45678<<endl;

	//123.46
	//****123.46
	//999.123
	//1.235e+02


//	好像 C++ 没有像 scanf 控制的那么精确，有个 cin.get() 是可以忽略掉一个字符的，但那个字符可以是任何字符，不限定是逗号。
//	比如:
	int a, b, c;
	cin>>a;
	cin.get();
	cin>>b;
	cin.get();
	cin>>c;
	
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;


	return 0;
}
