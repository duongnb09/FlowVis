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
#include <Utilities/MyVector.h>

class VectorField
{
    /* Note: All virtual functions in this interface are not pure virual functions which means the derived classes do not need to implement all of them */
public:
    // Get component u at a particular input spatial and temporal location
    virtual void uSpeed(const double x, const double y, const double t, double *u){};

    // Get component v at a particular input spatial and temporal location
    virtual void vSpeed(const double x, const double y, const double t, double *v){};

    // Get jacobian matrix at a particular input spatial and temporal location
    virtual void getJacobian(const double x, const double y, const double t, MyMatrix2x2& jac){};

    // Get a derived attribute value at a particular input spatial and temporal location
    virtual void getAttribute(const double x, const double y, const double t,double* value){};
private:

    /* Domain extents */
    double xLowBoundary = 0;
    double xHighBoundary = 0;
    double yLowBoundary = 0;
    double zLowBoundary = 0;
};

#endif // VECTORFIELDINTERFACE_H
