#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

string  Get_Current_Date();
//demo���� 20**-**-** **:**:** ��ʽ�����ǰ���ڣ�
int main( ) {
	// ����ǰ������ 20** - ** - ** ��ʽ���
	cout << Get_Current_Date().c_str() << endl;

	getchar();
	return 0;
}

string  Get_Current_Date() {
	time_t nowtime = time(NULL); //��ȡ����ʱ��
	char tmp[64];
	strftime(tmp,sizeof(tmp),"%Y-%m-%d %H:%M:%S",localtime(&nowtime));
	return tmp;

}
