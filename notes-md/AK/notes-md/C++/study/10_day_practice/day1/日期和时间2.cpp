#include <iostream>
#include <ctime>
using namespace std;
 
 
//���ĸ���ʱ����ص����ͣ�clock_t��time_t��size_t �� tm��
//���� clock_t��size_t �� time_t �ܹ���ϵͳʱ������ڱ�ʾΪ		ĳ��������
//�ṹ���� tm �����ں�ʱ���� C �ṹ����ʽ���棬tm �ṹ�Ķ������£�
//struct tm {
//  int tm_sec;   // �룬������Χ�� 0 �� 59���������� 61
//  int tm_min;   // �֣���Χ�� 0 �� 59
//  int tm_hour;  // Сʱ����Χ�� 0 �� 23
//  int tm_mday;  // һ���еĵڼ��죬��Χ�� 1 �� 31
//  int tm_mon;   // �£���Χ�� 0 �� 11
//  int tm_year;  // �� 1900 ���������
//  int tm_wday;  // һ���еĵڼ��죬��Χ�� 0 �� 6��������������
//  int tm_yday;  // һ���еĵڼ��죬��Χ�� 0 �� 365���� 1 �� 1 ������
//  int tm_isdst; // ����ʱ
//};

//1	time_t time(time_t *time);
//�ú�������ϵͳ�ĵ�ǰ����ʱ�䣬�� 1970 �� 1 �� 1 ���������������������ϵͳû��ʱ�䣬�򷵻� -1��
//2	char *ctime(const time_t *time);
//�÷���һ����ʾ����ʱ����ַ���ָ�룬�ַ�����ʽ day month year hours:minutes:seconds year\n\0��
//3	struct tm *localtime(const time_t *time);
//�ú�������һ��ָ���ʾ����ʱ��� tm �ṹ��ָ�롣
//4	clock_t clock(void);
//�ú������س���ִ����һ��Ϊ����Ŀ�ͷ����������ʱ����ʹ�õ�ʱ�䡣���ʱ�䲻���ã��򷵻� -1��
//5	char * asctime ( const struct tm * time );
//�ú�������һ��ָ���ַ�����ָ�룬�ַ��������� time ��ָ��ṹ�д洢����Ϣ��������ʽΪ��day month date hours:minutes:seconds year\n\0��
//6	struct tm *gmtime(const time_t *time);
//�ú�������һ��ָ�� time ��ָ�룬time Ϊ tm �ṹ����Э������ʱ��UTC��Ҳ����Ϊ�������α�׼ʱ�䣨GMT����ʾ��
//7	time_t mktime(struct tm *time);
//�ú�����������ʱ�䣬�൱�� time ��ָ��ṹ�д洢��ʱ�䡣
//8	double difftime ( time_t time2, time_t time1 );
//�ú������� time1 �� time2 ֮������������
//9	size_t strftime();
//�ú��������ڸ�ʽ�����ں�ʱ��Ϊָ���ĸ�ʽ��
 
int main( )
{
   // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
   time_t now = time(0);
   
   // �� now ת��Ϊ�ַ�����ʽ
   char* dt = ctime(&now);
   cout << "�������ں�ʱ�䣺" << dt << endl;
 
   // �� now ת��Ϊ tm �ṹ
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC ���ں�ʱ�䣺"<< dt << endl;
}
