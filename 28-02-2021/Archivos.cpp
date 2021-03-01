#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <conio.h>

using namespace std;

const char *nombre_archivo = "archivo2.dat";

struct Estudiante{

	int codigo;

	char nombres[50];

	char apellidos[50];

	int telefono;

};

void abrir();

void ingresar();

/*void modificar();

void buscar_id();

void buscar_codigo();*/

void eliminar();

main(){

	abrir();

	ingresar();

	/*modificar();

	buscar_id();

	buscar_codigo();*/
	
	eliminar();

}

void abrir(){

	system("cls");

	FILE* archivo = fopen(nombre_archivo,"rb");

	if (!archivo){

		archivo = fopen(nombre_archivo,"w+b");

	}

	Estudiante estudiante;

	int id= 0;

	//fread(&estudiante,sizeof(Estudiante),1,archivo);

	cout<<"id |"<<"Codigo |"<<"Nombres   |"<<"Apellidos   |"<<"Telefono"<<endl;

	do{

	
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	
	cout<<id<<" |"<<estudiante.codigo<<" |"<<estudiante.nombres<<"  |"<<estudiante.apellidos<<"  |"<<estudiante.telefono<<endl;


		id+=1;

	} while(feof(archivo) ==0);

	fclose(archivo);

}


void ingresar(){

	char continuar;

	FILE* archivo = fopen(nombre_archivo,"ab");

	Estudiante estudiante;

	string nombre,apellido;

	do{

		fflush(stdin);

		cout<<"Ingrese el Codigo:";

		cin>>estudiante.codigo;

		cin.ignore();

		

		cout<<"Ingrese Los Nombres: ";

		getline(cin,nombre);

		strcpy(estudiante.nombres,nombre.c_str());

		

		cout<<"Ingrese Los Apellidos: ";

		getline(cin,apellido);

		strcpy(estudiante.apellidos,apellido.c_str());

		

		cout<<"Ingrese el Telefono:";

		cin>>estudiante.telefono;

		fwrite(&estudiante,sizeof(Estudiante),1,archivo);

		cout<<"Desea ingresar otro dato (s/n):";

		cin>>continuar;

	} while (continuar=='s' || continuar=='S');

	fclose(archivo);

	abrir();

}

/*void modificar(){

	FILE* archivo = fopen(nombre_archivo,"r+b");

	

	int id=0;

	Estudiante estudiante;

	string nombre,apellido;

	cout<<"Ingrese el ID a Modificar:";

	cin>>id;

	fseek(archivo,id*sizeof(Estudiante),SEEK_SET);

	cout<<"Modificar el Codigo:";

		cin>>estudiante.codigo;

		cin.ignore();

		

		cout<<"Modificar Los Nombres: ";

		getline(cin,nombre);

		strcpy(estudiante.nombres,nombre.c_str());

		

		cout<<"Modificar Los Apellidos: ";

		getline(cin,apellido);

		strcpy(estudiante.apellidos,apellido.c_str());

		

		cout<<"Modificar el Telefono:";

		cin>>estudiante.telefono;

		fwrite(&estudiante,sizeof(Estudiante),1,archivo);

		fclose(archivo);

		abrir();

	

}


	
 
void buscar_id(){

	FILE* archivo = fopen(nombre_archivo,"rb");	

	int id;

	cout<<"Ingrese el ID que desea ver: ";

	cin>>id;

	fseek(archivo,id*sizeof(Estudiante),SEEK_SET);

	Estudiante estudiante;

	fread(&estudiante,sizeof(Estudiante),1,archivo);

	cout<<"Codigo: "<<estudiante.codigo<<endl;

	cout<<"Nombres: "<<estudiante.nombres<<endl;

	cout<<"Apellidos: "<<estudiante.apellidos<<endl;

	cout<<"Telefono: "<<estudiante.telefono<<endl;

	fclose(archivo);

}

void buscar_codigo(){

	FILE* archivo = fopen(nombre_archivo,"rb");	

	int codigo;

	cout<<"Ingrese el Codigo: ";

	cin>>codigo;

	

	Estudiante estudiante;

	fread(&estudiante,sizeof(Estudiante),1,archivo);

	do{

		if(estudiante.codigo == codigo){

			cout<<"______________________"<<endl;

			cout<<"Codigo: "<<estudiante.codigo<<endl;

			cout<<"Nombres: "<<estudiante.nombres<<endl;

			cout<<"Apellidos: "<<estudiante.apellidos<<endl;

			cout<<"Telefono: "<<estudiante.telefono<<endl;

		}

		fread(&estudiante,sizeof(Estudiante),1,archivo);

	} while (feof(archivo)==0);

	

	

	fclose(archivo);

}*/

void eliminar()
{
	Estudiante estudiante;
	
	char resp;
	
	cout<<"Desea eliminar una linea de codigo: S/N? ";
	cin>>resp;
	
	if(resp=='S'|| resp=='s'){
		
		int codigo=0; 
		cout<<"Ingrese el codigo que desea eliminar:";
		cin>>codigo;
		FILE* archivo = fopen(nombre_archivo,"rb");
		FILE* temporal = fopen("temp.dat","w+b");
		
		do{
			fread(&estudiante,sizeof(Estudiante),1,archivo);
			
			if(codigo!=estudiante.codigo){
				fwrite(&estudiante,sizeof(Estudiante),1,temporal);
				cout<<estudiante.codigo<<" "<<estudiante.nombres<<" "<<estudiante.apellidos<<" "<<estudiante.telefono<<endl;
				
			}
		
			
		}while(feof(archivo) ==0);
		
		cout<<"Registro eliminado correctamente";
		fclose(temporal);
		fclose(archivo);


		
		remove("archivo2.dat");
		rename("temp.dat","archivo2.dat");
		
	}

		
}

