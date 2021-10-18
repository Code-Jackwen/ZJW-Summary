//https://www.runoob.com/cplusplus/cpp-data-types.html

//C++ ��������������	��		�û��Զ�����������͡��±��г������ֻ����� C++ �������ͣ�
//����	�ؼ���
//������	bool
//�ַ���	char
//����		int
//������	float
//˫������	double
//������	void
//���ַ���	wchar_t

//��ʵ wchar_t ���������ģ�
//typedef short int wchar_t;
//���� wchar_t ʵ���ϵĿռ��Ǻ� short int һ����			

//short int			2 ���ֽ�	-32768 �� 32767
//short:         ��ռ�ֽ�����2   -32768 ��32767      
//int				4 ���ֽ�	-2147483648 �� 2147483647
//long int			8 ���ֽ�	-9,223,372,036,854,775,808 �� 9,223,372,036,854,775,807
//long double		16 ���ֽ�	��˫������ 16 ���ֽڣ�128λ���ڴ�ռ䣬���ṩ18-19λ��Ч���֡�
//wchar_t			2 �� 4 ���ֽ�	1 �����ַ�

//һЩ�������Ϳ���ʹ��һ�������������η��������Σ�
//signed		
//unsigned		���磺unsigned char	1 ���ֽ�	0 �� 255
//short
//long

//typedef ����,ʹ�� typedef Ϊһ�����е�����ȡһ���µ�����
//typedef int feet;
//feet x;

#include<iostream>  
#include <limits>
 
using namespace std;  

int main()  
{  
	//�����Ĵ�С����ݱ���������ʹ�õĵ��Զ�������ͬ��
	//����ʵ��������������ϸ����������͵Ĵ�С��
	
	//sizeof() ����������ȡ�����������͵Ĵ�С��
	
    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "��ռ�ֽ�����" << sizeof(bool);  
    cout << "\t���ֵ��" << (numeric_limits<bool>::max)();  
    cout << "\t\t��Сֵ��" << (numeric_limits<bool>::min)() << endl;  
    
    cout << "char: \t\t" << "��ռ�ֽ�����" << sizeof(char);  
    cout << "\t���ֵ��" << (numeric_limits<char>::max)();  
    cout << "\t\t��Сֵ��" << (numeric_limits<char>::min)() << endl; 
	 
    cout << "signed char: \t" << "��ռ�ֽ�����" << sizeof(signed char);  
    cout << "\t���ֵ��" << (numeric_limits<signed char>::max)();  
    cout << "\t\t��Сֵ��" << (numeric_limits<signed char>::min)() << endl;  
    
    cout << "unsigned char: \t" << "��ռ�ֽ�����" << sizeof(unsigned char);  
    cout << "\t���ֵ��" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t��Сֵ��" << (numeric_limits<unsigned char>::min)() << endl;  
    
    
    cout << "wchar_t: \t" << "��ռ�ֽ�����" << sizeof(wchar_t);  
    cout << "\t���ֵ��" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t��Сֵ��" << (numeric_limits<wchar_t>::min)() << endl;  
    
    
    
    cout << "short: \t\t" << "��ռ�ֽ�����" << sizeof(short);  
    cout << "\t���ֵ��" << (numeric_limits<short>::max)();  
    cout << "\t\t��Сֵ��" << (numeric_limits<short>::min)() << endl;  
    
    cout << "int: \t\t" << "��ռ�ֽ�����" << sizeof(int);  
    cout << "\t���ֵ��" << (numeric_limits<int>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<int>::min)() << endl;  
    
    cout << "unsigned: \t" << "��ռ�ֽ�����" << sizeof(unsigned);  
    cout << "\t���ֵ��" << (numeric_limits<unsigned>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<unsigned>::min)() << endl;  
    
    cout << "long: \t\t" << "��ռ�ֽ�����" << sizeof(long);  
    cout << "\t���ֵ��" << (numeric_limits<long>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<long>::min)() << endl;  
    
    
    cout << "unsigned long: \t" << "��ռ�ֽ�����" << sizeof(unsigned long);  
    cout << "\t���ֵ��" << (numeric_limits<unsigned long>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<unsigned long>::min)() << endl;  
    
    
    cout << "double: \t" << "��ռ�ֽ�����" << sizeof(double);  
    cout << "\t���ֵ��" << (numeric_limits<double>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<double>::min)() << endl;  
    
    
    cout << "long double: \t" << "��ռ�ֽ�����" << sizeof(long double);  
    cout << "\t���ֵ��" << (numeric_limits<long double>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<long double>::min)() << endl;  
    
    
    cout << "float: \t\t" << "��ռ�ֽ�����" << sizeof(float);  
    cout << "\t���ֵ��" << (numeric_limits<float>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<float>::min)() << endl;  
    
    
    cout << "size_t: \t" << "��ռ�ֽ�����" << sizeof(size_t);  
    cout << "\t���ֵ��" << (numeric_limits<size_t>::max)();  
    cout << "\t��Сֵ��" << (numeric_limits<size_t>::min)() << endl;  
    
    
    cout << "string: \t" << "��ռ�ֽ�����" << sizeof(string) << endl;  
    
    // << "\t���ֵ��" << (numeric_limits<string>::max)() << "\t��Сֵ��" << (numeric_limits<string>::min)() << endl;  
    
    
    cout << "type: \t\t" << "************size**************"<< endl;  
    return 0;  
}
