#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> temp;

	for (int i = 0; i < 10; ++i)
	{
		temp.push_back(i);
	}

	// c++11 for문
	for (auto number : temp)
	{
		std::cout << number << ", ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	// 하지만 게임에서 오브젝트를 지우기 위해서는 위와같은 for문 사용 x 아래와같은 for문 사용
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