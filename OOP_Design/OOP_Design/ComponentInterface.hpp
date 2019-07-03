#pragma once

class Component;

class ComponentInterface
{
public:
	ComponentInterface() = default;

	virtual void add(Component* comp) = 0;
	virtual void remove(Component* comp) = 0;
	//virtual void update() = 0;
};