#pragma once

class Application
{
private:
    Application()
    {};

public:
    static Application* app;
    static Application* GetApplication();

};

class EX_Singleton
{
private:
	EX_Singleton() : value(0)
	{};

public:
	static EX_Singleton* instance;
	static EX_Singleton* GetInstance();
	void SetData(int a);
	int GetData() { return value; }

private:
	int value;
};