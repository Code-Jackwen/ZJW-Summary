#include <iostream>
#include <cstring>

using namespace std;
void printBook( struct Books *book );

struct Books {
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

int main( ) {
	Books Book1;        // ����ṹ������ Books �ı��� Book1
	Books Book2;        // ����ṹ������ Books �ı��� Book2

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
	cout << "�����  : " << book->title <<endl;				//��ָ�룡���������� 
	cout << "������ : " << book->author <<endl;
	cout << "����Ŀ : " << book->subject <<endl;
	cout << "�� ID : " << book->book_id <<endl;
}
