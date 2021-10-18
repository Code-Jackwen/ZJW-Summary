#include <iostream>
 
using namespace std;
const int MAX = 3;
 const int MAX1 = 4;
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int *ptr[MAX];
 
   for (int i = 0; i < MAX; i++)
   {
      ptr[i] = &var[i]; // 赋值为整数的地址
   }
   for (int i = 0; i < MAX; i++)
   {
      cout << "Value of var[" << i << "] = ";
      cout << *ptr[i] << endl;//10\100\200
   }
   
   
   cout<<endl;
   cout<<endl;
   cout<<endl;
   
   //char *names[MAX] 是指针数组, 它的本质是存储指针的数组, 即：存储 char 类型的指针的数组,
   // 数组内的每个元素都是一个指针指向一个存储 char 类型的地址:
    const char *names[MAX1] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };

    for (int i = 0; i < MAX1; i++) {
    	//names[i] 拿到 char[]数组的第一个地址后，默认会给它输出完。 
        cout << " --- names[i]              = " << names[i] << endl;				// Zara Ali 	Hina Ali	
        cout << " --- *names[i]             = " << *names[i] << endl;				// Z			H
        cout << endl;
        cout << " --- (*names[i] + 1)       = " << (*names[i] + 1) << endl;			//91			73
        cout << " --- (char)(*names[i] + 1) = " << (char)(*names[i] + 1) << endl;	//[				I
        cout << " ------------------------------------ " << endl << endl << endl << endl;
    }
   
   
//   char abc = (char)(73-'a');//依然输出不来 
	int abc	= 'I';
   int abc1 = 'a';
   cout<<abc<<endl;//73
   cout<<abc1<<endl;//97
   
   return 0;
}
