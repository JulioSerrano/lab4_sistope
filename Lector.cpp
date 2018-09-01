#include "BMPInfoHeader.cpp"
#include "Imagen.cpp"
#include "uC++.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BufferImagen.cpp"

using std::cout;
using std::endl;
using std::string;

// producer
_Task Lector {

    BufferImagen &buffer;
    int cantidad_imagenes;

    private:
        void main(){
            string imagen= "imagen_";
            string bmp = ".bmp";
            for(int i = 1; i <= cantidad_imagenes; i++){
                string name = imagen + std::to_string(i) + bmp;
                Imagen img = readBmp(name);
                img.setN_imagen(i);
                buffer.insert(img);
            }

        }
    public:

        Lector( BufferImagen &buf, int cant) : buffer(buf), cantidad_imagenes(cant) {}

        Imagen readBmp(string filename){
            FILE* fp = fopen(filename.c_str(), "rb");
            if(fp == NULL){
                exit(-1);
            }
            uint16_t  type,planes,bpp;
            int size,reserved,offset,headersize,width,height,compress,imgsize,bpmx,bpmy,colors,imxtcolors;

            fread(&type, 2, 1, fp);
            fread(&size, 4, 1, fp);
            fread(&reserved, 4, 1, fp);
            fread(&offset, 4, 1, fp);
            fread(&headersize, 4, 1, fp);
            fread(&width, 4, 1, fp);
            fread(&height, 4, 1, fp);
            fread(&planes, 2, 1, fp);
            fread(&bpp, 2, 1, fp);
            fread(&compress, 4, 1, fp);
            fread(&imgsize, 4, 1, fp);
            fread(&bpmx, 4, 1, fp);
            fread(&bpmy, 4, 1, fp);
            fread(&colors, 4, 1, fp);
            fread(&imxtcolors, 4, 1, fp);

            imgsize = imgsize + (headersize - 40);

            unsigned char *imgdata=(unsigned char*)malloc(imgsize);

            fread(imgdata,imgsize,1, fp);

            fclose(fp);

            BMPInfoHeader b = BMPInfoHeader(type,size,reserved,offset,headersize,width,height,
                                            planes,bpp,compress,imgsize,bpmx,bpmy,colors,imxtcolors);

            Imagen i = Imagen(b,imgdata);
            return i;
        }

};
