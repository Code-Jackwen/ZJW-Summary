//C++ ���д����ĺ������������� null ��β���ַ���:
//strcpy(s1, s2);//�����ַ��� s2 ���ַ��� s1��
//strcat(s1, s2);//�����ַ��� s2 ���ַ��� s1 ��ĩβ�������ַ���Ҳ������ + �ţ�����:
//string str1 = "runoob";
//string str2 = "google";
//string str = str1 + str2;
//strlen(s1);//�����ַ��� s1 �ĳ��ȡ�
//strcmp(s1, s2);//��� s1 �� s2 ����ͬ�ģ��򷵻� 0����� s1<s2 �򷵻�ֵС�� 0����� s1>s2 �򷵻�ֵ���� 0��
//strchr(s1, ch);//����һ��ָ�룬ָ���ַ��� s1 ���ַ� ch �ĵ�һ�γ��ֵ�λ�á�
//strstr(s1, s2);//����һ��ָ�룬ָ���ַ��� s1 ���ַ��� s2 �ĵ�һ�γ��ֵ�λ�á�


#include <iostream>
#include <cstring>
using namespace std;

int main () {
	char str1[13] = "runoob";
	char str2[13] = "google";
	char str3[13];
	int  len ;

	// ���� str1 �� str3
	strcpy( str3, str1);//�Ƿ��ŵģ�������ߵ��ַ������Ƶ�ǰ�� 
	cout << "strcpy( str3, str1) : " << str3 << endl;//runoob

	// ���� str1 �� str2
	strcat( str1, str2);
	cout << "strcat( str1, str2): " << str1 << endl;//runoobgoogle

	// ���Ӻ�str1 ���ܳ���
	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;//12

// 	char str4[4] = "google";//���뱨��
// 	cout<<str4<<endl;
	char str5[8] = "google";
	cout<<str5<<endl;

	char str6[2];
	cout<<str6<<endl;//��@ 		���߰����
	strcpy( str6, str1);
	cout<<str6<<endl;//runoobgoogle			�ܳ���û����
		cout<<"str6 ���ȣ�"<<strlen(str1)<<endl;//12 
	
	char str61[8] = "111";
	cout<<str61<<endl;
	strcpy( str61, str1);
	cout<<str61<<endl;//runoobgoogle

	char str62[20] = "2";
	strcpy( str61, str62);
	cout<<str61<<endl;//2
	cout<<"str61 ���ȣ�"<<strlen(str61)<<endl;//1

	char str7[9] = "Խ�����"; //8�����Ȳ���������9�����ϡ�
	cout<<str7<<endl;
	
	strcat( str1, str7);
	cout << "strcat( str1, str7): " << str1 << endl;// runoobgoogleԽ�����
	cout<<"str1 ���ȣ�"<<strlen(str1)<<endl;//20
	strcat( str7, str1);
	cout << "strcat( str7, str1): " << str7 << endl;//Խ�����runoobgoogleԽ�����			������ûԽ�磡 
	cout<<"str7 ���ȣ�"<<strlen(str7)<<endl;//28
	
	char str8[9]; 
	cout<<"str8 ���ȣ�"<<strlen(str8)<<endl;//3			�����г�ʼ�������Ⱦ����ҵġ� 
	
	char str9[10] = "1"; 
	cout<<"str9 ���ȣ�"<<strlen(str9)<<endl;//1
	
	return 0;
}
