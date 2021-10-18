#include <iostream>
 
using namespace std;


//在类里面不写是什么类型，默认是 private 的。
//如果继承时不显示声明是 private，protected，public 继承，则默认是 private 继承，在 struct 中默认 public 继承：

//继承方式	基类的public成员	基类的protected成员	基类的private成员	继承引起的访问控制关系变化概括
//public继承	仍为public成员	仍为protected成员	不可见	基类的非私有成员在子类的访问属性不变
//protected继承	变为protected成员	变为protected成员	不可见	基类的非私有成员都为子类的保护成员
//private继承	变为private成员	变为private成员	不可见	基类中的非私有成员都称为子类的私有成员

 
class Box
{
   public:
      double length;
      void setWidth( double wid );
      double getWidth( void );
 
   private:
      double width;
};
 
// 成员函数定义
double Box::getWidth(void)
{
    return width ;
}
 
void Box::setWidth( double wid )
{
    width = wid;
}
 
// 程序的主函数
int main( )
{
   Box box;
 
   // 不使用成员函数设置长度
   box.length = 10.0; // OK: 因为 length 是公有的
   cout << "Length of box : " << box.length <<endl;
 
   // 不使用成员函数设置宽度
   // box.width = 10.0; // Error: 因为 width 是私有的
   box.setWidth(10.0);  // 使用成员函数设置宽度
   cout << "Width of box : " << box.getWidth() <<endl;
 
   return 0;
}
