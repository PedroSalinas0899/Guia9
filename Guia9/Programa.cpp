#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "Hash.h"

using namespace std;

void imprimir(int *Arreglo, int N){
    cout << endl;
    cout << "---Arreglo---" << endl;
    for (int i = 0; i < N; i++){
        cout << "[" << i << "]" << " = " << Arreglo[i] << endl;
    }
    cout << endl;
}

//Funcion principal
int main(int argc, char *argv[]){

    Hash *objeto = new Hash();
    
    int tamanio = 20;
    int *Arreglo = new int[tamanio];

    int opcion;
    int dato;

    int valor_hash;

    string parametro = argv[1];

    if (argc < 2){
        cout << "Falta el parametro de colisiones." << endl;
    }
    else {
        if (parametro == "L" or parametro == "C" or parametro == "D" or parametro == "E"){
            system("clear");
            do {
                cout << "1---Ingresar numero al arreglo---" << endl;
                cout << "2---Buscar numero en el arreglo---" << endl;
                cout << "3---Salir" << endl;
                cin >> opcion;
                system("clear");

                switch(opcion){
                    case 1: 
                        cout << "Ingrese un numero: " << endl;
                        cin >> dato;

                        valor_hash = objeto->hash(dato);

                        if (Arreglo[valor_hash] == '\0'){
                            Arreglo[valor_hash] = dato;

                            imprimir(Arreglo, tamanio);

                        }
                        else {
                            cout << "Se ha producido una colision en la posicion " << valor_hash << endl;

                            if (parametro == "L"){
                                objeto->reasignacion_prueba_lineal(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                            else if (parametro == "C"){
                                objeto->reasignacion_prueba_cuadratica(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                            else if (parametro == "D"){
                                objeto->reasignacion_prueba_doble_direccion_hash(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                            else if (parametro == "E"){
                                objeto->encadenamiento(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                        }
                
                        break;

                    case 2:
                        cout << "Ingrese un numero: " << endl;
                        cin >> dato;

                        valor_hash = objeto->hash(dato);

                        if (Arreglo[valor_hash] == dato){
                            cout << "Dato se encuentra en la posicion " << valor_hash << endl;
                            imprimir(Arreglo, tamanio);
                        }
                        else {
                            if (parametro == "L"){
                                objeto->reasignacion_lineal(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                            else if (parametro == "C"){
                                objeto->reasignacion_cuadratica(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                            else if (parametro == "D"){
                                objeto->reasignacion_doble_direccion_hash(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                            else if (parametro == "E"){
                                objeto->encadenamiento(Arreglo, tamanio, dato);
                                imprimir(Arreglo, tamanio);
                            }
                        }

                        break;
                    
                    case 3:
                    
                        break;

                    default:
                        cout << "Opcion no valida. " << endl;
                        
                        break;
                }

            }while (opcion != 3);
        }
        else {
            cout << "El parametro de colisiones no es valido." << endl;
            
        }
    }

    return 0;
}