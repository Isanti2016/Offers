#include <iostream>

using namespace std;

class A
{
public:
	A() { sum += numbers; numbers++; }
	~A() {}
	void Reset() { sum=0; }
	int GetSum() const { return sum; }
private:
	static unsigned int numbers;
	static unsigned int sum;

};

unsigned int A::numbers = 0;//static必须声明完后，要定义
unsigned int A::sum = 0;

int main_18_1()
{
	int n;
	cin >> n;
	A temp;
	temp.Reset();
	A* a = new A[n];
	delete[] a;
	a = NULL;

	cout << "total of 1+..."<<n<<" : "<<temp.GetSum() << endl;
	return 0;
}