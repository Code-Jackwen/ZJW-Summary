#include <iostream>
using namespace std;
const int MAX = 3;

//ָ��ıȽ�
//ָ������ù�ϵ��������бȽϣ��� ==��< �� >
int main () {
	int  var[MAX] = {10, 100, 200};
	int  *ptr;

	//ֻҪ����ָ����ָ��ĵ�ַС�ڻ������������һ��Ԫ�صĵ�ַ &var[MAX - 1]����ѱ���ָ����е���

	// ָ���е�һ��Ԫ�صĵ�ַ
	ptr = var;
	int i = 0;
	while ( ptr <= &var[MAX - 1] ) {			//����ĵ�ַ�Ƚ��Ƿ����߼��� 
		cout << "Address of var[" << i << "] = ";//0x70fe00��4��8 
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";//10��100��200 
		cout << *ptr << endl;

		// ָ����һ��λ��
		ptr++;//�ǲ���* �ı䶯�� 
		
		i++;
	}

	bool b = *ptr ==  var[MAX - 1];
	
	cout<< ptr <<endl;//0x70fe0c	���������һ��Ԫ�صĵ�ַ 		//����ĵ�ַ�ǲ������߼��� 
	
	cout<< *ptr <<endl;//0			������200 
	
	cout<< var[MAX - 1] <<endl;//200
	cout<< b <<endl;//0
//	cout<< *ptr ==  var[MAX - 1] <<endl;//���� 

	bool b1 = ptr ==  &var[MAX - 1];
	cout<< b1 <<endl;//0

	bool b2 = 1==1;
	cout<< b2 <<endl;//1

	if(1) cout<<"if(1) ִ��"<<endl;//ִ��
	if(2) cout<<"if(2) ִ��"<<endl;//ִ��
	if(0) cout<<"if(0) ִ��"<<endl;//��ִ��

	return 0;
}
