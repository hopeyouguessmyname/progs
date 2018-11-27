//builder
//Aplikacja pod nazwą Atrakcyjne pakiety

#include <iostream>
#include <string>

class Package
{
    std::string name;
    float price;

  public:
    void setName(std::string x) { name = x; }
    void setPrice(float x) { price = x; }

    void printPackage()
    {
      std::cout << name << std::endl;
      std::cout << "Za jedyne " << price << " zł." << std::endl;
    }
};

class Builder
{
  protected:
    Package *package;

  public:
    void createPackage() { package = new Package(); }
    Package *getPackage() { return package; }

    virtual void buildName() = 0;
    virtual void buildPrice() = 0;
};

class Package1Builder : public Builder
{
  public:
    Package1Builder() : Builder() {}

    void buildName() { package->setName("Nielimitowane połączenia do Play"); }
    void buildPrice() { package->setPrice(10.00); }
};

class Package2Builder : public Builder
{
  public:
    Package2Builder() : Builder() {}

    void buildName() { package->setName("30 minut do wszystkich"); }
    void buildPrice() { package->setPrice(6.00); }
};

class Package3Builder : public Builder
{
  public:
    Package3Builder() : Builder() {}

    void buildName() { package->setName("100 minut do Play i na stacjonarne"); }
    void buildPrice() { package->setPrice(5.00); }
};


class Consultant
{
    Builder *builder;
  
  public:
    void createBuilder(Builder *x) { builder = x; }
    Builder *getBuilder() { return builder; }

    void createPackage()
    {
      builder->createPackage();

      builder->buildName();
      builder->buildPrice();
    }
};

int main()
{
  Consultant *consultant = new Consultant();
  Builder *builder1 = new Package1Builder();
  Builder *builder2 = new Package2Builder();
  Builder *builder3 = new Package3Builder();

std::cout << "Atrakcyjne pakiety:\n-----\n";

  consultant->createBuilder(builder1);
  consultant->createPackage();
  Package *package1 = builder1->getPackage();
  package1->printPackage();

std::cout << "\n-----\n";

  consultant->createBuilder(builder2);
  consultant->createPackage();
  Package *package2 = builder2->getPackage();
  package2->printPackage();

std::cout << "\n-----\n";

  consultant->createBuilder(builder3);
  consultant->createPackage();
  Package *package3 = builder3->getPackage();
  package3->printPackage();


  return 0;
}
