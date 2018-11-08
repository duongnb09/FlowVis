/*=========================================================================
    Program:   Flow Visualization
    Module:    MyMatrix.h

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See LICENSE for details

=========================================================================*/
#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <math.h>
#include <stdlib.h>
#include <MyVector.h>


class MyMatrix2x2;
class MyMatrix3x3;

/*-----------------------------------------*/
/* ------ Define MyMatrix2x2 class ------- */
/*-----------------------------------------*/
class MyMatrix2x2 {
public:
    inline MyMatrix2x2();
    inline MyMatrix2x2(double x);
    inline MyMatrix2x2(const MyMatrix2x2 &that);

    inline MyMatrix2x2(double M00, double M01,
                       double M10, double M11);
    inline MyMatrix2x2(double M[2][2]);

    inline MyMatrix2x2 &set      (const double d);
    inline MyMatrix2x2 &operator=(const double d);

    inline MyMatrix2x2 &set      (const MyMatrix2x2 &that);
    inline MyMatrix2x2 &operator=(const MyMatrix2x2 &that);

    inline MyMatrix2x2 &set			 (double M[2][2]);
    inline MyMatrix2x2 &operator=(double M[2][2]);

    inline int operator!=(const MyMatrix2x2 &that)const;
    inline int operator==(const MyMatrix2x2 &that)const;

    inline int operator==(double d) const;
    inline int operator!=(double d) const;

    inline MyMatrix2x2 &operator+=(double d);
    inline MyMatrix2x2 &operator-=(double d);
    inline MyMatrix2x2 &operator*=(double d);

    // component-wise operations.
    inline MyMatrix2x2 &operator+=(const MyMatrix2x2 &that);
    inline MyMatrix2x2 &operator-=(const MyMatrix2x2 &that);
    inline MyMatrix2x2 &operator*=(const MyMatrix2x2 &that);

    // Left : this = that x this
    // Right: this = this x that
    MyMatrix2x2 &leftMultiply (const MyMatrix2x2 &that);
    MyMatrix2x2 &rightMultiply(const MyMatrix2x2 &that);

    inline MyMatrix2x2 &setIdentity     ();

public:
    double entry[2][2];

};

inline MyMatrix2x2 operator+(const MyMatrix2x2 &a, double b);
inline MyMatrix2x2 operator-(const MyMatrix2x2 &a, double b);
inline MyMatrix2x2 operator*(const MyMatrix2x2 &a, double b);

inline MyMatrix2x2 operator+(const MyMatrix2x2 &a, const MyMatrix2x2 &b);
inline MyMatrix2x2 operator-(const MyMatrix2x2 &a, const MyMatrix2x2 &b);
inline MyMatrix2x2 operator*(const MyMatrix2x2 &a, const MyMatrix2x2 &b);

inline MyMatrix2x2 multiply(const MyMatrix2x2 &a, const MyMatrix2x2 &b);
inline MyVector2d   operator*(const MyMatrix2x2 &a, const MyVector2d   &b);
inline MyVector2d   operator*(const MyVector2d   &a, const MyMatrix2x2 &b);

inline double determinant(const MyMatrix2x2 &a);

inline MyMatrix2x2 transpose(const MyMatrix2x2 &a);
inline MyMatrix2x2   inverse(const MyMatrix2x2 &a);

inline MyMatrix2x2::MyMatrix2x2() {
    entry[0][0] = 1;
    entry[0][1] = 0;
    entry[1][0] = 0;
    entry[1][1] = 1;
}

inline MyMatrix2x2::MyMatrix2x2(double x) {
    entry[0][0] = x;
    entry[0][1] = x;
    entry[1][0] = x;
    entry[1][1] = x;
}

inline MyMatrix2x2::MyMatrix2x2(double M00, double M01,
                                double M10, double M11) {
    entry[0][0] = M00;
    entry[0][1] = M01;
    entry[1][0] = M10;
    entry[1][1] = M11;
};

inline MyMatrix2x2::MyMatrix2x2(const MyMatrix2x2 &that) {
    entry[0][0] = that.entry[0][0];
    entry[0][1] = that.entry[0][1];
    entry[1][0] = that.entry[1][0];
    entry[1][1] = that.entry[1][1];
};

inline MyMatrix2x2 &MyMatrix2x2::set(const double d) {
    return (*this)=d;
}

inline MyMatrix2x2 &MyMatrix2x2::operator=(const double d) {
    entry[0][0] = d;
    entry[0][1] = d;

    entry[1][0] = d;
    entry[1][1] = d;
    return (*this);
};

inline MyMatrix2x2 &MyMatrix2x2::set(const MyMatrix2x2 &that) {
    return (*this)=that;
}

