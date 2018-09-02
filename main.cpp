#include <uC++.h>
#include <iostream>
#include <string>

#include "Lector.cpp"
#include "EscalaDeGrises.cpp"
#include "Binarizacion.cpp"
#include "Analisis.cpp"
#include "Escritor.cpp"
//#include "BufferImagen.cpp"

using std::cout;
using std::endl;
using std::string;



int main(int argc, char** argv)
{
    string str_umbral;
    string str_umbral_clas;
    string str_num_imagenes;
    string str_num_imagenes_buffer;

    int umbral = 0, umbral_clas = 0, num_imagenes = 0, b_flag = 0, num_imagenes_buffer = 0;


    int c;
    opterr = 0;
    while ((c = getopt (argc, argv, "c:u:n:B:b")) != -1)
        switch (c){
            case 'b':
                b_flag = 1;
                break;
            case 'u':
                str_umbral= optarg;
                umbral=stoi(str_umbral);
                break;
            case 'B':
                str_num_imagenes_buffer = optarg;
                num_imagenes_buffer=stoi(str_num_imagenes_buffer);
                break;
            case 'n':
                str_umbral_clas = optarg;
                umbral_clas=stoi(str_umbral_clas);
                break;
            case 'c':
                str_num_imagenes = optarg;
                num_imagenes=stoi(str_num_imagenes);
                break;
            case '?':
                if (optopt == 'c')
                    fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Opcion desconocida `-%c'.\n", optopt);
                else
                    fprintf (stderr, "Opcion de caracter desconocido `\\x%x'.\n", optopt);
                return 1;
                default:
            abort ();
    }

    //se inicializan los buffers necesarios para los procesos
    BufferImagen lector_escalaGris;
    BufferImagen escalaGris_binarizacion;
    BufferImagen binarizacion_analisis;
    BufferImagen analisis_escritor;

    //Se ingresa la cantidad de imagenes que determina el tamaño del buffer
    lector_escalaGris.setSize(num_imagenes_buffer);
    escalaGris_binarizacion.setSize(num_imagenes_buffer);
    binarizacion_analisis.setSize(num_imagenes_buffer);
    analisis_escritor.setSize(num_imagenes_buffer);

    if(b_flag==1){
        cout << "|---------------|--------------------|" << endl;
        cout << "|     image     |    nearly black    |" << endl;
        cout << "|---------------|--------------------|" << endl;
    }

    //se inician las tareas concurrentes ingresando como parametro los buffers correspondientes
    Lector lector(lector_escalaGris,num_imagenes);
    EscalaDeGrises escalaDeGrises(lector_escalaGris,escalaGris_binarizacion,num_imagenes);
    Binarizacion binarizacion(escalaGris_binarizacion, binarizacion_analisis, umbral,num_imagenes);
    Analisis analisis(binarizacion_analisis, analisis_escritor,umbral_clas,num_imagenes,b_flag);
    Escritor escritor(analisis_escritor,num_imagenes);

}
