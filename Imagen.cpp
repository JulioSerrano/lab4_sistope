#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
using std::string;

class Imagen {
    BMPInfoHeader info;
    unsigned char *imgdata;
    int n_imagen;


    public:
        Imagen(){

        }
        
        Imagen(BMPInfoHeader info1, unsigned char *imgdata1){
            info = info1;
            imgdata = imgdata1;
        }

        BMPInfoHeader getInfo(){
            return info;
        }

        unsigned char * getImgdata(){
            return imgdata;
        }

        int getN_imagen(){
            return n_imagen;
        }

        void setN_imagen(int n){
            n_imagen = n;
        }




};
