#include <iostream>
#include "Singleton.hpp"
#include <vector>

int main(void)
{
	// �̿Ͱ��� ���ε��ڸ� �������� �� ���ø����̼�, �׷��ȵ��� ������ ������ �ϳ��� �����ϱ⶧����
	// �̱��ϵ������� ����Ѵٸ� �����Ӱ� �����͸� ������ �ҷ��ü��ִ�.

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