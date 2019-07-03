#pragma once
#include <iostream>
#include "Component.hpp"

class Weapon
{
public:
	virtual void Attack() = 0;
};

class Sword : public Weapon
{
public:
	virtual void Attack()
	{
		std::cout << "This is MY Sword DICK" << std::endl;
	}
};

class Bow : public Weapon
{
	virtual void Attack()
	{
		std::cout << "This is MY Bow DICK" << std::endl;
	}
};

class Player : public Component
{
public:
	void SetWeapon(Weapon* type)
	{
		weapon = type;
	};

	void Attack() 
	{
		weapon->Attack();
	}

	Weapon* weapon;
};