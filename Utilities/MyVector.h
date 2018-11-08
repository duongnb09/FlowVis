/*=========================================================================
    Program:   Flow Visualization
    Module:    MyVector.h

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See LICENSE for details

=========================================================================*/
#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <math.h>
#include <stdlib.h>

class MyVector2d;
class MyVector3d;

/*----------------------------------------*/
/* ------ Define MyVector2D class ------- */
/*----------------------------------------*/
class MyVector2d{
public:
    inline MyVector2d();
    inline MyVector2d(double d);
    inline MyVector2d(double d0,double d1);

    inline MyVector2d(const MyVector2d& a);
    inline MyVector2d(const double*    a);

    inline MyVector2d& set(double d);
    inline MyVector2d& set(double d0, double d1);

    inline MyVector2d& set(const MyVector2d& a);
    inline MyVector2d& set(const double*    a);

    inline MyVector2d& operator=(double d);
    inline MyVector2d& operator=(const MyVector2d& a);
    inline MyVector2d& operator=(const double*    a);

    inline int operator==(const MyVector2d& a) const;
    inline int operator!=(const MyVector2d& a) const;

    inline int operator==(double d) const;
    inline int operator!=(double d) const;

    inline MyVector2d& operator+=(double d);
    inline MyVector2d& operator-=(double d);
    inline MyVector2d& operator*=(double d);
    inline MyVector2d& operator/=(double d);

    inline MyVector2d& operator+=(const MyVector2d& a);
    inline MyVector2d& operator-=(const MyVector2d& a);
    inline MyVector2d& operator*=(const MyVector2d& a);
    inline MyVector2d& operator/=(const MyVector2d& a);
    inline double length(const MyVector2d& a);
    inline void   normalize(MyVector2d& a);

    inline double    dot(const MyVector2d& a,const MyVector2d& b);
    inline MyVector2d cross(const MyVector2d& a);

public:
    union {
        double entry[2]; /// all the vector entries
        double array[2]; /// all the vector entries (an additional alias added later)
        struct {
            double x;
            double y;
        };
    };
};

inline MyVector2d operator-(const MyVector2d& a);

inline MyVector2d operator+(const MyVector2d& a, const MyVector2d& b);
inline MyVector2d operator-(const MyVector2d& a, const MyVector2d& b);

inline MyVector2d operator+(const MyVector2d& a, double b);
inline MyVector2d operator-(const MyVector2d& a, double b);
inline MyVector2d operator*(const MyVector2d& a, double b);

inline MyVector2d operator+(double a, const MyVector2d& b);
inline MyVector2d operator-(double a, const MyVector2d& b);
inline MyVector2d operator*(double a, const MyVector2d& b);

inline double length(const MyVector2d& a);
inline void   normalize(MyVector2d& a);


inline double dot(const MyVector2d& a,const MyVector2d& b);
inline MyVector2d cross(const MyVector2d& a);

inline MyVector2d::MyVector2d() {
    entry[0] = entry[1] = 0.0;
}
inline MyVector2d::MyVector2d(double d) {
    entry[0] = entry[1] = d;
}

inline MyVector2d::MyVector2d(double d0,double d1) {
    entry[0] = d0;
    entry[1] = d1;
}

inline MyVector2d::MyVector2d(const MyVector2d& a) {
    entry[0] = a.entry[0];
    entry[1] = a.entry[1];
}

inline MyVector2d::MyVector2d(const double* a) {
    entry[0] = a[0];
    entry[1] = a[1];
}

inline MyVector2d& MyVector2d::set(double d) {
    entry[0] = d;
    entry[1] = d;
    return (*this);
}

inline MyVector2d& MyVector2d::set(double d0, double d1) {
    entry[0] = d0;
    entry[1] = d1;
    return (*this);
}

inline MyVector2d& MyVector2d::set(const MyVector2d& a) {
    entry[0] = a.entry[0];
    entry[1] = a.entry[1];
    return (*this);
}

inline MyVector2d& MyVector2d::set(const double* a) {
    entry[0] = a[0];
    entry[1] = a[1];
    return (*this);
}

inline MyVector2d operator-(const MyVector2d& a) {
    return MyVector2d(-a.entry[0],-a.entry[1]);
}

inline MyVector2d& MyVector2d::operator=(double d) {
    return set(d);
}

inline MyVector2d& MyVector2d::operator=(const MyVector2d& a) {
    return set(a);
}

