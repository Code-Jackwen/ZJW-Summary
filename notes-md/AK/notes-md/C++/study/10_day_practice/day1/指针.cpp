#include <iostream>
 
using namespace std;
 
int main ()
{
	//ÿһ����������һ���ڴ�λ�ã�ÿһ���ڴ�λ�ö������˿�ʹ�����ֺţ�&����������ʵĵ�ַ������ʾ�����ڴ��е�һ����ַ�� 
   int  var1;
   char var2[10];
 
   cout << "var1 �����ĵ�ַ�� ";
   cout << &var1 << endl;//0x70fe1c
 
   cout << "var2 �����ĵ�ַ�� ";
   cout << &var2 << endl;//0x70fe10
 
   return 0;
}
