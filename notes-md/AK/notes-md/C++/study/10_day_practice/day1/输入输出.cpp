#include <iostream>
#include <iomanip>
using namespace std;


//C++ �� I/O ���������У������ֽ����С�����ֽ����Ǵ��豸������̡��������������������ӵȣ������ڴ棬��������������
//����ֽ����Ǵ��ڴ������豸������ʾ������ӡ�����������������������ӵȣ�����������������
int main() {

	
//	cout<<setiosflags(ios::left|ios::showpoint);  // ������룬��һ��ʵ����ʽ��ʾ
//	cout.precision(5);       // ���ó�С����������λ��Ч����
//	cout<<123.456789<<endl;
//	cout.width(10);          // ������ʾ���10
//	cout.fill('*');          // ����ʾ����հ״���*���
//	cout<<resetiosflags(ios::left);  // ���״̬�����
//	cout<<setiosflags(ios::right);   // �����Ҷ���
//	cout<<123.456789<<endl;
//	cout<<setiosflags(ios::left|ios::fixed);    // ������룬�Թ̶�С��λ��ʾ
//	cout.precision(3);    // ����ʵ����ʾ��λС��
//	cout<<999.123456<<endl;
//	cout<<resetiosflags(ios::left|ios::fixed);  //���״̬�����Ͷ����ʽ
//	cout<<setiosflags(ios::left|ios::scientific);    //��������룬�Կ�ѧ��������ʾ
//	cout.precision(3);   //���ñ�����λС��
//	cout<<123.45678<<endl;

	//123.46
	//****123.46
	//999.123
	//1.235e+02


//	���� C++ û���� scanf ���Ƶ���ô��ȷ���и� cin.get() �ǿ��Ժ��Ե�һ���ַ��ģ����Ǹ��ַ��������κ��ַ������޶��Ƕ��š�
//	����:
	int a, b, c;
	cin>>a;
	cin.get();
	cin>>b;
	cin.get();
	cin>>c;
	
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;


	return 0;
}
