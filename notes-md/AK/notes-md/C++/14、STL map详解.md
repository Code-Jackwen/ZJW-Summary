map 和 multimap 十分类似，区别在于 map 容器中元素的关键字不能重复。multimap 有的成员函数，map 都有。此外，map 还有成员函数 operator[]：

> T & operator[] (Key k); 

该成员函数返回 first 值为 k 的元素的 second 部分的引用。如果容器中没有元素的 first 值等于 k，则自动添加一个 first 值为 k 的元素。如果该元素的 second 成员变量是一个对象，则用无参构造函数对其初始化。



```c++
#include <iostream>
#include <map>  //使用map需要包含此头文件
using namespace std;

template <class T1,class T2>
    
ostream & operator <<(ostream & o,const pair<T1,T2> & p)
{ 
    //将pair对象输出为 (first,second)形式
    o << "(" << p.first  << "," << p.second << ")";
    return o;
}

template<class T>
    
void Print(T first,T last)
{	//打印区间[first,last)
    for( ; first != last; ++ first)
        cout <<  * first << " ";
    cout << endl;
}

typedef map<int,double,greater<int> > MYMAP; //此容器关键字是整型，元素按关键字从大到小排序

int main()
{
    MYMAP mp;
    mp.insert(MYMAP::value_type(15,2.7));
    pair<MYMAP::iterator,bool> p = mp.insert(make_pair(15,99.3));
    
    if(!p.second)
        cout << * (p.first) << " already exists" << endl; //会输出(15,2.7) already exists
    cout << "1) " << mp.count(15) << endl; //输出 1) 1
    
    mp.insert(make_pair(20,9.3));
    cout << "2) " << mp[40] << endl;//如果没有关键字为40的元素，则插入一个		//0
    cout << "3) ";Print(mp.begin(),mp.end());//输出：3) (40,0)(20,9.3)(15,2.7)
    
    mp[15] = 6.28; //把关键字为15的元素值改成6.28
    mp[17] = 3.14; //插入关键字为17的元素，并将其值设为3.14
    cout << "4) ";Print(mp.begin(),mp.end());	//(40,0) (20,9.3) (17,3.14) (15,6.28)
    
    return 0;
}
```



第 17 行的`greater  >`最右边的两个`>`之间要有空格，否则 Dev C++ 会将它们当作右移运算符，导致编译出错。在 Visual Studio 2010 中无此问题。

第 22 行用 STL 中的函数模板 make_pair 生成一个 pair 模板类对象插入 mp 中。

第 23 行，如果插入成功，p.second 的值会是 true。显然这里不能成功，因为 map 不允许关键字重复。因为关键字重复而插入失败时，p.first 就指向容器中关键字相同的那个元素。

第 27 行要访问关键字为 40 的元素。在没有这个元素的情况下，一个关键字为 40、值为 0 的元素被自动插入容器。

mp[40] 等价于`mp.operator[](40);`，其返回值是关键字为 40 的那个元素（不论是原有的还是新插入的）的 second 成员变量的引用。第 29 行和第 30 行的道理与此类似。 