// CrudEmpleados.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<mysql.h>
#include <string>
#include <iostream>
using namespace std;
MYSQL_RES* res;
MYSQL_ROW row;
//-----------PUESTOS---------------
//void crear(MYSQL* conectar);
//void leer(MYSQL* conectar);
//void actualizar(MYSQL* conectar);
//void eliminar(MYSQL* conectar);
//-----------EMPLEADOS---------------
//void crearE(MYSQL* conectar);
//void leerE(MYSQL* conectar);
//void actualizarE(MYSQL* conectar);
//void eliminarE(MYSQL* conectar);

int main(int argc, char* argv[])
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "keylo21", "db_empresa", 3306, NULL, 0);
    //crear(conectar);
    //leer(conectar);
    //actualizar(conectar);
   //eliminar(conectar);
   // ------EMPLEADOS--------
    //crearE(conectar);
    //leerE(conectar);
    //actualizarE(conectar);
   //eliminarE(conectar);

    system("pause");
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------CRUD PUESTOS----------------------------------------------------------


/*void crear(MYSQL* conectar)
    {

        if (conectar) {
            //cout << "Conexion Exitosa... " << endl;
            int estado;
            string puesto;
        cout << "Ingrese Puesto del Empleado: " << endl;
        cin >> puesto;
        string insert = "Insert into puestos(puesto) values ('" + puesto + "')";
        const char* i = insert.c_str();
        estado = mysql_query(conectar, i);
        if (!estado) {
            cout << "Ingreso Exitoso... " << endl;
        }
        else {
            cout << "xxx Error al Ingresar xxx " << endl;
        }
        }
        else {
            cout << "Error en la conexion... " << endl;
        }
    }
    */
/*
    void leer(MYSQL* conectar)
     {
         if (conectar) {
             //cout << "Conexion Exitosa... " << endl
             int estado;
             string select = "select * from puestos";
             const char* i = select.c_str();
             estado = mysql_query(conectar,i);
             if (!estado) {
                 res = mysql_store_result(conectar);
                 int num_fields = mysql_num_fields(res);
                 cout << " Registros mostrados exitosamente... " << endl;

                 while ((row = mysql_fetch_row(res)))
                 {
                     for (int i = 0; i < num_fields; i++)
                     {
                         if (row[i] != NULL)
                             cout << row[i]<<" ";
                         else
                             cout << "NULL" << endl;
                     }
                     cout<<endl;
                 }
             }
             else {
                 cout << "xxx Error al mostrar los Registro xxx " << endl;
             }
         }
         else {
             cout << "Error en la conexion... " << endl;
         }
    }
    */
/*
 void actualizar(MYSQL* conectar)
 {
     if (conectar) {
         //cout << "Conexion Exitosa... " << endl
         int estado;
         string update = "update puestos set puesto = 'Gerente' where puesto = 'Supervisor'";
         const char* i = update.c_str();
         estado = mysql_query(conectar, i);
         if (!estado) {
             cout << " Registro Actualizado Exitosamente... " << endl;
         }
         else {
             cout << "xxx Error al actualizar el Registro xxx " << endl;
         }
     }
     else {
         cout << "Error en la conexion... " << endl;
     }
 }

*/
 /*
 void eliminar(MYSQL* conectar)
 {
     if (conectar) {
         //cout << "Conexion Exitosa... " << endl;
         int estado;
         string delet = "DELETE FROM puestos WHERE id_puesto = 8";
         const char* i = delet.c_str();
         estado = mysql_query(conectar, i);
         if (!estado) {
             cout << " Registro Eliminado Exitosamente... " << endl;
         }
         else {
             cout << "xxx Error al eliminar el Registro xxx " << endl;
         }
     }
     else {
         cout << "Error en la conexion... " << endl;
     }
 }
 */

 //--------------------------------------------------------------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------------------------------------------------------------
 //--------------------------------------------------------------CRUD EMPLEADOS----------------------------------------------------------

 /*
 void crearE(MYSQL* conectar)
 {
     if (conectar) {
         //cout << "Conexion Exitosa... " << endl;
         int est;
         string codigo, nombres, apellidos, direccion, telefono,id_puesto;
         ;
         DATE fecha_nacimiento;
         cout << "Ingrese el codigo del Empleado: " << endl;
         getline(cin, codigo);

         cout << "Ingrese el nombre del Empleado: " << endl;
         getline(cin, nombres);

         cout << "Ingrese los apellidos del Empleado: " << endl;
         getline(cin, apellidos);

         cout << "Ingrese la direccion del Empleado: " << endl;
         getline(cin, direccion);

         cout << "Ingrese el telefono del Empleado: " << endl;
         getline(cin, telefono);


         cout << "Ingrese la fecha de nacimiento del Empleado: " << endl;
         cin>>fecha_nacimiento;
         cin.ignore();

         cout << "Ingrese el id puesto del Empleado: " << endl;
         getline(cin,id_puesto);
         
         string insert = "Insert into empleados(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento) values ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "', current_time())";
         const char* i = insert.c_str();
         est = mysql_query(conectar, i);
         if (!est) {
             cout << "Ingreso Exitoso... " << endl;
         }
         else {
             cout << "xxx Error al Ingresar xxx " << endl;
         }
     }
     else {
         cout << "Error en la conexion... " << endl;
     }
 }
 
 */
 /*
 void leerE(MYSQL* conectar)
 {
     if (conectar) {
         //cout << "Conexion Exitosa... " << endl
         int est;
         string select = "select * from empleados";
         const char* i = select.c_str();
         est = mysql_query(conectar, i);
         if (!est) {
             res = mysql_store_result(conectar);
             int num_fields = mysql_num_fields(res);
             cout << " Registros mostrados exitosamente... " << endl;
             while ((row = mysql_fetch_row(res)))
             {
                 for (int i = 0; i < num_fields; i++)
                 {
                     if (row[i] != NULL)
                         cout << row[i] << " ";
                     else
                         cout << "NULL" << endl;
                 }
                 cout << endl;
             }
         }
         else {
             cout << "xxx Error al mostrar los Registro xxx " << endl;
         }
     }
     else {
         cout << "Error en la conexion... " << endl;
     }
 }
 */

 /*
 void actualizarE(MYSQL* conectar)
     {
         if (conectar) {
             //cout << "Conexion Exitosa... " << endl
             int est;
             string update = "update empleados set nombres = 'Adrian' where nombres= 'Alejandro'";
             const char* i = update.c_str();
             est = mysql_query(conectar, i);
             if (!est) {
                 cout << " Registro Actualizado Exitosamente... " << endl;
             }
             else {
                 cout << "xxx Error al actualizar el Registro xxx " << endl;
             }
         }
         else {
             cout << "Error en la conexion... " << endl;
         }
     }
     */

    /*
         void eliminarE(MYSQL* conectar)
         {
             if (conectar) {
                 //cout << "Conexion Exitosa... " << endl;
                 int est;
                 string delet = "DELETE FROM empleados WHERE id_empleado = 7";
                 const char* i = delet.c_str();
                 est = mysql_query(conectar, i);
                 if (!est) {
                     cout << " Registro Eliminado Exitosamente... " << endl;
                 }
                 else {
                     cout << "xxx Error al eliminar el Registro xxx " << endl;
                 }
             }
             else {
                 cout << "Error en la conexion... " << endl;
             }
         }

         */
 
