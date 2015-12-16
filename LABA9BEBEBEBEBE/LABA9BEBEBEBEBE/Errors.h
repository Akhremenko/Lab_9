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

class OverFlow : public Error   //������������
{
public:
	OverFlow(string msg)
	{
		this->message = msg;
	}
	virtual void show()
	{
		cout << "������������ ���������� �����������:";
		cout << this->message << endl;
	}
};

class IncorrectIndex : public Error   //������������ ����������
{
public:
	IncorrectIndex(string msg)
	{
		this->message = msg;
	}
	virtual void show()
	{
		cout << "������������ ������: ";
		cout << this->message << endl;
	}
};

class DividingByZero : public Error   //������� �� 0
{
public:
	DividingByZero(string msg)
	{
		this->message = msg;
	}
	virtual void show()
	{
		cout << "������� �� ����:";
		cout << this->message << endl;
	}
};