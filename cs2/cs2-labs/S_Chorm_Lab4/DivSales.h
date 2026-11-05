#ifndef DIVSALES_H_INCLUDED
#define DIVSALES_H_INCLUDED

using namespace std;

class DivSales { // Declaration of the DivSales class for the *.h file
    private:
        static double corpSales;
        double divSales;

    public:
        DivSales() // Constructor
        { divSales = 0; }

        double qtrs[4];

        void setDivSales(double s)
        { divSales = divSales + s; }

        void setCorpSales(double s)
        { corpSales = corpSales + s; }

        double getDivSales() const
        { return divSales; }

        double getCorpSales() const
        { return corpSales; }
};

double DivSales::corpSales; // Static member variable definition

#endif // DIVSALES_H_INCLUDED
