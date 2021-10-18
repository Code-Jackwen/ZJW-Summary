#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
 //注意 
 //C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static变量。 
 
// 要生成和返回随机数的函数
int * getRandom( )
{
  static int  r[10];//静态的 
//   int  r[10];//非静态的 		会很乱，对应不上 !
 
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