inline MyMatrix2x2 &MyMatrix2x2::operator=(const MyMatrix2x2 &that) {
    entry[0][0] = that.entry[0][0];
    entry[0][1] = that.entry[0][1];

    entry[1][0] = that.entry[1][0];
    entry[1][1] = that.entry[1][1];
    return (*this);
};

inline MyMatrix2x2 &MyMatrix2x2::set(double M[2][2]) {
    return (*this)=M;
}

inline MyMatrix2x2 &MyMatrix2x2::operator=(double M[2][2]) {
    entry[0][0] = M[0][0];
    entry[0][1] = M[0][1];

    entry[1][0] = M[1][0];
    entry[1][1] = M[1][1];
    return (*this);
};

inline int MyMatrix2x2::operator==(double d) const {
    return  ( (entry[0][0] == d) &&
            (entry[0][1] == d) &&
            (entry[1][0] == d) &&
            (entry[1][1] == d) );
}

inline int MyMatrix2x2::operator!=(double d) const {
    return  ( (entry[0][0] != d) ||
            (entry[0][1] != d) ||
            (entry[1][0] != d) ||
            (entry[1][1] != d) );
}

inline int MyMatrix2x2::operator==(const MyMatrix2x2 &that)const {
    return ( (entry[0][0] == that.entry[0][0]) &&
            (entry[0][1] == that.entry[0][1]) &&
            (entry[1][0] == that.entry[1][0]) &&
            (entry[1][1] == that.entry[1][1]) );
}

inline int MyMatrix2x2::operator!=(const MyMatrix2x2 &that)const {
    return ( (entry[0][0] != that.entry[0][0]) ||
            (entry[0][1] != that.entry[0][1]) ||
            (entry[1][0] != that.entry[1][0]) ||
            (entry[1][1] != that.entry[1][1]) );
}

inline MyMatrix2x2 &MyMatrix2x2::operator+=(double d) {
    entry[0][0] += d; entry[1][0] += d;
    entry[0][1] += d; entry[1][1] += d;
    return (*this);
}

inline MyMatrix2x2 &MyMatrix2x2::operator-=(double d) {
    entry[0][0] -= d; entry[1][0] -= d;
    entry[0][1] -= d; entry[1][1] -= d;
    return (*this);
}

inline MyMatrix2x2 &MyMatrix2x2::operator*=(double d) {
    entry[0][0] *= d; entry[1][0] *= d;
    entry[0][1] *= d; entry[1][1] *= d;
    return (*this);
}

inline MyMatrix2x2 &MyMatrix2x2::operator+=(const MyMatrix2x2 &that) {
    entry[0][0] += that.entry[0][0]; entry[1][0] += that.entry[1][0];
    entry[0][1] += that.entry[0][1]; entry[1][1] += that.entry[1][1];
    return (*this);
}

inline MyMatrix2x2 &MyMatrix2x2::operator-=(const MyMatrix2x2 &that) {
    entry[0][0] -= that.entry[0][0]; entry[1][0] -= that.entry[1][0];
    entry[0][1] -= that.entry[0][1]; entry[1][1] -= that.entry[1][1];
    return (*this);
}

inline MyMatrix2x2 &MyMatrix2x2::operator*=(const MyMatrix2x2 &that) {

    /* Lei's original code */
    //entry[0][0] *= that.entry[0][0]; entry[1][0] *= that.entry[1][0];
    //entry[0][1] *= that.entry[0][1]; entry[1][1] *= that.entry[1][1];

    /*  Updated code */
    double item00 = entry[0][0] * that.entry[0][0] + entry[0][1] * that.entry[1][0];
    double item01 = entry[0][0] * that.entry[0][1] + entry[0][1] * that.entry[1][1];

    double item10 = entry[1][0] * that.entry[0][0] + entry[1][1] * that.entry[1][0];
    double item11 = entry[1][0] * that.entry[0][1] + entry[1][1] * that.entry[1][1];
    entry[0][0] = item00;
    entry[0][1] = item01;
    entry[1][0] = item10;
    entry[1][1] = item11;
    return (*this);
}

inline MyMatrix2x2 &MyMatrix2x2::leftMultiply (const MyMatrix2x2 &that){
    MyMatrix2x2 tmp(entry[0][0], entry[0][1], entry[1][0], entry[1][1]);

    entry[0][0] = that.entry[0][0] * tmp.entry[0][0] + that.entry[0][1] * tmp.entry[1][0];
    entry[0][1] = that.entry[0][0] * tmp.entry[0][1] + that.entry[0][1] * tmp.entry[1][1];
    entry[1][0] = that.entry[1][0] * tmp.entry[0][0] + that.entry[1][1] * tmp.entry[1][0];
    entry[1][1] = that.entry[1][0] * tmp.entry[0][1] + that.entry[1][1] * tmp.entry[1][1];
    return (*this);
};