inline MyVector2d& MyVector2d::operator=(const double* a) {
    return set(a);
}

//-------------------------------------------------------------------

inline int MyVector2d::operator==(const MyVector2d& a) const {
    return ((entry[0] == a.entry[0]) && (entry[1] == a.entry[1]));
}

inline int MyVector2d::operator!=(const MyVector2d& a) const {
    return ((entry[0] != a.entry[0]) || (entry[1] != a.entry[1]));
}

inline int MyVector2d::operator==(double d) const {
    return ((entry[0] == d) && (entry[1] == d));
}

inline int MyVector2d::operator!=(double d) const {
    return ((entry[0] != d) || (entry[1] != d));
}

//-------------------------------------------------------------------

inline MyVector2d& MyVector2d::operator+=(double d) {
    entry[0] += d;
    entry[1] += d;
    return (*this);
}

inline MyVector2d& MyVector2d::operator-=(double d) {
    entry[0] -= d;
    entry[1] -= d;
    return (*this);
}

inline MyVector2d& MyVector2d::operator*=(double d) {
    entry[0] *= d;
    entry[1] *= d;
    return (*this);
}

inline MyVector2d& MyVector2d::operator+=(const MyVector2d& a) {
    entry[0] += a.entry[0];
    entry[1] += a.entry[1];
    return (*this);
}

inline MyVector2d& MyVector2d::operator-=(const MyVector2d& a) {
    entry[0] -= a.entry[0];
    entry[1] -= a.entry[1];
    return (*this);
}

inline MyVector2d& MyVector2d::operator*=(const MyVector2d& a) {
    entry[0] *= a.entry[0];
    entry[1] *= a.entry[1];
    return (*this);
}

//-------------------------------------------------------------------

inline MyVector2d operator+(const MyVector2d& a,const MyVector2d& b) {
    return MyVector2d(a.entry[0] + b.entry[0], a.entry[1] + b.entry[1]);
}

inline MyVector2d operator-(const MyVector2d& a,const MyVector2d& b) {
    return MyVector2d(a.entry[0] - b.entry[0], a.entry[1] - b.entry[1]);
}

inline MyVector2d operator+(const MyVector2d& a,double b){
    return MyVector2d(a.entry[0] + b, a.entry[1] + b);
}

inline MyVector2d operator-(const MyVector2d& a,double b){
    return MyVector2d(a.entry[0] - b, a.entry[1] - b);
}

inline MyVector2d operator*(const MyVector2d& a,double b){
    return MyVector2d(a.entry[0] * b, a.entry[1] * b);
}

inline MyVector2d operator+(double a,const MyVector2d& b){
    return MyVector2d(a + b.entry[0], a + b.entry[1]);
}

inline MyVector2d operator-(double a,const MyVector2d& b){
    return MyVector2d(a - b.entry[0], a - b.entry[1]);
}

inline MyVector2d operator*(double a,const MyVector2d& b){
    return MyVector2d(a * b.entry[0], a * b.entry[1]);
}

inline double length(const MyVector2d& a) {
    return sqrt(a.entry[0] * a.entry[0] + a.entry[1] * a.entry[1]);
}

inline void normalize(MyVector2d& a) {
    register double m = length(a);
    if (m != 0) a *= (1/m);
}

inline double dot(const MyVector2d& a, const MyVector2d& b) {
    return (a.entry[0] * b.entry[0] + a.entry[1] * b.entry[1]);
}

inline MyVector2d cross(const MyVector2d& a) {
    return MyVector2d(-a.entry[1], a.entry[0]);
}

/*----------------------------------------*/
/* ------ Define MyVector3D class ------- */
/*----------------------------------------*/
class MyVector3d{
public:
    inline MyVector3d();
    inline MyVector3d(double d);
    inline MyVector3d(double d0,double d1,double d2);

    inline MyVector3d(const MyVector3d& a);
    inline MyVector3d(const double*    a);

    inline MyVector3d& set(double d);
    inline MyVector3d& set(double d0, double d1,double d2);

    inline MyVector3d& set(const MyVector3d& a);
    inline MyVector3d& set(const double*    a);

    inline MyVector3d& operator=(double d);
    inline MyVector3d& operator=(const MyVector3d& a);
    inline MyVector3d& operator=(const double*    a);

