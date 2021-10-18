//容器（Containers）	容器是用来管理某一类对象的集合。C++ 提供了各种不同类型的容器，比如 deque、list、vector、map 等。
//算法（Algorithms）	算法作用于容器。它们提供了执行各种操作的方式，包括对容器内容执行初始化、排序、搜索和转换等操作。
//迭代器（iterators）	迭代器用于遍历对象集合的元素。这些集合可能是容器，也可能是容器的子集。


//push_back( ) 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
//size( ) 函数显示向量的大小。
//begin( ) 函数返回一个指向向量开头的迭代器。
//end( ) 函数返回一个指向向量末尾的迭代器。

//C++ STL 之 vector 的 capacity 和 size 属性区别
//size 是当前 vector 容器真实占用的大小，也就是容器当前拥有多少个容器。
//capacity 是指在发生 realloc 前能允许的最大元素数，即预分配的内存空间。

//当然，这两个属性分别对应两个方法：resize() 和 reserve()。
//使用 resize() 容器内的对象内存空间是真正存在的。
//使用 reserve() 仅仅只是修改了 capacity 的值，容器内的对象并没有真实的内存空间(空间是"野"的)。
//此时切记使用 [] 操作符访问容器内的对象，很可能出现数组越界的问题。


//注： 对于 reserve(10) 后接着直接使用 [] 访问越界报错(内存是野的)，大家可以加一行代码试一下，我这里没有贴出来。
//这里直接用[]访问，vector 退化为数组，不会进行越界的判断。此时推荐使用 at()，会先进行越界检查。

#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
   // 创建一个向量存储 int
   vector<int> vec; 
   int i;
 
   // 显示 vec 的原始大小
   cout << "vector size = " << vec.size() << endl;
 
   // 推入 5 个值到向量中
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
 
   // 显示 vec 扩展后的大小
   cout << "extended vector size = " << vec.size() << endl;
 
   // 访问向量中的 5 个值
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
 
 
   // 使用迭代器 iterator 访问值
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }
   
   
//    vector<int> v;
//    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
//    v.reserve(10);
//    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
//    v.resize(10);
//    v.push_back(0);
//    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
   
 
   return 0;
}
