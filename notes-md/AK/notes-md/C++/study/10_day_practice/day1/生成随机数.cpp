#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//�������������������������صĺ�����һ���� rand()���ú���ֻ����һ��α����������������֮ǰ�����ȵ��� srand() ������
//������һ����������������ļ�ʵ����ʵ����ʹ���� time() ��������ȡϵͳʱ���������ͨ������ rand() �����������������
int main () {
	int i,j;

//	// ��������
//	srand( (unsigned)time( NULL ) );
//	/* ���� 10 ������� */
//	for( i = 0; i < 10; i++ ) {
//		// ����ʵ�ʵ������
//		j= rand();
//		cout <<"������� " << j << endl;
//	}

	// �ӵ������Ҫ�ŵ�ѭ����ߣ��������������ͬ���������5λ�����ڡ� 
    srand((unsigned)time(NULL));//
	for (int i = 0; i < 100000; ++i) {
//		srand((unsigned)time(NULL));
		int a=rand();
		std::cout<<a<<std::endl;
	}

	return 0;
}
