#include <iostream>

using namespace std;
const int MAX = 3;

int main () {

	//���Ǹ�ָ��� �����Ч�滻������
	int  var[MAX] = {10, 100, 200};
	int  *ptr;

	// ָ���е������ַ
	ptr = var;
	cout<<"var: "<<var<<endl;//var: 0x70fe00

	for (int i = 0; i < MAX; i++) {
		cout << "var[" << i << "]���ڴ��ַΪ ";
		cout << ptr << endl;

		cout << "var[" << i << "] ��ֵΪ ";
		cout << *ptr << endl;

		// �ƶ�����һ��λ��
		ptr++;
	}

	//���Ǹ�ָ��� ���� ���ܵ�Ч�滻������
	int  arr[MAX] = {10, 100, 200};
	for (int i = 0; i < 8; i++) {
		*arr = i;    // ������ȷ���﷨		*arr Ĭ�ϴ��� arr[0] ����˵������ĵ�һ��ֵ��Ϊ��7
//		arr++;       // ���ǲ���ȷ��		�޸� arr ��ֵ�ǷǷ��ġ�������Ϊ arr ��һ��ָ�����鿪ͷ�ĳ�����������Ϊ��ֵ��
	}

	for (int i = 0; i < MAX; i++) {
		cout<<arr[i]<<endl; //7\100\200
	}

	//һ����������Ӧһ��ָ�볣������Ȼ������ָ����ʽ�ı��ʽ�� ����arr����ֱ������ 
	//Ҳ����˵ arr �Ǹ������Ψһ��һ����ֵַ�������ñ��ָ�������������Ȼ��ı��Ǹ����ã�����arr�����ܱ䡣
	//���磬������һ����Ч����䣬�� var[2] ��ֵΪ 500��
	*(arr + 2) = 500;
	cout<<arr[2]<<endl;//500



	cout<<endl;
	cout<<endl;
	cout<<endl;

	//����ʵ���������½����һ��Ӧ�ò���˵�����ڵ���ֵ�����޸ģ�
	//����˵ֻҪvar��ֵ����ַ�����䣬��ô��Ӧλ�õ���ֵ�ı��ˣ�������ĵ�ַҲ�����ܵ�Ӱ�졣
	int  arr1[MAX] = {10, 100, 200};
	cout<<arr1<<endl;//0x70fde0
	cout<<*arr1<<endl;//10
	for (int i = 0; i < MAX; i++) {
		*arr1 = i;    // ������ȷ���﷨
		cout<<*arr1<<endl;
		cout<<i<<endl;		//�� 
		cout<<&i<<endl;		//0x70fddc ....
		cout<<arr1<<endl;	//0x70fde0 .... ����û�� 
		*(arr1+1)=500;
		cout<<*(arr1+1)<<endl;		//һֵ��500 
		//var++;       // ���ǲ���ȷ��
		cout<<endl;
	}






	return 0;	//����return ������
	return 0;
}
