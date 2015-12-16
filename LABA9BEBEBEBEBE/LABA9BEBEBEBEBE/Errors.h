#pragma once
#include <string>

using namespace std;

class Error
{
protected:
	string message;
public:
	Error()
	{
		message = "";
	}
	Error(string msg)
	{
		message = msg;
	}
	~Error()
	{
		message = "";
	}
	virtual void show(void) = 0;
};

class OverFlow : public Error   //ÏÅÐÅÏÎËÍÅÍÈÅ
{
public:
	OverFlow(string msg)
	{
		this->message = msg;
	}
	virtual void show()
	{
		cout << "Ïåðåïîëíåíèå èñêëþ÷åíèÿ âûïîëíÿåòñÿ:";
		cout << this->message << endl;
	}
};

class IncorrectIndex : public Error   //ÍÅÏÐÀÂÈËÜÍÀß ÈÍÄÅÊÑÀÖÈß
{
public:
	IncorrectIndex(string msg)
	{
		this->message = msg;
	}
	virtual void show()
	{
		cout << "Íåïðàâèëüíûé èíäåêñ: ";
		cout << this->message << endl;
	}
};

class DividingByZero : public Error   //ÄÅËÅÍÈÅ ÍÀ 0
{
public:
	DividingByZero(string msg)
	{
		this->message = msg;
	}
	virtual void show()
	{
		cout << "Äåëåíèå íà íîëü:";
		cout << this->message << endl;
	}
};