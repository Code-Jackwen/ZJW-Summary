## set 

 set 是关联容器的一种，是排序好的集合（元素已经进行了排序）。set 和 multiset 类似，它和 multiset 的差别在于 set 中不能有重复的元素。multiset 的成员函数 set 中也都有。



**关联容器的 equal_range 成员函数的返回值也是 pair 模板类对象**，其原型如下：

pair<iterator, iterator> equal_range(const T & val);

返回值对象中的 first 就是 lower_bound 的值，second 就是 upper_bound 的值。



```c++
#include <iostream>
#include <set>  //使用set须包含此文件
using namespace std;
int main()
{
    typedef set<int>::iterator IT;
    
    int a[5] = { 3,4,6,1,2 };
    set<int> st(a,a+5);    // st里是 1 2 3 4 6
    pair< IT,bool> result;
    result = st.insert(5); // st变成  1 2 3 4 5 6
    
    if(result.second)    //插入成功则输出被插入元素
        cout << * result.first  << " inserted" << endl; //输出: 5 inserted
    
    
    if(st.insert(5).second)
        cout << * result.first  << endl;
    else
        cout << * result.first << " already exists" << endl;//输出 5 already exists

    
    pair<IT,IT> bounds = st.equal_range(4);
    cout << * bounds.first << "," << * bounds.second ;  //输出：4,5
    
    return 0;
}
```


