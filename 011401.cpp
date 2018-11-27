#include <iostream>

class Foo
{
    static int i;

  public:
    static void method();
    void method2() const;
    void print() const;
};

int Foo::i=0;

void Foo::method()
{
  Foo::i++;
}

void Foo::method2() const
{
  A::i++;
}

void Foo::print() const
{
  std::cout << Foo::i << std::endl;
}


int main()
{
  Foo *obiekt1 = new Foo();
  obiekt1->print();
  obiekt1->method2();
  obiekt1->print();

  return 0;
}

