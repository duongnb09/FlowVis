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
    inline MyVector2d(float d);
    inline MyVector2d(float d0,float d1);

    inline MyVector2d(const MyVector2d& a);
    inline MyVector2d(const float*    a);

    inline MyVector2d& set(float d);
    inline MyVector2d& set(float d0, float d1);

    inline MyVector2d& set(const MyVector2d& a);
    inline MyVector2d& set(const float*    a);

    inline MyVector2d& operator=(float d);
    inline MyVector2d& operator=(const MyVector2d& a);
    inline MyVector2d& operator=(const float*    a);

    inline int operator==(const MyVector2d& a) const;
    inline int operator!=(const MyVector2d& a) const;

    inline int operator==(float d) const;
    inline int operator!=(float d) const;

    inline MyVector2d& operator+=(float d);
    inline MyVector2d& operator-=(float d);
    inline MyVector2d& operator*=(float d);
    inline MyVector2d& operator/=(float d);

    inline MyVector2d& operator+=(const MyVector2d& a);
    inline MyVector2d& operator-=(const MyVector2d& a);
    inline MyVector2d& operator*=(const MyVector2d& a);
    inline MyVector2d& operator/=(const MyVector2d& a);
    inline float length(const MyVector2d& a);
    inline void   normalize(MyVector2d& a);

    inline float    dot(const MyVector2d& a,const MyVector2d& b);
    inline MyVector2d cross(const MyVector2d& a);

public:
    union {
        float entry[2]; /// all the vector entries
        float array[2]; /// all the vector entries (an additional alias added later)
        struct {
            float x;
            float y;
        };
    };
};

inline MyVector2d operator-(const MyVector2d& a);

inline MyVector2d operator+(const MyVector2d& a, const MyVector2d& b);
inline MyVector2d operator-(const MyVector2d& a, const MyVector2d& b);

inline MyVector2d operator+(const MyVector2d& a, float b);
inline MyVector2d operator-(const MyVector2d& a, float b);
inline MyVector2d operator*(const MyVector2d& a, float b);

inline MyVector2d operator+(float a, const MyVector2d& b);
inline MyVector2d operator-(float a, const MyVector2d& b);
inline MyVector2d operator*(float a, const MyVector2d& b);

inline float length(const MyVector2d& a);
inline void   normalize(MyVector2d& a);


inline float dot(const MyVector2d& a,const MyVector2d& b);
inline MyVector2d cross(const MyVector2d& a);

inline MyVector2d::MyVector2d() {
    entry[0] = entry[1] = 0.0;
}
inline MyVector2d::MyVector2d(float d) {
    entry[0] = entry[1] = d;
}

inline MyVector2d::MyVector2d(float d0,float d1) {
    entry[0] = d0;
    entry[1] = d1;
}

inline MyVector2d::MyVector2d(const MyVector2d& a) {
    entry[0] = a.entry[0];
    entry[1] = a.entry[1];
}

inline MyVector2d::MyVector2d(const float* a) {
    entry[0] = a[0];
    entry[1] = a[1];
}

inline MyVector2d& MyVector2d::set(float d) {
    entry[0] = d;
    entry[1] = d;
    return (*this);
}

inline MyVector2d& MyVector2d::set(float d0, float d1) {
    entry[0] = d0;
    entry[1] = d1;
    return (*this);
}

inline MyVector2d& MyVector2d::set(const MyVector2d& a) {
    entry[0] = a.entry[0];
    entry[1] = a.entry[1];
    return (*this);
}

inline MyVector2d& MyVector2d::set(const float* a) {
    entry[0] = a[0];
    entry[1] = a[1];
    return (*this);
}

inline MyVector2d operator-(const MyVector2d& a) {
    return MyVector2d(-a.entry[0],-a.entry[1]);
}

inline MyVector2d& MyVector2d::operator=(float d) {
    return set(d);
}

inline MyVector2d& MyVector2d::operator=(const MyVector2d& a) {
    return set(a);
}

inline MyVector2d& MyVector2d::operator=(const float* a) {
    return set(a);
}

//-------------------------------------------------------------------

inline int MyVector2d::operator==(const MyVector2d& a) const {
    return ((entry[0] == a.entry[0]) && (entry[1] == a.entry[1]));
}

