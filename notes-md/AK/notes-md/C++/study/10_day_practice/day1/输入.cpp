//https://www.runoob.com/cplusplus/cpp-strings.html

//C++ ������ķ�ʽ��ʵ���кܶ࣬����������һ���� C ������ getchar() ���Ƶġ�
//cin.getline();
//cin.getline() ��������һ���ַ���ɺ�ʼ��ȡ���ݣ�ע�⣬��������ɺ���EnterΪ������־��
//������һʵ��������һ���ַ������ͳ�����е����ָ�����Ӣ����ĸ������������ַ��� # Ϊ������־��

#include<iostream>
using namespace std;

//#define N 100
int main()
{
	
//	int N=5;		//����һλһ���� #�� ��Ҳ���ǻس��� 
	int N; 
	cin>>N;			//5 ab1  ���������ȷ�ģ���5 �س� �᷵�� 0 0 
    char cs[N];
    cin.getline(cs,N);                               //��cin.getline��ʽ����
    int a=0,b=0;
    for(int i=0;i<N;i++)
    {
        if(cs[i]=='#')                                      //Ϊ#Ϊ������־
            break;
        if(cs[i]>='0'&&cs[i]<='9')
            a++;                                         //ͳ�����ָ���
         if((cs[i]>='a'&&cs[i]<='z')||(cs[i]>='A'&&cs[i]<='Z'))
            b++;                                      //ͳ��Ӣ����ĸ����
    }
    cout<<a<<endl;
	cout<<b<<endl;
    return 0;
}
