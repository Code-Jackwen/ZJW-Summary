#include <iostream>
#include <string>

using namespace std;
//C++ ��׼���ṩ�� string �����ͣ��������չʾ��c��Щ���������еĲ���
int main () {
	string str1 = "runoob";
	string str2 = "google";
	string str3;
	int  len ;

	// ���� str1 �� str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// ���� str1 �� str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// ���Ӻ�str3 ���ܳ���
	len = str3.size();
	cout << "str3.size() :  " << len << endl;//12

	//tring���ṩ��һϵ������ַ����Ĳ��������磺
// 1. append() -- ���ַ�����ĩβ����ַ�
// 2. find() -- ���ַ����в����ַ���������   ���ĵ�һ���ַ���λ��
// 4. insert() -- �����ַ�
// 5. length() -- �����ַ����ĳ���
// 6. replace() -- �滻�ַ���
// 7. substr() -- ����ĳ�����ַ���
// 8. ...

	//����һ��string�����
	string http = "www.runoob.com";

	//��ӡ�ַ�������
	cout<<http.length()<<endl;//14

	//ƴ��
	http.append("/C++");
	cout<<http<<endl; //��ӡ���Ϊ��www.runoob.com/C++
	cout<<http.length()<<endl;//18

	//ɾ��
	int pos = http.find("/C++"); //����"C++"���ַ����е�λ��
	cout<<pos<<endl;//14
	cout<<http[14]<<endl;//		/
	cout<<http[15]<<endl;//		C

	http.replace(pos, 1, "");
	cout<<http<<endl;//www.runoob.comC++

	http.replace(pos, 4, "");   //��λ��pos��ʼ��֮���4���ַ��滻Ϊ�գ���ɾ��
	cout<<http<<endl;//www.runoob.com

	http.replace(pos, 10, "");
	cout<<http<<endl;//www.runoob.com

	//���Ӵ�runoob
	int first = http.find_first_of("."); //��ͷ��ʼѰ���ַ�'.'��λ��
	int last = http.find_last_of(".");   //��β��ʼѰ���ַ�'.'��λ��
	cout<<first<<endl;//3
	cout<<last<<endl;//10
	cout<<last-first-1<<endl;//6
	cout<<http.substr(first+1, last-first-1)<<endl; //��ȡ"runoob"�Ӵ�����ӡ		Ҳ����4��6
	//substr() �Ǵ��Ǹ�λ�ÿ�ʼ�����λ�ð������ڡ�Ȼ���ǽ�ȡ��󳤶ȣ���ȡ6������


	http.insert(3,"123");
	cout<<http<<endl;//www123.runoob.com
	http.insert(9,"123456",2);//www123.ru12noob.com
	cout<<http<<endl;//www123.runoob.com

	return 0;
}
