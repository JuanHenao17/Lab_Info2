#include <iostream>
#include "codificacion-decodificacion.h"
# include <fstream>
# include <bitset>

using namespace std;

string codificacion_metodo2(const string &cadena, int semilla){

    string bloque_codificado;
    string cadena_binaria;
    string codificado;

    cadena_binaria = char2binario(cadena); //lee contenido del archivo y lo convierte a binario string

    for(int i=0; i<cadena_binaria.length();i += semilla){
        string bloque = cadena_binaria.substr(i, semilla);
        int tamano_bloque = bloque.length();

        for(int j=0; j<tamano_bloque;j++){
            if (j == 0) {
                bloque_codificado += bloque[bloque.length() - 1]; // último a primero
            } else {
                bloque_codificado += bloque[j - 1]; // resto se desplaza
            }
        }
        codificado += bloque_codificado;
        bloque_codificado = "";
    }
    return codificado;
}

string decodificacion_metodo2(const string &nombre_archivo, int semilla){

    string decodificado;
    string bloque_decodificado;
    string strBinario_codificado = leerArchivoPorCaracter(nombre_archivo);

    for(int i=0; i<strBinario_codificado.length();i += semilla){
        string bloque = strBinario_codificado.substr(i, semilla);
        int tamano_bloque = bloque.length();

        for (int j = 0; j < tamano_bloque; j++) {
            if (j == tamano_bloque - 1) {
                bloque_decodificado += bloque[0];

            } else {

                bloque_decodificado += bloque[j + 1];
            }
        }

        decodificado += bloque_decodificado;
        bloque_decodificado = "";

    }

    return decodificado;
}

string char2binario(string texto)
{

    char caracter;
    string str_binario;

    for (int i=0; i<texto.length();i++)
    {
        caracter = texto[i];
        bitset<8> binario(caracter);
        str_binario += binario.to_string();
    }

    return str_binario;
}

void escribirArchivoBinario(const string &nombreArchivo, const string &contenido) {
    ofstream archivo(nombreArchivo, ios::binary);  // Modo binario
    if (archivo.is_open()) {
        archivo.write(contenido.c_str(), contenido.size());  // Escribir binario
        archivo.close();
    } else {
        cout << "Error al abrir el archivo binario para escribir." << endl;
    }
}

string leerArchivoPorCaracter(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    char c;
    while (archivo.get(c))
    {
        contenido += c;
    }
    archivo.close();

    return contenido;
}

string binarioACaracteres(string binario) {
    string resultado;

    for (int i = 0; i < binario.length(); i += 8) {
        string byte = binario.substr(i, 8);
        char c = bitset<8>(byte).to_ulong();
        resultado += c;
    }
    return resultado;
}

void escribirArchivo(string nombreArchivo, string texto, bool limpiar)
{
    fstream archivo;
    if (limpiar) // Si limpiar es verdadero, se sobreescribe el archivo
    {
        archivo.open(nombreArchivo, ios::out | ios::trunc);
    }
    else // Si limpiar es falso, se agrega contenido al final del archivo
    {
        archivo.open(nombreArchivo, ios::out | ios::app);
    }

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo\n";
        return;
    }

    archivo << texto << endl;
    archivo.close();
}

string codificacion_metodo1(const string& block, int count0s, int count1s) {
    string encodedBlock;
    unsigned short contCaso3 = 0;

    if (count0s == count1s) {

        for (int i = 0; i < block.length(); ++i) {
            char bit = (block[i] == '1')? '0' : '1';
            encodedBlock += bit;
        }
    }
    else if(count0s > count1s) {

        for (int i = 0; i < block.length(); ++i) {
            if(i%2 != 0){
                char bit = (block[i] == '1')? '0' : '1';
                encodedBlock += bit;
            }
            else{
                encodedBlock += block[i];
            }
        }
    }

    else{

        for (int i = 0; i < block.length(); ++i) {

            contCaso3++;
            if(contCaso3 == 3){
                char bit = (block[i] == '1')? '0' : '1';
                encodedBlock += bit;
                contCaso3 = 0;
            }

            else{
                encodedBlock += block[i];
            }
        }

    }
    return encodedBlock;
}

string encodeFile(const string& cadena, int n) {

    string binaryString = char2binario(cadena);
    string encodedString;
    int cont1s = 0;
    int cont0s = 0;

    string block = binaryString.substr(0, n);
    for (int j = 0; j < block.length(); ++j) {
        char bit = (block[j] == '1')? '0' : '1';
        encodedString += bit;

        if(block[j] == '1'){
            cont1s++;
        }
        else{
            cont0s++;
        }
    }


    for (int i = n; i < binaryString.length(); i += n) {
        block = binaryString.substr(i, n);
        encodedString += codificacion_metodo1(block, cont0s, cont1s);
        cont1s = 0;
        cont0s = 0;
        for (int h = 0; h < block.length(); ++h) {
            if(block[h] == '1'){
                cont1s++;
            }
            else{
                cont0s++;
            }
        }

    }

    return encodedString;

}


string decodeFile(const string& inputFileName, int n) {

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error: No se pudo abrir el archivo de entrada." << endl;
        return "";
    }

    string decodificado;
    string bloque_decodificado;
    string strBinario_codificado = leerArchivoPorCaracter(inputFileName);

    int count1s = 0;
    int count0s = 0;

    string block = strBinario_codificado.substr(0, n);
    for (int i = 0; i < block.length(); ++i) {
        char bit = (block[i] == '1')? '0' : '1';
        bloque_decodificado += bit;

        if(bit == '1'){
            count1s++;
        }
        else{
            count0s++;
        }
    }

    decodificado = bloque_decodificado;

    for (size_t i = n; i < strBinario_codificado.length(); i += n){

        block = strBinario_codificado.substr(i, n);
        bloque_decodificado = codificacion_metodo1(block, count0s, count1s);
        decodificado += bloque_decodificado;
        count1s = 0;
        count0s = 0;

        for(int j = 0; j < bloque_decodificado.length();j++){
            if(bloque_decodificado[j] == '1'){
                count1s++;
            }
            else{
                count0s++;
            }
        }

    }

    // Convertir el string de bits a caracteres
    string finalOutput;
    for (size_t i = 0; i < decodificado.length(); i += 8) {
        string byte = decodificado.substr(i, 8);
        char c = bitset<8>(byte).to_ulong();
        finalOutput += c;
    }

    return finalOutput;
}
