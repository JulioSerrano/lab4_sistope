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
        //constructor
        EscalaDeGrises( BufferImagen &buf, BufferImagen &buf2, int c) : buffer(buf),bufferSalida(buf2), cantidad_imagenes(c) {}

        /*
        *Entrada: Una imagen
        *Salida: La imagen modificada en esacala de grises
        *Resumen: Función que transforma cada uno de los pixeles a escala de grises.
        */
        Imagen gris(Imagen img){

            for(int i =0; i< img.getInfo().getImgsize(); i = i + (img.getInfo().getBpp()/8)){
                int gris = img.getImgdata()[i] * 0.3 + img.getImgdata()[i+1] * 0.59 + img.getImgdata()[i+2] * 0.11;
                img.getImgdata()[i] = gris;
                img.getImgdata()[i+1] = gris;
                img.getImgdata()[i+2] = gris;
            }
            return img;
        }
};
