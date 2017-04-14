#include "Container.h"
#include "Base.h"
#include "Shapes.h"
#include "ShapeFactory.h"
using namespace std;
int main()
{
	Container<Shape> Figures;
	for (int i = 0; i < 30; i++)
	{

		int ShapeType = rand() % 6 + 1;
		switch (ShapeType)
		{
		case 1:Figures.AddLast(ShapeCreator::CreatePoint(true)); break;
		case 2:Figures.AddLast(ShapeCreator::CreateCircle()); break;
		case 3:Figures.AddLast(ShapeCreator::CreateRectangle()); break;
		case 4:Figures.AddLast(ShapeCreator::CreateSquare()); break;
		case 5:Figures.AddLast(ShapeCreator::CreateLine()); break;
		case 6:Figures.AddLast(ShapeCreator::CreateNgon()); break;
		default: break;
		}
	}
	cout << "\n" << "Number of figures: " << Shape::GetCount()<<endl;
	for (int i = 0; i < 30; i++)
	{
		Figures.DeleteFirst();
	}
	cout << "\n" << "Number of figures: " << Shape::GetCount()<<endl;		
	system("pause");
	return 1;
}
