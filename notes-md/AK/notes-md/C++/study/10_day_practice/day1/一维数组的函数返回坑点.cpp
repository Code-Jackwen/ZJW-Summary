#include <iostream>

using namespace std;

float* MultMatrix(float A[4], float B[4])
{
    float w[4];//��new�Ļ����������������Ҫ���ͷŵ�������ͱ�Ĳ����� 
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
    float *M = MultMatrix(A, B);//��Mָ��ָ���˺�����w������׵�ַ 
    cout << M[0] << " " << M[1] << endl;	//1.75 1.75
    cout << M[2] << " " << M[3] << endl;	//0 0

	//delete[] M;//�ͷ��ڴ棬����ȷ����new�Ŀռ�Ҳdelete���ˡ� 

	//����Ľ�� 
	//1.75 1.75
	//1.75 0
    return 0;
}