inline MyMatrix2x2 &MyMatrix2x2::rightMultiply(const MyMatrix2x2 &that){
    MyMatrix2x2 tmp(entry[0][0], entry[0][1], entry[1][0], entry[1][1]);

    entry[0][0] = tmp.entry[0][0] * that.entry[0][0] + tmp.entry[0][1] * that.entry[1][0];
    entry[0][1] = tmp.entry[0][0] * that.entry[0][1] + tmp.entry[0][1] * that.entry[1][1];
    entry[1][0] = tmp.entry[1][0] * that.entry[0][0] + tmp.entry[1][1] * that.entry[1][0];
    entry[1][1] = tmp.entry[1][0] * that.entry[0][1] + tmp.entry[1][1] * that.entry[1][1];
    return (*this);
};

inline MyMatrix2x2 &MyMatrix2x2::setIdentity() {
    entry[0][0] = 1; entry[0][1] = 0;
    entry[1][0] = 0; entry[1][1] = 1;
    return (*this);
};

inline MyMatrix2x2 operator+(const MyMatrix2x2 &a,double b) {
    return (MyMatrix2x2(a)+=b);
}

inline MyMatrix2x2 operator-(const MyMatrix2x2 &a,double b) {
    return (MyMatrix2x2(a)-=b);
}

inline MyMatrix2x2 operator*(const MyMatrix2x2 &a,double b) {
    return (MyMatrix2x2(a)*=b);
}

inline MyMatrix2x2 operator+(double a, const MyMatrix2x2 &b) {
    return b+a;
}

inline MyMatrix2x2 operator-(double a, const MyMatrix2x2 &b) {
    return MyMatrix2x2(a-b.entry[0][0],a-b.entry[0][1],
            a-b.entry[1][0],a-b.entry[1][1]);
}

inline MyMatrix2x2 operator*(double a, const MyMatrix2x2 &b) {
    return b*a;
}

inline MyMatrix2x2 operator+(const MyMatrix2x2 &a,const MyMatrix2x2 &b) {
    return (MyMatrix2x2(a)+=b);
}

inline MyMatrix2x2 operator-(const MyMatrix2x2 &a,const MyMatrix2x2 &b) {
    return (MyMatrix2x2(a)-=b);
}

inline MyMatrix2x2 operator*(const MyMatrix2x2 &a,const MyMatrix2x2 &b) {
    return (MyMatrix2x2(a)*=b);
}

inline MyMatrix2x2 multiply(const MyMatrix2x2 &a,const MyMatrix2x2 &b) {
    MyMatrix2x2 tmp(a);
    tmp.rightMultiply(b);
    return tmp;
}

inline MyVector2d operator*(const MyMatrix2x2 &a,const MyVector2d &b) {
    return MyVector2d(b.entry[0]*a.entry[0][0] + b.entry[1]*a.entry[0][1],
            b.entry[0]*a.entry[1][0] + b.entry[1]*a.entry[1][1]);
}

inline MyVector2d operator*(const MyVector2d &a,const MyMatrix2x2 &b) {
    return MyVector2d(a.entry[0]*b.entry[0][0] + a.entry[1]*b.entry[1][0],
            a.entry[0]*b.entry[0][1] + a.entry[1]*b.entry[1][1]);
}

inline double determinant(const MyMatrix2x2 &a) {
    return ( a.entry[0][0] * a.entry[1][1] - a.entry[0][1] * a.entry[1][0] );
}

inline MyMatrix2x2 transpose(const MyMatrix2x2 &a) {
    MyMatrix2x2 tmp(a);

    tmp.entry[0][1] = a.entry[1][0];
    tmp.entry[1][0] = a.entry[0][1];
    return tmp;
}

inline MyMatrix2x2 inverse(const MyMatrix2x2 &a) {
    MyMatrix2x2 tmp;
    double dmt;

    if ((dmt=determinant(a))!= 0.0) {
        tmp.entry[0][0] = a.entry[1][1]/dmt;
        tmp.entry[0][1] = -a.entry[0][1]/dmt;
        tmp.entry[1][0] = -a.entry[1][0]/dmt;
        tmp.entry[1][1] = a.entry[0][0]/dmt;
    }
    return tmp;
}

/*-----------------------------------------*/
/* ------ Define MyMatrix3x3 class ------- */
/*-----------------------------------------*/
class MyMatrix3x3 {
public:
    inline MyMatrix3x3();
    inline MyMatrix3x3(double x);
    inline MyMatrix3x3(const MyMatrix3x3 &that);
    inline MyMatrix3x3(const MyVector3d &v1, const MyVector3d &v2, const MyVector3d &v3);

