#include <iostream>

using namespace std;
template<unsigned int n> //ģ���д��
class Solution4
{
public:					//��Ȼstruct��class�����ʱ��ȼۣ�����classʱ���գ�Ҫ��pubulic
	enum Value { N = Solution4<n - 1>::N + n };
};
template<> 
class Solution4<1>//ȫ�ػ���ģ��
{
public:
	enum Value { N = 1 };
};
int main_18_4()
{
	Solution4<100> temp;//ģ��Ԫ��̣������ʱ���������ֵ
	cout << temp.N << endl;
	return 0;
}