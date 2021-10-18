#include <iostream>

using namespace std;

class Box {
	public:
		double length;         // 长度
		double breadth;        // 宽度
		double height;         // 高度

		// 成员函数声明
		double getVolume(void);
		void setLength( double len );
		void setBreadth( double bre );
		void setHeight( double hei );
};

// 成员函数定义
double Box::getVolume(void) {
	return length * breadth * height;
}

void Box::setLength( double len ) {
	length = len;
}

void Box::setBreadth( double bre ) {
	breadth = bre;
}

void Box::setHeight( double hei ) {
	height = hei;
}

// 程序的主函数
int main( ) {
	Box Box1;                // 声明 Box1，类型为 Box
	Box Box2;                // 声明 Box2，类型为 Box
	double volume = 0.0;     // 用于存储体积

	// box 1 详述
	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	// box 2 详述
	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);

	// box 1 的体积
	volume = Box1.getVolume();
	cout << "Box1 的体积：" << volume <<endl;

	// box 2 的体积
	volume = Box2.getVolume();
	cout << "Box2 的体积：" << volume <<endl;
	return 0;
}


//其他使用，来自评论区
//:: 叫作用域区分符，指明一个函数属于哪个类或一个数据属于哪个类。
//:: 可以不跟类名，表示全局数据或全局函数（即非成员函数）。

//int month;//全局变量
//int day;
//int year;
//void Set(int m,int d,int y)
//{
//    ::year=y; //给全局变量赋值，此处可省略
//    ::day=d;
//    ::month=m;
//}
//
//Class Tdate
//{
//    public:
//        void Set(int m,int d,int y) //成员函数
//        {
//            ::Set(m,d,y); //非成员函数
//        }
//    private:
//        int month;
//        int day;
//        int year;
//}
