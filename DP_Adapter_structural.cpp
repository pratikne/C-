//https://sourcemaking.com/design_patterns/adapter/cpp/1
/**
 * LegacyRectangle's interface is not compatible with the system that would like to reuse it. 
 * An abstract base class is created that specifies the desired interface. 
 * An "adapter" class is defined that publicly inherits the interface of the abstract class
 * , and privately inherits the implementation of the legacy component. This adapter class "maps" 
 * or "impedance matches" the new interface to the old implementation.
 * 
 * Below, a legacy Rectangle component's display() method expects to receive "x, y, w, h" parameters. 
 * But the client wants to pass "upper left x and y" and "lower right x and y". This 
 * incongruity can be reconciled by adding an additional level of indirection – i.e. 
 * an Adapter object.
 
Convert the interface of a class into another interface clients expect. Adapter lets 
classes work together that couldn't otherwise because of incompatible interfaces.
Wrap an existing class with a new interface.
Impedance match an old component to a new system
 */

#include <iostream>
using namespace std;

typedef int Coordinate;
typedef int Dimension;

// Desired interface
class Rectangle
{
  public:
    virtual void draw() = 0;
};

// Legacy component
class LegacyRectangle
{
  public:
    LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        cout << "LegacyRectangle:  create.  (" << x1_ << "," << y1_ << ") => ("
          << x2_ << "," << y2_ << ")" << endl;
    }
    void oldDraw()
    {
        cout << "LegacyRectangle:  oldDraw.  (" << x1_ << "," << y1_ << 
          ") => (" << x2_ << "," << y2_ << ")" << endl;
    }
  private:
    Coordinate x1_;
    Coordinate y1_;
    Coordinate x2_;
    Coordinate y2_;
};

// Adapter wrapper
class RectangleAdapter: public Rectangle, private LegacyRectangle
{
  public:
    RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h):
      LegacyRectangle(x, y, x + w, y + h)
    {
        cout << "RectangleAdapter: create.  (" << x << "," << y << 
          "), width = " << w << ", height = " << h << endl;
    }
    virtual void draw()
    {
        cout << "RectangleAdapter: draw." << endl;
        oldDraw();
    }
};

int main()
{
  Rectangle *r = new RectangleAdapter(120, 200, 60, 40);
  r->draw();
}