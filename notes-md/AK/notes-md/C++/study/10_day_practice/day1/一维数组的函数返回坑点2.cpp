#include <iostream>

using namespace std;

void MultMatrix(float M[4], float A[4], float B[4])
{
    M[0] = A[0]*B[0] + A[1]*B[2];
    M[1] = A[0]*B[1] + A[1]*B[3];
    M[2] = A[2]*B[0] + A[3]*B[2];
    M[3] = A[2]*B[1] + A[3]*B[3];

    cout << M[0] << " " << M[1] << endl;
    cout << M[2] << " " << M[3] << endl;
}

int main()
{
    float A[4] = { 1.75, 0.66, 0, 1.75 };
    float B[4] = {1, 1, 0, 0};

    float *M = new float[4];//��������飬���� ָ����� *M ָ�������ͷ 
    MultMatrix(M, A, B);

	cout<<"test: *M\t"<<*M<<endl;//��������һ���±��	ֵ��0.75 

    cout << M[0] << " " << M[1] << endl;
    cout << M[2] << " " << M[3] << endl;
    delete[] M;

	cout<<"test: *M\t"<<*M<<endl;//�����ַ 

//��� 
//	1.75 1.75
//	0 0
//	1.75 1.75
//	0 0 

    return 0;
}
