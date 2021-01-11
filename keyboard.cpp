#include "variables.h"

void pressKey(unsigned char key, int xx, int yy)
{
    switch (key)
    {
    case 'w':
        LightX += -1.5f;
        break;
    case 's':
        LightX += 1.5f;
        break;
    case 'a':
        LightZ += 1.5f;
        break;
    case 'd':
        LightZ += -1.5f;
        break;
    case GLUT_ACTIVE_CTRL:
        printf("CTRL\n");
        break;
    default:
        break;
    }
}

void releaseKey(unsigned char key, int x, int y)
{
}