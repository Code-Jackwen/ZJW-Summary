#include <iostream>
using namespace std;
const int MAX = 3;

//ָ������� 
//���Զ�ָ����������������㣺++��--��+��-��

int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // ָ���е������ַ
   //ptr = var;
   ptr = &var[0];//���ϱߵ�Ч 
   
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;//��ַ 0x70fe00��0x70fe04��0x70fe08 		��ַ����Ϊ4 
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;//10��100��200 
 
      // �ƶ�����һ��λ��
      ptr++;
   }
   
   cout<<endl;
   
   short  arr[MAX] = {10, 100, 200};
   short  *p;
 
   // ָ���е������ַ
   p = arr;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << p << endl;//��ַ 0x70fde0�� 0x70fde2��0x70fde4 		��ַ����Ϊ2
 
      cout << "Value of var[" << i << "] = ";
      cout << *p << endl;//10��100��200 
 
      // �ƶ�����һ��λ��
      p++;
   }
   
   cout<<endl;
   //�ݼ�һ��ָ�� 
   
   int  arr1[MAX] = {10, 100, 200};
   int  *p1;
 
   // ָ�������һ��Ԫ�صĵ�ַ
   p1 = &arr1[MAX-1];
   for (int i = MAX; i > 0; i--)
   {
      cout << "Address of var[" << i << "] = ";//0x70fdc8 ��4��0 
      cout << p1 << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *p1 << endl;
 
      // �ƶ�����һ��λ��
      p1--;
   }
   
   
   
   return 0;
}
