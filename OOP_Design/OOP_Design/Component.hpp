#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ComponentInterface.hpp"

class Component : public ComponentInterface
{
public:
	virtual void add(Component* comp);
	virtual void remove(Component* comp);
	virtual void update();

private:
	std::vector<Component*> components;
};

class ProSexer : public Component
{
public:
	ProSexer(std::string name_) :
		name(name_)
	{}

	virtual void update()
	{
		std::cout << name << " ProSexer" << std::endl;
	}

private:
	std::string name;
};

class ProSingle : public Component
{
public:
	ProSingle(std::string name_) :
		name(name_)
	{}

	virtual void update()
	{
		std::cout << name << " ProSingle" << std::endl;
	}

private:
	std::string name;
};