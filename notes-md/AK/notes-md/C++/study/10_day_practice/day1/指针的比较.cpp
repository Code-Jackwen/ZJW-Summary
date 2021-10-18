#include <iostream>
using namespace std;
const int MAX = 3;

//指针的比较
//指针可以用关系运算符进行比较，如 ==、< 和 >
int main () {
	int  var[MAX] = {10, 100, 200};
	int  *ptr;

	//只要变量指针所指向的地址小于或等于数组的最后一个元素的地址 &var[MAX - 1]，则把变量指针进行递增

	// 指针中第一个元素的地址
	ptr = var;
	int i = 0;
	while ( ptr <= &var[MAX - 1] ) {			//这里的地址比较是符合逻辑的 
		cout << "Address of var[" << i << "] = ";//0x70fe00、4、8 
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";//10、100、200 
		cout << *ptr << endl;

		// 指向上一个位置
		ptr++;//是不带* 的变动！ 
		
		i++;
	}

	bool b = *ptr ==  var[MAX - 1];
	
	cout<< ptr <<endl;//0x70fe0c	并不是最后一个元素的地址 		//这里的地址是不符合逻辑的 
	
	cout<< *ptr <<endl;//0			并不是200 
	
	cout<< var[MAX - 1] <<endl;//200
	cout<< b <<endl;//0
//	cout<< *ptr ==  var[MAX - 1] <<endl;//报错 

	bool b1 = ptr ==  &var[MAX - 1];
	cout<< b1 <<endl;//0

	bool b2 = 1==1;
	cout<< b2 <<endl;//1

	if(1) cout<<"if(1) 执行"<<endl;//执行
	if(2) cout<<"if(2) 执行"<<endl;//执行
	if(0) cout<<"if(0) 执行"<<endl;//不执行

	return 0;
}
