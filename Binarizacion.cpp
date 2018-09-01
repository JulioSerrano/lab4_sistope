#include "uC++.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


_Task Binarizacion {
    BufferImagen &buffer;
    BufferImagen &bufferSalida;
    int umbral;
    int cantidad_imagenes;

    private:
        void main(){

            for(int i = 0 ; i < cantidad_imagenes ; i++){
                Imagen img = buffer.remove();
                img = binarizar(img);
                bufferSalida.insert(img);
            }
        }


    public:
        Binarizacion( BufferImagen &buf, BufferImagen &buf2, int u, int c) :
                buffer(buf),bufferSalida(buf2),umbral(u), cantidad_imagenes(c) {}

        Imagen binarizar(Imagen img){
            for(int i =0; i< img.getInfo().getImgsize(); i = i + (img.getInfo().getBpp()/8)){
                if(img.getImgdata()[i] > umbral){
                    img.getImgdata()[i]=255;
                    img.getImgdata()[i+1]=255;
                    img.getImgdata()[i+2]=255;
                }
                else{
                    img.getImgdata()[i]=0;
                    img.getImgdata()[i+1]=0;
                    img.getImgdata()[i+2]=0;
                }
            }
            return img;
        }
};
