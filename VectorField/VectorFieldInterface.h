/*=========================================================================
    Program:   Flow Visualization
    Module:    VectorFieldInterface.h

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See LICENSE for details

=========================================================================*/

#ifndef VECTORFIELDINTERFACE_H
#define VECTORFIELDINTERFACE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <Utilities/MyMatrix.h>
#include <Utilities/MyVector.h>
#include <Utilities/Utilities.h>

class VectorField
{
    /* Note: All virtual functions in this interface are pure virual functions which means the derived classes need to implement all of them */
public:
    // Get component u at a particular input spatial and temporal location
    virtual void uSpeed(const float x, const float y, const float t, float *u)=0;

    // Get component v at a particular input spatial and temporal location
    virtual void vSpeed(const float x, const float y, const float t, float *v)=0;

    // Get both u and v components at a particular input spatial and temporal location
    virtual void getSpeed(const float x,const float y, const float t, float *u, float *v)=0;


    // Get jacobian matrix at a particular input spatial and temporal location
    virtual void getJacobian(const float x, const float y, const float t, MyMatrix2x2& jac)=0;

    // Get a derived attribute value at a particular input spatial and temporal location
    virtual void getAttribute(const float x, const float y, const float t,float* value)=0;

    void getDomainExtents(float &xLow,float &xHigh,float &yLow,float &yHigh){
        xLow = xLowBoundary;
        xHigh = xHighBoundary;
        yLow = yLowBoundary;
        yHigh = yHighBoundary;
    }


    void getLICSize(int &width,int &height){
        width = LIC_width;
        height = LIC_height;
    }

    void getTimeWindow(float &tWindow){
        tWindow = timeWindow;
    }

    void getDt(float &dt)
    {
        dt = delta_t;
        printf("delta %f \n",delta_t);
    }

    void getSampleNumb(int& xNum,int& yNum)
    {
        xNum = xSampleNumb;
        yNum = ySampleNumb;
    }

protected:
    /* Domain extents */
    float xLowBoundary = 0;
    float xHighBoundary = 0;
    float yLowBoundary = 0;
    float yHighBoundary = 0;

    /*LIC texture image size*/
    int LIC_width,LIC_height;

    /* The number of sample points for generating LIc texture */
    int xSampleNumb,ySampleNumb;

    /* Time window and and a single time step */
    float timeWindow;
    float delta_t;



};

#endif // VECTORFIELDINTERFACE_H
