 multimap 是关联容器的一种，multimap 的每个元素都分为关键字和值两部分，容器中的元素是按关键字排序的，并且允许有多个元素的关键字相同。

注意，不能直接修改 multimap 容器中的关键字。因为 multimap 中的元素是按照关键字排序的，当关键字被修改后，容器并不会自动重新调整顺序，于是容器的有序性就会被破坏，再在其上进行查找等操作就会得到错误的结果。
 



例题：一个学生成绩录入和查询系统接受以下两种输入：


name 是一个字符串，其中不包含空格，表示学生姓名。id 是一个整数，表示学号。score 是一个整数，表示分数。学号不会重复，分数和姓名都可能重复。



两种输入交替出现。 

- 第一种输入表示要添加一个学生的信息，碰到这种输入，就记下学生的姓名、id 和分数。
- 第二种输入表示要查询分数为 score 的学生的信息，碰到这种输入，就输出已有记录中分数比查询分数低的最高分获得者的姓名、学号和分数。如果有多个学生满足条件，则输出学号最大的学生的信息。如果找不到满足条件的学生，则输出“Nobody”。



 输入样例：
Add Jack 12 78
Query 78
Query 81
Add Percy 9 81
Add Marry 8 81
Query 82
Add Tom 11 79
Query 80
Query 81

输出结果样例：
Nobody
Jack 12 78
Percy 9 81
Tom 11 79
Tom 11 79 



 此题如果用 vector 存放所有学生的信息，然后进行顺序查找的话，在学生数量很大和查询很多的情况下非常费时，因为顺序查找的时间复杂度是 O(n)。将 vector 排序后再查找也不行，因为会不断插入新元素，每次插入新元素就要进行元素的移动，而这一步骤的时间复杂度是O(n)，这会导致效率低下。



下面程序的思路是用 multimap 存放学生信息，使学生信息按照分数排序。

要添加学生时，就用 insert 成员函数插入学生记录，这步操作的时间复杂度是 O(log(n))。



输入一个要查询的分数 score 时，就用 lower_bound 求得该分数对应的下界——迭代器 p（这一步的时间复杂度是 O(log(n)）。 *p 这个元素的分数是大于或等于 score 的，往前再找一个元素，其分数就是低于 score 的最高分了。继续往前遍历所有等于该分数的元素，找出 id 最大的元素输出即可。 

```c++
#include <iostream>
#include <map>  //使用multimap需要包含此头文件
#include <string>
using namespace std;

class CStudent
{
public:
    struct CInfo  //类的内部还可以定义类
    {
        int id;
        string name;
    };
    int score;
    CInfo info;  //学生的其他信息
};

typedef multimap <int, CStudent::CInfo> MAP_STD;

int main()
{
    
    MAP_STD mp;
    CStudent st;
    string cmd;
    
    while (cin >> cmd) {
        
        if (cmd == "Add") {
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(MAP_STD::value_type(st.score, st.info));
        }
        else if (cmd == "Query") {
            
            int score;
            cin >> score;
            
            MAP_STD::iterator p = mp.lower_bound(score);
            
            if (p != mp.begin()) {
                --p;
                score = p->first;  //比要查询分数低的最高分
                
                MAP_STD::iterator maxp = p;
                int maxId = p->second.id;
                
                for (; p != mp.begin() && p->first == score; --p) {
                    //遍历所有成绩和score相等的学生
                    if (p->second.id > maxId) {
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                
                if (p->first == score) { //如果上面的循环因为 p == mp.begin()
                                         //而终止，则p指向的元素还要处理
                    if (p->second.id > maxId) {
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                
                cout << maxp->second.name << " " << maxp->second.id << " "
                    << maxp->first << endl;
                
            }
            else  //lower_bound 的结果就是 begin，说明没有分数比查询分数低
                cout << "Nobody" << endl;
            
        }
    }
    
    return 0;
}
```

