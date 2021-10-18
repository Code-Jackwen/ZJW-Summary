#include <iostream>

using namespace std;

float* MultMatrix(float A[4], float B[4])
{
    float w[4];//不new的话，出了这个函数就要被释放掉，结果就变的不对了 
//    float *w = new float[4];
    w[0] = A[0]*B[0] + A[1]*B[2];
    w[1] = A[0]*B[1] + A[1]*B[3];
    w[2] = A[2]*B[0] + A[3]*B[2];
    w[3] = A[2]*B[1] + A[3]*B[3];

    return w;
}

int main()
{
    float A[4] = { 1.75, 0.66, 0, 1.75 };
    float B[4] = {1, 1, 0, 0};
    float *M = MultMatrix(A, B);//将M指针指向了函数中w数组的首地址 
    cout << M[0] << " " << M[1] << endl;	//1.75 1.75
    cout << M[2] << " " << M[3] << endl;	//0 0

	//delete[] M;//释放内存，答案正确，且new的空间也delete掉了。 

	//错误的结果 
	//1.75 1.75
	//1.75 0
    return 0;
}