    inline MyMatrix3x3(double M00, double M01, double M02,
                       double M10, double M11, double M12,
                       double M20, double M21, double M22);
    inline MyMatrix3x3(double M[3][3]);

    inline MyMatrix3x3 &set      (const double d);
    inline MyMatrix3x3 &operator=(const double d);

    inline MyMatrix3x3 &set      (const MyMatrix3x3 &that);
    inline MyMatrix3x3 &operator=(const MyMatrix3x3 &that);

    inline MyMatrix3x3 &set			 (double M[3][3]);
    inline MyMatrix3x3 &operator=(double M[3][3]);

    inline MyMatrix3x3 &set     (const MyVector3d &v1, const MyVector3d &v2, const MyVector3d &v3);
    inline MyMatrix3x3 &set			(double M00, double M01, double M02,
                                     double M10, double M11, double M12,
                                     double M20, double M21, double M22);
    inline int operator!=(const MyMatrix3x3 &that)const;
    inline int operator==(const MyMatrix3x3 &that)const;

    inline int operator==(double d) const;
    inline int operator!=(double d) const;

    inline MyMatrix3x3 &operator+=(double d);
    inline MyMatrix3x3 &operator-=(double d);
    inline MyMatrix3x3 &operator*=(double d);

    // component-wise operations.
    inline MyMatrix3x3 &operator+=(const MyMatrix3x3 &that);
    inline MyMatrix3x3 &operator-=(const MyMatrix3x3 &that);
    inline MyMatrix3x3 &operator*=(const MyMatrix3x3 &that);

    // Left : this = that x this
    // Right: this = this x that
    MyMatrix3x3 &leftMultiply (const MyMatrix3x3 &that);
    MyMatrix3x3 &rightMultiply(const MyMatrix3x3 &that);

    inline MyMatrix3x3 &setIdentity     ();

public:
    double entry[3][3];

};

inline MyMatrix3x3 operator+(const MyMatrix3x3 &a, double b);
inline MyMatrix3x3 operator-(const MyMatrix3x3 &a, double b);
inline MyMatrix3x3 operator*(const MyMatrix3x3 &a, double b);

inline MyMatrix3x3 operator+(const MyMatrix3x3 &a, const MyMatrix3x3 &b);
inline MyMatrix3x3 operator-(const MyMatrix3x3 &a, const MyMatrix3x3 &b);
inline MyMatrix3x3 operator*(const MyMatrix3x3 &a, const MyMatrix3x3 &b);

inline MyMatrix3x3 multiply(const MyMatrix3x3 &a, const MyMatrix3x3 &b);
inline MyMatrix3x3 conjugate(const MyMatrix3x3 &a, const MyMatrix3x3 &b);
inline MyMatrix3x3 othoconjugate(const MyMatrix3x3 &a, const MyMatrix3x3 &b);
inline MyVector3d   operator*(const MyMatrix3x3 &a, const MyVector3d   &b);
inline MyVector3d   operator*(const MyVector3d   &a, const MyMatrix3x3 &b);

inline double determinant(const MyMatrix3x3 &a);

inline MyMatrix3x3 transpose(const MyMatrix3x3 &a);
inline MyMatrix3x3   inverse(const MyMatrix3x3 &a);

inline MyMatrix3x3::MyMatrix3x3() {
    entry[0][0] = 1;
    entry[0][1] = 0;
    entry[0][2] = 0;
    entry[1][0] = 0;
    entry[1][1] = 1;
    entry[1][2] = 0;
    entry[2][0] = 0;
    entry[2][1] = 0;
    entry[2][2] = 1;
}

inline MyMatrix3x3::MyMatrix3x3(double x) {
    entry[0][0] = x;
    entry[0][1] = x;
    entry[0][2] = x;
    entry[1][0] = x;
    entry[1][1] = x;
    entry[1][2] = x;
    entry[2][0] = x;
    entry[2][1] = x;
    entry[2][2] = x;
}

inline MyMatrix3x3::MyMatrix3x3(double M00, double M01, double M02,
                                double M10, double M11, double M12,
                                double M20, double M21, double M22) {
    entry[0][0] = M00;
    entry[0][1] = M01;
    entry[0][2] = M02;
    entry[1][0] = M10;
    entry[1][1] = M11;
    entry[1][2] = M12;
    entry[2][0] = M20;
    entry[2][1] = M21;
    entry[2][2] = M22;
};

inline MyMatrix3x3::MyMatrix3x3(const MyMatrix3x3 &that) {
    entry[0][0] = that.entry[0][0];
    entry[0][1] = that.entry[0][1];
    entry[0][2] = that.entry[0][2];
    entry[1][0] = that.entry[1][0];
    entry[1][1] = that.entry[1][1];
    entry[1][2] = that.entry[1][2];
    entry[2][0] = that.entry[2][0];
    entry[2][1] = that.entry[2][1];
    entry[2][2] = that.entry[2][2];
};

