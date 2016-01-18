// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	Point(string n="new", int a=2, int b=4)
	{
		name = n;
		x = a;
		y = b;
	}
	virtual void v() =0; //pure virtual
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
	Square(string n = "new", int a = 1, int b = 2, int aa = 4, int bb=5  ) :Point(n,a,b)
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
	getchar();
	getchar();


    return 0;
}

