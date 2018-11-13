#ifndef DOUBLEGYREVECTORFIELD_H
#define DOUBLEGYREVECTORFIELD_H


#include <VectorField/VectorFieldInterface.h>

class DoubleGyreVectorField : public VectorField
{

public:
    DoubleGyreVectorField();
    DoubleGyreVectorField(float A, float ww, float ee);
    void uSpeed(const float x, const float y, const float t, float *u);
    void vSpeed(const float x, const float y, const float t, float *v);
    void getSpeed(const float x, const float y, const float t, float *u, float *v);
    void getJacobian(const float x, const float y, const float t, MyMatrix2x2& jac);
    void getAttribute(const float x, const float y, const float t,float* value);
private:

private:
    float A;
    float ww;
    float ee;

    float fxt(float x, float t);

    /** needs to convert to numerical way*/
    float dfdx(float x, float t);
    float at(float t);

    float bt(float t);
};

#endif // DOUBLEGYREVECTORFIELD_H
