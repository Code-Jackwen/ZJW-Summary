//ָ��ָ���ָ����һ�ֶ༶���Ѱַ����ʽ������˵��һ��		ָ������
//ָ���ָ����ǽ�ָ��ĵ�ַ�������һ��ָ�����档	

#include <iostream>
 
using namespace std;
 
int main ()
{
    int  var;
    int  *ptr;
    int  **pptr;			//�������� ����**  ����Ҳ������** 
 
    var = 3000;
 
    // ��ȡ var �ĵ�ַ
    ptr = &var;
 
    // ʹ������� & ��ȡ ptr �ĵ�ַ
    pptr = &ptr;
 
    // ʹ�� pptr ��ȡֵ
    cout << "var ֵΪ :" << var << endl;			//3000
    cout << "*ptr ֵΪ:" << *ptr << endl;			//3000
    cout << "**pptr ֵΪ:" << **pptr << endl;		//3000
    
    cout << "var ��ַΪ :" << &var << endl;			//0x70fe0c
    cout << "ptr=&var ֵΪvar�ĵ�ַ:" << ptr << endl;//0x70fe0c
    
    cout << "*pptr=ptr=&var  ֵΪvar�ĵ�ַ:" << *pptr << endl;	//0x70fe0c		!!!
    
    cout << "ptr��ַΪ:" << &ptr << endl;			//0x70fe00
    cout << "pptr ��ַΪ:" << &pptr << endl;		//0x70fdf8
 	
    return 0;
}
