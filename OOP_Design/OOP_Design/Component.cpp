#include "Component.hpp"
#include <algorithm>

void Component::add(Component * comp)
{
	components.push_back(comp);
}

void Component::remove(Component * comp)
{
	components.erase(std::find(components.begin(), components.end(), comp));
}

void Component::update()
{
	for (auto component : components)
	{
		component->update();
	}
}
