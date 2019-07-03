#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>

// 그냥 어떻게 진행되는지만 보자
int main(void)
{
	srand((unsigned)time(NULL));

	std::vector<int> sort_ex;
	std::vector<int> revers_sort_ex;
	for (int i = 0; i < 10; ++i)
	{
		int temp = rand() % 51;
		sort_ex.push_back(temp);
		revers_sort_ex.push_back(temp);
	}

	std::stable_sort(sort_ex.begin(), sort_ex.end());
	std::stable_sort(revers_sort_ex.begin(), revers_sort_ex.end(), [](int val1, int val2) {return val1 > val2; });

	for (auto number : sort_ex)
	{
		std::cout << number << ", ";
	}
	std::cout << std::endl << std::endl;


	for (auto number : revers_sort_ex)
	{
		std::cout << number << ", ";
	}
	std::cout << std::endl;

	return 0;
}