// Singleton w C++11
// g++ -std=gnu++11 210102.cpp -o 210102

#include<iostream>

class Singleton
{
  static int x;
  Singleton(){};

  public:
    Singleton(Singleton const&)=delete;
    void operator=(Singleton const&)=delete;

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
