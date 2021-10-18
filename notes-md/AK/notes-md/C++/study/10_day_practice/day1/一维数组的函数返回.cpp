#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
//一、 
//C++中函数是不能直接返回一个数组的，但是数组其实就是指针，所以可以让函数返回指针来实现:
//int * myFunction()

//二、 
//另外，C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
 
 
// 要生成和返回随机数的函数
int * getRandom( )
{
  static int  r[10];
 
  // 设置种子
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }
 
  return r;
}
 
// 要调用上面定义函数的主函数
int main ()
{
   // 一个指向整数的指针
   int *p;
 
   p = getRandom();
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }
 
   return 0;
}
