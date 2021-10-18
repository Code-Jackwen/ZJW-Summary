 stack 是容器适配器的一种。要使用 stack，必须包含头文件 <stack>。



stack的定义如下：

```
template < class T, class Cont == deque <T> >
class stack{
  ...
}; 
```

第二个参数表明，在默认情况下，stack 就是用 deque 实现的。当然，也可以指定用 vector 或 list 实现。



 虽然 stack 使用顺序容器实现，但它不提供顺序容器具有的成员函数。除了 size、 empty 这两个所有容器都有的成员函数外，stack 还有以下三个成员函数，如表 1 所示。 

| 成员函数                 | 功  能                                                       |
| ------------------------ | ------------------------------------------------------------ |
| void pop();              | 弹出（即删除）栈顶元素                                       |
| T & top();               | 返回栈顶元素的引用。通过此函数可以读取栈顶元素的值，也可以修改栈顶元素 |
| void push (const T & x); | 将 x 压入栈顶                                                |


例题：编写程序，输入一个十进制数 n 和进制 k（k≤10），输出 n 对应的 k 进制数。

```c++
#include <iostream>
#include <stack>  //使用stack需要包含此头文件
using namespace std;

int main()
{
    int n, k;
    stack <int> stk;
    cin >> n >> k;  //将n转换为k进制数			7,2		7:000111
    if (n == 0) {
        cout << 0;
        return 0;
    }
    while (n) {
        stk.push(n%k);		//1、1、1
        n /= k;				//3、1、0
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}
```