inline MyMatrix3x3::MyMatrix3x3(const MyVector3d &v1, const MyVector3d &v2, const MyVector3d &v3) {
    entry[0][0] = v1.entry[0];
    entry[0][1] = v1.entry[1];
    entry[0][2] = v1.entry[2];
    entry[1][0] = v2.entry[0];
    entry[1][1] = v2.entry[1];
    entry[1][2] = v2.entry[2];
    entry[2][0] = v3.entry[0];
    entry[2][1] = v3.entry[1];
    entry[2][2] = v3.entry[2];
}

inline MyMatrix3x3 &MyMatrix3x3::set(const double d) {
    return (*this)=d;
}

inline MyMatrix3x3 &MyMatrix3x3::operator=(const double d) {
    entry[0][0] = d;
    entry[0][1] = d;
    entry[0][2] = d;

    entry[1][0] = d;
    entry[1][1] = d;
    entry[1][2] = d;

    entry[2][0] = d;
    entry[2][1] = d;
    entry[2][2] = d;

    return (*this);
};

inline MyMatrix3x3 &MyMatrix3x3::set(const MyMatrix3x3 &that) {
    return (*this)=that;
}

inline MyMatrix3x3 &MyMatrix3x3::operator=(const MyMatrix3x3 &that) {
    entry[0][0] = that.entry[0][0];
    entry[0][1] = that.entry[0][1];
    entry[0][2] = that.entry[0][2];
    entry[1][0] = that.entry[1][0];
    entry[1][1] = that.entry[1][1];
    entry[1][2] = that.entry[1][2];
    entry[2][0] = that.entry[2][0];
    entry[2][1] = that.entry[2][1];
    entry[2][2] = that.entry[2][2];
    return (*this);
};

inline MyMatrix3x3 &MyMatrix3x3::set(double M[3][3]) {
    return (*this)=M;
}

inline MyMatrix3x3 &MyMatrix3x3::operator=(double M[3][3]) {
    entry[0][0] = M[0][0];
    entry[0][1] = M[0][1];
    entry[0][2] = M[0][2];

    entry[1][0] = M[1][0];
    entry[1][1] = M[1][1];
    entry[1][2] = M[1][2];

    entry[2][0] = M[2][0];
    entry[2][1] = M[2][1];
    entry[2][2] = M[2][2];
    return (*this);
};

inline MyMatrix3x3 &MyMatrix3x3::set(const MyVector3d &v1, const MyVector3d &v2, const MyVector3d &v3) {
    entry[0][0] = v1.entry[0];
    entry[0][1] = v1.entry[1];
    entry[0][2] = v1.entry[2];
    entry[1][0] = v2.entry[0];
    entry[1][1] = v2.entry[1];
    entry[1][2] = v2.entry[2];
    entry[2][0] = v3.entry[0];
    entry[2][1] = v3.entry[1];
    entry[2][2] = v3.entry[2];
    return (*this);
}

inline MyMatrix3x3 &MyMatrix3x3::set			(double M00, double M01, double M02,
                                                 double M10, double M11, double M12,
                                                 double M20, double M21, double M22)
{
    entry[0][0] = M00;
    entry[0][1] = M01;
    entry[0][2] = M02;
    entry[1][0] = M10;
    entry[1][1] = M11;
    entry[1][2] = M12;
    entry[2][0] = M20;
    entry[2][1] = M21;
    entry[2][2] = M22;
    return (*this);
}

inline int MyMatrix3x3::operator==(double d) const {
    return  ( (entry[0][0] == d) && (entry[0][1] == d) && (entry[0][2] == d) &&
            (entry[1][0] == d) && (entry[1][1] == d) && (entry[1][2] == d) &&
            (entry[2][0] == d) && (entry[2][1] == d) && (entry[2][2] == d));
}

inline int MyMatrix3x3::operator!=(double d) const {
    return  ( (entry[0][0] != d) || (entry[0][1] != d) || (entry[0][2] != d) ||
            (entry[1][0] != d) || (entry[1][1] != d) || (entry[1][2] != d) ||
            (entry[2][0] != d) || (entry[2][1] != d) || (entry[2][2] != d));
}

inline int MyMatrix3x3::operator==(const MyMatrix3x3 &that)const {
    return ( (entry[0][0] == that.entry[0][0]) && (entry[0][1] == that.entry[0][1]) && (entry[0][2] == that.entry[0][2]) &&
            (entry[1][0] == that.entry[1][0]) && (entry[1][1] == that.entry[1][1]) && (entry[1][2] == that.entry[1][2]) &&
            (entry[2][0] == that.entry[2][0]) && (entry[2][1] == that.entry[2][1]) && (entry[2][2] == that.entry[2][2]));
}

