//prototype

#include <iostream>

class IPrototype
{
  public:
    virtual IPrototype * Klonuj() const = 0;
    virtual ~IPrototype() { }
    virtual int getLiczba() const = 0;
    virtual void setLiczba(int liczba) = 0;
};

class CMyPrototype1 : public IPrototype
{
    int iLiczba;
  public:

    CMyPrototype1(int iLiczba) : iLiczba(iLiczba){ }
    CMyPrototype1(const CMyPrototype1 & kopia) : iLiczba(kopia.iLiczba){ }
    virtual IPrototype * Klonuj() const{ return new CMyPrototype1(* this); } //INFO: Przykładowa implementacja klonowania
    virtual int getLiczba() const { return iLiczba; }
    virtual void setLiczba(int liczba) { iLiczba = liczba; }
};

class CMyPrototype2 : public IPrototype //INFO: konkretny prototyp
{
  virtual IPrototype * Klonuj() const{ return NULL; } //INFO: klonowanie obiektu zabronione
};



int main()
{
  IPrototype *p1 = new CMyPrototype1(33);
  IPrototype *p2 = p1->Klonuj();
  p1->setLiczba(44);

  std::cout << p1 << " " << p1->getLiczba() << std::endl;
  std::cout << p2 << " " << p2->getLiczba() << std::endl;

  return 0;
}
