## queue

queue 就是“队列”。队列是先进先出的，和排队类似。队头的访问和删除操作只能在队头进行，添加操作只能在队尾进行。不能访问队列中间的元素。
queue 可以用 list 和 deque 实现，默认情况下用 deque 实现。



 queue 同样也有和 stack 类似的 push、pop、top 函数。区别在于，queue 的 push 发生在队尾，pop 和 top 发生在队头。 

## priority_queue

 priority_queue 是“优先队列”。它和普通队列的区别在于，优先队列的队头元素总是最大的——即执行 pop 操作时，删除的总是最大的元素；执行 top 操作时，返回的是最大元素的引用。 

 priority_queue 可以用 vector 和 deque 实现，默认情况下用 vector 实现。 



priority_queue 定义如下：

```
template < class T, class Container = vector <T>, class Compare = less<T> >
class priority_queue{
  ...
};
```

priority_queue 的第三个类型参数可以用来指定排序规则。



```c++
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    
    priority_queue<double> pq1;
    pq1.push(3.2); pq1.push(9.8); pq1.push(9.8); pq1.push(5.4);
    while(!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    } //上面输出 9.8 9.8 5.4 3.2
    cout << endl;
    
    priority_queue<double,vector<double>,	greater<double> > pq2;
    pq2.push(3.2); pq2.push(9.8); pq2.push(9.8); pq2.push(5.4);
    while(!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    //上面输出 3.2 5.4 9.8 9.8
    return 0;
}
```

 程序的输出结果是：
9.8 9.8 5.4 3.2
3.2 5.4 9.8 9.8 