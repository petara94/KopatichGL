#pragma once
#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cstdio>
#include <GL/freeglut.h>

#include "structs.h"

// Загружает и регестрирует текстуру из файла
GLuint getTexFromImage(const char *filename);
// Инициирует различные режимы OpenGL
void init();
// Выставляет свет
void Light();
// Прорисовка сцены
void display();
// Реакция на изменение размеров окна
void reshape(int w, int h);
//
void timer(int extra);
void pressKey(unsigned char key, int xx, int yy);
void releaseKey(unsigned char key, int x, int y);
void xyzCalc(int mx, int my);
void mouseMove(int mx, int my);
void mouseClick(int key, int IsUp, int mx, int my);

#endif //FUNCS_H
