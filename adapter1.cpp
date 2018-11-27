#include <iostream>


//1.
class iPoint
{
  public:
    virtual void setX(int)=0;
    virtual void setY(int)=0;
    virtual int getX()const=0;
    virtual int getY()const=0;
    virtual void printPoint()const=0;
};

class Point : public iPoint 
{
    int x;
    int y;

  public:
    Point(int px, int py) : x(px), y(py){  }
    void setX(int px){ x = px; }
    void setY(int py){ y = py; }
    int getX()const{ return x; }
    int getY()const{ return y; }
    void printPoint()const{ std::cout << "Point=(" << x << "," << y << ")" << std::endl; }
};


//2.
class iPoint3d
{
  public:
    virtual void setX(int)=0;
    virtual void setY(int)=0;
    virtual void setZ(int)=0;
    virtual int getX()const=0;
    virtual int getY()const=0;
    virtual int getZ()const=0;
    virtual void printPoint()const=0;
};

class Point3d : public iPoint3d, private Point
{
    int z;

  public:
    Point3d(const iPoint* point) : Point(point->getX(), point->getY()), z(0){  }
    void setX(int px){ this->setX(px); }
    void setY(int py){ this->setY(py); }
    void setZ(int pz){ z = pz; }
    int getX()const{ return this->getX(); }
    int getY()const{ return this->getY(); }
    int getZ()const{ return z; }
    void printPoint()const{ std::cout << "Point3d=(" << Point::getX() << "," << Point::getY() << "," << z << ")" << std::endl; }
};


int main()
{
  //1.
  //tablica obiektów z punktami tworzącymi kwadrat
  int squarePoints=4;

  iPoint **square = new iPoint *[squarePoints];
  square[0] = new Point(0,0);
  square[1] = new Point(0,5);
  square[2] = new Point(5,5);
  square[3] = new Point(5,0);

  std::cout << "Square:\n";
  for (int i = 0; i < squarePoints; i++)
    square[i]->printPoint();

  //2.
  //dodanie punktów będących ich kopią i przesuniętych w płaszczyźnie z dla utworzenia prostopadłościanu.
  int move = 5;
  int cubePoints=2*squarePoints;

  std::cout << "\nCube:\n";
  iPoint3d **cube = new iPoint3d *[cubePoints];
  for (int i = 0, j = 0; i < cubePoints; i++)
  {
    if(i % 2)
    {
      cube[i] = cube[i-1];
      cube[i]->setZ(cube[i]->getZ()+move);
    }
    else
    {
      cube[i] = new Point3d(square[j]);
      j++;
    }
    cube[i]->printPoint();
  }
  
  return 0;
}