inline int MyMatrix3x3::operator!=(const MyMatrix3x3 &that)const {
    return ( (entry[0][0] != that.entry[0][0]) || (entry[0][1] != that.entry[0][1]) || (entry[0][2] != that.entry[0][2]) ||
            (entry[1][0] != that.entry[1][0]) || (entry[1][1] != that.entry[1][1]) || (entry[1][2] != that.entry[1][2]) ||
            (entry[2][0] != that.entry[2][0]) || (entry[2][1] != that.entry[2][1]) || (entry[2][2] != that.entry[2][2]));
}

inline MyMatrix3x3 &MyMatrix3x3::operator+=(double d) {
    entry[0][0] += d; entry[0][1] += d; entry[0][2] += d;
    entry[1][0] += d; entry[1][1] += d; entry[1][2] += d;
    entry[2][0] += d; entry[2][1] += d; entry[2][2] += d;
    return (*this);
}

inline MyMatrix3x3 &MyMatrix3x3::operator-=(double d) {
    entry[0][0] -= d; entry[0][1] -= d; entry[0][2] -= d;
    entry[1][0] -= d; entry[1][1] -= d; entry[1][2] -= d;
    entry[2][0] -= d; entry[2][1] -= d; entry[2][2] -= d;
    return (*this);
}

inline MyMatrix3x3 &MyMatrix3x3::operator*=(double d) {
    entry[0][0] *= d; entry[0][1] *= d; entry[0][2] *= d;
    entry[1][0] *= d; entry[1][1] *= d; entry[1][2] *= d;
    entry[2][0] *= d; entry[2][1] *= d; entry[2][2] *= d;
    return (*this);
}

inline MyMatrix3x3 &MyMatrix3x3::operator+=(const MyMatrix3x3 &that) {
    entry[0][0] += that.entry[0][0]; entry[0][1] += that.entry[0][1]; entry[0][2] += that.entry[0][2];
    entry[1][0] += that.entry[1][0]; entry[1][1] += that.entry[1][1]; entry[1][2] += that.entry[1][2];
    entry[2][0] += that.entry[2][0]; entry[2][1] += that.entry[2][1]; entry[2][2] += that.entry[2][2];
    return (*this);
}

inline MyMatrix3x3 &MyMatrix3x3::operator-=(const MyMatrix3x3 &that) {
    entry[0][0] -= that.entry[0][0]; entry[0][1] -= that.entry[0][1]; entry[0][2] -= that.entry[0][2];
    entry[1][0] -= that.entry[1][0]; entry[1][1] -= that.entry[1][1]; entry[1][2] -= that.entry[1][2];
    entry[2][0] -= that.entry[2][0]; entry[2][1] -= that.entry[2][1]; entry[2][2] -= that.entry[2][2];
    return (*this);
}

inline MyMatrix3x3 &MyMatrix3x3::operator*=(const MyMatrix3x3 &that) {
    entry[0][0] *= that.entry[0][0]; entry[0][1] *= that.entry[0][1]; entry[0][2] *= that.entry[0][2];
    entry[1][0] *= that.entry[1][0]; entry[1][1] *= that.entry[1][1]; entry[1][2] *= that.entry[1][2];
    entry[2][0] *= that.entry[2][0]; entry[2][1] *= that.entry[2][1]; entry[2][2] *= that.entry[2][2];
    return (*this);
}

inline MyMatrix3x3 &MyMatrix3x3::leftMultiply (const MyMatrix3x3 &that){
    MyMatrix3x3 tmp(entry[0][0], entry[0][1], entry[0][2],
            entry[1][0], entry[1][1], entry[1][2],
            entry[2][0], entry[2][1], entry[2][2]);

    entry[0][0] = that.entry[0][0] * tmp.entry[0][0] + that.entry[0][1] * tmp.entry[1][0] + that.entry[0][2] * tmp.entry[2][0];
    entry[0][1] = that.entry[0][0] * tmp.entry[0][1] + that.entry[0][1] * tmp.entry[1][1] + that.entry[0][2] * tmp.entry[2][1];
    entry[0][2] = that.entry[0][0] * tmp.entry[0][2] + that.entry[0][1] * tmp.entry[1][2] + that.entry[0][2] * tmp.entry[2][2];

    entry[1][0] = that.entry[1][0] * tmp.entry[0][0] + that.entry[1][1] * tmp.entry[1][0] + that.entry[1][2] * tmp.entry[2][0];
    entry[1][1] = that.entry[1][0] * tmp.entry[0][1] + that.entry[1][1] * tmp.entry[1][1] + that.entry[1][2] * tmp.entry[2][1];
    entry[1][2] = that.entry[1][0] * tmp.entry[0][2] + that.entry[1][1] * tmp.entry[1][2] + that.entry[1][2] * tmp.entry[2][2];

    entry[2][0] = that.entry[2][0] * tmp.entry[0][0] + that.entry[2][1] * tmp.entry[1][0] + that.entry[2][2] * tmp.entry[2][0];
    entry[2][1] = that.entry[2][0] * tmp.entry[0][1] + that.entry[2][1] * tmp.entry[1][1] + that.entry[2][2] * tmp.entry[2][1];
    entry[2][2] = that.entry[2][0] * tmp.entry[0][2] + that.entry[2][1] * tmp.entry[1][2] + that.entry[2][2] * tmp.entry[2][2];
    return (*this);
};

