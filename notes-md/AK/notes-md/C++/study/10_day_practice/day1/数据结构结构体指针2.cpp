#include <iostream>
#include <cstring>

using namespace std;
void printBook( struct Books *book );


//����ṹ���� C++ ��ֻ���������𣬳����������κ�����
//��1��class ��Ĭ�ϵĳ�Ա����Ȩ���� private �ģ��� struct ������ public �ġ�
//��2���� class �̳�Ĭ���� private �̳У����� struct �̳�Ĭ���� public �̳С�
//��3��class ���Զ���ģ�壬�� struct �����ԡ� 

//������C��C++�ṹ����ǰ�߲����к��������߿����С�

//����һ��demo�Ľṹ�壬���� typedef �ؼ��֣��Զ������͵����֣�����д�� 

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


//���Ƶģ�typedef����ǽṹ�������� 
//typedef long int *pint32;
//pint32 x, y, z; 		//x, y �� z ����ָ������ long int ��ָ�롣


int main( ) {
//	Books Book1;        // ����ṹ������ Books �ı��� Book1
//	Books Book2;        // ����ṹ������ Books �ı��� Book2

	Books Book1, Book2;

	// Book1 ����
	strcpy( Book1.title, "C++ �̳�");
	strcpy( Book1.author, "Runoob");
	strcpy( Book1.subject, "�������");
	Book1.book_id = 12345;

	// Book2 ����
	strcpy( Book2.title, "CSS �̳�");
	strcpy( Book2.author, "Runoob");
	strcpy( Book2.subject, "ǰ�˼���");
	Book2.book_id = 12346;

	// ͨ���� Book1 �ĵ�ַ����� Book1 ��Ϣ
//	printBook( &Book1 );
	Books *b1 = &Book1;
	printBook( b1 );		//������*b1 ��д���� �ᱨ��ġ� 


	// ͨ���� Book2 �ĵ�ַ����� Book2 ��Ϣ
//	printBook( &Book2 );
	Books *b2 = &Book2;
	printBook( b2 );

	return 0;
}
// �ú����Խṹָ����Ϊ����
void printBook( struct Books *book ) {
	cout << "�����  : " << book->title <<endl;
	cout << "������ : " << book->author <<endl;
	cout << "����Ŀ : " << book->subject <<endl;
	cout << "�� ID : " << book->book_id <<endl;
}
