//simple factory

enum ShapeType
{
  SquareType = 1,
  TriangleType = 2
};

class IShape {  };
 
class Square : public IShape {  };
class Triangle : public IShape {  };


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

  return 0;
}