inline int MyVector2d::operator!=(const MyVector2d& a) const {
    return ((entry[0] != a.entry[0]) || (entry[1] != a.entry[1]));
}

inline int MyVector2d::operator==(float d) const {
    return ((entry[0] == d) && (entry[1] == d));
}

inline int MyVector2d::operator!=(float d) const {
    return ((entry[0] != d) || (entry[1] != d));
}

//-------------------------------------------------------------------

inline MyVector2d& MyVector2d::operator+=(float d) {
    entry[0] += d;
    entry[1] += d;
    return (*this);
}

inline MyVector2d& MyVector2d::operator-=(float d) {
    entry[0] -= d;
    entry[1] -= d;
    return (*this);
}

inline MyVector2d& MyVector2d::operator*=(float d) {
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

inline MyVector2d operator+(const MyVector2d& a,float b){
    return MyVector2d(a.entry[0] + b, a.entry[1] + b);
}

inline MyVector2d operator-(const MyVector2d& a,float b){
    return MyVector2d(a.entry[0] - b, a.entry[1] - b);
}

inline MyVector2d operator*(const MyVector2d& a,float b){
    return MyVector2d(a.entry[0] * b, a.entry[1] * b);
}

inline MyVector2d operator+(float a,const MyVector2d& b){
    return MyVector2d(a + b.entry[0], a + b.entry[1]);
}

inline MyVector2d operator-(float a,const MyVector2d& b){
    return MyVector2d(a - b.entry[0], a - b.entry[1]);
}

inline MyVector2d operator*(float a,const MyVector2d& b){
    return MyVector2d(a * b.entry[0], a * b.entry[1]);
}

inline float length(const MyVector2d& a) {
    return sqrt(a.entry[0] * a.entry[0] + a.entry[1] * a.entry[1]);
}

inline void normalize(MyVector2d& a) {
    register float m = length(a);
    if (m != 0) a *= (1/m);
}

inline float dot(const MyVector2d& a, const MyVector2d& b) {
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
    inline MyVector3d(float d);
    inline MyVector3d(float d0,float d1,float d2);

    inline MyVector3d(const MyVector3d& a);
    inline MyVector3d(const float*    a);

    inline MyVector3d& set(float d);
    inline MyVector3d& set(float d0, float d1,float d2);

    inline MyVector3d& set(const MyVector3d& a);
    inline MyVector3d& set(const float*    a);

    inline MyVector3d& operator=(float d);
    inline MyVector3d& operator=(const MyVector3d& a);
    inline MyVector3d& operator=(const float*    a);

    inline int operator==(const MyVector3d& a) const;
    inline int operator!=(const MyVector3d& a) const;

    inline int operator==(float d) const;
    inline int operator!=(float d) const;

    inline MyVector3d& operator+=(float d);
    inline MyVector3d& operator-=(float d);
    inline MyVector3d& operator*=(float d);
    inline MyVector3d& operator/=(float d);

    inline MyVector3d& operator+=(const MyVector3d& a);
    inline MyVector3d& operator-=(const MyVector3d& a);
    inline MyVector3d& operator*=(const MyVector3d& a);
    inline MyVector3d& operator/=(const MyVector3d& a);
    inline float length(const MyVector3d& a);
    inline void   normalize(MyVector3d& a);

    inline float    dot(const MyVector3d& a, const MyVector3d& b);
    inline MyVector3d cross(const MyVector3d& a);
    void project(const MyVector3d& a);

public:
    union {
        float entry[3]; /// all the vector entries
        float array[3]; /// all the vector entries (an additional alias added later)
        struct {
            float x;
            float y;
            float z;
        };
    };
};

inline MyVector3d operator-(const MyVector3d& a);

inline MyVector3d operator+(const MyVector3d& a, const MyVector3d& b);
inline MyVector3d operator-(const MyVector3d& a, const MyVector3d& b);

inline MyVector3d operator+(const MyVector3d& a, float b);
inline MyVector3d operator-(const MyVector3d& a, float b);
inline MyVector3d operator*(const MyVector3d& a, float b);

inline MyVector3d operator+(float a, const MyVector3d& b);
inline MyVector3d operator-(float a, const MyVector3d& b);
inline MyVector3d operator*(float a, const MyVector3d& b);

inline float length(const MyVector3d& a);
inline void normalize(MyVector3d& a);


inline float dot(const MyVector3d& a,const MyVector3d& b);
inline MyVector3d cross(const MyVector3d& a, const MyVector3d& b);

inline MyVector3d::MyVector3d() {
    entry[0] = entry[1] = entry[2] = 0.0;
}
inline MyVector3d::MyVector3d(float d) {
    entry[0] = entry[1] = entry[2] = d;
}

inline MyVector3d::MyVector3d(float d0,float d1,float d2) {
    entry[0] = d0;
    entry[1] = d1;
    entry[2] = d2;
}

inline MyVector3d::MyVector3d(const MyVector3d& a) {
    entry[0] = a.entry[0];
    entry[1] = a.entry[1];
    entry[2] = a.entry[2];
}

inline MyVector3d::MyVector3d(const float* a) {
    entry[0] = a[0];
    entry[1] = a[1];
    entry[2] = a[2];
}

//-------------------------------------------------------------------

inline MyVector3d& MyVector3d::set(float d) {
    entry[0] = d;
    entry[1] = d;
    entry[2] = d;
    return (*this);
}

inline MyVector3d& MyVector3d::set(float d0, float d1, float d2) {
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

inline MyVector3d& MyVector3d::set(const float* a) {
    entry[0] = a[0];
    entry[1] = a[1];
    entry[2] = a[2];
    return (*this);
}

inline MyVector3d operator-(const MyVector3d& a) {
    return MyVector3d(-a.entry[0],-a.entry[1],-a.entry[2]);
}

inline MyVector3d& MyVector3d::operator=(float d) {
    return set(d);
}

inline MyVector3d& MyVector3d::operator=(const MyVector3d& a) {
    return set(a);
}

inline MyVector3d& MyVector3d::operator=(const float* a) {
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

inline int MyVector3d::operator==(float d) const {
    return (
                (entry[0] == d) &&
            (entry[1] == d) &&
            (entry[2] == d));
}

inline int MyVector3d::operator!=(float d) const {
    return (
                (entry[0] != d) ||
            (entry[1] != d) ||
            (entry[2] != d));
}

//-------------------------------------------------------------------

inline MyVector3d& MyVector3d::operator+=(float d) {
    entry[0] += d;
    entry[1] += d;
    entry[2] += d;
    return (*this);
}

inline MyVector3d& MyVector3d::operator-=(float d) {
    entry[0] -= d;
    entry[1] -= d;
    entry[2] -= d;
    return (*this);
}

inline MyVector3d& MyVector3d::operator*=(float d) {
    entry[0] *= d;
    entry[1] *= d;
    entry[2] *= d;
    return (*this);
}

inline MyVector3d& MyVector3d::operator/=(float d) {
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

inline MyVector3d operator+(const MyVector3d& a,float b){
    return MyVector3d(a.entry[0] + b, a.entry[1] + b, a.entry[2] + b);
}

inline MyVector3d operator-(const MyVector3d& a,float b){
    return MyVector3d(a.entry[0] - b, a.entry[1] - b, a.entry[2] - b);
}

inline MyVector3d operator*(const MyVector3d& a,float b){
    return MyVector3d(a.entry[0] * b, a.entry[1] * b, a.entry[2] * b);
}

inline MyVector3d operator+(float a,const MyVector3d& b){
    return MyVector3d(a + b.entry[0], a + b.entry[1], a + b.entry[2]);
}

inline MyVector3d operator-(float a,const MyVector3d& b){
    return MyVector3d(a - b.entry[0], a - b.entry[1], a - b.entry[2]);
}

inline MyVector3d operator*(float a,const MyVector3d& b){
    return MyVector3d(a * b.entry[0], a * b.entry[1], a * b.entry[2]);
}

inline float length(const MyVector3d& a) {
    return sqrt(a.entry[0] * a.entry[0] + a.entry[1] * a.entry[1] + a.entry[2]
            * a.entry[2]);
}

inline void normalize(MyVector3d& a) {
    register float m = length(a);
    if (m != 0) a *= (1/m);
}

/* Dot product */
inline float dot(const MyVector3d& a,const MyVector3d& b) {
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
