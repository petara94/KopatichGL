#include "variables.h"

GLuint getTexFromImage(const char *filename)
{
    imagemyGl image;
    GLuint texture;

    FILE *file;

    file = fopen(filename, "rb");

    if (file == NULL)
        return -1;

    image.data = (unsigned char *)malloc(image.width * image.height * 4);
    fseek(file, 135, SEEK_SET);
    fread(image.data, image.width * image.height * 4, 1, file);
    fclose(file);

    for (int i = 0; i < image.width * image.height; ++i)
    {
        int index = i * 4;
        unsigned char B, R;
        B = image.data[index];
        R = image.data[index + 2];

        image.data[index] = R;
        image.data[index + 2] = B;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, image.width, image.height, GL_RGBA, GL_UNSIGNED_BYTE, image.data);

    free(image.data);

    return texture;
}