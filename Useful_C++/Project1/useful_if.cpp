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

	// c++17 ���� if������ if�� ��ü���� ���� �Ҵ�� �̿��� ����
	// ���� if������ ���̴� �Լ��� ������ ���̳� �����϶� �װ��� ��� �̿��Ѵٸ� ���� ������ ���� �ʿ䰡 ���� ����
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
