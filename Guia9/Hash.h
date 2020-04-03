#include <iostream>

using namespace std;

typedef struct _Nodo{
    int n;
    struct _Nodo *sig;
} Nodo;

class Hash{

    public:
		//Metodo hash principal
        int hash(int );
        //Metodo hash auxiliar
        int hash_alternativo(int );
        //Arreglar colisiones por prueba lineal
        void reasignacion_prueba_lineal(int *, int , int);
        void reasignacion_lineal(int *, int , int );
        //Arreglar colisiones por prueba cuadratica
        void reasignacion_prueba_cuadratica(int *, int , int );
        void reasignacion_cuadratica(int *, int , int );
        //Arreglar colisiones por doble direccion hash
        void reasignacion_prueba_doble_direccion_hash(int *, int , int );
        void reasignacion_doble_direccion_hash(int *, int , int );
        //Arreglar colisiones por encadenamiento
        void encadenamiento(int *, int , int );
        //Metodo auxiliares para encadenamiento
        void arreglo_encadenamiento(Nodo *[], int *, int );
        void imprimir_encadenamiento(Nodo *[], int );
};
