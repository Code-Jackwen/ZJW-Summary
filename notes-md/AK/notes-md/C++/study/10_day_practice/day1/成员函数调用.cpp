#include<iostream>
using namespace std;

int test(int c, int d); 

int main() {
	int ret = test(1,1);
	
	cout<<ret;
	return 0;
}
//class Solution {
//public:
int test(int c, int d) {
//		int c, d;
//		scanf("%d%d", &c, &d);
	d = 100;
	int f = c + d;
	return f;
}
//};
