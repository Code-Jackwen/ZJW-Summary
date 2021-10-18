#include <iostream>

using namespace std;

class Line {
	public:
		void setLength( double len );
		double getLength( void );
		Line(double len);  // 这是构造函数

	private:
		double length;
};

//其他：
 
//使用初始化列表来初始化字段：
//Line::Line( double len): length(len) {
//	cout << "Object is being created, length = " << len << endl;
//}
//等同于下边的 
//Line::Line( double len)
//{
//    length = len;
//    cout << "Object is being created, length = " << len << endl;
//}

//使用初始化列表来初始化字段：
//同理，格式类推
//C::C( double a, double b, double c): X(a), Y(b), Z(c)
//{
//  ....
//} 



// 成员函数定义，包括构造函数
Line::Line( double len) {
	cout << "Object is being created, length = " << len << endl;
	length = len;
}

void Line::setLength( double len ) {
	length = len;
}

double Line::getLength( void ) {
	return length;
}
// 程序的主函数
int main( ) {
	Line line(10.0);

	// 获取默认设置的长度
	cout << "Length of line : " << line.getLength() <<endl;
	// 再次设置长度
	line.setLength(6.0);
	cout << "Length of line : " << line.getLength() <<endl;

	return 0;
}
