#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHAPE_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHAPE_H
#include "shared_pointer.h"
#include "person.h"

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    virtual double getArea() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : m_w(w), m_h(h) {}
    virtual ~Rectangle() {}
    virtual double getArea() const { return m_w * m_h; }
private:
    double m_w, m_h;
};

Rectangle* rectPt( new Rectangle(22.2, 11.1) );
Shape* shapePt(rectPt); // Compiles and works well

shared_ptr<Rectangle> rectSPt( new Rectangle(22.2, 11.1) );
shared_ptr<Shape> shapeSPt(rectSPt); // Will not compile, but should

shared_ptr<Person> personSpt( new Person("Kyle") );
//shared_ptr<Shape> shapeSPt(personSpt); // Should never compile


#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHAPE_H
