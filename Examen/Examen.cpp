#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <conio.h>

using namespace std;

const char *nombre_archivo = "archivo.dat";

struct Empleado{

	int codigo_empleado;

	char nombres[50];

	char apellidos[50];
	
	char puesto[50];

	int sueldo_base, bonificacion;

};

void abrir();

void ingresar();

void modificar();

void buscar_codigo();

void eliminar();

main(){

	abrir();

	ingresar();

	modificar();

	buscar_codigo();
	
	eliminar();

}

void abrir(){

	system("cls");

	FILE* archivo = fopen(nombre_archivo,"rb");

	if (!archivo){

		archivo = fopen(nombre_archivo,"w+b");

	}

	Empleado empleado;
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		cout<<"______________________________________________________________________________________________________________________"<<endl;
		cout<<"Codigo_Empleado |"<<"Nombres   |"<<"Apellidos   |"<<"Puesto   |"<<"Sueldo_base   |"<<"Bonificacion   |"<<"Sueldo_Total"<<" "<<endl;
		do{
			cout<<"__________________________________________________________________________________________________________________"<<endl;
			cout<<empleado.codigo_empleado<<" |"<<empleado.nombres<<"  |"<<empleado.apellidos<<"  |"<<empleado.puesto<<"  |"<<empleado.sueldo_base<<"  |"<<empleado.bonificacion<<"  |"<<(empleado.sueldo_base+empleado.bonificacion)<<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
			
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}




void ingresar(){

	char continuar;

	FILE* archivo = fopen(nombre_archivo,"ab");

	Empleado empleado;

	string nombre,apellido, puest;
	int sueldo_total;
	
	cout<<"---------------INGRESAR EMPLEADOS---------------";
	cout<<endl;

	do{

		fflush(stdin);

		cout<<"Ingrese el Codigo de Empleado:";

		cin>>empleado.codigo_empleado;

		cin.ignore();

		

		cout<<"Ingrese Nombres: ";

		getline(cin,nombre);

		strcpy(empleado.nombres,nombre.c_str());

		

		cout<<"Ingrese Apellidos: ";

		getline(cin,apellido);

		strcpy(empleado.apellidos,apellido.c_str());
		
		
		
		cout<<"Ingrese Puesto: ";

		getline(cin,puest);

		strcpy(empleado.puesto,puest.c_str());

		

		cout<<"Ingrese Sueldo Base:";

		cin>>empleado.sueldo_base;
		
		
		
		cout<<"Ingrese Bonificacion:";

		cin>>empleado.bonificacion;
		
		
		sueldo_total=empleado.sueldo_base + empleado.bonificacion;
		
		cout<<"El sueldo total del empleado es: "<<sueldo_total<<endl;

		fwrite(&empleado,sizeof(Empleado),1,archivo);

		cout<<"Desea ingresar otro dato (s/n):";

		cin>>continuar;

	} while (continuar=='s' || continuar=='S');

	fclose(archivo);

	abrir();

}

void modificar(){

	FILE* archivo = fopen(nombre_archivo,"r+b");

	

	Empleado empleado;

	string nombre,apellido, puest;
	
	cout<<"---------------MODIFICAR EMPLEADOS---------------";
	cout<<endl;

	cout<<"Ingrese el Codigo a Modificar:";

	cin>>empleado.codigo_empleado;
	
	cin.ignore();


	cout<<"Modificar Los Nombres: ";

	getline(cin,nombre);

	strcpy(empleado.nombres,nombre.c_str());

		

	cout<<"Modificar Los Apellidos: ";
	
	getline(cin,apellido);

	strcpy(empleado.apellidos,apellido.c_str());


	
	cout<<"Modificar Puesto: ";
	
	getline(cin,puest);

	strcpy(empleado.puesto,puest.c_str());
		

	cout<<"Modificar Sueldo Base:";

	cin>>empleado.sueldo_base;
	
	
	cout<<"Modificar Bonificacion:";

	cin>>empleado.bonificacion;

	fwrite(&empleado,sizeof(Empleado),1,archivo);

	fclose(archivo);

	abrir();

	

}


void buscar_codigo(){

	FILE* archivo = fopen(nombre_archivo,"rb");	

	int codigo;
	
	cout<<"---------------BUSCAR EMPLEADOS---------------";
	cout<<endl;

	cout<<"Ingrese el Codigo del Empleado que buscar: ";

	cin>>codigo;

	

	Empleado empleado;

	fread(&empleado,sizeof(Empleado),1,archivo);

	do{

		if(empleado.codigo_empleado == codigo){

			cout<<"______________________"<<endl;

			cout<<"Codigo: "<<empleado.codigo_empleado<<endl;

			cout<<"Nombres: "<<empleado.nombres<<endl;

			cout<<"Apellidos: "<<empleado.apellidos<<endl;
			
			cout<<"Puesto: "<<empleado.puesto<<endl;

			cout<<"Sueldo Base: "<<empleado.sueldo_base<<endl;
			
			cout<<"Bonificacion: "<<empleado.bonificacion<<endl;
			
			cout<<"Sueldo Total: "<<(empleado.sueldo_base+empleado.bonificacion)<<endl;

		}

		fread(&empleado,sizeof(Empleado),1,archivo);

	} while (feof(archivo)==0);

	

	

	fclose(archivo);

}

void eliminar()
{
	Empleado empleado;
	
	char resp;
	
	cout<<"---------------ELIMINAR EMPLEADOS---------------";
	cout<<endl;
	
	cout<<"Desea eliminar un registro: S/N? ";
	cin>>resp;
	
	if(resp=='S'|| resp=='s'){
		
		int codigo=0; 
		cout<<"Ingrese el codigo que desea eliminar:";
		cin>>codigo;
		FILE* archivo = fopen(nombre_archivo,"rb");
		FILE* temporal = fopen("temp.dat","w+b");
		
		do{
			fread(&empleado,sizeof(Empleado),1,archivo);
			
			if(codigo!=empleado.codigo_empleado){
				fwrite(&empleado,sizeof(Empleado),1,temporal);
				cout<<empleado.codigo_empleado<<" "<<empleado.nombres<<" "<<empleado.apellidos<<" "<<empleado.puesto<<" "<<empleado.sueldo_base<<" "<<empleado.bonificacion<<endl;
				cout<<"Registro eliminado correctamente";
			}
		
			
		}while(feof(archivo) ==0);
		
		
		fclose(temporal);
		fclose(archivo);


		
		remove("archivo.dat");
		rename("temp.dat","archivo.dat");
		
	}

		
}

