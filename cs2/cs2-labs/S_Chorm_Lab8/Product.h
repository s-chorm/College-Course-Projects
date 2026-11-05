#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

using namespace std;

class Product
{
private:
    string name;
    int units;
    double price;
    int reOrderPoint;

public: // constructor
    Product(string n, double p, int u)
    {
        name = n;
        price = p;
        units = u;
        reOrderPoint = 3;
    }

    void setName(string n)
    { name = n; }

    void setPrice(double p)
    { price = p; }

    void setUnits(int u)
    { units = u; }

    void setReorderPoint(int r)
    { reOrderPoint = r; }

    string getName() const
    { return name; }

    double getPrice() const
    { return price; }

    int getUnits() const
    { return units; }

    int getReorderPoint() const
    { return reOrderPoint; }
};

#endif // PRODUCT_H_INCLUDED
