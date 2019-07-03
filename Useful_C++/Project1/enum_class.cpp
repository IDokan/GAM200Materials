#include <iostream>
// Error 
//enum Color { RED, GREEN, BLUE }; 
//
//enum TrafficLight {
//	GREEN,
//	YELLOW, 
//	RED
//};

enum class Color 
{ 
	RED, 
	GREEN, 
	BLUE 
};

enum class TrafficLight 
{
	GREEN,
	YELLOW,
	RED
};

enum class ProSexer;

class A
{
private:
	ProSexer goodSexer;
};


enum class ProSexer
{
	Sexer1,
	Sexer2
};

int main(void)
{
	std::cout << sizeof(ProSexer) << std::endl;

	return 0;
}