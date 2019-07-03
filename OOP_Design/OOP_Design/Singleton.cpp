#include "Singleton.hpp"

EX_Singleton* EX_Singleton::instance = nullptr;

EX_Singleton* EX_Singleton::GetInstance()
{
	if (instance == nullptr)
		instance = new EX_Singleton;

	return instance;
}

void EX_Singleton::SetData(int a)
{
	value = a;
}
