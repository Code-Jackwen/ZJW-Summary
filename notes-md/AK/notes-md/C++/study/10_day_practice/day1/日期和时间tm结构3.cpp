#include <iostream>
#include <ctime>
 
using namespace std;
 
 //tm �ṹ�� C/C++ �д������ں�ʱ����صĲ���ʱ���Ե���Ϊ��Ҫ.
 //�����ʵ��ʹ���� tm �ṹ�͸��������ں�ʱ����صĺ����� 
 
int main( )
{
   // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
   time_t now = time(0);
 
   cout << "1970 ��Ŀǰ��������:" << now << endl;
 
   tm *ltm = localtime(&now);
 
   // ��� tm �ṹ�ĸ�����ɲ���
   cout << "��: "<< 1900 + ltm->tm_year << endl;//��: 2021
   cout << "��: "<< 1 + ltm->tm_mon<< endl;//��: 4
   cout << "��: "<<  ltm->tm_mday << endl;//��: 30
   cout << "ʱ��: "<< ltm->tm_hour << ":";//ʱ��: 21:16:2
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}
