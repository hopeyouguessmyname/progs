#include <iostream>

enum ProductType{ CONCRETE_PRODUCT1, CONCRETE_PRODUCT2 };

class IProduct{ };
class ConcreteProduct1 : public IProduct{ public: ConcreteProduct1(){ std::cout << "ConcreteProduct1\n"; } };
class ConcreteProduct2 : public IProduct{ public: ConcreteProduct2(){ std::cout << "ConcreteProduct2\n"; } };

class SimpleFactory
{
  public:
    IProduct *factoryMethod(ProductType productType)
    {
      switch(productType)
      {
        case CONCRETE_PRODUCT1:
          return new ConcreteProduct1();
          break;
        case CONCRETE_PRODUCT2:
          return new ConcreteProduct2();
          break;
        default:
          return NULL;
      }
    }
};

int main()
{
  SimpleFactory * factory = new SimpleFactory();
  IProduct *product = factory->factoryMethod(CONCRETE_PRODUCT1);
  product = factory->factoryMethod(CONCRETE_PRODUCT2);
  product = factory->factoryMethod(ProductType(100));
  if(product == NULL)
    std::cout << "błąd produkcji\n";

  return 0;
}
