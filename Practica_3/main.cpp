#include <iostream>
#include "codificacion-decodificacion.h"
#include <fstream>

using namespace std;

void menu_principal();
void menu_administrador(int*& cedulas, string*& claves, double*& saldos, int& totalUsuarios);
void menu_usuario(int index, double *&saldos);
bool validarAdmin();
void registrar_usuario(int*& cedulas, string*& claves, double*& saldos, int& totalUsuarios);
int validarUser(int* cedulas, string* claves, int totalUsuarios);
void retirar_dinero(int index, double *&saldos);

void retirar_dinero(int index, double *&saldos){

    double cantRetirar;
    cout << "Ingrese la cantidad que desea retirar: ";
    cin >> cantRetirar;

    if(saldos[index] < cantRetirar){
        cout << "Fondos insuficientes: la cantidad que desea retirar es mayor al saldo de su cuenta. \n";
        return;
    }
    else{
        saldos[index] -= cantRetirar;
    }
}

int validarUser(int* cedulas, string* claves, int totalUsuarios){

    int cedulaIngresada;
    string claveIngresada;

    cout << "Ingrese su cedula: ";
    cin >> cedulaIngresada;
    cout << "Ingrese su clave: ";
    cin >> claveIngresada;

    for (int i = 0; i < totalUsuarios; i++) {
        if (cedulas[i] == cedulaIngresada && claves[i] == claveIngresada) {
            cout << "Acceso concedido. Bienvenido.\n";
            return i;
        }
    }

    cout << "Cedula o clave incorrecta.\n";
    return -1;

}


void registrar_usuario(int*& cedulas, string*& claves, double*& saldos, int& totalUsuarios){

    int nuevaCedula;
    string nuevaClave;
    double nuevoSaldo;

    cout << "Ingrese la cedula del usuario: ";
    cin >> nuevaCedula;
    cout << "Ingrese la clave del usuario: ";
    cin >> nuevaClave;
    cout << "Ingrese el saldo inicial (COP): ";
    cin >> nuevoSaldo;

    int* tempCedulas = new int[totalUsuarios + 1];
    string* tempClaves = new string[totalUsuarios + 1];
    double* tempSaldos = new double[totalUsuarios + 1];

    for (int i = 0; i < totalUsuarios; i++) {
        tempCedulas[i] = cedulas[i];
        tempClaves[i] = claves[i];
        tempSaldos[i] = saldos[i];
    }

    tempCedulas[totalUsuarios] = nuevaCedula;
    tempClaves[totalUsuarios] = nuevaClave;
    tempSaldos[totalUsuarios] = nuevoSaldo;

    delete[] cedulas;
    delete[] claves;
    delete[] saldos;

    cedulas = tempCedulas;
    claves = tempClaves;
    saldos = tempSaldos;

    totalUsuarios++;

    cout << "Usuario registrado con exito.\n";
}

bool validarAdmin(){

    ifstream archivo("sudo.txt");
    if (!archivo) {
        cerr << "Error: No se pudo abrir el archivo sudo.txt." << endl;
        return false;
    }

    string clave_encriptada_archivo;
    getline(archivo, clave_encriptada_archivo);
    archivo.close();

    string clave_ingresada;
    cout << "Ingrese la clave de administrador: ";
    cin >> clave_ingresada;

    if (clave_encriptada_archivo == encodeFile(clave_ingresada, 4)){
        cout << "Acceso concedido." << endl;
        return true;
    }
    else {
        cout << "Clave incorrecta." << endl;
        return false;
    }
}

void menu_principal() {

    int* cedulas = nullptr;
    string* claves = nullptr;
    double* saldos = nullptr;
    int totalUsuarios = 0;
    int indice;
    int opcion;

    do {
        cout << "=== MENU PRINCIPAL ===\n";
        cout << "1. Acceder como Administrador\n";
        cout << "2. Acceder como Usuario\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:

            if (validarAdmin()) {
                menu_administrador(cedulas, claves, saldos, totalUsuarios);
            }
            break;
        case 2:

            indice = validarUser(cedulas, claves, totalUsuarios);
            if (indice != -1) {
                saldos[indice] -= 1000;
                menu_usuario(indice, saldos);
            }
            break;
        case 3:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion no valida, intente de nuevo.\n";
            break;
        }
    } while (opcion != 3);


    delete[] cedulas;
    delete[] claves;
    delete[] saldos;

}

void menu_administrador(int *&cedulas, string *&claves, double *&saldos, int &totalUsuarios) {
    int opcion;
    do {
        cout << "=== MENU ADMINISTRADOR ===\n";
        cout << "1. Registrar nuevo usuario\n";
        cout << "2. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrar_usuario(cedulas, claves, saldos, totalUsuarios);
            break;
        case 2:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion no valida, intente de nuevo.\n";
            break;
        }
    } while (opcion != 2);
}

void menu_usuario(int index, double *&saldos) {
    int opcion;
    do {
        cout << "=== MENU USUARIO ===\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Usted posee un saldo de " << saldos[index] << " pesos\n";

            break;
        case 2:
            retirar_dinero(index, saldos);
            break;
        case 3:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion no válida, intente de nuevo.\n";
            break;
        }
    } while (opcion != 3);
}

int main()
{

    menu_principal();

}
