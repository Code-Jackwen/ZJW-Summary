#include <iostream>
 
using namespace std;


//��������������ĳ�ʼ����䣬�ڴ�����һ������ʱ�����еľ�̬���ݶ��ᱻ��ʼ��Ϊ�㡣
//���ܰѾ�̬��Ա�ĳ�ʼ����������Ķ����У�
//���ǿ���������ⲿͨ��ʹ�÷�Χ��������� :: ������������̬�����Ӷ��������г�ʼ�����������ʵ����ʾ��

class Box
{
   public:
      static int objectCount;
      // ���캯������
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         // ÿ�δ�������ʱ���� 1
         objectCount++;
      }
      double Volume()
      {
         return length * breadth * height;
      }
   private:
      double length;     // ����
      double breadth;    // ���
      double height;     // �߶�
};
 
// ��ʼ���� Box �ľ�̬��Ա
int Box::objectCount = 0;
 
int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // ���� box1
   Box Box2(8.5, 6.0, 2.0);    // ���� box2
 
   // ������������
   cout << "Total objects: " << Box::objectCount << endl;
 
   return 0;
}