    inline int operator==(const MyVector3d& a) const;
    inline int operator!=(const MyVector3d& a) const;

    inline int operator==(double d) const;
    inline int operator!=(double d) const;

    inline MyVector3d& operator+=(double d);
    inline MyVector3d& operator-=(double d);
    inline MyVector3d& operator*=(double d);
    inline MyVector3d& operator/=(double d);

    inline MyVector3d& operator+=(const MyVector3d& a);
    inline MyVector3d& operator-=(const MyVector3d& a);
    inline MyVector3d& operator*=(const MyVector3d& a);
    inline MyVector3d& operator/=(const MyVector3d& a);
    inline double length(const MyVector3d& a);
    inline void   normalize(MyVector3d& a);

    inline double    dot(const MyVector3d& a, const MyVector3d& b);
    inline MyVector3d cross(const MyVector3d& a);
    void project(const MyVector3d& a);

public:
    union {
        double entry[3]; /// all the vector entries
        double array[3]; /// all the vector entries (an additional alias added later)
        struct {
            double x;
            double y;
            double z;
        };
    };
};

inline MyVector3d operator-(const MyVector3d& a);

inline MyVector3d operator+(const MyVector3d& a, const MyVector3d& b);
inline MyVector3d operator-(const MyVector3d& a, const MyVector3d& b);

inline MyVector3d operator+(const MyVector3d& a, double b);
inline MyVector3d operator-(const MyVector3d& a, double b);
inline MyVector3d operator*(const MyVector3d& a, double b);

inline MyVector3d operator+(double a, const MyVector3d& b);
inline MyVector3d operator-(double a, const MyVector3d& b);
inline MyVector3d operator*(double a, const MyVector3d& b);

inline double length(const MyVector3d& a);
inline void normalize(MyVector3d& a);


inline double dot(const MyVector3d& a,const MyVector3d& b);
inline MyVector3d cross(const MyVector3d& a, const MyVector3d& b);

inline MyVector3d::MyVector3d() {
    entry[0] = entry[1] = entry[2] = 0.0;
}
inline MyVector3d::MyVector3d(double d) {
    entry[0] = entry[1] = entry[2] = d;
}

inline MyVector3d::MyVector3d(double d0,double d1,double d2) {
    entry[0] = d0;
    entry[1] = d1;
    entry[2] = d2;
}

inline MyVector3d::MyVector3d(const MyVector3d& a) {
    entry[0] = a.entry[0];
    entry[1] = a.entry[1];
    entry[2] = a.entry[2];
}

inline MyVector3d::MyVector3d(const double* a) {
    entry[0] = a[0];
    entry[1] = a[1];
    entry[2] = a[2];
}

//-------------------------------------------------------------------

inline MyVector3d& MyVector3d::set(double d) {
    entry[0] = d;
    entry[1] = d;
    entry[2] = d;
    return (*this);
}

inline MyVector3d& MyVector3d::set(double d0, double d1, double d2) {
    entry[0] = d0;
    entry[1] = d1;
    entry[2] = d2;
    return (*this);
}

inline MyVector3d& MyVector3d::set(const MyVector3d& a) {
    entry[0] = a.entry[0];
    entry[1] = a.entry[1];
    entry[2] = a.entry[2];
    return (*this);
}

inline MyVector3d& MyVector3d::set(const double* a) {
    entry[0] = a[0];
    entry[1] = a[1];
    entry[2] = a[2];
    return (*this);
}

inline MyVector3d operator-(const MyVector3d& a) {
    return MyVector3d(-a.entry[0],-a.entry[1],-a.entry[2]);
}

inline MyVector3d& MyVector3d::operator=(double d) {
    return set(d);
}

inline MyVector3d& MyVector3d::operator=(const MyVector3d& a) {
    return set(a);
}

inline MyVector3d& MyVector3d::operator=(const double* a) {
    return set(a);
}

//-------------------------------------------------------------------

inline int MyVector3d::operator==(const MyVector3d& a) const {
    return (
                (entry[0] == a.entry[0]) &&
            (entry[1] == a.entry[1]) &&
            (entry[2] == a.entry[2]));
}

inline int MyVector3d::operator!=(const MyVector3d& a) const {
    return (
                (entry[0] != a.entry[0]) ||
            (entry[1] != a.entry[1]) ||
            (entry[2] != a.entry[2]));
}