inline MyMatrix3x3 &MyMatrix3x3::rightMultiply(const MyMatrix3x3 &that){
    MyMatrix3x3 tmp(entry[0][0], entry[0][1], entry[0][2],
            entry[1][0], entry[1][1], entry[1][2],
            entry[2][0], entry[2][1], entry[2][2]);

    entry[0][0] = tmp.entry[0][0] * that.entry[0][0] + tmp.entry[0][1] * that.entry[1][0] + tmp.entry[0][2] * that.entry[2][0];
    entry[0][1] = tmp.entry[0][0] * that.entry[0][1] + tmp.entry[0][1] * that.entry[1][1] + tmp.entry[0][2] * that.entry[2][1];
    entry[0][2] = tmp.entry[0][0] * that.entry[0][2] + tmp.entry[0][1] * that.entry[1][2] + tmp.entry[0][2] * that.entry[2][2];

    entry[1][0] = tmp.entry[1][0] * that.entry[0][0] + tmp.entry[1][1] * that.entry[1][0] + tmp.entry[1][2] * that.entry[2][0];
    entry[1][1] = tmp.entry[1][0] * that.entry[0][1] + tmp.entry[1][1] * that.entry[1][1] + tmp.entry[1][2] * that.entry[2][1];
    entry[1][2] = tmp.entry[1][0] * that.entry[0][2] + tmp.entry[1][1] * that.entry[1][2] + tmp.entry[1][2] * that.entry[2][2];

    entry[2][0] = tmp.entry[2][0] * that.entry[0][0] + tmp.entry[2][1] * that.entry[1][0] + tmp.entry[2][2] * that.entry[2][0];
    entry[2][1] = tmp.entry[2][0] * that.entry[0][1] + tmp.entry[2][1] * that.entry[1][1] + tmp.entry[2][2] * that.entry[2][1];
    entry[2][2] = tmp.entry[2][0] * that.entry[0][2] + tmp.entry[2][1] * that.entry[1][2] + tmp.entry[2][2] * that.entry[2][2];
    return (*this);
};

inline MyMatrix3x3 &MyMatrix3x3::setIdentity() {
    entry[0][0] = 1; entry[0][1] = 0; entry[0][2] = 0;
    entry[1][0] = 0; entry[1][1] = 1; entry[1][2] = 0;
    entry[2][0] = 0; entry[2][1] = 0; entry[2][2] = 1;
    return (*this);
};

inline MyMatrix3x3 operator+(const MyMatrix3x3 &a,double b) {
    return (MyMatrix3x3(a)+=b);
}

inline MyMatrix3x3 operator-(const MyMatrix3x3 &a,double b) {
    return (MyMatrix3x3(a)-=b);
}

inline MyMatrix3x3 operator*(const MyMatrix3x3 &a,double b) {
    return (MyMatrix3x3(a)*=b);
}

inline MyMatrix3x3 operator+(double a, const MyMatrix3x3 &b) {
    return b+a;
}

inline MyMatrix3x3 operator-(double a, const MyMatrix3x3 &b) {
    return MyMatrix3x3(a-b.entry[0][0],a-b.entry[0][1],a-b.entry[0][2],
            a-b.entry[1][0],a-b.entry[1][1],a-b.entry[1][2],
            a-b.entry[2][0],a-b.entry[2][1],a-b.entry[2][2]);
}

inline MyMatrix3x3 operator*(double a, const MyMatrix3x3 &b) {
    return b*a;
}

inline MyMatrix3x3 operator+(const MyMatrix3x3 &a,const MyMatrix3x3 &b) {
    return (MyMatrix3x3(a)+=b);
}

inline MyMatrix3x3 operator-(const MyMatrix3x3 &a,const MyMatrix3x3 &b) {
    return (MyMatrix3x3(a)-=b);
}

