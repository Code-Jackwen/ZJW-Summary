#include <iostream>
using namespace std;

//��������Ϊ�����ĺ��������԰ѱ������룬�����ܴ��볣����ֵ��

int hls(int& a1, int& a2, int& b1, int& b2) { //��������ʽ����
	int temp;
	temp=a1*b2-a2*b1;
	return temp;
}

int hls2(int a1, int a2, int b1, int b2) { //��������ʽ����
	int temp;
	temp=a1*b2-a2*b1;
	return temp;
}

int main() {
	int x1=11;
	int x2=9;
	int y1=15;
	int y2=14;  //�������
	int result;  //����ʽ������
	result=hls(x1,x2,y1,y2);   //result=hls(11,9,15,14)�ᱨ��
	cout << result << endl;


	cout <<endl;
	cout <<endl;
	cout <<endl;


	result=hls2(11,9,15,14);//�ᱨ��
	cout << result << endl;
	
	return 0;
}
