#include "Observer.hpp"
#include <algorithm>
#include <iostream>

void ConcreateSubjects::add(Observer * o)
{
	observers.push_back(o);
}

void ConcreateSubjects::remove(Observer * o)
{
	observers.erase(std::find(observers.begin(), observers.end(), o));
}

void ConcreateSubjects::notify()
{
	for (auto ob : observers)
	{
		ob->update();
	}
}

void Newreader::update()
{
	std::cout << "I am New Reader!" << std::endl;
}

void NeighborReader::update()
{
	std::cout << "I am NeighborReader! " << std::endl;
}
