// Tarea 2  POO y Mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "JavierPrado14", "bd2_empresa", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion Exitosa..." <<endl;
        string marca;
        cout << "Por favor Ingrese Marca: ";
        cin >> marca;
        string insert = "insert into marcas(marca) values ('"+ marca +"')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar,i); 
        if (!q_estado) {
            cout << "Ingreso Exitoso" << endl;

        }
        else {
            cout << "Error en el ingreso..." << endl;
        }

    }
    else {
        cout << "Falla en Conexion..." <<endl;
    }
    system("pause");
    return 0;
}

