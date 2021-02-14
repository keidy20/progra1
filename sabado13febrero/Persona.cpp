#include <iostream>

///Persona
#include <iostream>
using namespace std;
class Persona{
	//atributos
	protected : string nombres,apellidos,direccion;
				int telefono;
	//contrusctor
	protected : 
			Persona(){
					}
			Persona(string nom,string ape,string dir,int tel){
				nombres = nom;
				apellidos=ape;
				direccion = dir;
				telefono = tel;
					}

	//metodos
	void mostrar();
};
