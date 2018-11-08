/*=========================================================================
    Program:   Flow Visualization
    Module:    VectorFieldInterface.h

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See LICENSE for details

=========================================================================*/

#ifndef VECTORFIELDINTERFACE_H
#define VECTORFIELDINTERFACE_H

#include <Utilities/MyMatrix.h>

class VectorField
{
    public:
        virtual void uSpeed(const double x, const double y, const double t, double *u){};
        virtual void vSpeed(const double x, const double y, const double t, double *v){};
        virtual void getJacobian(const double x, const double y, const double t, MyMatrix2x2& jac) {};
        virtual void getAttribute(const double x, const double y, const double t,double* value){};
private:
    double xLowBoundary = 0;
    double xHighBoundary = 0;
    double yLowBoundary = 0;
    double zLowBoundary = 0;
};

#endif // VECTORFIELDINTERFACE_H
