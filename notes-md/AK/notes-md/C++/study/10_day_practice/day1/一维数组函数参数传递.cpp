#include <iostream>
using namespace std;

//������βο����� һ��ͷָ�룬�������顣 
//����һ�� void myFunction(int *param)		��ʽ������һ��ָ�룺
//�������� void myFunction(int param[10])	��ʽ������һ���Ѷ����С�����飺
//�������� void myFunction(int param[])		��ʽ������һ��δ�����С�����飺

// ��������
double getAverage(int arr[], int size);
 
int main ()
{
   // ���� 5 ��Ԫ�ص���������
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   // ����һ��ָ�������ָ����Ϊ����
   avg = getAverage( balance, 5 ) ;
 
   // �������ֵ
   cout << "ƽ��ֵ�ǣ�" << avg << endl; 
    
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
