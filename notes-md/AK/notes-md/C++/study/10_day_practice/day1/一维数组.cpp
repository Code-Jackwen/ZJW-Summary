#include <iostream>
using namespace std;
 
#include <iomanip>
using std::setw;
 
int main ()
{
   int n[ 10 ]; // n ��һ������ 10 ������������
 
 	//��ʼ�����飬double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0}; 
 
   // ��ʼ������Ԫ��          
   for ( int i = 0; i < 10; i++ )
   {
      n[ i ] = i + 100; // ����Ԫ�� i Ϊ i + 100
   }
   cout << "Element" << setw( 13 ) << "Value" << endl;
 
   // ���������ÿ��Ԫ�ص�ֵ                     
   for ( int j = 0; j < 10; j++ )
   {
      cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
   }
 
   return 0;
}
