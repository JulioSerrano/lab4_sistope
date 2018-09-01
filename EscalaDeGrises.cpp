#include "uC++.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


_Task EscalaDeGrises {
    BufferImagen &buffer;
    BufferImagen &bufferSalida;
    int cantidad_imagenes;
    private:
        void main(){

            for(int i = 0;i<cantidad_imagenes;i++){
                    Imagen img = buffer.remove();
                    img = gris(img);
                    bufferSalida.insert(img);
            }
        }
    public:
        EscalaDeGrises( BufferImagen &buf, BufferImagen &buf2, int c) : buffer(buf),bufferSalida(buf2), cantidad_imagenes(c) {}


        Imagen gris(Imagen img){

            for(int i =0; i< img.getInfo().getImgsize(); i = i + (img.getInfo().getBpp()/8)){
                int gris = img.getImgdata()[i] * 0.3 + img.getImgdata()[i+1] * 0.59 + img.getImgdata()[i+2] * 0.11;
                img.getImgdata()[i] = gris;
                img.getImgdata()[i+1] = gris;
                img.getImgdata()[i+2] = gris;
            }
            return img;
        }

        void writeBmp(Imagen img){

            string imagen= "imagen_";
            string bmp = "_salida.bmp";
            string name = imagen + std::to_string(img.getN_imagen()) +bmp;

            FILE* fp = fopen(name.c_str(), "w+");

            uint16_t type = img.getInfo().getType();
            int size = img.getInfo().getSize();
            int reserved = img.getInfo().getReserved();
            int offset = img.getInfo().getOffset();
            int headersize = img.getInfo().getHeadersize();
            int width = img.getInfo().getWidth();
            int height = img.getInfo().getHeight();
            uint16_t planes = img.getInfo().getPlanes();
            uint16_t bpp = img.getInfo().getBpp();
            int compress = img.getInfo().getCompress();
            int imgsize = img.getInfo().getImgsize();
            int bpmx = img.getInfo().getBpmx();
            int bpmy = img.getInfo().getBpmy();
            int colors = img.getInfo().getColors();
            int imxtcolors = img.getInfo().getImxtcolor();

            fwrite(&type, 2, 1, fp);
            fwrite(&size, 4, 1, fp);
            fwrite(&reserved, 4, 1, fp);
            fwrite(&offset, 4, 1, fp);
            fwrite(&headersize, 4, 1, fp);
            fwrite(&width, 4, 1, fp);
            fwrite(&height, 4, 1, fp);
            fwrite(&planes, 2, 1, fp);
            fwrite(&bpp, 2, 1, fp);
            fwrite(&compress, 4, 1, fp);
            fwrite(&imgsize, 4, 1, fp);
            fwrite(&bpmx, 4, 1, fp);
            fwrite(&bpmy, 4, 1, fp);
            fwrite(&colors, 4, 1, fp);
            fwrite(&imxtcolors, 4, 1, fp);

            fwrite(img.getImgdata(),img.getInfo().getImgsize(),1, fp);

            fclose(fp);
        }

};
