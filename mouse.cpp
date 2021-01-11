#include "variables.h"

void xyzCalc(int mx, int my)
{
    angleX = preAngleX + (float)(mx - preMousePosX) * 0.005;
    angleY = preAngleY + (float)(my - preMousePosY) * 0.005;

    printf("x = %lf | y = %lf | z = %lf  |  aX = %lf | aY = %lf\n", x, y, z, angleX, angleY);

    y = R * cosf(angleY);
    x = R * cosf(angleX);
    z = R * sinf(angleX);
}

void mouseMove(int mx, int my)
{

    if (!LeftKeyDown)
    {
        xyzCalc(mx, my);
    }
}

void mouseClick(int key, int IsUp, int mx, int my)
{

    switch (key)
    {
    case 0:
        preMousePosX = mx;
        preMousePosY = my;
        LeftKeyDown = IsUp;
        if (!LeftKeyDown) // UP
        {
            preAngleX = angleX;
            preAngleY = angleY;
            preMousePosX = mx;
            preMousePosY = my;
            xyzCalc(mx, my);
        }
        break;
    case 4:
        if (LeftKeyDown)
        {
            preAngleX = angleX;
            preAngleY = angleY;
            preMousePosX = mx;
            preMousePosY = my;
            R += 0.5;
            xyzCalc(mx, my);
        }
        break;
    case 3:
        if (LeftKeyDown)
        {
            preAngleX = angleX;
            preAngleY = angleY;
            preMousePosX = mx;
            preMousePosY = my;
            if (R > 0.5)
                R -= 0.5;
            xyzCalc(mx, my);
        }
        break;
    default:
        break;
    }
    printf("key = %d stat = %d - x = %lf y = %lf R = %lf\n", key, IsUp, x, z, R);
}