// Mysql_POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include "Cliente.h"
using namespace std;
void  menuPrincipal(Cliente c){
	int op;
		cout << "\t\t\t*******************************************" << endl;
		cout << "\t\t\t\t     .: CRUD MENU :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVO CLIENTE" << endl;
		cout << "\t\t\t 2.  LEER CLIENTE" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR CLIENTE" << endl;
		cout << "\t\t\t 4.  ELIMINAR CLIENTE" << endl;
		cout << "\t\t\t 5.  SALIR" << endl << endl;
		cout << "\t\t\t*******************************************" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> op;

		
		switch (op) {
		case 1:
			system("cls");
			c.crear();
			break;
		case 2:
			c.leer();
			break;
		case 3:
			c.actualizar();
			break;
		case 4:
			c.eliminar();

			break;
		case 5:
			cout << "Ha salido Exitosamente..." << endl;

			break;
			
		default:
			cout << "Ingreso una opcion incorrecta";
			break;
		}


		
	}


int main()
{
	Cliente c = Cliente();
	menuPrincipal(c);
    system("pause");
    return 0;
}
