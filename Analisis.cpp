#include "uC++.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


_Task Analisis {
    BufferImagen &buffer;
    BufferImagen &bufferSalida;
    int umbral;
    int cantidad_imagenes;
    int flag;

    private:
        void main(){
            int count=0;
            for(int i = 0 ; i < cantidad_imagenes ; i++){
                Imagen img = buffer.remove();
                analizar(img);
                bufferSalida.insert(img);
            }
        }

    public:
        Analisis( BufferImagen &buf, BufferImagen &buf2, int u, int c,int b) :
                buffer(buf),bufferSalida(buf2),umbral(u), cantidad_imagenes(c), flag(b){}


        void analizar(Imagen img){

            float count_black, count_white, percent_black, percent_white;
            int number_pixels = (img.getInfo().getBpp()/8);

            for(int i =0; i< img.getInfo().getImgsize(); i = i + number_pixels ){
                if(img.getImgdata()[i] == 0){
                    count_black++;
                }
                else{
                    count_white++;
                }
            }

            percent_black =(count_black / (img.getInfo().getImgsize() / number_pixels))*100;
            percent_white =(count_white / (img.getInfo().getImgsize() / number_pixels))*100;

            if(flag==1){
                if(percent_black > umbral){
                    cout << "|   imagen_" << img.getN_imagen() <<  "    |         yes        |" << endl;
                }
                else{
                    cout << "|   imagen_" << img.getN_imagen() <<  "    |         no         |" << endl;
                }
            }
        }
};
