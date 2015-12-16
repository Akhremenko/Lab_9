#include <iostream>
#include <string>
#include "Errors.h"

using namespace std;

class Transportnoe_sredstvo
{
public:
	string nazvanie;

	Transportnoe_sredstvo()
	{
		nazvanie = "";
	};

	Transportnoe_sredstvo(string qwert)
	{
		nazvanie = qwert;
	}

	friend Transportnoe_sredstvo operator +(Transportnoe_sredstvo& V1, Transportnoe_sredstvo& V2)
	{
		return Transportnoe_sredstvo(V1.nazvanie + V2.nazvanie);
	}
	friend bool operator ==(Transportnoe_sredstvo& T1, Transportnoe_sredstvo& T2)
	{
		return (T1.nazvanie == T2.nazvanie);
	}
	friend bool operator >(Transportnoe_sredstvo& T1, Transportnoe_sredstvo& T2)
	{
		return (T1.nazvanie.length() > T2.nazvanie.length());
	}
	friend bool operator <(Transportnoe_sredstvo& T1, Transportnoe_sredstvo& T2)
	{
		return (T1.nazvanie.length() < T2.nazvanie.length());
	}
	friend bool operator <(Transportnoe_sredstvo& T1, int& T2)
	{
		return (T1.nazvanie.length() < T2);
	}
	friend ostream& operator <<(ostream& output, Transportnoe_sredstvo& T)
	{
		return output << T.nazvanie;
	}
	friend int operator /(Transportnoe_sredstvo& V1, Transportnoe_sredstvo& V2)
	{
		try
		{
			if (V2.nazvanie.length() == 0)
			{
				throw  new DividingByZero("V2.nazvanie.length() = 0!");
			}
			return (V1.nazvanie.length() / V2.nazvanie.length());
		}
		catch (DividingByZero* e)
		{
			e->show();
		}
	}
};

template<class Type>
class Vektor
{
public:
	Type Arr[3];

	Vektor(Type A, Type B, Type C)
	{
		Arr[0] = A;
		Arr[1] = B;
		Arr[2] = C;
	}

	friend Vektor operator +(Vektor& V1, Vektor& V2)
	{
		return Vektor(V1.Arr[0] + V2.Arr[0], V1.Arr[1] + V2.Arr[1], V1.Arr[2] + V2.Arr[2]);
	}

	Type operator()(int index)
	{
		try 
		{
			if (index < 0)
			{
				throw new IncorrectIndex ("она не может быть меньше, чем 0!"); //определяем тип исключительной ситуации
			}
			if (index > 2)
			{
				throw new OverFlow("она не может быть больше 2!");
			}
				return Arr[index];
		}
		catch (IncorrectIndex *e)
		{
			e->show();
		}
		catch (OverFlow *e)
		{
			e->show();
		}
	}

	friend bool operator == (Vektor& V1, Vektor& V2)
	{
		return ((V1.Arr[0] == V2.Arr[0]) && (V1.Arr[1] == V2.Arr[1]) && (V1.Arr[2] == V2.Arr[2]));
	}

	friend bool operator > (Vektor& V1, Vektor& V2)
	{
		return ((V1.Arr[0] > V2.Arr[0]) && (V1.Arr[1] > V2.Arr[1]) && (V1.Arr[2] > V2.Arr[2]));
	}
	friend bool operator < (Vektor& V1, Vektor& V2)
	{
		return ((V1.Arr[0] < V2.Arr[0]) && (V1.Arr[1] < V2.Arr[1]) && (V1.Arr[2] < V2.Arr[2]));
	}
	friend bool operator < (Vektor& V1, int& V2)
	{
		return ((V1.Arr[0] < V2) && (V1.Arr[1] < V2) && (V1.Arr[2] < V2));
	}


	~Vektor() {};
	void Vektor::print()
	{
		cout << "Arr[0] = " << Arr[0] << endl;
		cout << "Arr[1] = " << Arr[1] << endl;
		cout << "Arr[2] = " << Arr[2] << endl;
	}
};

template <class Type>
Vektor<Type> minV(Vektor<Type> x, Vektor <Type> y)
{
	int zero = 0;
	if (x<zero)
	{
		if (x > y)
		{
			return x;
		}
	}
	if (y<zero)
	{
		return y;
	}
	if (x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	Vektor<int> W1(-1, 2, 4);
	Vektor<int> W2(-4, -5, -8);
	minV(W1, W2).print();
	cout << "___________________________________" << endl;

	Vektor<double> W12(-0.1, 0.2, 0.4);
	Vektor<double> W22(-0.4, -0.5, -0.8);
	minV(W12, W22).print();
	cout << "___________________________________" << endl;

	Transportnoe_sredstvo as("lol");
	Transportnoe_sredstvo sd("lal");
	Transportnoe_sredstvo df("lul");
	Vektor<Transportnoe_sredstvo> W123(as, sd, df);
	Vektor<Transportnoe_sredstvo> W223(as, sd, df);
	minV(W123, W223).print();
	cout << "___________________________________" << endl;

	Vektor<int> V1(1, 2, 3);
	Vektor<int> V2(4, 5, 6);
	Vektor<int> V3(0, 0, 0);
	Vektor<int> V4(5, 7, 9);
	V3 = V1 + V2;
	V3.print();
	cout << V2(1) << endl;

	if (V3 == V4)
	{
		cout << "Вектора равны" << endl;
	}

	if (V2 > V1)
	{
		cout << "Вектор V2>V1" << endl << "________________" << endl;
	}

	Vektor<double> V1_1(0.1, 0.2, 0.3);
	Vektor<double> V2_2(0.4, 0.5, 0.6);
	Vektor<double> V3_3(0, 0, 0);
	Vektor<double> V4_4(0.5, 0.7, 0.9);
	V3_3 = V1_1 + V2_2;
	V3_3.print();
	cout << V2_2(1) << endl;

	if (V3_3 == V4_4)
	{
		cout << "Вектора равны" << endl;
	}

	if (V2_2 > V1_1)
	{
		cout << "Вектор V2_2>V1_1" << endl << "________________" << endl;
	}

	Transportnoe_sredstvo fg("8");

	Vektor<Transportnoe_sredstvo> V_23(as, sd, df);
	Vektor<Transportnoe_sredstvo> V_34(fg, fg, fg);
	Vektor<Transportnoe_sredstvo> V_45(df, sd, as);
	V_45 = V_23 + V_34;
	V_45.print();


	W1(4);
	W1(-1);

	Transportnoe_sredstvo t1("Привет");
	Transportnoe_sredstvo t2;
	t1 / t2;
	system("pause");
}