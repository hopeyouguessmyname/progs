//abstract factory

#include <iostream>

// kształty
class IShape {  };
 
class Square : public IShape {  };
class Triangle : public IShape {  };
 
// liczby
class INumber { };
 
class RealNumber : public INumber { };
class ComplexNumber : public INumber { };
 
// fabryka abstrakcyjna rodziny obiektów
class MathTestFactory
{
  public:
    virtual IShape *CreateShape() = 0;
    virtual INumber *CreateNumber() = 0;
};
        
// konkretna fabryka rodziny obiektów
class PrimarySchoolTestFactory : public MathTestFactory
{
  public:
    virtual IShape *CreateShape(){ return new Square(); }
    virtual INumber *CreateNumber(){ return new RealNumber(); }
};
 
// konkretna fabryka rodziny obiektów
class HighSchoolTestFactory : public MathTestFactory
{
  public:
    virtual IShape *CreateShape(){ return new Triangle(); }
    virtual INumber *CreateNumber(){ return new ComplexNumber(); }
};
 
// klasa klienta (kontekst wykonania fabryki)
class MathTest
{
    MathTestFactory *mathTestFactory;
 
  public:
    MathTest(MathTestFactory *mathTestFactory){ this->mathTestFactory = mathTestFactory; }
    void GenerateTest()
    {
      IShape *shape = this->mathTestFactory->CreateShape();
      INumber *number = this->mathTestFactory->CreateNumber();
      std::cout << "Test wygenerowany" << std::endl;
    }
};


int main()
{
  MathTest *mathTest;
 
  mathTest = new MathTest( new PrimarySchoolTestFactory() );
  mathTest->GenerateTest(); // łatwy test przy użyciu PrimarySchoolTestFactory()
 
  mathTest = new MathTest( new HighSchoolTestFactory() );
  mathTest->GenerateTest(); // trudny test przy użyciu HighSchoolTestFactory()

  return 0;
}

