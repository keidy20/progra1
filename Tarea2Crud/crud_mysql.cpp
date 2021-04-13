// crud_mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<mysql.h>
#include <string>
#include <iostream>
using namespace std;
MYSQL_RES *res;
MYSQL_ROW row;
//-----------MARCAS---------------
//void crear(MYSQL* conectar);
//void leer(MYSQL* conectar);
//void actualizar(MYSQL* conectar);
// void eliminar(MYSQL* conectar);
//-----------PRODUCTOS---------------
//void crearP(MYSQL* conectar);
//void leerP(MYSQL* conectar);
//void actualizarP(MYSQL* conectar);
//void eliminarP(MYSQL* conectar);

int main( int argc, char * argv[])
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "keylo21", "db_kardex", 3306, NULL, 0);
    //crear(conectar);
    //leer(conectar);
    //actualizar(conectar);
   //eliminar(conectar);
   // ------PRODUCTOS--------
    //crearP(conectar);
    //leerP(conectar);
    //actualizarP(conectar);
    //eliminarP(conectar);
    
    system("pause");
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------CRUD MARCAS----------------------------------------------------------


/*void crear(MYSQL* conectar)
    {
       
        if (conectar) {
            //cout << "Conexion Exitosa... " << endl;
            int estado;
            string marca;

        cout << "Ingrese Marca del Producto: " << endl;
        cin >> marca;

        string insert = "Insert into marcas(marca) values ('" + marca + "')";
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

    }*/

       /* void leer(MYSQL* conectar)
    {
        if (conectar) {
            //cout << "Conexion Exitosa... " << endl
            int estado;
            string select = "select * from marcas";
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

    }*/

    /*void actualizar(MYSQL* conectar)
    {
        if (conectar) {
            //cout << "Conexion Exitosa... " << endl
            int estado;
            string update = "update marcas set marca = 'OSTER' where marca = 'PHILLIPS'";
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

    }*/


    /*
    void eliminar(MYSQL* conectar) 
    {
        if (conectar) {
            //cout << "Conexion Exitosa... " << endl;
            int estado;

            string delet = "DELETE FROM marcas WHERE idmarca = 12";
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

    }*/
    
//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------CRUD PRODUCTOS----------------------------------------------------------

/*
void crearP(MYSQL* conectar)
{

    if (conectar) {
        //cout << "Conexion Exitosa... " << endl;
        int est;
        string producto, descripcion, imagen, precio_costo, precio_venta;

        //time_t fecha_ingreso;
        //time(&fecha_ingreso);
        cout << "Ingrese el Producto: " << endl;
        getline(cin, producto);

        cout << "Ingrese la Descripcion del Producto: " << endl;
        getline(cin, descripcion);

        cout << "Ingrese la Imagen del Producto: " << endl;
        getline(cin, imagen);

        cout << "Ingrese el Precio Costo del Producto: " << endl;
        getline(cin, precio_costo);

        cout << "Ingrese el Precio Venta del Producto: " << endl;
        getline(cin, precio_venta);

        string insert = "Insert into productos(producto,descripcion,imagen,precio_costo,precio_venta) values ('" + producto + "','" + descripcion + "','" + imagen + "','" + precio_costo + "','" + precio_venta + "')";
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
void leerP(MYSQL* conectar)
{
    if (conectar) {
        //cout << "Conexion Exitosa... " << endl
        int est;
        string select = "select * from productos";
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
void actualizarP(MYSQL* conectar)
    {
        if (conectar) {
            //cout << "Conexion Exitosa... " << endl
            int est;
            string update = "update productos set producto = 'Microondas' where producto = 'Estufa'";
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
    void eliminarP(MYSQL* conectar)
    {
        if (conectar) {
            //cout << "Conexion Exitosa... " << endl;
            int est;

            string delet = "DELETE FROM productos WHERE idProducto = 13";
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