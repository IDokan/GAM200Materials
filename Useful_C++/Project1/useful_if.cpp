#include <iostream>

int prosexer()
{
    return 5;
}

int main()
{
	int test_num = 0;

	std::cout << "Write Down Original Number: ";
	std::cin >> test_num;

	// c++17 문법 if문으로 if문 자체에서 변수 할당및 이용이 가능
	// 만약 if절에서 쓰이는 함수의 리턴이 참이나 거짓일때 그것을 계속 이용한다면 변수 선언이 따로 필요가 없어 용이
	if(auto hi = test_num;
		hi > 0)
	{
		std::cout << "Write Down New Number: ";
		std::cin >> hi;
		std::cout << std::endl;

		std::cout << "New Number Is that: " << hi << std::endl;
	}
	else
	{
		std::cout << "ERROR! " << std::endl;
	}


	return 0;
}
