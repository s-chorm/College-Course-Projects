#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

class Circle {

    private:
        double radius;
        double pi;

    public:
        Circle() {
            radius = 0.0;
            pi = 3.14159;
        }

        Circle(double r) {
            if (r >= 0.0) {
                radius = r;
            }
            else {
                radius = 0.0;
            }
            pi = 3.14159;
        }

        void setRadius(double r) {
            if (r >= 0.0) {
                radius = r;
            }
        }

        double getRadius() const {
            return radius;
        }

        double getArea() const {
            return pi * (radius * radius);
        }

        double getDiameter() const {
            return radius * 2;
        }

        double getCircumference() const {
            return 2 * pi * radius;
        }
};

#endif // CIRCLE_H_INCLUDED
