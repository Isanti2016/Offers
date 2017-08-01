#include <iostream>

using namespace std;

template <class T> class MakeSealed
{
	friend T;//友元类
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
	//SealedClassD D;//不能被继承的类
	return 0;
}