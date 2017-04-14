#pragma once
#include"Container.h"
#include"iostream"
#include"algorithm"
#include"math.h"
#include"Base.h"
const double Pi = 3.14159;
double Counter = 0;
class Shape : public Printable
{
public:
	Shape()
	{
		Counter ++;
	}
	Shape(const Shape& shape)
	{
		Counter++;
	}
	static double GetCount()
	{
		return Counter;
	}
	std::string Print() const { return "Shape"; }
	~Shape()
	{
		Counter--;
	}
};
class Point : public Shape, public Named
{
public:
	double ox, oy;
	Point(): Named("Point")
	{
		ox = 0;
		oy = 0;
	}
	Point(const double &x, const double &y):Named("Point")
	{
		ox = x;
		oy = y;
	}
	std::string Print() const
	{
		return "\n" + this->GetName() + "\nox:" + std::to_string(this->ox) + "\noy:" + std::to_string(this->oy) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& os, Point& point)
	{
		return os << point.Print();
	}
};
class Circle : public Shape, public Named
{
public:
	double ox, oy, radius;
	Circle():Named("Circle")
	{
		ox = 0;
		oy = 0;
		radius = 0;
	}
	Circle(const double &x, const double &y, const double &r) :Named("Circle")
	{
		ox = x;
		oy = y;
		radius = r;
	}
	std::string Print() const
	{	
		return "\n" + this->GetName() + "\nCenter Ox:" + std::to_string(this->ox) + "\nCenter Oy:" + std::to_string(this->oy)
			+ "\nRadius:" + std::to_string(this->radius) + "\nArea of Circle:" + std::to_string(this->radius * this->radius * Pi) + "\n";;
	}
	friend std::ostream& operator<<(std::ostream& Os, Circle& circle)
	{
		return Os << circle.Print();
	}
};
class Rect : public Shape, public Named
{
public:
	Point Point1, Point2;
	Rect(): Named("Rectangle")
	{
		Point1 = Point();
		Point2 = Point();
	}
	Rect(const double &LeftX, const double &LeftY, const double &RightX, 
		const double &RightY): Named("Rectangle")
	{
		Point1 = Point(LeftX, LeftY);
		Point2 = Point(RightX, RightY);
	}
	std::string Print() const
	{
		return "\n" + this->GetName()
			+ "\nbig side length:" + std::to_string(std::max(fabs(this->Point1.ox - this->Point2.ox), fabs(this->Point1.oy - this->Point2.oy)))
			+ "\nsmall side length:" + std::to_string(std::min(fabs(this->Point1.ox - this->Point2.ox), fabs(this->Point1.oy - this->Point2.oy)))
			+ "\narea:" + std::to_string(fabs(this->Point1.ox - this->Point2.ox)*fabs(this->Point1.oy - this->Point2.oy)) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& Os, Rect& Rectangle)
	{
		return Os << Rectangle.Print();
	}
};
class Square : public Shape, public Named
{
public:
	Point LeftPoint;
	double Length;
	Square(): Named("Square")
	{
		LeftPoint = Point();
		Length = 0;
	}
	Square(const double &LeftX, const double &LeftY, const double & length): Named("Square")
	{
		LeftPoint = Point(LeftX, LeftY);
		Length = length;
	}
	std::string Print() const
	{
		return "\n" + this->GetName() + "\nside length:" + std::to_string(this->Length) + "\narea:" + std::to_string(pow(this->Length, 2)) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& Os, Square& square)
	{
		return Os <<square.Print();
	}
};
class Polyline : public Shape, public Named
{
public:
	Container<Point> Points;
	double Length;
	Polyline(): Named("Polyline")
	{
		Points.AddFirst(Point());
		Length = 0;
	}
	Polyline(Container<Point>& dots, const int& size): Named("Polyline")
	{
		Length = 0;
		dots.SetToFirst();
		AddPoint(dots.GetFirst());
		for (int i = 1; i < size; i ++)
		{
			AddPoint(*dots.GetAndMove());
		}
	}
	void AddPoint(const Point& point)
	{
		if (this->Points.IsEmpty())
		{
			this->Points.AddLast(point);
			return;
		}
		else
		{
			double dotX = this->Points.GetLast().ox;
			double dotY = this->Points.GetLast().oy;
			this->Points.AddLast(point);
			this->Length += sqrt(pow(dotX - point.ox, 2) + pow(dotY - point.oy, 2));
		}
	}
	std::string Print() const
	{
		return "\n" + this->GetName() + "\nlength:" + std::to_string(this->Length) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& Os, Polyline& Line)
	{
		return Os <<Line.Print();
	}
};
class Polygone : public Shape, public Named
{
public:
	Container<Point> Points;
	double Length;
	Polygone(): Named("Polygone")
	{
		Points.AddFirst(Point());
		Length = 0;
	}
	Polygone(Container<Point>& dots, const int& size): Named("Polygone")
	{
			Length = sqrt(pow(dots.GetFirst().ox - dots.GetLast().ox, 2) + 
				pow(dots.GetFirst().oy - dots.GetLast().oy, 2));
			dots.SetToFirst();
			AddPoint(dots.GetFirst());
		for (int i = 1; i < size ; i ++)
		{
			AddPoint(*dots.GetAndMove());
		}
	}
	void AddPoint(const Point& point)
	{
		if (this->Points.IsEmpty())
		{
			this->Points.AddLast(point);
			return;
		}
		else
		{
			double dotX = this->Points.GetLast().ox;
			double dotY = this->Points.GetLast().oy;
			this->Points.AddLast(point);
			this->Length += sqrt(pow(dotX - point.ox, 2) + pow(dotY - point.oy, 2));
		}
	}
	std::string Print() const
	{
		return "\n" + this->GetName() + "\nperimeter:" + std::to_string(this->Length) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& Os, Polygone& Ngon)
	{
		return Os << Ngon.Print();
	}
};