#include "DoubleGyreVectorField.h"

DoubleGyreVectorField::DoubleGyreVectorField()
{

}


DoubleGyreVectorField::DoubleGyreVectorField(double A, double ww, double ee)
{
    this->A = A;
    this->ww = ww;
    this->ee = ee;
}

void DoubleGyreVectorField::uSpeed(const double x, const double y, const double t, double *u)
{
    *u = -PI*A*sin(PI*fxt(x, t))*cos(PI*y);
    if(*u<1e-8&&*u>-1e-8)
        *u=0;
}



void DoubleGyreVectorField::vSpeed(const double x, const double y, const double t, double *v)
{
    *v = PI*A*cos(PI*fxt(x, t))*sin(PI*y)*dfdx(x, t);
    if(*v<1e-8&&*v>-1e-8)
        *v=0;
}

void DoubleGyreVectorField::getJacobian(const double x, const double y, const double t, MyMatrix2x2& jac)
{
    double a_t = ee*sin(ww*t);
    double b_t = 1.0 - 2.0*ee*sin(ww*t);
    double f_x = a_t*x*x + b_t*x;
    double d_f_x = 2.0*a_t*x + b_t;
    double dd_f_x = 2.0*a_t;
    double vx = -PI*A*sin(PI*f_x)*cos(PI*y);
    double vy = PI*A*cos(PI*f_x)*sin(PI*y)*d_f_x;
    jac.entry[0][0] = -PI*A*PI*cos(PI*f_x)*d_f_x*cos(PI*y); //d(vx)/dx
    jac.entry[0][1] = PI*A*sin(PI*f_x)*sin(PI*y)*PI; //d(vx)/dy
    jac.entry[1][0] = (PI*A*sin(PI*y))*(-PI*sin(PI*f_x)*d_f_x*d_f_x + cos(PI*f_x)*dd_f_x);
    jac.entry[1][1] = PI*A*cos(PI*f_x)*cos(PI*y)*PI*d_f_x;
}

void DoubleGyreVectorField::getAttribute(const double x, const double y, const double t, double *value)
{

}

double DoubleGyreVectorField::fxt(double x, double t)
{
    return at(t)*x*x + bt(t)*x;
}

/** needs to convert to numerical way*/
double DoubleGyreVectorField::dfdx(double x, double t)
{
    return 2*x*at(t) + bt(t);
}

double DoubleGyreVectorField::at(double t)
{
    return ee*sin(ww*t);
}

double DoubleGyreVectorField::bt(double t)
{
    return (1-2*ee*sin(ww*t));
}
