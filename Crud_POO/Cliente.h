#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;
class Cliente : Persona{
	//atributos
private: string nit;
	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
		
		
	}
	//metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	// metodo


	void crear(){
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string nit, nombres, apellidos, direccion, fecha_nacimiento;
			cin.ignore();
			cout << "Ingrese NIT: " << endl;
			getline(cin, nit);
			cout << "Ingrese Nombres: " << endl;
			getline(cin, nombres);
			cout << "Ingrese Apellidos: " << endl;
			getline(cin, apellidos);
			cout << "Ingrese Telefono: " << endl;
			cin >> t;
			cin.ignore();
			cout << "Ingrese Direccion: " << endl;
			getline(cin, direccion);
			cout << "Ingrese Fecha de Nacimiento: " << endl;
			getline(cin, fecha_nacimiento);

			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('"+ nit +"','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;
			}
			else {
				cout << "xxxx Error al Ingresar xxxxx" << endl;
			}
		}
		else {
			cout << "Error en la Conexion..." << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------------------------Clientes----------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << endl;
				}
			}
			else {
				cout << "xxxx Error al Consultar xxxxx" << endl;
			}
		}
		else {
			cout << "Error en la Conexion..." << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int q_estado;
			string id,dir;
			string tel = to_string(telefono);
			cout << "Ingrese el Id del Cliente que desea Actualizar: " << endl;
			cin >> id;
			
			cout << "Ingrese Direccion: " << endl;
			cin >> dir;
			cout << "Ingrese Telefono: " << endl;
			cin >> tel;
				
			string update = "UPDATE clientes SET direccion = '"+ dir +"',telefono = '" + tel + "' WHERE id_cliente = '" + id + "'";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Registro Actualizado Exitosamente... " << endl;
			}
			else {
				cout << "xxx Error al actualizar el Registro xxx " << endl;
			}

		}
		else {
			cout << "Error en la conexion... " << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(){
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int q_estado;
			string id;
			cout << "Ingrese el Id del Cliente que desea eliminar: " << endl;
			cin >> id;
			string delet = "DELETE FROM clientes WHERE id_cliente = '"+ id +"'";
			const char* i = delet.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (q_estado) {
				cout << " Registro Eliminado Exitosamente... " << endl;
			}
			else {
				cout << "xxx Error al eliminar el Registro xxx " << endl;
			}

		}
		else {
			cout << "Error en la conexion... " << endl;
		}
		cn.cerrar_conexion();
	}
		
};

