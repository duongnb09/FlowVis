#include "LICOpenGLWidget.h"

LICOpenGLWidget::LICOpenGLWidget(QWidget *parent) : QGLWidget(parent)
{

}

LICOpenGLWidget::~LICOpenGLWidget()
{

}

void LICOpenGLWidget::initializeGL()
{
    glClearColor(1, 1, 1, 1);
    glDrawBuffer(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

void LICOpenGLWidget::paintGL()
{

}

void LICOpenGLWidget::resizeGL(int width, int height)
{

}

void LICOpenGLWidget::mousePressEvent(QMouseEvent *event)
{

}

void LICOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{

}

void LICOpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{

}

void LICOpenGLWidget::keyPressEvent(QKeyEvent *event)
{

}
