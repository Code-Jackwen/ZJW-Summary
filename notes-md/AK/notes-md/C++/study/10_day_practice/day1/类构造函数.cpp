#include <iostream>
 
using namespace std;

//��Ĺ��캯����һ������ĺ������ڴ���һ���µĶ���ʱ���á������������Ҳ��һ������ĺ�������ɾ���������Ķ���ʱ���á�

//��Ĺ��캯�������һ������ĳ�Ա������������ÿ�δ�������¶���ʱִ�С�
//���캯���������������������ȫ��ͬ�ģ����Ҳ��᷵���κ����ͣ�Ҳ���᷵�� void�����캯��������ΪĳЩ��Ա�������ó�ʼֵ��

class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();  // ���ǹ��캯��
 
   private:
      double length;
};
 
// ��Ա�������壬�������캯��
Line::Line(void)
{
    cout << "Object is being created" << endl;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
// �����������
int main( )
{
   Line line;
 
   // ���ó���
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}
