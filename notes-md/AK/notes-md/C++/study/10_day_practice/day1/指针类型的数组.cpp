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
      ptr[i] = &var[i]; // ��ֵΪ�����ĵ�ַ
   }
   for (int i = 0; i < MAX; i++)
   {
      cout << "Value of var[" << i << "] = ";
      cout << *ptr[i] << endl;//10\100\200
   }
   
   
   cout<<endl;
   cout<<endl;
   cout<<endl;
   
   //char *names[MAX] ��ָ������, ���ı����Ǵ洢ָ�������, �����洢 char ���͵�ָ�������,
   // �����ڵ�ÿ��Ԫ�ض���һ��ָ��ָ��һ���洢 char ���͵ĵ�ַ:
    const char *names[MAX1] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };

    for (int i = 0; i < MAX1; i++) {
    	//names[i] �õ� char[]����ĵ�һ����ַ��Ĭ�ϻ��������ꡣ 
        cout << " --- names[i]              = " << names[i] << endl;				// Zara Ali 	Hina Ali	
        cout << " --- *names[i]             = " << *names[i] << endl;				// Z			H
        cout << endl;
        cout << " --- (*names[i] + 1)       = " << (*names[i] + 1) << endl;			//91			73
        cout << " --- (char)(*names[i] + 1) = " << (char)(*names[i] + 1) << endl;	//[				I
        cout << " ------------------------------------ " << endl << endl << endl << endl;
    }
   
   
//   char abc = (char)(73-'a');//��Ȼ������� 
	int abc	= 'I';
   int abc1 = 'a';
   cout<<abc<<endl;//73
   cout<<abc1<<endl;//97
   
   return 0;
}
