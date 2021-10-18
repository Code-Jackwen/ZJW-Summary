//指向指针的指针是一种多级间接寻址的形式，或者说是一个		指针链。
//指针的指针就是将指针的地址存放在另一个指针里面。	

#include <iostream>
 
using namespace std;
 
int main ()
{
    int  var;
    int  *ptr;
    int  **pptr;			//定义是是 两个**  访问也是两个** 
 
    var = 3000;
 
    // 获取 var 的地址
    ptr = &var;
 
    // 使用运算符 & 获取 ptr 的地址
    pptr = &ptr;
 
    // 使用 pptr 获取值
    cout << "var 值为 :" << var << endl;			//3000
    cout << "*ptr 值为:" << *ptr << endl;			//3000
    cout << "**pptr 值为:" << **pptr << endl;		//3000
    
    cout << "var 地址为 :" << &var << endl;			//0x70fe0c
    cout << "ptr=&var 值为var的地址:" << ptr << endl;//0x70fe0c
    
    cout << "*pptr=ptr=&var  值为var的地址:" << *pptr << endl;	//0x70fe0c		!!!
    
    cout << "ptr地址为:" << &ptr << endl;			//0x70fe00
    cout << "pptr 地址为:" << &pptr << endl;		//0x70fdf8
 	
    return 0;
}
