#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <iostream>

using namespace std;

class Circle
{
private:
    double radius;
    const double PI = 3.14159;

public:
    class NegativeRadius
    {
    private:
        double value;

    public:
        NegativeRadius(double val)
        { value = val; }

        double getValue() const
        { return value; }
    };

    Circle()
    { radius = 0.0; }

    Circle (double r)
    { setRadius(r); }

    void setRadius(double r)
    {
        if (r < 0) {
            throw NegativeRadius(r);
        }
        radius = r;
    }

    double getRadius() const
    { return radius; }

    double getArea() const
    { return PI * radius * radius; }

    double getDiameter() const
    { return radius * 2; }

    double getCircumference() const
    { return 2 * PI * radius; }
};

#endif // CIRCLE_H_INCLUDED
