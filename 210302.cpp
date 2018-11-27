//factory method

class IShape {  };
 
class Square : public IShape {  };
class Triangle : public IShape {  };
 
class ShapeFactory
{
  public:
    virtual IShape *CreateShape() = 0;
};
 
class SquareFactory : public ShapeFactory
{
  public:
    IShape *CreateShape(){ return new Square(); }
};
 
class TriangleFactory : public ShapeFactory
{
  public:
    IShape *CreateShape(){ return new Triangle(); }
};
 

int main()
{
  ShapeFactory *shapeFactory = new SquareFactory();
  IShape *square = shapeFactory->CreateShape();

  return 0;
}
