#include <iostream>
#include <cstring>

using namespace std;
void printBook( struct Books *book );


//类与结构体在 C++ 中只有两点区别，除此这外无任何区别。
//（1）class 中默认的成员访问权限是 private 的，而 struct 中则是 public 的。
//（2）从 class 继承默认是 private 继承，而从 struct 继承默认是 public 继承。
//（3）class 可以定义模板，而 struct 不可以。 

//其他：C与C++结构体中前者不能有函数，后者可以有。

//给上一个demo的结构体，加上 typedef 关键字，自定义类型的名字，简化书写。 

//struct Books {
//	char  title[50];
//	char  author[50];
//	char  subject[100];
//	int   book_id;
//};

typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}BKS;


//类似的，typedef定义非结构数据类型 
//typedef long int *pint32;
//pint32 x, y, z; 		//x, y 和 z 都是指向长整型 long int 的指针。


int main( ) {
//	Books Book1;        // 定义结构体类型 Books 的变量 Book1
//	Books Book2;        // 定义结构体类型 Books 的变量 Book2

	Books Book1, Book2;

	// Book1 详述
	strcpy( Book1.title, "C++ 教程");
	strcpy( Book1.author, "Runoob");
	strcpy( Book1.subject, "编程语言");
	Book1.book_id = 12345;

	// Book2 详述
	strcpy( Book2.title, "CSS 教程");
	strcpy( Book2.author, "Runoob");
	strcpy( Book2.subject, "前端技术");
	Book2.book_id = 12346;

	// 通过传 Book1 的地址来输出 Book1 信息
//	printBook( &Book1 );
	Books *b1 = &Book1;
	printBook( b1 );		//不存在*b1 的写法， 会报错的。 


	// 通过传 Book2 的地址来输出 Book2 信息
//	printBook( &Book2 );
	Books *b2 = &Book2;
	printBook( b2 );

	return 0;
}
// 该函数以结构指针作为参数
void printBook( struct Books *book ) {
	cout << "书标题  : " << book->title <<endl;
	cout << "书作者 : " << book->author <<endl;
	cout << "书类目 : " << book->subject <<endl;
	cout << "书 ID : " << book->book_id <<endl;
}
