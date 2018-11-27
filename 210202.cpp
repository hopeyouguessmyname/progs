//simple factory

#include <iostream>

enum ShapeType
{
  SquareType = 1,
  TriangleType = 2
};

class IShape { public: virtual void print(){ ; } };
 
class Square : public IShape { public: void print(){ std::cout << "Square" << std::endl; } };
class Triangle : public IShape { public: void print(){ std::cout << "Triangle" << std::endl; } };


class ShapeFactory
{
  public:
    IShape *CreateShape(ShapeType shapeType)
    {
      switch (shapeType)
      {
        case SquareType :
          return new Square();
          break;
 
        case TriangleType:
          return new Triangle();
          break;
 
        default:
          /*throw new ArgumentException()*/;
      }
    }
};

int main()
{
  ShapeFactory *shapeFactory = new ShapeFactory(); 
  IShape *triangle = shapeFactory->CreateShape(TriangleType);
  IShape *square = shapeFactory->CreateShape(SquareType);
  
  triangle->print();
  square->print();

  return 0;
}
