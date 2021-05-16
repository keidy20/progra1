#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

//prototipos de funciones
void menu();
void mostrarCola(Nodo*&, Nodo*&, Nodo*&);
void insertarCola(Nodo*&, Nodo*&, int);
bool cola_vacia(Nodo* frente);
void eliminarCola(Nodo*&, Nodo*&, int&);
void insertarPila(Nodo*& pila, int n);
void ingresarElementos(Nodo*&, Nodo*&);
void mostrarPila(Nodo*& pila);
void eliminarDatoPila(Nodo*&, int&);
int atendidos = 0;

int main() {
	Nodo* frente = NULL;
	Nodo* fin = NULL;
	Nodo* pila = NULL;

	menu();



	system("pause");
	return 0;
}

void menu() {
	int opc;


	Nodo* frente = NULL;
	Nodo* fin = NULL;
	Nodo* pila = NULL;
	char res;

	do {
		cout << "\t.:MENU:.\n";
		cout << "1. Ingresar elementos a la cola" << endl;
		cout << "2. Atender los elementos de la cola" << endl;
		cout << "3. Ver los elementos ingresados a la pila" << endl;
		cout << "4. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:

			ingresarElementos(frente, fin);
			cout << "Se han ingresado exitosamente los clientes" << endl;


			system("pause");

			break;

		case 2:

			mostrarCola(frente, fin, pila);

			cout << "Se han atendido exitosamente a los clientes" << endl;


			system("pause");

			break;

		case 3:

			mostrarPila(pila);

			cout << "Se ha atendido la cantidad de: "<< atendidos <<" clientes"<< endl;


			system("pause");

			break;

		case 4:

			cout << "\n\tHA SALIDO EXITOSAMENTE...." << endl;
			system("pause");

			break;
		}
		system("cls");
	} while (opc != 3);
}


//funcion para mostrar
void mostrarCola(Nodo*& frente, Nodo*& fin, Nodo*& pila)
{
	cout << endl << endl << endl << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|                                                                             |" << endl;
	cout << "---------------------------- SIMULADOR DE UN BANCO ----------------------------" << endl;
	cout << endl;
	cout << "\t     CAJA1" "\t     CAJA2" "\t     CAJA3" "\t     CAJA4" << endl;
	cout << endl;

	Nodo* aux = frente;
	if (frente != NULL) {
		int cont = 0;
		while (frente != NULL) {
			cont++;
			printf("\t""%8d", frente->dato);

			if (cont % 4 == 0) {
				printf("\n");
			}
			frente = frente->siguiente;
		}
		frente = aux;
		Sleep(2000);
		system("cls");
		for (int i = 0; i < 4; i++) {
			if (frente != NULL) {
				insertarPila(pila, frente->dato);
				eliminarCola(frente, fin, frente->dato);
			}
			else {
				break;
			}
			
		}

		mostrarCola(frente, fin, pila);

	}

}

//funcion para mostrar pila
void mostrarPila(Nodo*& pila) {
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|                                                                             |" << endl;
	cout << "---------------------------- SIMULADOR DE UN BANCO ----------------------------" << endl;
	cout << endl;
	cout << "\t     | PILA1 |" "\t     | PILA2 |" "\t     | PILA3 |" "\t     | PILA4 |" << endl;
	cout << endl;

	Nodo* auxiliar = pila;
	if (pila != NULL) {
		int cont = 0;
		while (pila != NULL) {
			cont++;
			
			printf("\t""%8d", pila->dato);

			if (cont % 4 == 0) {
				printf("\n");
			}
			pila = pila->siguiente;

		}

		pila = auxiliar;

		Sleep(2000);
		system("cls");
		for (int i = 0; i < 4; i++) {
			if (pila != NULL) {
				atendidos++;
				eliminarDatoPila(pila, pila->dato);
			}
			else {
				break;
			}
			
		}

		mostrarPila(pila);
	}
	
}


//Funcion para mostrar los elementos que se estan insertando a la cola
void ingresarElementos(Nodo*& frente, Nodo*& fin) {

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|                                                                             |" << endl;
	cout << "---------------------------- SIMULADOR DE UN BANCO ----------------------------" << endl;
	cout << endl;
	cout << "\t     CAJA1" "\t     CAJA2" "\t     CAJA3" "\t     CAJA4" << endl;
	cout << endl;

	srand(time(NULL));
	int dato = 200;

	for (int i = 1; i <= dato; i++) {

		int num = (1 + (rand() % 90));
		printf("\t""%8d", num);


		if (i % 4 == 0) {
			printf("\n");
			Sleep(1000);
		}

		insertarCola(frente, fin, num);

	}
	system("pause");

}

//funicon para insertar elementos en la cola
void insertarCola(Nodo*& frente, Nodo*& fin, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	if (cola_vacia(frente)) {
		frente = nuevo_nodo;
	}
	else {
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}
//funcion para determinar si la cola esta vacia
bool cola_vacia(Nodo* frente) {
	return (frente == NULL) ? true : false;
}
//funcion para eliminar de la cola
void eliminarCola(Nodo*& frente, Nodo*& fin, int& n) {
	n = frente->dato;
	Nodo* aux = frente;
	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente = frente->siguiente;
	}
	delete aux;
}

void insertarPila(Nodo*& pila, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;

}

void eliminarDatoPila(Nodo*& pila, int &dato)
{
	Nodo* aux = pila;
	dato = aux->dato;
	pila = aux->siguiente;
	delete aux;
}