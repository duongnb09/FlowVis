#include "DoubleGyreVectorField.h"

DoubleGyreVectorField::DoubleGyreVectorField()
{

}


DoubleGyreVectorField::DoubleGyreVectorField(float A, float ww, float ee)
{
    this->A = A;
    this->ww = ww;
    this->ee = ee;
    xLowBoundary = 0.0;
    xHighBoundary = 2;
    yLowBoundary = 0;
    yHighBoundary = 1;
    xSampleNumb = 64; //256
    ySampleNumb = 32; //128
    LIC_width = 256;
    LIC_height = 128;
    timeWindow = 10;
    delta_t = 0.1;

}

void DoubleGyreVectorField::uSpeed(const float x, const float y, const float t, float *u)
{
    *u = -PI*A*sin(PI*fxt(x, t))*cos(PI*y);
    if(*u<1e-8&&*u>-1e-8)
        *u=0;
}



void DoubleGyreVectorField::vSpeed(const float x, const float y, const float t, float *v)
{
    *v = PI*A*cos(PI*fxt(x, t))*sin(PI*y)*dfdx(x, t);
    if(*v<1e-8&&*v>-1e-8)
        *v=0;
}

void DoubleGyreVectorField::getSpeed(const float x, const float y, const float t, float *u, float *v)
{
    uSpeed(x, y, t, u);
    vSpeed(x, y, t, v);
}

void DoubleGyreVectorField::getJacobian(const float x, const float y, const float t, MyMatrix2x2& jac)
{
    float a_t = ee*sin(ww*t);
    float b_t = 1.0 - 2.0*ee*sin(ww*t);
    float f_x = a_t*x*x + b_t*x;
    float d_f_x = 2.0*a_t*x + b_t;
    float dd_f_x = 2.0*a_t;
    float vx = -PI*A*sin(PI*f_x)*cos(PI*y);
    float vy = PI*A*cos(PI*f_x)*sin(PI*y)*d_f_x;
    jac.entry[0][0] = -PI*A*PI*cos(PI*f_x)*d_f_x*cos(PI*y); //d(vx)/dx
    jac.entry[0][1] = PI*A*sin(PI*f_x)*sin(PI*y)*PI; //d(vx)/dy
    jac.entry[1][0] = (PI*A*sin(PI*y))*(-PI*sin(PI*f_x)*d_f_x*d_f_x + cos(PI*f_x)*dd_f_x);
    jac.entry[1][1] = PI*A*cos(PI*f_x)*cos(PI*y)*PI*d_f_x;
}

void DoubleGyreVectorField::getAttribute(const float x, const float y, const float t, float *value)
{

}

float DoubleGyreVectorField::fxt(float x, float t)
{
    return at(t)*x*x + bt(t)*x;
}

/** needs to convert to numerical way*/
float DoubleGyreVectorField::dfdx(float x, float t)
{
    return 2*x*at(t) + bt(t);
}

float DoubleGyreVectorField::at(float t)
{
    return ee*sin(ww*t);
}

float DoubleGyreVectorField::bt(float t)
{
    return (1-2*ee*sin(ww*t));
}
