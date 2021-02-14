#include "Empleado.cpp"
#include <iostream>
using namespace std;
main(){
	string cod_empleado,puesto,nombres,apellidos,direccion;
	int telefono,sueldo;
	cout<<"Ingrese Codigo de Empleado: ";
	cin>>cod_empleado;
	cout<<"Ingrese Puesto: ";
	cin>>puesto;
	cout<<"Ingrese Nombres: ";
	cin>>nombres;
	cout<<"Ingrese Apellidos: ";
	cin>>apellidos;
	cout<<"Ingrese Direccion: ";
	cin>>direccion;
	cout<<"Ingrese Telefono: ";
	cin>>telefono;
	cout<<"Ingrese Sueldo: ";
	cin>>sueldo;
	//instanciar la clase
	Empleado obj = Empleado(nombres,apellidos,direccion,telefono,cod_empleado,puesto,sueldo);
	obj.mostrar();
	
		// modificar atributos
	cout<<"---Modificar---"<<endl;
	cout<<"Modificar Codigo de Empleado:";
	cin>>cod_empleado;
	obj.setCodigo(cod_empleado);
	cout<<"Modificar Puesto:";
	cin>>puesto;
	obj.setPuesto(puesto);
	cout<<"Modificar Nombre:";
	cin>>nombres;
	obj.setNombres(nombres);
	cout<<"Modificar apellido:";
	cin>>apellidos;
	obj.setApellidos(apellidos);
	cout<<"Modificar direccion:";
	cin>>direccion;
	obj.setDireccion(direccion);
	cout<<"Modificar telefono:";
	cin>>telefono;
	obj.setTelefono(telefono);
	cout<<"Modificar Sueldo:";
	cin>>sueldo;
	obj.setSueldo(sueldo);
	 
	obj.mostrar();
};
