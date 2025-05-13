#ifndef CODI_DECODI_H
#define CODI_DECODI_H
#include <string>
using namespace std;

string codificacion_metodo2(const string &nombre_archivo, int semilla);
string decodificacion_metodo2(const string &nombre_archivo, int semilla);
string char2binario(string texto);
string leerArchivoPorCaracter(string nombreArchivo);
string codificacion_metodo1(const string& block, int count0s, int count1s);
string encodeFile(const string& cadena, int n);
string decodeFile(const string& inputFileName, int n);

#endif // CODI_DECODI_H
