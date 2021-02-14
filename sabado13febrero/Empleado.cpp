#include "Persona.cpp"
#include <iostream>
using namespace std;
class Empleado : Persona{
	//atributos
	private : string cod_empleado, puesto;
				int sueldo;
	//constructor
	public :
	Empleado(){
	}
	Empleado(string nom,string ape,string dir,int tel,string cod_emp,string _puesto,int _sueldo) : Persona(nom,ape,dir,tel){
		cod_empleado = cod_emp;
		puesto = _puesto;
		sueldo = _sueldo;
	}
	//metodos
	//set (modificar)
	void setCodigo (string cod_emp){cod_empleado =cod_emp;}
	void setPuesto(string _puesto ){puesto = _puesto;}
	void setNombres(string nom ){nombres=nom;}
	void setApellidos(string ape){apellidos = ape;}
	void setDireccion(string dir ){direccion = dir;}
	void setTelefono(int tel){telefono = tel;}
	void setSueldo(int _sueldo ){sueldo = _sueldo;}
	//get (mostrar)
	string getCodigo(){return cod_empleado;}
	string getPuesto(){return puesto;}
	string getNombres() {return nombres;}
	string getApellidos(){return apellidos;}
	string getDireccion(){return direccion;}
	int getTelefono(){return telefono;}
	int getSueldo(){return sueldo;}
	
	// metodo mostrar
	void mostrar(){
		cout<<"___________________________________________________________________________"<<endl;
		cout<<cod_empleado<<","<<puesto<<","<<nombres<<","<<apellidos<<","<<direccion<<","<<telefono<<","<<sueldo<<endl;
	}
};
