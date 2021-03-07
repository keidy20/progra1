#include <iostream>
#include <stdlib.h>

using namespace std;

main(){

	

	int tam=1,*p_notas;

	char s;

	p_notas = new int[tam];
	
	int estu=0, codigo=0;
	string nombre;
	
	cout<<"Cuantos Estudiantes desea Ingresar: ";
	cin>>estu;
	
	cout<<"Cuantas Notas desea Ingresar: ";
	cin>>tam;
	
	cout<<" --------- Ingrese Notas ---------"<<endl;
	int contador=0;
	
	do{
	
	cout<<"Codigo: ";
	cin>>codigo;
	cin.ignore();
			
	cout<<"Nombre: ";
	getline(cin,nombre);
	
	
	
	for(int i=0; i<tam; i++){

		cout<<"Ingrese Nota "<<i+1<<":";

		cin>>p_notas[i];

	}

	cout<<"------------------------------------"<<endl;
	 contador++;

	}while(contador < estu);
	
	
	
	cout<<" --------- Mostrar Notas ---------"<<endl;
	cout<<"Codigo: "<<codigo<<" "<<"Nombre:"<<nombre<<endl;

	for (int i = 0; i<tam;i++){

		cout<<"Nota ["<<i+1<<"]:"<<*p_notas<<endl;

		p_notas++;
		

	}
	

	delete[] p_notas;

	

}
