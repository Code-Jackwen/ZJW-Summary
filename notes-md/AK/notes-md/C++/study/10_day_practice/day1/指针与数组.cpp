#include <iostream>

using namespace std;
const int MAX = 3;

int main () {

	//这是个指针和 数组等效替换的例子
	int  var[MAX] = {10, 100, 200};
	int  *ptr;

	// 指针中的数组地址
	ptr = var;
	cout<<"var: "<<var<<endl;//var: 0x70fe00

	for (int i = 0; i < MAX; i++) {
		cout << "var[" << i << "]的内存地址为 ";
		cout << ptr << endl;

		cout << "var[" << i << "] 的值为 ";
		cout << *ptr << endl;

		// 移动到下一个位置
		ptr++;
	}

	//这是个指针和 数组 不能等效替换的例子
	int  arr[MAX] = {10, 100, 200};
	for (int i = 0; i < 8; i++) {
		*arr = i;    // 这是正确的语法		*arr 默认代表 arr[0] 就是说把数组的第一个值改为了7
//		arr++;       // 这是不正确的		修改 arr 的值是非法的。这是因为 arr 是一个指向数组开头的常量，不能作为左值。
	}

	for (int i = 0; i < MAX; i++) {
		cout<<arr[i]<<endl; //7\100\200
	}

	//一个数组名对应一个指针常量，仍然可以用指针形式的表达式。 但是arr不能直接运算 
	//也就是说 arr 是个数组的唯一的一个地址值，可以用别的指针变量引用他，然后改变那个引用，但是arr本身不能变。
	//例如，下面是一个有效的语句，把 var[2] 赋值为 500：
	*(arr + 2) = 500;
	cout<<arr[2]<<endl;//500



	cout<<endl;
	cout<<endl;
	cout<<endl;

	//根据实验结果，此章节最后一句应该不是说数组内的数值不能修改，
	//而是说只要var的值（地址）不变，那么相应位置的数值改变了，该数组的地址也不会受到影响。
	int  arr1[MAX] = {10, 100, 200};
	cout<<arr1<<endl;//0x70fde0
	cout<<*arr1<<endl;//10
	for (int i = 0; i < MAX; i++) {
		*arr1 = i;    // 这是正确的语法
		cout<<*arr1<<endl;
		cout<<i<<endl;		//变 
		cout<<&i<<endl;		//0x70fddc ....
		cout<<arr1<<endl;	//0x70fde0 .... 俩逗没变 
		*(arr1+1)=500;
		cout<<*(arr1+1)<<endl;		//一值是500 
		//var++;       // 这是不正确的
		cout<<endl;
	}






	return 0;	//两个return 不报错。
	return 0;
}
