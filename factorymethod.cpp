#include <iostream>

class IProduct{};
class ConcreteProduct1 : public IProduct { public: ConcreteProduct1(){ std::cout << "ConcreteProduct1" << std::endl; } };
class ConcreteProduct2 : public IProduct { public: ConcreteProduct2(){ std::cout << "ConcreteProduct2" << std::endl; } };

class IFactory{ public: virtual IProduct *factoryMethod() = 0; };
class FactoryNo1 : public IFactory{ public: virtual IProduct *factoryMethod(){ return new ConcreteProduct1(); } };
class FactoryNo2 : public IFactory{ public: virtual IProduct *factoryMethod(){ return new ConcreteProduct2(); } };

int main()
{
  IFactory *factory = new FactoryNo1();
  IProduct *concreteProduct = factory->factoryMethod();
  delete factory;
  delete concreteProduct;

  factory = new FactoryNo2();
  concreteProduct = factory->factoryMethod();

  return 0;
}
