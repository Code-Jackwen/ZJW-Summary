#include<iostream>
using namespace std;

//int c = 10,d = 20;
int c,d;

void test(int c, int d); 

int main() {
	
	test(1,1);
	
	cout<<c<<endl;
	cout<<d<<endl;
	return 0;
}
void test(int c, int d) {
	c = c + 100;
	d = d + c;
}

