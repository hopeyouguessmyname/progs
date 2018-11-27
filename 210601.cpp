//decorator

#include <iostream>
#include <string>


/* Standardowy nieudekorowany samochod */
class Samochod
{
  protected:
    std::string samochod;
    double wartosc;
  public:
    Samochod()
    {
      std::cout<<"Samochod()";
      samochod = "Samochod podstawowy";
      wartosc=0;
    }

    virtual ~Samochod(){};
    virtual std::string about() { std::cout<<"Samochod.about()";return samochod; }
    virtual double cena() { return wartosc; }
};

/* abstrakcyjny dekorator */
class Dekorator : public Samochod
{
  public:
    virtual std::string about() { std::cout<<"Dekorator.about()";return "hmm"; }
};

/* teraz mamy 2 przykladowe marki samochodow */
class Mercedes : public Samochod
{
  public:
    Mercedes():Samochod()
    {
      std::cout<<"Mercedes()";
      samochod = "Mercedes";
      wartosc=500000;
    }
};

class Fiat : public Samochod
{
  public:
    Fiat():Samochod()
    {
      std::cout<<"Fiat()";
      samochod = "Fiat";
      wartosc=100000;
    }
};

/* czas na same dodatki */
class Klimatyzacja : public Dekorator
{
    Samochod *car;
  public:

    Klimatyzacja(Samochod *samochod):Dekorator() { std::cout<<"Klimatyzacja()";car = samochod; }
    std::string about() { std::cout<<"Klimatyzacja.about()";return car->about() + " + klimatyzacja"; }
    double cena() { return car->cena()+1111; }
};

class OponyZimowe : public Dekorator
{
    Samochod *car;
  public:

    OponyZimowe(Samochod *samochod):Dekorator() { std::cout<<"OponyZimowe";car = samochod; }
    std::string about() { std::cout<<"OponyZimowe.about()";return car->about() + " + opony zimowe"; }
    /* niech ceny beda takie same */

    double cena() { return car->cena() + 31234; }
};



int main()
{
  Samochod *s1 = new Mercedes();
  Samochod *s2 = new Fiat();
  std::cout<<"\nBez wyposazenia"<<std::endl;
  std::cout<<s1->about()<<" "<<s1->cena()<<std::endl;
  std::cout<<s2->about()<<" "<<s2->cena()<<std::endl;
  
  //dodajemy po klimie
  s1 = new Klimatyzacja(s1);
  s2 = new Klimatyzacja(s2);
  std::cout<<"\nZ Klima"<<std::endl;
  std::cout<<s1->about()<<" "<<s1->cena()<<std::endl;
  std::cout<<s2->about()<<" "<<s2->cena()<<std::endl;

  // i opony
  s1 = new OponyZimowe(s1);
  s2 = new OponyZimowe(s2);
  std::cout<<"\nZ oponami"<<std::endl;
  std::cout<<s1->about()<<" "<<s1->cena()<<std::endl;
  std::cout<<s2->about()<<" "<<s2->cena()<<std::endl;

  s1 = new OponyZimowe(s1);
  s2 = new OponyZimowe(s2);
  std::cout<<"\nZ oponami"<<std::endl;
  std::cout<<s1->about()<<" "<<s1->cena()<<std::endl;
  
  //od razu tworzymy wyposazony samochod
  std::cout<<"\nPelne wyposazenie"<<std::endl;
  Samochod *s3 = new OponyZimowe( new Klimatyzacja( new Mercedes()));
  Samochod *s3 = new OponyZimowe( new Klimatyzacja( new Fiat()));
  std::cout<<s3->about()<<" "<<s3->cena()<<std::endl;

  return 0;
}