inline MyMatrix3x3 operator*(const MyMatrix3x3 &a,const MyMatrix3x3 &b) {
    return (MyMatrix3x3(a)*=b);
}

inline MyMatrix3x3 multiply(const MyMatrix3x3 &a,const MyMatrix3x3 &b) {
    MyMatrix3x3 tmp(a);
    tmp.rightMultiply(b);
    return tmp;
}

inline MyMatrix3x3 conjugate(const MyMatrix3x3 &a, const MyMatrix3x3 &b) {
    MyMatrix3x3 tmp(a);
    MyMatrix3x3 c = inverse(b);
    tmp.rightMultiply(b);
    tmp.leftMultiply(c);
    return tmp;
}

inline MyMatrix3x3 othoconjugate(const MyMatrix3x3 &a, const MyMatrix3x3 &b) {
    MyMatrix3x3 tmp(a);
    MyMatrix3x3 c = transpose(b);
    tmp.rightMultiply(b);
    tmp.leftMultiply(c);
    return tmp;
}

inline MyVector3d operator*(const MyMatrix3x3 &a,const MyVector3d &b) {
    return MyVector3d(b.entry[0]*a.entry[0][0] + b.entry[1]*a.entry[0][1] + b.entry[2]*a.entry[0][2],
            b.entry[0]*a.entry[1][0] + b.entry[1]*a.entry[1][1] + b.entry[2]*a.entry[1][2],
            b.entry[0]*a.entry[2][0] + b.entry[1]*a.entry[2][1] + b.entry[2]*a.entry[2][2]);
}

inline MyVector3d operator*(const MyVector3d &a,const MyMatrix3x3 &b) {
    return MyVector3d(a.entry[0]*b.entry[0][0] + a.entry[1]*b.entry[1][0] + a.entry[2]*b.entry[2][0],
            a.entry[0]*b.entry[0][1] + a.entry[1]*b.entry[1][1] + a.entry[2]*b.entry[2][1],
            a.entry[0]*b.entry[0][2] + a.entry[1]*b.entry[1][2] + a.entry[2]*b.entry[2][2]);
}

inline double determinant(const MyMatrix3x3 &a) {
    return ( a.entry[0][0] * a.entry[1][1] * a.entry[2][2] - a.entry[2][0] * a.entry[1][1] * a.entry[0][2]
            + a.entry[1][0] * a.entry[2][1] * a.entry[0][2] - a.entry[0][0] * a.entry[2][1] * a.entry[1][2]
            + a.entry[2][0] * a.entry[0][1] * a.entry[1][2] - a.entry[1][0] * a.entry[0][1] * a.entry[2][2]);
}

inline MyMatrix3x3 transpose(const MyMatrix3x3 &a) {
    MyMatrix3x3 tmp(a);

    tmp.entry[0][1] = a.entry[1][0];
    tmp.entry[1][0] = a.entry[0][1];

    tmp.entry[0][2] = a.entry[2][0];
    tmp.entry[2][0] = a.entry[0][2];

    tmp.entry[2][1] = a.entry[1][2];
    tmp.entry[1][2] = a.entry[2][1];
    return tmp;
}

inline MyMatrix3x3 inverse(const MyMatrix3x3 &a) {
    MyMatrix3x3 tmp;
    double dmt;

    if ((dmt=determinant(a))!= 0.0) {
        tmp.entry[0][0] = (a.entry[1][1] * a.entry[2][2] - a.entry[2][1] * a.entry[1][2])/dmt;
        tmp.entry[0][1] = (a.entry[2][1] * a.entry[0][2] - a.entry[0][1] * a.entry[2][2])/dmt;
        tmp.entry[0][2] = (a.entry[0][1] * a.entry[1][2] - a.entry[1][1] * a.entry[0][2])/dmt;

        tmp.entry[1][0] = (a.entry[1][2] * a.entry[2][0] - a.entry[2][2] * a.entry[1][0])/dmt;
        tmp.entry[1][1] = (a.entry[2][2] * a.entry[0][0] - a.entry[0][2] * a.entry[2][0])/dmt;
        tmp.entry[1][2] = (a.entry[0][2] * a.entry[1][0] - a.entry[1][2] * a.entry[0][0])/dmt;

        tmp.entry[2][0] = (a.entry[1][0] * a.entry[2][1] - a.entry[2][0] * a.entry[1][1])/dmt;
        tmp.entry[2][1] = (a.entry[2][0] * a.entry[0][1] - a.entry[0][0] * a.entry[2][1])/dmt;
        tmp.entry[2][2] = (a.entry[0][0] * a.entry[1][1] - a.entry[1][0] * a.entry[0][1])/dmt;
    }
    return tmp;
}
#endif // MYMATRIX_H
