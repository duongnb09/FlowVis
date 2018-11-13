#include "LICOpenGLWidget.h"

LICOpenGLWidget::LICOpenGLWidget(QWidget *parent) : QGLWidget(parent)
{
    LIC_width = 0;
    LIC_height = 0;
    xLowBoundary = 0;
    yLowBoundary = 0;
    xHighBoundary = 0;
    yHighBoundary = 0;
    timeWindow = 0;
    delta_t = 0;
}

LICOpenGLWidget::~LICOpenGLWidget()
{

}

/* ---------------------------------------*/
/* ------- OpenGL Override functions -----*/
/* ---------------------------------------*/
void LICOpenGLWidget::initializeGL()
{
    glClearColor(1, 1, 1, 1);
    glDrawBuffer(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_FLAT);
    setMinimumSize(QSize(LIC_width, LIC_height));
}

void LICOpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glLoadIdentity();
    glTranslatef(0., 0., 0.);
    glScalef(1., 1., 1.);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    if (isLICGenerated)
        renderLIC();
}

void LICOpenGLWidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLowBoundary, xHighBoundary, yLowBoundary, yHighBoundary);

    glMatrixMode(GL_MODELVIEW);

    updateGL();
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

/* ---------------------------------------*/
/* ----------- Slot functions-------------*/
/* ---------------------------------------*/

/*
 * Update the vector field data and call the getLIC function to generate a new LIC texture
 */
void LICOpenGLWidget::updateLICData(VectorField & vField)
{
    vectorField = &vField;
    vectorField->getDomainExtents(xLowBoundary,xHighBoundary,yLowBoundary,yHighBoundary);
    vectorField->getLICSize(LIC_width,LIC_height);
    vectorField->getTimeWindow(timeWindow);
    vectorField->getDt(delta_t);
    vectorField->getSampleNumb(xSampleNumb,ySampleNumb);

    getLIC(0);
    resizeGL(LIC_width, LIC_height);
    isLICGenerated = true;
    updateGL();
}

/* ---------------------------------------*/
/* -----------Private functions-----------*/
/* ---------------------------------------*/

/*
 * Generate a LIC texture at a given time step
 */
