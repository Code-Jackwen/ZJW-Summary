#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

//https://blog.csdn.net/lijiang1991/article/details/52727478

/**
默认比较函数为less, 大顶堆
**/
void defaultCmpLess() {
    cout << "=========defaultCmpLess(big heap)========" << endl;
    priority_queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout <<endl;

}

/**
使用greater比较函数，小顶堆
**/
void useCmpGreater() {
    cout << "=========useCmpGreater(small heap)========" << endl;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout <<endl;
}


//=========================
/**
自构建比较函数
**/
struct cmp2
{
    bool operator()(int a, int b) {
        return a > b;
    }
};

void designCmp() {
    cout << "=========designCmp========" << endl;
    cout << "operator a<b" << endl;
    priority_queue<int, vector<int>, cmp2 > q;

    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout <<endl;
}


//==========================
/**
运算符重载		<
**/

struct Node
{
    int x, y;
    Node(int a = 0, int b = 0):x(a), y(b){};
    friend bool operator<(const Node &a, const Node &b);

};
inline bool operator<(const Node &a, const Node &b) {
    if (a.x != b.x)  return a.x < b.x;
    return a.y > b.y;
}

void overloadOperator() {
    cout << "=========overload Operator< =========" << endl;
    cout << "a.x < b.x; a.y > b.y" << endl;
    priority_queue<Node> q;
    for (int i = 0; i < 10; i++) {

        q.push( Node( rand()%20, rand()%20 ) );
    }

    while (!q.empty()) {
        cout << q.top().x << "," << q.top().y << endl;
        q.pop();
    } 
    cout << endl;   
}


int main(int argc, char const *argv[])
{   
//    defaultCmpLess();//默认是大根堆，比较用的 > 号 
//    useCmpGreater();

    overloadOperator();//if (a.x != b.x)  return a.x < b.x;		    return a.y > b.y;
    //18,18
	//16,7
	//11,1
	//7,1
	//7,1
	//5,5
	//4,2
	//4,9
	//2,15
	//0,14
    
//    designCmp();	//operator a<b	18 18 14 9 7 4 4 2 1 0			相反的 
					//operator a>b	0 1 2 4 4 7 9 14 18 18

}

