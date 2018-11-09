#ifndef DOUBLEGYREVECTORFIELD_H
#define DOUBLEGYREVECTORFIELD_H


#include <VectorField/VectorFieldInterface.h>

class DoubleGyreVectorField : public VectorField
{

public:
    DoubleGyreVectorField();
    DoubleGyreVectorField(double A, double ww, double ee);
    void uSpeed(const double x, const double y, const double t, double *u);
    void vSpeed(const double x, const double y, const double t, double *v);
    void getJacobian(const double x, const double y, const double t, MyMatrix2x2& jac);
    void getAttribute(const double x, const double y, const double t,double* value);

private:
    double A;
    double ww;
    double ee;

    double fxt(double x, double t);

    /** needs to convert to numerical way*/
    double dfdx(double x, double t);
    double at(double t);

    double bt(double t);
};

#endif // DOUBLEGYREVECTORFIELD_H
