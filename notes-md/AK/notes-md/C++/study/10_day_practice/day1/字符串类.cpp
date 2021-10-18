#include <iostream>
#include <string>

using namespace std;
//C++ 标准库提供了 string 类类型，下面进行展示，c哪些函数的所有的操作
int main () {
	string str1 = "runoob";
	string str2 = "google";
	string str3;
	int  len ;

	// 复制 str1 到 str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// 连接 str1 和 str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// 连接后，str3 的总长度
	len = str3.size();
	cout << "str3.size() :  " << len << endl;//12

	//tring类提供了一系列针对字符串的操作，比如：
// 1. append() -- 在字符串的末尾添加字符
// 2. find() -- 在字符串中查找字符串，返回   串的第一个字符的位置
// 4. insert() -- 插入字符
// 5. length() -- 返回字符串的长度
// 6. replace() -- 替换字符串
// 7. substr() -- 返回某个子字符串
// 8. ...

	//定义一个string类对象
	string http = "www.runoob.com";

	//打印字符串长度
	cout<<http.length()<<endl;//14

	//拼接
	http.append("/C++");
	cout<<http<<endl; //打印结果为：www.runoob.com/C++
	cout<<http.length()<<endl;//18

	//删除
	int pos = http.find("/C++"); //查找"C++"在字符串中的位置
	cout<<pos<<endl;//14
	cout<<http[14]<<endl;//		/
	cout<<http[15]<<endl;//		C

	http.replace(pos, 1, "");
	cout<<http<<endl;//www.runoob.comC++

	http.replace(pos, 4, "");   //从位置pos开始，之后的4个字符替换为空，即删除
	cout<<http<<endl;//www.runoob.com

	http.replace(pos, 10, "");
	cout<<http<<endl;//www.runoob.com

	//找子串runoob
	int first = http.find_first_of("."); //从头开始寻找字符'.'的位置
	int last = http.find_last_of(".");   //从尾开始寻找字符'.'的位置
	cout<<first<<endl;//3
	cout<<last<<endl;//10
	cout<<last-first-1<<endl;//6
	cout<<http.substr(first+1, last-first-1)<<endl; //提取"runoob"子串并打印		也就是4到6
	//substr() 是从那个位置开始，这个位置包含在内。然后是截取多大长度，截取6个长度


	http.insert(3,"123");
	cout<<http<<endl;//www123.runoob.com
	http.insert(9,"123456",2);//www123.ru12noob.com
	cout<<http<<endl;//www123.runoob.com

	return 0;
}
