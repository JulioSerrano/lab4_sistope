#include <vector>

using std::vector;

//buffer que contendrá las imagenes
_Monitor BufferImagen {
    uCondition full, empty;
    int front, back, count,size;
    vector<Imagen> imagenes;


    public:
        //constructor
        BufferImagen() : front(0), back(0),count(0){}

        _Nomutex int query(){
            return count;
        }

        //funcion que inserta una imagen en el buffer
        void insert(Imagen imagen){
            if(count == size) empty.wait();

            imagenes[back] = imagen;
            back = (back + 1)% size;
            count++;
            full.signal();
        }

        //funcion que obtiene una imagen del buffer
        Imagen remove(){
            if(count == 0) full.wait();

            Imagen imagen = imagenes[front];
            front = (front + 1)% size;
            count--;
            empty.signal();
            return imagen;
        }

        //funcion que da tamaño al buffer
        void setSize(int cantidad_imagenes){
            size = cantidad_imagenes;
            imagenes.reserve(cantidad_imagenes);
        }



};
