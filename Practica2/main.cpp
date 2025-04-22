#include <iostream>
#include <string>
using namespace std;

const int N = 5;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void fun_c_corregida(double a[], int n, double *promedio, double *suma);
void problema2();
int problema4();
void problema6();
void problema8();
void problema12();
void problema14();
void imprimirMatriz(int matriz[N][N]);
void rotar90(int matriz[N][N], int rotada[N][N]);
void problema16();
unsigned long long factorial(int num);
void problema18();

int main()
{

    //Caso de prueba fun_c
    double promedio, suma;
    double *ap_promedio, *ap_suma;
    ap_promedio = &promedio;
    ap_suma = &suma;
    double arrayb[10] = {2.3, 4.5, 6.6, 12.1, 0.0, 1.0, 7.7, 7.7, 9.99, 3.4};

    fun_c_corregida(arrayb, 10, ap_promedio, ap_suma);
    cout << endl << "El promedio esperado es: 5.529" << endl;
    cout << "El promedio resultante es: " << promedio << endl;

    problema8();

}

void fun_a(int *px,int*py){ int
        tmp = *px;
    *px = *py;
    *py = tmp;
}

void fun_b(int a[], int tam){
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--) {
        fun_a(&b[f], &b[l]);
    }
}

void fun_c_corregida(double a[], int n, double *promedio, double *suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++){
        *suma += *(a + i);
    }
    *promedio = *suma / n;
}

void problema2(){

    srand(time(0));
    const int tam = 200;
    char letras[tam];

    for(int i=0; i<tam; i++){
        letras[i] = 'A' + rand() % 26;
    }

    for(int i=0; i<tam; i++){
        cout << letras[i];
    }

    cout << endl;

    int cont[26]={0};

    for(int i=0; i<tam; i++){
        cont[letras[i]-'A']++;
    }

    for (int i = 0; i < 26; ++i){
        cout << char('A' + i) << ": " << cont[i] << endl;
    }
}

int problema4(){

    string cadena;
    cout << "Ingrese una cadena: ";
    cin >> cadena;

    int numero = 0;
    for (int i = 0; i < cadena.length(); i++) {
        char c = cadena[i];
        numero = numero * 10 + (c - '0');
    }
    return numero;
}

void problema6(){

    string cadena;

    cout << "Introduzca la cadena de caracteres: " << endl;
    getline(cin, cadena);

    string copia = cadena;
    for(int i=0; i< cadena.length(); i++){
        if (copia[i] >= 'a' && copia[i] <= 'z'){
            copia[i] = toupper(copia[i]);
        }
    }

    cout << endl << "Original: " << cadena << endl;
    cout << "En mayuscula: " << copia << endl;

}

void problema8(){

    string cadena;
    cout << "Ingrese una cadena: ";
    cin >> cadena;

    string texto = "";
    string numeros = "";

    for (int i = 0; i < cadena.size(); i++) {
        char c = cadena[i];
        if (isdigit(c)) {
            numeros += c;
        } else {
            texto += c;
        }
    }

    cout << endl << "Original: " << cadena << endl;
    cout << "Texto: " << texto << endl;
    cout << "Numero: " << numeros << endl;
}

void problema14(){

    int matriz[N][N];
    int rotada90[N][N];
    int rotada180[N][N];
    int rotada270[N][N];
    unsigned short int num = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = num;
            num++;
        }
    }

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);
    cout << endl;

    rotar90(matriz, rotada90);
    cout << "Matriz rotada 90 grados:" << endl;
    imprimirMatriz(rotada90);
    cout << endl;

    rotar90(rotada90, rotada180);
    cout << "Matriz rotada 180 grados:" << endl;
    imprimirMatriz(rotada180);
    cout << endl;

    rotar90(rotada180, rotada270);
    cout << "Matriz rotada 270 grados:" << endl;
    imprimirMatriz(rotada270);
    cout << endl;

}

