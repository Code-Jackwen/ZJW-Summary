#include <iostream>
using namespace std;

/*
 * ���������ʾ���з����������޷�������֮��Ĳ��
*/
int main() {
	short int i;           // �з��Ŷ�����
	short unsigned int j;  // �޷��Ŷ�����

	j = 50000;

	i = j;
	cout << i << " " << j;

	return 0;
	//������ĳ�������ʱ����������н����
	//-15536 50000
}
