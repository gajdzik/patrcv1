
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Point
{
protected:
	string name;
	int x;
	int y;

public:
	Point(string n = "new", int a = 2, int b = 4)
	{
		name = n;
		x = a;
		y = b;
	}
	virtual void v() = 0; //pure virtual
	virtual void get()
	{
		cout << "name :" << name << " x :" << x << " y :" << y << endl;
	}

	virtual ~Point() {};
};

class Square : public Point
{
	int xx;
	int yy;
	int area;

public:
	Square(string n = "new", int a = 1, int b = 2, int aa = 4, int bb = 5) :Point(n, a, b)
	{
		xx = aa;
		yy = bb;
		area = abs(x - xx)*(abs(y - yy));
	}
	virtual void v() override {}; // przys³aniamy metodê pure virtual, ¿eby nie byæ klas¹ abstrakcyjn¹
	virtual void get()
	{
		Point::get();
		cout << " xx :" << xx << " yy :" << yy << " area :" << area << endl;

	}
	virtual ~Square() {};
};



int main()
{
	Square second;
	second.get();
	auto i = 15;
	int j = 0;
	//for
	for (j = 0; j < 5; j++)
	{
		cout << "petla for " << j << endl;
	}
	//while
	while (j<6)
	{
		cout << "petla while" << j << endl;
		j++;
	}
	//do while
	do
	{
		cout << "petla do...while" << j << endl;
		j++;
	} while (j<7);
	//konwersja typów
	double x = 15.2305;
	int y = x;
	cout << "double x :" << x << endl;
	cout << "konwersja double na int y :" << y << endl;
	//alokacja statyczna
	int tab[2] = { 15, 16 };
	cout << tab[0] << " " << tab[1] << endl;
	//alokacja dynamiczna 
	int *ptr = new int[2];
	*ptr = 13;
	*(ptr + 1) = 14;
	cout << *ptr << " " << *(ptr + 1) << endl;
	delete[] ptr;
	//arytmetyka wskaŸników
	int *nowy = new int[5];
	int *p = nowy;
	*nowy = 10;
	*(nowy + 1) = 11;
	*(nowy + 2) = 12;
	*(nowy + 3) = 13;
	*(nowy + 4) = 14;
	cout << "na starcie : " << *p << endl;
	p = p + 3;
	cout << "po dodawaniu : " << *p << endl;
	p = p - 2;
	cout << "po odejmowaniu : " << *p << endl;
	int g = p - nowy;
	cout << "roznica pomiedzy wskaznikami 'p' a 'nowy' : " << g << endl;
	delete[] nowy;

	getchar();
	getchar();


	return 0;
}

