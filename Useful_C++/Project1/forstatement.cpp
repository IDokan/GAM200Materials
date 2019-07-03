#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> temp;

	for (int i = 0; i < 10; ++i)
	{
		temp.push_back(i);
	}

	// c++11 for��
	for (auto number : temp)
	{
		std::cout << number << ", ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	// ������ ���ӿ��� ������Ʈ�� ����� ���ؼ��� ���Ͱ��� for�� ��� x �Ʒ��Ͱ��� for�� ���
	for (auto i = temp.begin(); i != temp.end(); )
	{
		if (*i % 2 == 0)
		{
			i = temp.erase(i);
		}
		else
		{
			i++;
		}
	}

	for (auto number : temp)
	{
		std::cout << number << ", ";
	}
	std::cout << std::endl;
	return 0;
}