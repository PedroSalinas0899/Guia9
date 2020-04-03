#include <iostream>

using namespace std;

typedef struct _Nodo{
    int n;
    struct _Nodo *sig;
} Nodo;

class Hash{

    public:
		
        int hash(int );
        int hash_alternativo(int );
        void reasignacion_prueba_lineal(int *, int , int);
        void reasignacion_lineal(int *, int , int );
        void reasignacion_prueba_cuadratica(int *, int , int );
        void reasignacion_cuadratica(int *, int , int );
        void reasignacion_prueba_doble_direccion_hash(int *, int , int );
        void reasignacion_doble_direccion_hash(int *, int , int );
        void encadenamiento(int *, int , int );
        void arreglo_encadenamiento(Nodo *[], int *, int );
        void imprimir_encadenamiento(Nodo *[], int );
};
