#include <iostream>

using namespace std;

template <class T> class MakeSealed
{
	friend T;//��Ԫ��
private:
	MakeSealed(){}
	~MakeSealed(){}
};
class SealedClassC :virtual public MakeSealed<SealedClassC>
{
public:
	SealedClassC(){}
	~SealedClassC(){}
};
class SealedClassD :public SealedClassC
{

};
int main_19_2()
{
	SealedClassC C;
	//SealedClassD D;//���ܱ��̳е���
	return 0;
}