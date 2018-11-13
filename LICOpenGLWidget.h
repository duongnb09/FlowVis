#ifndef LICOPENGLWIDGET_H
#define LICOPENGLWIDGET_H

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <QWidget>
#include <QGLWidget>
#include <QtWidgets>
#include <QtOpenGL>

#include <gl/GL.h>
#include <gl/GLU.h>
#include <VectorField/VectorFieldInterface.h>
#include <VectorField/DoubleGyreVectorField.h>

using namespace std;
class LICOpenGLWidget : public QGLWidget{
    Q_OBJECT
public:
     LICOpenGLWidget(QWidget *parent = 0);
     ~LICOpenGLWidget();

signals:

public slots:
     void updateLICData(VectorField&);
protected:
     void initializeGL();
     void paintGL();
     void resizeGL(int w, int h);

     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);

     void keyPressEvent(QKeyEvent *event);
private:
     /* -----------Functions ------ */
      void getLIC(float time);
      void renderLIC();

     /* -------- --Variables --------*/
     VectorField *vectorField;
     vector<unsigned char> licImage; // LIC texture image
     int LIC_width, LIC_height; // Width and heigth of the LIC image
     int xSampleNumb,ySampleNumb; // The number of sample points on the x and y dimension to generate the LIC texture
     float xLowBoundary, xHighBoundary, yLowBoundary, yHighBoundary; // Domain extents
     float timeWindow;
     float delta_t ;
     bool isShowOriginalVelocityField;
     bool isLICGenerated = false;

};

#endif // LICOPENGLWIDGET_H
