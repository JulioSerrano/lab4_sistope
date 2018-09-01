#include <vector>

using std::vector;

_Monitor BufferImagen {
    uCondition full, empty;
    int front, back, count,size;
    vector<Imagen> imagenes;


    public:
        BufferImagen() : front(0), back(0),count(0){}

        _Nomutex int query(){
            return count;
        }

        void insert(Imagen imagen){
            if(count == size) empty.wait();

            imagenes[back] = imagen;
            back = (back + 1)% size;
            count++;
            full.signal();
        }

        Imagen remove(){
            if(count == 0) full.wait();

            Imagen imagen = imagenes[front];
            front = (front + 1)% size;
            count--;
            empty.signal();
            return imagen;
        }


        void setSize(int cantidad_imagenes){
            size = cantidad_imagenes;
            imagenes.reserve(cantidad_imagenes);
        }



};
