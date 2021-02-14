#include "Cliente.cpp"
#include <iostream>
using namespace std;
main(){
	string nit,nombres,apellidos,direccion;
	int telefono;
	cout<<"Ingrese Nit: ";
	cin>>nit;
	cout<<"Ingrese Nombres: ";
	cin>>nombres;
	cout<<"Ingrese Apellidos: ";
	cin>>apellidos;
	cout<<"Ingrese Direccion: ";
	cin>>direccion;
	cout<<"Ingrese Telefono: ";
	cin>>telefono;
	//instanciar la clase
	Cliente obj = Cliente(nombres,apellidos,direccion,telefono,nit);
	obj.mostrar();
	
	// modificar atributos
	cout<<"---Modificar---"<<endl;
	cout<<"Modificar Nit:";
	cin>>nit;
	obj.setNit(nit);
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
	 
	obj.mostrar();
 /*cout<<obj.getNit()<<endl;
  cout<<obj.getNombres()<<endl;
   cout<<obj.getApellidos()<<endl;
    cout<<obj.getTelefono()<<endl;*/
};
