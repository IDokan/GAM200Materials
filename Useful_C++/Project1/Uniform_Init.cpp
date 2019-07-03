#include <iostream>
#include <vector>

class A
{
public:
	A() 
	{
		std::cout << "Constructor Of A !" << std::endl;
	}

private:
    int a;
};

class B
{
public:
	B(A a)
	{
		std::cout << "Constructor Of B !" << std::endl;
	}
};

int main(void)
{
	std::cout << "Test1 " << std::endl;
	A a();
	std::cout << std::endl;

	std::cout << "Test2 " << std::endl;
	B b(A());
	std::cout << std::endl;

	// FIX
	std::cout << "Test3 " << std::endl;
	A a_fix{};
	std::cout << std::endl;

	std::cout << "Test4 " <<  std::endl;
	B b_fix{ A() };
	std::cout << std::endl;
	return 0;
}