//C++ 中有大量的函数用来操作以 null 结尾的字符串:
//strcpy(s1, s2);//复制字符串 s2 到字符串 s1。
//strcat(s1, s2);//连接字符串 s2 到字符串 s1 的末尾。连接字符串也可以用 + 号，例如:
//string str1 = "runoob";
//string str2 = "google";
//string str = str1 + str2;
//strlen(s1);//返回字符串 s1 的长度。
//strcmp(s1, s2);//如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
//strchr(s1, ch);//返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
//strstr(s1, s2);//返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。


#include <iostream>
#include <cstring>
using namespace std;

int main () {
	char str1[13] = "runoob";
	char str2[13] = "google";
	char str3[13];
	int  len ;

	// 复制 str1 到 str3
	strcpy( str3, str1);//是反着的，参数后边的字符串复制到前面 
	cout << "strcpy( str3, str1) : " << str3 << endl;//runoob

	// 连接 str1 和 str2
	strcat( str1, str2);
	cout << "strcat( str1, str2): " << str1 << endl;//runoobgoogle

	// 连接后，str1 的总长度
	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;//12

// 	char str4[4] = "google";//编译报错
// 	cout<<str4<<endl;
	char str5[8] = "google";
	cout<<str5<<endl;

	char str6[2];
	cout<<str6<<endl;//戌@ 		乱七八糟的
	strcpy( str6, str1);
	cout<<str6<<endl;//runoobgoogle			很长！没报错
		cout<<"str6 长度："<<strlen(str1)<<endl;//12 
	
	char str61[8] = "111";
	cout<<str61<<endl;
	strcpy( str61, str1);
	cout<<str61<<endl;//runoobgoogle

	char str62[20] = "2";
	strcpy( str61, str62);
	cout<<str61<<endl;//2
	cout<<"str61 长度："<<strlen(str61)<<endl;//1

	char str7[9] = "越界测试"; //8个长度不够，必须9个以上。
	cout<<str7<<endl;
	
	strcat( str1, str7);
	cout << "strcat( str1, str7): " << str1 << endl;// runoobgoogle越界测试
	cout<<"str1 长度："<<strlen(str1)<<endl;//20
	strcat( str7, str1);
	cout << "strcat( str7, str1): " << str7 << endl;//越界测试runoobgoogle越界测试			函数都没越界！ 
	cout<<"str7 长度："<<strlen(str7)<<endl;//28
	
	char str8[9]; 
	cout<<"str8 长度："<<strlen(str8)<<endl;//3			不进行初始化，长度就是乱的。 
	
	char str9[10] = "1"; 
	cout<<"str9 长度："<<strlen(str9)<<endl;//1
	
	return 0;
}
