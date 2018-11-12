#ifndef LICOPENGLWIDGET_H
#define LICOPENGLWIDGET_H

#include <iostream>
#include <QWidget>
#include <QGLWidget>
#include <QtWidgets>
#include <QtOpenGL>

#include <gl/GL.h>
#include <gl/GLU.h>

class LICOpenGLWidget : public QGLWidget{
    Q_OBJECT
public:
     LICOpenGLWidget(QWidget *parent = 0);
     ~LICOpenGLWidget();

signals:

public slots:

protected:
     void initializeGL();
     void paintGL();
     void resizeGL(int w, int h);

     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);

     void keyPressEvent(QKeyEvent *event);
};

#endif // LICOPENGLWIDGET_H