inline int MyVector3d::operator==(double d) const {
    return (
                (entry[0] == d) &&
            (entry[1] == d) &&
            (entry[2] == d));
}

inline int MyVector3d::operator!=(double d) const {
    return (
                (entry[0] != d) ||
            (entry[1] != d) ||
            (entry[2] != d));
}

//-------------------------------------------------------------------

inline MyVector3d& MyVector3d::operator+=(double d) {
    entry[0] += d;
    entry[1] += d;
    entry[2] += d;
    return (*this);
}

inline MyVector3d& MyVector3d::operator-=(double d) {
    entry[0] -= d;
    entry[1] -= d;
    entry[2] -= d;
    return (*this);
}

inline MyVector3d& MyVector3d::operator*=(double d) {
    entry[0] *= d;
    entry[1] *= d;
    entry[2] *= d;
    return (*this);
}

inline MyVector3d& MyVector3d::operator/=(double d) {
    entry[0] /= d;
    entry[1] /= d;
    entry[2] /= d;
    return (*this);
}

inline MyVector3d& MyVector3d::operator+=(const MyVector3d& a) {
    entry[0] += a.entry[0];
    entry[1] += a.entry[1];
    entry[2] += a.entry[2];
    return (*this);
}

inline MyVector3d& MyVector3d::operator-=(const MyVector3d& a) {
    entry[0] -= a.entry[0];
    entry[1] -= a.entry[1];
    entry[2] -= a.entry[2];
    return (*this);
}

inline MyVector3d& MyVector3d::operator*=(const MyVector3d& a) {
    entry[0] *= a.entry[0];
    entry[1] *= a.entry[1];
    entry[2] *= a.entry[2];
    return (*this);
}

inline MyVector3d& MyVector3d::operator/=(const MyVector3d& a) {
    entry[0] /= a.entry[0];
    entry[1] /= a.entry[1];
    entry[2] /= a.entry[2];
    return (*this);
}

//-------------------------------------------------------------------

inline MyVector3d operator+(const MyVector3d& a,const MyVector3d& b) {
    return MyVector3d(a.entry[0] + b.entry[0], a.entry[1] + b.entry[1],
            a.entry[2] + b.entry[2]);
}

inline MyVector3d operator-(const MyVector3d& a,const MyVector3d& b) {
    return MyVector3d(a.entry[0] - b.entry[0], a.entry[1] - b.entry[1],
            a.entry[2] - b.entry[2]);
}

inline MyVector3d operator+(const MyVector3d& a,double b){
    return MyVector3d(a.entry[0] + b, a.entry[1] + b, a.entry[2] + b);
}

inline MyVector3d operator-(const MyVector3d& a,double b){
    return MyVector3d(a.entry[0] - b, a.entry[1] - b, a.entry[2] - b);
}

inline MyVector3d operator*(const MyVector3d& a,double b){
    return MyVector3d(a.entry[0] * b, a.entry[1] * b, a.entry[2] * b);
}

inline MyVector3d operator+(double a,const MyVector3d& b){
    return MyVector3d(a + b.entry[0], a + b.entry[1], a + b.entry[2]);
}

inline MyVector3d operator-(double a,const MyVector3d& b){
    return MyVector3d(a - b.entry[0], a - b.entry[1], a - b.entry[2]);
}

inline MyVector3d operator*(double a,const MyVector3d& b){
    return MyVector3d(a * b.entry[0], a * b.entry[1], a * b.entry[2]);
}

inline double length(const MyVector3d& a) {
    return sqrt(a.entry[0] * a.entry[0] + a.entry[1] * a.entry[1] + a.entry[2]
            * a.entry[2]);
}

inline void normalize(MyVector3d& a) {
    register double m = length(a);
    if (m != 0) a *= (1/m);
}

/* Dot product */
inline double dot(const MyVector3d& a,const MyVector3d& b) {
    return (a.entry[0] * b.entry[0] + a.entry[1] * b.entry[1] + a.entry[2] *
            b.entry[2]);
}

/* Cross product */
inline MyVector3d cross(const MyVector3d& a, const MyVector3d& b) {
    return MyVector3d(
                a.entry[1] * b.entry[2] - a.entry[2] * b.entry[1],
            a.entry[2] * b.entry[0] - a.entry[0] * b.entry[2],
            a.entry[0] * b.entry[1] - a.entry[1] * b.entry[0]);
}
#endif // MYVECTOR_H
