#include <cmath>
#include <iostream>
#include "variables.h"

void init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_TEXTURE_2D);

    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
}

void Light()
{
    GLfloat pos1[] = {LightX, LightY, LightZ, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, pos1);
}

void timer(int extra)
{
    glutPostRedisplay();
    glutTimerFunc(1, timer, 0);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitWindowSize(1080, 720);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Bear");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(pressKey);
    glutKeyboardUpFunc(releaseKey);

    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);

    glutTimerFunc(0, timer, 0);

    glEnable(GL_DEPTH_TEST);

    texture = getTexFromImage("Kopatich.bmp");

    if (texture == -1)
    {
        std::cout << "SOIL fail\n";
        return -1;
    }

    glutMainLoop();
    return 0;
}