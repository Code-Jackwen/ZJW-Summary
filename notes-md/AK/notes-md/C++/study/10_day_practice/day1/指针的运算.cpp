#include <iostream>
using namespace std;
const int MAX = 3;

//指针的运算 
//可以对指针进行四种算术运算：++、--、+、-。

int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中的数组地址
   //ptr = var;
   ptr = &var[0];//和上边等效 
   
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;//地址 0x70fe00、0x70fe04、0x70fe08 		地址递增为4 
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;//10、100、200 
 
      // 移动到下一个位置
      ptr++;
   }
   
   cout<<endl;
   
   short  arr[MAX] = {10, 100, 200};
   short  *p;
 
   // 指针中的数组地址
   p = arr;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << p << endl;//地址 0x70fde0、 0x70fde2、0x70fde4 		地址递增为2
 
      cout << "Value of var[" << i << "] = ";
      cout << *p << endl;//10、100、200 
 
      // 移动到下一个位置
      p++;
   }
   
   cout<<endl;
   //递减一个指针 
   
   int  arr1[MAX] = {10, 100, 200};
   int  *p1;
 
   // 指针中最后一个元素的地址
   p1 = &arr1[MAX-1];
   for (int i = MAX; i > 0; i--)
   {
      cout << "Address of var[" << i << "] = ";//0x70fdc8 、4、0 
      cout << p1 << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *p1 << endl;
 
      // 移动到下一个位置
      p1--;
   }
   
   
   
   return 0;
}
