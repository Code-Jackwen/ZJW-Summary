#include <iostream>
using namespace std;

//其他例子： 
int &changevalue()
{
    static int b =-29;
    
    cout<<"b的地址："<<&b<<endl;
    return b;
}

int main()
{
    int &a_return=changevalue();//0x472010
    
    cout<<"a_return的地址："<<&a_return<<endl;//0x472010
    
    a_return =20;		// 
    
    cout<<"a_return的地址："<<&a_return<<endl;//0x472010
    
    int &c = changevalue();//0x472010
    
    cout<<"&c："<<&c<<endl;//0x472010
    cout<<"c："<<c<<endl;//20
    
    cout<<changevalue()<<endl;//	0x472010   然后 20
    cout<<c<<endl;//20
    
    a_return = 1;
    cout<<"a_return的地址："<<&a_return<<endl;//0x472010
	cout<< a_return<<endl;
    
}
