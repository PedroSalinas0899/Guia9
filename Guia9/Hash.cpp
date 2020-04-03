#include <iostream>

#include "Hash.h"

using namespace std;
//Metodos de la funcion "Hash"
int Hash::hash(int dato){
    int valor_hash = (dato%19) + 1;
    
    return valor_hash;
}

int Hash::hash_alternativo(int dato){
    int valor_hash = (dato%77)%20 + 1;

    return valor_hash;
}

void Hash::reasignacion_prueba_lineal(int *Arreglo, int tamanio, int dato){
    int D, DX, contador;
    D = hash(dato);

    if (Arreglo[D] != '\0' and Arreglo[D] == dato){
        cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;
    }
    else {
        DX = D + 1;
        contador = 1;
        
        while (DX != D and DX <= tamanio and Arreglo[DX] != '\0' and Arreglo[DX] == dato){
            DX = DX + 1;
            
            if (DX == tamanio + 1){
                DX = 1;
            }
            contador = contador + 1;
        }
        if (Arreglo[DX] == '\0'){
            Arreglo[DX] = dato;
            cout << "El dato se mueve a la posicion " << DX << " del arreglo " << endl;
        }
        if (contador == tamanio){
            cout << "El arreglo se encuentra lleno" << endl;
        }
    }
}

void Hash::reasignacion_lineal(int *Arreglo, int tamanio, int dato){
    int D, DX;
    D = hash(dato);
    
    if (Arreglo[D] != '\0' and Arreglo[D] == dato){
        cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;
    }
    else {
        DX = D + 1;
        
        while (DX != D and DX <= tamanio and Arreglo[DX] != '\0' and Arreglo[DX] == dato){
            DX = DX + 1;
            
            if (DX == tamanio + 1){
                DX = 1;
            }
        }
        if (Arreglo[DX] == '\0' or DX == D){
            cout << "Dato no encontrado en el arreglo" << endl;
        }
        else {
            cout << "El dato se mueve a la posicion " << DX << " del arreglo " << endl;
        }
    }
}

void Hash::reasignacion_prueba_cuadratica(int *Arreglo, int tamanio, int dato){
    int D, DX, i;
    D = hash(dato);
    
    if (Arreglo[D] != '\0' and Arreglo[D] == dato){
        cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;
    }
    else {
        i = 0;
        DX  = D + (i*i);

        while (Arreglo[DX] != '\0' and Arreglo[DX] != dato){
            i = i + 1;
            DX  = D + (i*i);

            if (DX > tamanio){
                i = 0;
                DX = 1;
                D = 1;
            }
        }
        if (Arreglo[DX] == '\0'){
            Arreglo[DX] = dato;
            cout << "Dato movido a la posicion " << DX << " del arreglo " << endl;
        }
        else {
            cout << "Dato encontrado en la posicion " << DX << " del arreglo " << endl;
        }
    }
}

void Hash::reasignacion_cuadratica(int *Arreglo, int tamanio, int dato){
    int D, DX, i;
    D = hash(dato);
    
    if (Arreglo[D] != '\0' and Arreglo[D] == dato){
        cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;
    }
    else {
        i = 1;
        DX  = D + (i*i);

        while (Arreglo[DX] != '\0' and Arreglo[DX] != dato){
            i = i + 1;
            DX  = D + (i*i);

            if (DX > tamanio){
                i = 0;
                DX = 1;
                D = 1;
            }
        }
        if (Arreglo[DX] == '\0'){
            cout << "Dato no encontrado" << endl;
        }
        else {
            cout << "Dato encontrado en la posicion " << DX << " del arreglo " << endl;
        }
    }
}

void Hash::reasignacion_prueba_doble_direccion_hash(int *Arreglo, int tamanio, int dato){
    int D, DX;
	D = hash(dato);
	
    if (Arreglo[D] != '\0' and Arreglo[D] == dato){
        cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;	}			
    else{
		DX = hash_alternativo(D);
		
        while (DX <= tamanio and DX != D and Arreglo[DX] != dato and Arreglo[DX] != '\0'){
			DX = hash_alternativo(DX);
		}
		
        if (Arreglo[DX] == '\0' or Arreglo[DX] != dato){
			Arreglo[DX] = dato;
			
            if(DX == tamanio){
                cout << "El arreglo se encuentra lleno" << endl;
			}
			else{ 
                cout << "Dato movido a la posicion " << DX << " del arreglo " << endl;
			}	
        }
		else{
            cout << "Dato encontrado en la posicion " << DX << " del arreglo " << endl;			
		}
	}    
}

void Hash::reasignacion_doble_direccion_hash(int *Arreglo, int tamanio, int dato){
    int D, DX;
	D = hash(dato);
	
    if (Arreglo[D] != '\0' and Arreglo[D] == dato){
        cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;	}			
    else{
		DX = hash_alternativo(D);
		
        while (DX <= tamanio and DX != D and Arreglo[DX] != dato and Arreglo[DX] != '\0'){
			DX = hash_alternativo(DX);
		}
        if (Arreglo[DX] == '\0' or DX == D){
            cout << "Dato no encontrado" << endl;
        }
        else {
            cout << "Dato encontrado en la posicion " << DX << " del arreglo " << endl;			
        }
    }
}

void Hash::encadenamiento(int *Arreglo, int tamanio, int dato){
    int D;
    Nodo *aux = NULL;
    Nodo *A[tamanio];

    for (int i = 0; i < tamanio; i++){
        A[i] = new Nodo();
        A[i]->sig = NULL;
        A[i]->n = '\0';
    }
    arreglo_encadenamiento(A, Arreglo, tamanio);

    D = hash_alternativo(dato);

    if (Arreglo[D] != '\0' and Arreglo[D] == dato){
        cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;			
    }
    else {
        aux = A[D]->sig;

        while (aux != NULL and aux->n != dato){
            aux = aux->sig;
        }
        if (aux == NULL){
            cout << "Dato no encontrado" << endl;
        }
        else {
            cout << "Dato encontrado en la posicion " << D << " del arreglo " << endl;			
        }
    }
    imprimir_encadenamiento(A,D);
}

void Hash::arreglo_encadenamiento(Nodo *A[], int *Arreglo, int tamanio){
    for (int i = 0; i < tamanio; i++){
        A[i]->n = Arreglo[i];
        A[i]->sig = NULL;
    }
}

void Hash::imprimir_encadenamiento(Nodo *A[], int D){
    Nodo *aux = NULL;
    aux = A[D];

    cout << "Lista enlazada:" << endl;

    while (aux != NULL){
        if (aux->n != '\0'){
            cout << aux->n << " -->";
        }
        aux = aux->sig;
    }
    cout << endl;
}
