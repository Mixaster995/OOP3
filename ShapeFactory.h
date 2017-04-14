#pragma once
#include"Shapes.h"
class ShapeCreator
{
public:
	static Point CreatePoint(bool print_on)
	{
		Point NewPoint(rand(), rand());
		if (print_on)
		{
			std::cout << NewPoint << "\n";
		}
		return NewPoint;
	}
	static Circle CreateCircle()
	{
		Circle NewCircle(rand(), rand(), rand());
		std::cout << NewCircle << "\n";
		return NewCircle;
	}
	static Rect CreateRectangle()
	{
		Rect NewRectangle(rand(), rand(), rand(), rand());
		std::cout << NewRectangle << "\n";
		return NewRectangle;
	}
	static Square CreateSquare()
	{
		Square NewSquare (rand(), rand(), rand());
		std::cout << NewSquare << "\n";
		return NewSquare;
	}
	static Polyline CreateLine()
	{
		int size = rand() % 100 + 1;
		Container<Point> dots;
		for (int i = 0; i < size; i++)
		{
			dots.AddLast(ShapeCreator::CreatePoint(false));
		}
		Polyline NewLine(dots, size);
		std::cout << NewLine << "\n";
		return NewLine;
	}
	static Polygone CreateNgon()
	{
		int size = rand() % 100 + 1;
		Container<Point> dots;
		for (int i = 0; i < size; i++)
		{
			dots.AddLast(ShapeCreator::CreatePoint(false));
		}
		Polygone NewNgon(dots, size);
		std::cout << NewNgon << "\n";
		return NewNgon;
	}
};