void LICOpenGLWidget::getLIC(float time)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawBuffer(GL_BACK);
    glViewport(0, 0, (GLsizei)(LIC_width), (GLsizei)(LIC_height));
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluOrtho2D(xLowBoundary, xHighBoundary, yLowBoundary, yHighBoundary);
    float dx = (xHighBoundary - xLowBoundary) / (xSampleNumb - 1);
    float dy = (yHighBoundary - yLowBoundary) / (ySampleNumb - 1);
    float max_vx = FLT_MIN, max_vy = FLT_MIN;
    float min_vx = FLT_MAX, min_vy = FLT_MAX;

    // For some flow simulations (e.g Cylinder), we need to compute the average velocity to reveal the vortex structure
    float avgVX =0,avgVY =0;
    float vx = 0, vy = 0.;

    // Compute the average velocity
    if (!isShowOriginalVelocityField) {
        for (int i = 0; i < xSampleNumb; i++) {
            float x = xLowBoundary + dx * i;
            for (int j = 0; j < ySampleNumb; j++) {
                float y = yLowBoundary + dy * j;
                vectorField->getSpeed(x, y, time, &vx, &vy);
                avgVX += vx;
                avgVY += vy;
            }
        }
        avgVX /= (xSampleNumb*ySampleNumb);
        avgVY /= (xSampleNumb*ySampleNumb);
    }

    vector<vector<float> > velocity_x = vector<vector<float> >(xSampleNumb, vector<float>(xSampleNumb, 0));
    vector<vector<float> > velocity_y = vector<vector<float> >(xSampleNumb, vector<float>(ySampleNumb, 0));

    for (int i = 0; i < xSampleNumb; i++) {
        float x = xLowBoundary + dx * i;
        for (int j = 0; j < ySampleNumb; j++) {
            float y = yLowBoundary + dy * j;
            vectorField->getSpeed(x, y, time, &vx, &vy);

            max_vx = max(vx, max_vx);
            min_vx = min(vx, min_vx);
            max_vy = max(vy, max_vy);
            min_vy = min(vy, min_vy);
            velocity_x[i][j] = vx - avgVX;
            velocity_y[i][j] = vy - avgVY;
        }
    }

    //Get color image based on velocity
    float rgb[3] = { 0. };
    for (int i = 0; i < xSampleNumb - 1; i++) {
        float x = xLowBoundary + dx * i;
        for (int j = 0; j < ySampleNumb - 1; j++) {
            float y = yLowBoundary + dy * j;
            glBegin(GL_QUADS);
            //point 1:
            vx = velocity_x[i][j];
            vy = velocity_y[i][j];
            rgb[0] = (vx - min_vx) / (max_vx - min_vx);
            rgb[1] = (vy - min_vy) / (max_vy - min_vy);
            glColor3d(rgb[0], rgb[1], rgb[2]);
            glVertex2d(x, y);

            //point 2:
            vx = velocity_x[i][j + 1];
            vy = velocity_y[i][j + 1];
            rgb[0] = (vx - min_vx) / (max_vx - min_vx);
            rgb[1] = (vy - min_vy) / (max_vy - min_vy);
            glColor3d(rgb[0], rgb[1], rgb[2]);
            glVertex2d(x, y + dy);

            //point 3:
            vx = velocity_x[i + 1][j + 1];
            vy = velocity_y[i + 1][j + 1];
            rgb[0] = (vx - min_vx) / (max_vx - min_vx);
            rgb[1] = (vy - min_vy) / (max_vy - min_vy);
            glColor3d(rgb[0], rgb[1], rgb[2]);
            glVertex2d(x + dx, y + dy);

            //point 4:
            vx = velocity_x[i + 1][j];
            vy = velocity_y[i + 1][j];
            rgb[0] = (vx - min_vx) / (max_vx - min_vx);
            rgb[1] = (vy - min_vy) / (max_vy - min_vy);
            glColor3d(rgb[0], rgb[1], rgb[2]);
            glVertex2d(x + dx, y);
            glEnd();
        }
    }

    vector<unsigned char> vec_img; // Vector field image
    vec_img.clear();
    vec_img.resize(LIC_height*LIC_width*3);
    glReadBuffer(GL_BACK);
    glReadPixels(0, 0, LIC_width, LIC_height, GL_RGB, GL_UNSIGNED_BYTE, &vec_img[0]);

    //Noise texture, another noise texture: 255*(rand() % 32768) / 32768.0
    vector<vector<unsigned char> > noise_tex = vector<vector<unsigned char> >(LIC_height, vector<unsigned char>(LIC_width, 0));

    for (int i = 0; i < LIC_height; i++) {
        for (int j = 0; j < LIC_width; j++) {
            noise_tex[i][j] = 255 * (rand() % 32768) / 32768.0;// (rand() % 2) * 255;
        }
    }

    //Generate LIC
    int stream_len = 25; //The number of streamline integration steps

    licImage.clear();
    licImage.resize(LIC_height*LIC_width * 3);
    float dis;
    for (int i = 0; i<LIC_height; i++) {
        for (int j = 0; j<LIC_width; j++) {
            float sumColor = 0;
            int totalNumbPoint = 0;
            float vx, vy, s;
            float next_j = i + 0.5, next_i = j + 0.5;
            for (int k = 0; k <= stream_len; k++)
            {
                if (next_i >= 0 && next_i<LIC_width &&next_j >= 0 && next_j<LIC_height)
                {
                    sumColor += noise_tex[(int)next_j][(int)next_i];

                    vx = min_vx + (max_vx - min_vx)*vec_img[((int)next_j*LIC_width + (int)next_i) * 3 + 0] / 255.0;
                    vy = min_vy + (max_vy - min_vy)*vec_img[((int)next_j*LIC_width + (int)next_i) * 3 + 1] / 255.0;
                    dis = sqrt(vx*vx + vy*vy);
                    vx = vx / dis;
                    vy = vy / dis;

                    next_i = next_i + vx;
                    next_j = next_j + vy;
                    totalNumbPoint++;
                }
                else
                    break;
            }
            next_j = i + 0.5; next_i = j + 0.5;
            for (int k = 0; k <= stream_len; k++)
            {
                if (next_i >= 0 && next_i<LIC_width &&next_j >= 0 && next_j<LIC_height)
                {
                    sumColor += noise_tex[(int)next_j][(int)next_i];
                    vx = min_vx + (max_vx - min_vx)*vec_img[((int)next_j*LIC_width + (int)next_i) * 3 + 0] / 255.0;
                    vy = min_vy + (max_vy - min_vy)*vec_img[((int)next_j*LIC_width + (int)next_i) * 3 + 1] / 255.0;
                    dis = sqrt(vx*vx + vy*vy);
                    vx = vx / dis;
                    vy = vy / dis;
                    totalNumbPoint++;

                    next_i = next_i - vx;
                    next_j = next_j - vy;
                }
                else
                    break;
            }

            licImage[(i*LIC_width + j) * 3 + 0] = (unsigned char)(sumColor / totalNumbPoint);
            licImage[(i*LIC_width + j) * 3 + 1] = (unsigned char)(sumColor / totalNumbPoint);
            licImage[(i*LIC_width + j) * 3 + 2] = (unsigned char)(sumColor / totalNumbPoint);
        }
    }

}

/*
 * Render LIC texture in the OpenGL widget
 */
void LICOpenGLWidget::renderLIC(){
    try{
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glEnable(GL_TEXTURE_2D);
        glShadeModel(GL_FLAT);//GL_SMOOTH
        glEnable(GL_BLEND);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, LIC_width, LIC_height, 0,
                     GL_RGB, GL_UNSIGNED_BYTE, &licImage[0]);



        glBegin(GL_QUAD_STRIP);
        glTexCoord2f(0.0, 0.0);  glVertex2f(xLowBoundary, yLowBoundary);
        glTexCoord2f(0.0, 1.0);  glVertex2f(xLowBoundary, yHighBoundary);
        glTexCoord2f(1.0, 0.0);  glVertex2f(xHighBoundary, yLowBoundary);
        glTexCoord2f(1.0, 1.0);  glVertex2f(xHighBoundary, yHighBoundary);
        glEnd();

        glDisable(GL_TEXTURE_2D);
    } catch (...){
        cout<<"Exception occurred in renderLIC"<<endl;
    }


}
