//�ַ�����vector
//��ʱû�ܡ�δ�� 


#include <iostream>
using namespace std;

int main() {

//	�ַ�������ֵ���׼��string����ͬһ������
	string s("hello");
	cout<<s.size()<<endl;        //OK
//	cout<<"hello".size()<<endl;  //ERROR
	cout<<s+"world"<<endl;       //OK
//	cout<<"hello"+"world"<<endl; //ERROR

//	strlen��sizeof��size()���ַ������ȵ�����
	string s1 = "123";
	cout<<strlen("123")<<endl;   //���� 3
	cout<<sizeof("123")<<endl;   //���� 4
	string s = "123";
	cout<<s1.size()<<endl;        //���� 3

//	��׼string���е�getline��������ʱ�ᶪ�����з�const iterator��const_iterator������
	vector<int>::const_iterator //���ܸı�ָ���ֵ�������ֵ���Ըı�
	const vector<int>::iterator //���Ըı�ָ���ֵ�������ֵ���ܸı�
	const vector<int>::const_iterator //�����ֵ��ָ���ֵ����ֻ����


//	�κθı�vector���ȵĲ�������ʹ�Ѵ��ڵĵ�����ʧЧ���磺�ڵ���push_back֮�󣬾Ͳ���������ָ��vector�ĵ�������
	vector<int> ivec;
	ivec.push_back(10);
	vector<int>::iterator it = ivec.begin();
	cout<<*it<<endl;
	ivec.push_back(9);
	cout<<*it<<endl;      //�������Ѿ�ʧЧ

}
