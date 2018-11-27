//builder
//Aplikacja pod nazwą Atrakcyjne pakiety

#include <iostream>
#include <string>

#define ABONAMENT 'a'
#define KARTA 'k'

class Package
{
    std::string name;
    char kindOfContract;
    std::string activationCode;
    std::string SMSContent;
    std::string SMSNumber;
    float price;
    std::string deactivationCode;

  public:
    void setName(std::string x) { name = x; }
    void setKindOfContract(char x) { kindOfContract = x; }
    void setActivationCode(std::string x) { activationCode = x; }
    void setSMSContent(std::string x) { SMSContent = x; }
    void setSMSNumber(std::string x) { SMSNumber = x; }
    void setPrice(float x) { price = x; }
    void setDeactivationCode(std::string x) { deactivationCode = x; }

    std::string getName() { return name; }
    char getKindOfContract() { return kindOfContract; }
    std::string getActivationCode() { return activationCode; }
    std::string getSMSContent() { return SMSContent; }
    std::string setSMSNumber() { return SMSNumber; }
    float getPrice() { return price; }
    std::string getDeactivationCode() { return deactivationCode; }

    void printPackage()
    {
      std::cout << name;
      if(kindOfContract == KARTA) std::cout << " na kartę." << std::endl;
      else if(kindOfContract == ABONAMENT) std::cout << " na abonament." << std::endl;
      std::cout << "Za jedyne " << price << " zł." << std::endl;
      std::cout << "Kod aktywacyjny: " << activationCode << std::endl;
      std::cout << "Kod dezaktywacyjny: " << deactivationCode << std::endl;
      std::cout << "Pakiet można aktywować wysyłając SMS o treści: " << SMSContent 
      << " pod numer " << SMSNumber << std::endl;
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
    virtual void buildKindOfContract() = 0;
    virtual void buildActivationCode() = 0;
    virtual void buildSMSContent() = 0;
    virtual void buildSMSNumber() = 0;
    virtual void buildPrice() = 0;
    virtual void buildDeactivationCode() = 0;
};

class Package1Builder : public Builder
{
  public:
    Package1Builder() : Builder() {}

    void buildName() { package->setName("Nielimitowane połączenia do Play"); }
    void buildKindOfContract() { package->setKindOfContract(KARTA); }
    void buildActivationCode() { package->setActivationCode("*111*575*1#"); }
    void buildSMSContent() { package->setSMSContent("START.575"); }
    void buildSMSNumber() { package->setSMSNumber("111"); }
    void buildPrice() { package->setPrice(10.00); }
    void buildDeactivationCode() { package->setDeactivationCode("*111*575*2#"); }
};

class Package2Builder : public Builder
{
  public:
    Package2Builder() : Builder() {}

    void buildName() { package->setName("30 minut do wszystkich"); }
    void buildKindOfContract() { package->setKindOfContract(KARTA); }
    void buildActivationCode() { package->setActivationCode("*111*577*1#"); }
    void buildSMSContent() { package->setSMSContent("START.577"); }
    void buildSMSNumber() { package->setSMSNumber("111"); }
    void buildPrice() { package->setPrice(6.00); }
    void buildDeactivationCode() { package->setDeactivationCode("*111*577*2#"); }
};

class Package3Builder : public Builder
{
  public:
    Package3Builder() : Builder() {}

    void buildName() { package->setName("100 minut do Play i na stacjonarne"); }
    void buildKindOfContract() { package->setKindOfContract(KARTA); }
    void buildActivationCode() { package->setActivationCode("*111*576*1#"); }
    void buildSMSContent() { package->setSMSContent("START.576"); }
    void buildSMSNumber() { package->setSMSNumber("111"); }
    void buildPrice() { package->setPrice(5.00); }
    void buildDeactivationCode() { package->setDeactivationCode("*111*576*2#"); }
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
      builder->buildKindOfContract();
      builder->buildActivationCode();
      builder->buildSMSContent();
      builder->buildSMSNumber();
      builder->buildPrice();
      builder->buildDeactivationCode();
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
