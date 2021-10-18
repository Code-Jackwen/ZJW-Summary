//字符串与vector
//暂时没跑。未看 


#include <iostream>
using namespace std;

int main() {

//	字符串字面值与标准库string不是同一种类型
	string s("hello");
	cout<<s.size()<<endl;        //OK
//	cout<<"hello".size()<<endl;  //ERROR
	cout<<s+"world"<<endl;       //OK
//	cout<<"hello"+"world"<<endl; //ERROR

//	strlen、sizeof与size()求字符串长度的区别
	string s1 = "123";
	cout<<strlen("123")<<endl;   //返回 3
	cout<<sizeof("123")<<endl;   //返回 4
	string s = "123";
	cout<<s1.size()<<endl;        //返回 3

//	标准string库中的getline函数返回时会丢弃换行符const iterator与const_iterator的区别
	vector<int>::const_iterator //不能改变指向的值，自身的值可以改变
	const vector<int>::iterator //可以改变指向的值，自身的值不能改变
	const vector<int>::const_iterator //自身的值和指向的值都是只读的


//	任何改变vector长度的操作都会使已存在的迭代器失效。如：在调用push_back之后，就不能再信赖指向vector的迭代器了
	vector<int> ivec;
	ivec.push_back(10);
	vector<int>::iterator it = ivec.begin();
	cout<<*it<<endl;
	ivec.push_back(9);
	cout<<*it<<endl;      //迭代器已经失效

}
