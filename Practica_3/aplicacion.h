#ifndef APLICACION_H
#define APLICACION_H
#include <string>
using namespace std;

void menu_principal();
void menu_administrador(int*& cedulas, string*& claves, double*& saldos, int& totalUsuarios);
void menu_usuario(int index, double *&saldos);
bool validarAdmin();
void registrar_usuario(int*& cedulas, string*& claves, double*& saldos, int& totalUsuarios);
int validarUser(int* cedulas, string* claves, int totalUsuarios);
void retirar_dinero(int index, double *&saldos);

#endif // APLICACION_H
