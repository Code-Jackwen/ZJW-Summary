## emplace_back()和push_back()的区别

emplace_back() 和 push_back() 的区别，就在于底层实现的机制不同。push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。



 push_back() 在底层实现时，会优先选择调用移动构造函数，如果没有才会调用拷贝构造函数。 

 显然完成同样的操作，push_back() 的底层实现过程比 emplace_back() 更繁琐，换句话说，emplace_back() 的执行效率比 push_back() 高。因此，在实际使用时，建议大家优先选用 emplace_back()。 

 由于 emplace_back() 是 C++ 11 标准新增加的，如果程序要兼顾之前的版本，还是应该使用 push_back()。 



```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> values{};
    values.push_back(1);
    values.push_back(2);
    //values.emplace_back(1);
    //values.emplace_back(2);
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    return 0;
}
```



