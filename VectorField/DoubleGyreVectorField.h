#ifndef DOUBLEGYREVECTORFIELD_H
#define DOUBLEGYREVECTORFIELD_H


#include <VectorFieldInterface.h>

class DoubleGyreVectorField : public VectorFieldInterface
{
public:
    DoubleGyreVectorField();
    DoubleGyreVectorField(double A, double ww, double ee);
private:
    double A;
    double ww;
    double ee;

    double fxt(double x, double t)
    {
        return at(t)*x*x + bt(t)*x;
    }

    /** needs to convert to numerical way*/
    double dfdx(double x, double t)
    {
        return 2*x*at(t) + bt(t);
    }

    double at(double t)
    {
        return ee*sin(ww*t);
    }

    double bt(double t)
    {
        return (1-2*ee*sin(ww*t));
    }
};

#endif // DOUBLEGYREVECTORFIELD_H
