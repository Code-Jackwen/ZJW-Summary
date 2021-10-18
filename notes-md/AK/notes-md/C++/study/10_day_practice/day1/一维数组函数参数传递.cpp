#include <iostream>
using namespace std;

//数组的形参可以是 一个头指针，或者数组。 
//方法一： void myFunction(int *param)		形式参数是一个指针：
//方法二： void myFunction(int param[10])	形式参数是一个已定义大小的数组：
//方法三： void myFunction(int param[])		形式参数是一个未定义大小的数组：

// 函数声明
double getAverage(int arr[], int size);
 
int main ()
{
   // 带有 5 个元素的整型数组
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   // 传递一个指向数组的指针作为参数
   avg = getAverage( balance, 5 ) ;
 
   // 输出返回值
   cout << "平均值是：" << avg << endl; 
    
   return 0;
}

double getAverage(int arr[], int size)
{
  int    i, sum = 0;       
  double avg;          
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
   }
 
  avg = double(sum) / size;
 
  return avg;
}
