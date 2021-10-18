//������Containers��	��������������ĳһ�����ļ��ϡ�C++ �ṩ�˸��ֲ�ͬ���͵����������� deque��list��vector��map �ȡ�
//�㷨��Algorithms��	�㷨�����������������ṩ��ִ�и��ֲ����ķ�ʽ����������������ִ�г�ʼ��������������ת���Ȳ�����
//��������iterators��	���������ڱ������󼯺ϵ�Ԫ�ء���Щ���Ͽ�����������Ҳ�������������Ӽ���


//push_back( ) ��Ա������������ĩβ����ֵ������б�Ҫ����չ�����Ĵ�С��
//size( ) ������ʾ�����Ĵ�С��
//begin( ) ��������һ��ָ��������ͷ�ĵ�������
//end( ) ��������һ��ָ������ĩβ�ĵ�������

//C++ STL ֮ vector �� capacity �� size ��������
//size �ǵ�ǰ vector ������ʵռ�õĴ�С��Ҳ����������ǰӵ�ж��ٸ�������
//capacity ��ָ�ڷ��� realloc ǰ����������Ԫ��������Ԥ������ڴ�ռ䡣

//��Ȼ�����������Էֱ��Ӧ����������resize() �� reserve()��
//ʹ�� resize() �����ڵĶ����ڴ�ռ����������ڵġ�
//ʹ�� reserve() ����ֻ���޸��� capacity ��ֵ�������ڵĶ���û����ʵ���ڴ�ռ�(�ռ���"Ұ"��)��
//��ʱ�м�ʹ�� [] ���������������ڵĶ��󣬺ܿ��ܳ�������Խ������⡣


//ע�� ���� reserve(10) �����ֱ��ʹ�� [] ����Խ�籨��(�ڴ���Ұ��)����ҿ��Լ�һ�д�����һ�£�������û����������
//����ֱ����[]���ʣ�vector �˻�Ϊ���飬�������Խ����жϡ���ʱ�Ƽ�ʹ�� at()�����Ƚ���Խ���顣

#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
   // ����һ�������洢 int
   vector<int> vec; 
   int i;
 
   // ��ʾ vec ��ԭʼ��С
   cout << "vector size = " << vec.size() << endl;
 
   // ���� 5 ��ֵ��������
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
 
   // ��ʾ vec ��չ��Ĵ�С
   cout << "extended vector size = " << vec.size() << endl;
 
   // ���������е� 5 ��ֵ
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
 
 
   // ʹ�õ����� iterator ����ֵ
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
