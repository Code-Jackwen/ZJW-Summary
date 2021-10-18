//https://www.runoob.com/cplusplus/cpp-data-types.html

//C++ 有内置数据类型	和		用户自定义的数据类型。下表列出了七种基本的 C++ 数据类型：
//类型	关键字
//布尔型	bool
//字符型	char
//整型		int
//浮点型	float
//双浮点型	double
//无类型	void
//宽字符型	wchar_t

//其实 wchar_t 是这样来的：
//typedef short int wchar_t;
//所以 wchar_t 实际上的空间是和 short int 一样。			

//short int			2 个字节	-32768 到 32767
//short:         所占字节数：2   -32768 到32767      
//int				4 个字节	-2147483648 到 2147483647
//long int			8 个字节	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
//long double		16 个字节	长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。
//wchar_t			2 或 4 个字节	1 个宽字符

//一些基本类型可以使用一个或多个类型修饰符进行修饰：
//signed		
//unsigned		例如：unsigned char	1 个字节	0 到 255
//short
//long

//typedef 声明,使用 typedef 为一个已有的类型取一个新的名字
//typedef int feet;
//feet x;

#include<iostream>  
#include <limits>
 
using namespace std;  

int main()  
{  
	//变量的大小会根据编译器和所使用的电脑而有所不同。
	//下面实例会输出您电脑上各种数据类型的大小。
	
	//sizeof() 函数用来获取各种数据类型的大小。
	
    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);  
    cout << "\t最大值：" << (numeric_limits<bool>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;  
    
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
    cout << "\t最大值：" << (numeric_limits<char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl; 
	 
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;  
    
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);  
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;  
    
    
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);  
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;  
    
    
    
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);  
    cout << "\t最大值：" << (numeric_limits<short>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;  
    
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);  
    cout << "\t最大值：" << (numeric_limits<int>::max)();  
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;  
    
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);  
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;  
    
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);  
    cout << "\t最大值：" << (numeric_limits<long>::max)();  
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;  
    
    
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);  
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;  
    
    
    cout << "double: \t" << "所占字节数：" << sizeof(double);  
    cout << "\t最大值：" << (numeric_limits<double>::max)();  
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;  
    
    
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);  
    cout << "\t最大值：" << (numeric_limits<long double>::max)();  
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;  
    
    
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);  
    cout << "\t最大值：" << (numeric_limits<float>::max)();  
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;  
    
    
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);  
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();  
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;  
    
    
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;  
    
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    
    
    cout << "type: \t\t" << "************size**************"<< endl;  
    return 0;  
}