void imprimirMatriz(int matriz[N][N]) {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}


void rotar90(int matriz[N][N], int rotada[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotada[j][N - 1 - i] = matriz[i][j];
        }
    }
}

void problema12() {
    int n;

    // Solicitar el tamaño de la matriz
    cout << "Introduce el tamano de la matriz cuadrada: ";
    cin >> n;

    // Asegurarse de que el tamaño sea positivo
    if (n <= 0) {
        cerr << "El tamaño de la matriz debe ser un numero positivo." << endl;
        return;
    }

    // Crear y leer la matriz
    int matriz[n][n];
    cout << "Introduce los elementos de la matriz (" << n * n << " numeros):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Imprimir la matriz
    cout << endl << "Matriz ingresada:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Calcular la suma deseada usando la primera fila
    int suma_deseada = 0;
    for (int j = 0; j < n; ++j) {
        suma_deseada += matriz[0][j];
    }

    // Verificar sumas de filas
    for (int i = 0; i < n; ++i) {
        int suma_fila = 0;
        for (int j = 0; j < n; ++j) {
            suma_fila += matriz[i][j];
        }
        if (suma_fila != suma_deseada) {
            cout << "La matriz no es un cuadrado magico." << endl;
            return;
        }
    }

    // Verificar sumas de columnas
    for (int j = 0; j < n; ++j) {
        int suma_columna = 0;
        for (int i = 0; i < n; ++i) {
            suma_columna += matriz[i][j];
        }
        if (suma_columna != suma_deseada) {
            cout << "La matriz no es un cuadrado magico." << endl;
            return;
        }
    }

    // Verificar suma de la diagonal principal
    int suma_diagonal_principal = 0;
    for (int i = 0; i < n; ++i) {
        suma_diagonal_principal += matriz[i][i];
    }
    if (suma_diagonal_principal != suma_deseada) {
        cout << "La matriz no es un cuadrado magico." << endl;
        return;
    }

    // Verificar suma de la diagonal secundaria
    int suma_diagonal_secundaria = 0;
    for (int i = 0; i < n; ++i) {
        suma_diagonal_secundaria += matriz[i][n - 1 - i];
    }
    if (suma_diagonal_secundaria != suma_deseada) {
        cout << "La matriz no es un cuadrado magico." << endl;
        return;
    }

    // Si todas las verificaciones pasan
    cout << "La matriz es un cuadrado magico." << endl;
}


void problema16() {
    int n;

    // Solicitar el tamaño de la cuadrícula
    cout << "Introduce el tamano de la cuadricula (n): ";

    cin >> n;

    // Asegurarse de que el tamaño sea positivo
    if (n <= 0) {
        cerr << "El tamano de la cuadricula debe ser un numero positivo." << endl;
        return;
    }


    // Calcular el número de combinaciones C(2n, n)
    unsigned long long factorial_2n = factorial(2 * n);
    unsigned long long factorial_n = factorial(n);
    unsigned long long caminos = factorial_2n / (factorial_n * factorial_n);

    // Imprimir el resultado
    cout << endl << "Para una malla de " << n << "x" << n << " hay " << caminos << " caminos." << endl;
}

unsigned long long factorial(int num) {
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

void problema18(){

    int n;
    cout << "Ingresa el valor de n: ";
    cin >> n;
    int copiaN = n;
    n--;

    int numeros[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int factorial[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

    string permutacion = "";

    // Calcular la enésima permutación
    for (int i = 9; i >= 0; i--) {
        int j = n / factorial[i];
        permutacion += to_string(numeros[j]);

        // Remover el número usado, desplazando los elementos a la izquierda
        for (int k = j; k < 9; k++) {
            numeros[k] = numeros[k + 1];
        }

        // Actualizar n para el siguiente dígito
        n %= factorial[i];
    }

    cout << endl << "La permutacion numero " << copiaN << " es: " << permutacion << endl;
}
