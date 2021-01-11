#pragma once
#ifndef STRUCTS_H
#define STRUCTS_H

#define IMG_W 1000
#define IMG_H 1000

struct imagemyGl {
    int width, height;
    unsigned char *data;
    imagemyGl(){
        width = IMG_W;
        height = IMG_H;
    }
    imagemyGl(int code){
        if (code == -1){
            width = -1;
            height = -1;
        }
    }
};

#endif //STRUCTS_H