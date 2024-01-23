/*
Pérez Moreno Sergio Gabriel
Ingenieria en Computacion Inteligente
Estructuras Computacionales

Instrucciones:

Elaborar  la implementación de las siguientes operaciones fundamentales de una lista doblemente enlazada

1) Inserción de nodos a la lista

2) Borrado de nodos a la lista

3) Búsqueda de nodos en la lista

4)Borrar todos los nodos de una lista

5) Despliegue de los nodos de la lista de principio a fin y de atrás hacia adelante.
*/

#include <iostream>
#include <clocale>
#include <conio.h>

using namespace std;

struct nodo{
	int dato;
	nodo *anterior;
	nodo *siguiente;
} *primero, *ultimo;

void insertar();
void buscar();
void eliminar();
void eliminartodo();
void mostrar_IF();
void mostrar_FI();

int main()
{
	setlocale(LC_ALL, "spanish");
	int op = 0;
	do{
		cout<<" ---MENÚ--- "<<endl;
		cout<<"1. Insertar elementos la lista. "<<endl;
		cout<<"2. Borrar nodo de la lista. "<<endl;
		cout<<"3. Buscar nodo en la lista. "<<endl;
		cout<<"4. Mostrar de inicio a fin. "<<endl;
		cout<<"5. Mostrar de fin a incio. "<<endl;
		cout<<"6. Salir. "<<endl;
		cout<<"¿Qué desea hacer? "<<endl;
		cin>>op;
		switch(op){
			case 1:
				insertar();
				cout<<"\n";
				break;
				
			case 2:
				eliminar();
				cout<<"\n";
				break;
			
			case 3:
				buscar();
				cout<<"\n";
				break;
				
				
			case 4:
				mostrar_IF();
				cout<<"\n";
				break;
				
			case 5:
				mostrar_FI();
				cout<<"\n";
				break;
				
			case 6:
				cout<<"Saliendo del programa. "<<endl;
				break;
				
			default:
				cout<<"Opción inválida, ingrese otra respuesta. "<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(op != 6);
	return 0;
}

void insertar()
{
	nodo *nuevo = new nodo();
	cout<<"Ingrese elemento: ";
	cin>>nuevo->dato;

	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = primero;
	}
	else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->anterior = ultimo;
		ultimo = nuevo;
	}
	cout<<"Elemento insertado correctamente. "<<endl;
}

void eliminar()
{
	nodo *actual = new nodo();
	actual = primero;
	nodo *atras = new nodo;
	atras = NULL;
	bool found = false;
	int elemento = 0;
	
	cout<<"Ingrese el elemento que desee eliminar: ";
	cin>>elemento;
	
	if(primero != NULL){
		while(actual != NULL && found != true){
			if(actual->dato == elemento){
				cout<<"Elemento encontrado. "<<endl;
				if(actual == primero){
					primero = primero->siguiente;
					primero->anterior = NULL;
				}
				else if(actual == ultimo){
					atras->siguiente = NULL;
					ultimo = atras;
				}
				else{
					atras->siguiente = actual->siguiente;
					actual->siguiente->anterior = atras;
				}
				cout<<"Elemento eliminado de la lista. "<<endl;
				found = true;
			}
			atras = actual;
			actual = actual->siguiente;
		}
		if(found == false){
			cout<<"El elemento no está dentro de la lista. "<<endl;
		}
	}
	else{
		cout<<"La lista está vacia. "<<endl;
	}
}

void buscar()
{
	nodo *actual = new nodo();
	actual = primero;
	int cont = 0, elemento = 0;
	bool found = false;
	
	cout<<"¿Cuál elemento desea buscar? "<<endl;
	cin>>elemento;
	
	if(primero != NULL){
		while(actual != NULL && found != true){
			cont++;
			if(actual->dato == elemento){
				cout<<"Elemento ("<<elemento<<") encontrado. "<<endl;
				cout<<"se encuentra en la posicion "<<cont<<endl;
				found = true;
			}
			actual = actual->siguiente;
		}
		if(found == false){
			cout<<"El elemento no se encuentra dentro de la lista. "<<endl;
		}
	}
	else{
		cout<<"La lista está vacia. "<<endl;
	}
}
//Funcion para mostrar los elementos de inicio a fin acorde a como los ingresó el usuario
void mostrar_IF()
{
	nodo *actual = new nodo();
	actual = primero;
	if(primero != NULL){
		cout<<"--- ELEMENTOS DE INICIO A FIN --- "<<endl;
		while(actual != NULL){
			cout<<" - "<<actual->dato;
			actual = actual->siguiente;
		}
	}
	else{
		cout<<"La lista está vacia. "<<endl;
	}
}
//Funcion para mostrar los elementos de fin a inicio
void mostrar_FI()
{
	nodo *actual = new nodo();
	actual = ultimo;
	if(primero != NULL){
		cout<<"--- ELEMENTOS DE FIN A INICIO --- "<<endl;
		while(actual != NULL){
			cout<<" - "<<actual->dato;
			actual = actual->anterior;
		}
	}
	else{
		cout<<"La lista está vacia. "<<endl;
	}
}
