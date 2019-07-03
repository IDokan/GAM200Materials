#pragma once
#include <vector>

class Observer
{
public:
	virtual void update() = 0;
};

class Subject
{
public:
	virtual void add(Observer* o) = 0;
	virtual void remove(Observer* o) = 0;
	virtual void notify() = 0;
};

class ConcreateSubjects : public Subject
{
public:
	ConcreateSubjects() = default;

	virtual void add(Observer* o);
	virtual void remove(Observer* o);
	virtual void notify();

	std::vector<Observer*> observers{};
};

class Newreader : public Observer
{
public:
	Subject* subj;

	Newreader(Subject* sub)
	{
		subj = sub;
		subj->add(this);
	}

	void update();	
};

class NeighborReader : public Observer
{
public:
	Subject* subj;

	NeighborReader(Subject* sub)
	{
		subj = sub;
		subj->add(this);
	}

	void update();
};