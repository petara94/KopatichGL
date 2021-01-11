#include "variables.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Light();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    double aspect = (double)viewport[2] / (double)viewport[3];
    gluPerspective(60, aspect, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // move back a bit
    glTranslatef(0, 0, -R);
    gluLookAt(0.0f, 0.0f, 0.0f,
              x, y, z,
              0.0f, 1.0f, 0.0f);

    // Солнце
    glPushMatrix();
    glTranslatef(LightX, LightY, LightZ);
    glColor3ub(242, 255, 151);
    glutSolidSphere(1, 200, 200);
    glPopMatrix();

    // Пол
    glPushMatrix();
    glTranslatef(0, -1007, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(27, 154, 52);
    //glutSolidSphere(1000, 500, 500);
    //glutSolidCylinder(40, 10, 10, 100);
    glPopMatrix();

    // Начало головы

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(4, 0, 2);
    glRotatef(90, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    GLUquadricObj *quadObj;
    glEnable(GL_TEXTURE_2D);
        quadObj = gluNewQuadric();
        gluQuadricTexture(quadObj, GL_TRUE);
        gluQuadricDrawStyle(quadObj, GLU_FILL);
        gluSphere(quadObj, 5, 200, 200);
        gluDeleteQuadric(quadObj);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 4, 5);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glColor3ub(255, 105, 0);
    glutSolidTorus(0.6f, 0.7f, 200, 200);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 4, -1);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glColor3ub(255, 105, 0);
    glutSolidTorus(0.6f, 0.7f, 200, 200);
    glPopMatrix();
    // Конец головы

    // Шляпа
    glPushMatrix();
    glTranslatef(4, 5, 2);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3ub(240, 249, 5);
    glutSolidCylinder(2.5, -0.2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 5.2, 2);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3ub(240, 249, 5);
    glutSolidCylinder(1.5, -1.0, 100, 100);
    glPopMatrix();
    // Конец шляпы

    // Лапы
    glPushMatrix();
    glTranslatef(4, 0.5f, 5);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glColor3ub(255, 105, 0);
    glutSolidCylinder(0.5, 5.0, 100, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0.5f, -1);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glColor3ub(255, 105, 0);
    glutSolidCylinder(0.5, -5.0, 100, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -3.5, 0.5);
    glRotatef(120.0f, 1.0f, 0.0f, 0.0f);
    glColor3ub(255, 105, 0);
    glutSolidCylinder(0.5, 5.0, 100, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -8, 6);
    glRotatef(-120.0f, 1.0f, 0.0f, 0.0f);
    glColor3ub(255, 105, 0);
    glutSolidCylinder(0.5, 5.0, 100, 1);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(-1.2, w, h, 1.2, -1, 1);

    // модельная матрица единичная

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}