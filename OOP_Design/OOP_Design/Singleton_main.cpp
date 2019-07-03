#include <iostream>
#include "Singleton.hpp"
#include <vector>

int main(void)
{
	// 이와같이 예로들자면 엔진에서 각 어플리케이션, 그래픽들은 엔진에 무조건 하나만 존재하기때문에
	// 싱글턴디자인을 사용한다면 자유롭게 데이터를 가져와 불러올수있다.

	EX_Singleton* ex = EX_Singleton::GetInstance();

	ex->SetData(5);
	std::cout << ex->GetData() << std::endl;

	EX_Singleton* ex2 = EX_Singleton::GetInstance();
	ex2->SetData(3);

	std::cout << "First EX Data: ";
	std::cout << ex->GetData() << std::endl;

	std::cout << "Second EX Data: ";
	std::cout << ex2->GetData() << std::endl;

	return 0;
}