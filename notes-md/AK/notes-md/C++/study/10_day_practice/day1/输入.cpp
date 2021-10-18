//https://www.runoob.com/cplusplus/cpp-strings.html

//C++ 中输入的方式其实还有很多，下面来介绍一种与 C 语言中 getchar() 类似的。
//cin.getline();
//cin.getline() 是在输入一段字符完成后开始读取数据（注意，是输入完成后，以Enter为结束标志）
//下面是一实例：输入一串字符，编程统计其中的数字个数和英文字母个数。输入的字符以 # 为结束标志。

#include<iostream>
using namespace std;

//#define N 100
int main()
{
	
//	int N=5;		//最后的一位一定是 #号 ，也就是回车。 
	int N; 
	cin>>N;			//5 ab1  输出的是正确的，而5 回车 会返回 0 0 
    char cs[N];
    cin.getline(cs,N);                               //以cin.getline形式输入
    int a=0,b=0;
    for(int i=0;i<N;i++)
    {
        if(cs[i]=='#')                                      //为#为结束标志
            break;
        if(cs[i]>='0'&&cs[i]<='9')
            a++;                                         //统计数字个数
         if((cs[i]>='a'&&cs[i]<='z')||(cs[i]>='A'&&cs[i]<='Z'))
            b++;                                      //统计英文字母个数
    }
    cout<<a<<endl;
	cout<<b<<endl;
    return 0;
}
