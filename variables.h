#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H

#include "structs.h"
#include "funcs.h"
#include "math.h"

// угол поворота камеры
extern float angleX, angleY;

// старый угол поворота камеры
extern float preAngleX, preAngleY;

// удаление камеры от центра
extern float R;

// XYZ позиция камеры
extern float y, x, z;

// Позиция солнца
extern float LightX, LightY, LightZ;

// Старые координаты
extern int preMousePosX, preMousePosY;

// состаяние левой кнопки
extern int LeftKeyDown;

extern GLuint texture;

#endif