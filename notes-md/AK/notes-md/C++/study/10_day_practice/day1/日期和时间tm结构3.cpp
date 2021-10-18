#include <iostream>
#include <ctime>
 
using namespace std;
 
 //tm 结构在 C/C++ 中处理日期和时间相关的操作时，显得尤为重要.
 //下面的实例使用了 tm 结构和各种与日期和时间相关的函数。 
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
 
   cout << "1970 到目前经过秒数:" << now << endl;
 
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;//年: 2021
   cout << "月: "<< 1 + ltm->tm_mon<< endl;//月: 4
   cout << "日: "<<  ltm->tm_mday << endl;//日: 30
   cout << "时间: "<< ltm->tm_hour << ":";//时间: 21:16:2
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}
