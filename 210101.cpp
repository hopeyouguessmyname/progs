// Singleton w C++03
// g++ 210101.cpp -o 210101

#include<iostream>

class Singleton
{
  static int x;

  Singleton(){};
  Singleton(Singleton const&);
  void operator=(Singleton const&);

  public:
    static Singleton& getInstance()
    {
      static Singleton instance;
      return instance;
    }

    int getX(){ return x; }
    void setX(int px){ x = px; }
};

int Singleton::x = 0;

int main()
{
  std::cout << Singleton::getInstance().getX() << std::endl;
  Singleton::getInstance().setX(23);
  std::cout << Singleton::getInstance().getX() << std::endl;
  Singleton::getInstance().setX(33);
  std::cout << Singleton::getInstance().getX() << std::endl;

  return 0;
}
