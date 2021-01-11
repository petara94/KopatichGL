#include "variables.h"

// угол поворота камеры
float angleX = 3.145f, angleY = 1.65f;

// старый угол поворота камеры
float preAngleX = 0.0f, preAngleY = 0.0f;

// удаление камеры от центра
float R = 30.0f;

// XYZ позиция камеры
float y = R * cosf(angleY),
    x = R * cosf(angleX),
    z = R * sinf(angleX);

// Позиция солнца
float LightX = 10.0f, LightY = 10.0f, LightZ = 5.0f;

// Старые координаты
int preMousePosX = 0, preMousePosY = 0;

// состаяние левой кнопки
int LeftKeyDown = 1;

GLuint texture = -1;