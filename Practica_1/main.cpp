#include <iostream>

using namespace std;

int ejercicio2(){
    int a;
    cout << "Ingrese un numero:" << endl;
    cin >> a;
    if (a%2 == 0) {
        cout << endl << a << " es par." << endl;
    }
    else {
        cout << endl << a << " es impar." << endl;
    }
    return 0;
}

int ejercicio4(){

    int a, b;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    if (a == b) {
        cout << endl << a << " es igual a " << b << endl;
    }
    else if (a>b) {
        cout << endl << b << " es menor que " << a << endl;
    }
    else{
        cout << endl << a << " es menor que " << b << endl;
    }
    return 0;
}

int ejercicio6() {

    int a, b, total = 1;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    for (int i=0; i<b; ++i) {
        total *= a;
    }

    cout << endl << a << "∧" << b << " = " << total << endl;

    return 0;
}

int ejercicio8() {

    int a;
    long long total = 1;
    cout << "Ingrese un numero:" << endl;
    cin >> a;
    int aux = a;
    for(int i=0; i<a; ++i) {
        total *= aux;
        --aux;
    }
    cout << endl << a << "! = " << total << endl;
    return 0;
}

int ejercicio10(){

    int a;

    do{
        cout << "Ingrese un numero entre 1 y 100:" << endl;
        cin >> a;

    }while(a>100);

    for (int i = 1; i <= 100; ++i) {
        if (i%a == 0){
            cout << endl << i << endl;}

    }

    return 0;
}

int ejercicio12() {
    int N;


    cout << "Introduce un numero entero : ";
    cin >> N;
    int pot = N;
    for (int i = 1; i <= 5; ++i) {

        cout << "N^" << i << " = " << pot << endl;
        pot *= N;
    }

    return 0;
}

int ejercicio14(){

    cout << "Columna 1" << "      " << "Columna 2" << endl;
    cout << "--------------------------" << endl;

    for (int i = 1, j = 50; i <= 50; ++i, --j) {
        cout << i;
        cout << "      ";
        cout << j << endl;
    }

    return 0;
}

int ejercicio16(){
    int numero;
    int suma = 0;
    int i=0;
    int prom;
    do {
        cout << "Escriba un numero (0 para salir): ";
        cin>> numero;
        if  (numero !=0){
            suma +=numero;
            i++;
        }
        prom= suma/i;
    } while(numero !=0);
    cout<< "El promedio es: "<< prom << endl;
    return 0;
}

int ejercicio18(){
    int N;
    cout << "Escriba un numero: ";
    cin >> N;
    bool escuaperfecto = false;

    int i = 1;
    while (i * i <= N) {
        if (i * i == N) {
            escuaperfecto = true;
            break;
        }
        i++;
    }
    if (escuaperfecto) {
        cout << N << " Es un cuadrado perfecto" << endl;
    } else {
        cout << N << " No es un cuadrado perfecto" << endl;
    }

    return 0;
}

bool ejercicio20(int N){

    int Noriginal;
    int inverso = 0;
    int digito;

    Noriginal = N;

    while (N > 0) {
        digito = N % 10;
        inverso = (inverso * 10) + digito;
        N /= 10;
    }

    return (Noriginal == inverso);
}

int ejercicio22(){

    int segs, horas, mins;
    cout << "Ingrese una cantidad de segundos: " << endl;
    cin >> segs;

    horas = segs/3600;
    segs -= (3600*horas);

    mins = segs/60;
    segs -= (60*mins);

    cout << endl << horas << ":" << mins << ":" << segs << endl;

    return 0;
}

int ejercicio24() {

    int fila;
    cout << "Ingrese un numero:" << endl;
    cin >> fila;
    int espacios = fila - 2;
    cout << endl;

    for(int i = 0; i < fila; ++i){
        cout << "+";
    }
    cout << endl;

    for (int i = 0; i < espacios; ++i){
        cout << "+";
        for (int j = 0; j < espacios; ++j){
            cout << " ";
        }
        cout << "+";
        cout << endl;
    }

    for(int i = 0; i < fila; ++i){
        cout << "+";
    }

    return 0;
}

int ejercicio26() {

    int a, b, c;
    cout << "Ingrese los tres lados del triangulo:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a+b>c && a+c>b && b+c>a){
        if(a==b && b==c){
            cout << endl << "Se forma un triangulo equilatero." << endl;
        }
        else if (a == b || a==c || b==c){
            cout << endl << "Se forma un triangulo isoceles." << endl;
        }
        else{
            cout << endl << "Se forma un triangulo escaleno." << endl;
        }
    }
    else{
        cout << endl << "Las longitudes ingresadas no forman un triangulo." << endl;
    }
    return 0;
}

int ejercicio28(){

    int a;
    double pi = 0.0;
    double sign = 1.0;

    cout << endl << "Ingrese el numero de elementos que van a ser usados en la aproximacion: ";
    cin >> a;

    if (a <= 0){
        cout << endl << "Numeros mayores  a cero ";
    }

    for(int i=0; i<a; ++i){
        double elem = sign / (2*i+1);
        pi += elem;
        sign = -sign;
    }

    pi *= 4;
    cout << endl << "pi es aproximadamente: " << pi << endl;

    return 0;
}

int ejercicio30(){

    cout << "Voy a pensar en un numero entre el 0 y el 100, lo tendras que adivinar." << endl;
    int guess;
    bool band = true;
    srand(time(0));
    int secret = rand() % 101;

    while (band){
        cout << endl << "Introduce un numero entre 0 y 100." << endl;
        cin >> guess;
        while (guess<0 || guess>100) {
            cout << endl << "Numero fuera de rango, intente nuevamente." << endl;
            cin >> guess;
        }
        if(guess>secret){
            cout << endl << "Menor." << endl;
        }
        else if(guess < secret){
            cout << endl << "Mayor." << endl;
        }
        else{
            cout << endl << "Lo has adivinado, felicitaciones." << endl;
            band = false;
        }
    }
    return 0;
}

int problema2(){

    int plata, devuelta50k, devuelta20k, devuelta10k, devuelta5k, devuelta2k, devuelta1k, devuelta500, devuelta200, devuelta100, devuelta50;
    cout << "Ingrese la cantidad de dinero:" << endl;
    cin >> plata;
    int faltante = plata;

    devuelta50k = faltante/50000;
    faltante %= 50000;
    devuelta20k = faltante/20000;
    faltante %= 20000;
    devuelta10k = faltante/10000;
    faltante %= 10000;
    devuelta5k = faltante/5000;
    faltante %= 5000;
    devuelta2k = faltante/2000;
    faltante %= 2000;
    devuelta1k = faltante/1000;
    faltante %= 1000;

    devuelta500 = faltante/500;
    faltante %= 500;
    devuelta200 = faltante/200;
    faltante %= 200;
    devuelta100 = faltante/100;
    faltante %= 100;
    devuelta50 = faltante/50;
    faltante %= 50;

    cout << endl << "50000: " << devuelta50k << endl;
    cout << "20000: " << devuelta20k << endl;
    cout << "10000: " << devuelta10k << endl;
    cout << "5000: " << devuelta5k << endl;
    cout << "2000: " << devuelta2k << endl;
    cout << "1000: " << devuelta1k << endl;
    cout << "500: " << devuelta500 << endl;
    cout << "200: " << devuelta200 << endl;
    cout << "100: " << devuelta100 << endl;
    cout << "50: " << devuelta50 << endl;
    cout << "Faltante: " << faltante << endl;
    return 0;
}

int problema4(){

    int horaInicial, suma_tiempo;
    cout << "Ingrese la hora inicial en formato hhmm(horas minutos): ";
    cin >> horaInicial;
    cout << "Ingrese el tiempo que le desea sumar en formato hhmm(horas minutos): ";
    cin >> suma_tiempo;

    int horasI = horaInicial/100;
    int minsI = horaInicial % 100;
    if (horasI < 0 || horasI >= 24 || minsI < 0 || minsI >= 60) {
        cout << endl << horaInicial << " es un tiempo invalido." << endl;
        return 0;
    }

    int tiempo_horas = suma_tiempo/100;
    int tiempo_mins = suma_tiempo % 100;
    int total_mins = (horasI*60 + minsI) + (tiempo_horas*60 + tiempo_mins);

    int horasF = (total_mins/60) % 24;
    int minsF = total_mins % 60;
    cout << endl << "La hora es " << horasF << minsF << "." << endl;

    return 0;
}

int problema6(){

    int a;
    cout << "Ingrese el numero de elementos para la aproximacion de e: ";
    cin >> a;

    double e = 0.0;
    long long factorial = 1;

    for (int i = 0; i < a; i++) {
        if (i > 0) {
            factorial *= i;
        }
        e += 1.0 / factorial;
    }

    cout << endl << "e es aproximadamente: " << e << endl;

    return 0;
}

int problema8(){

    int a, b, c;
    cout << "Ingrese tres numeros: ";
    cin >> a;
    cin >> b;
    cin >> c;
    int suma = 0;

    cout << endl;

    for (int i = a; i < c; i+=a) {
        suma += i;
        cout << i << " + ";
    }

    for (int i = b; i < c; i+=b){
        if (i%a != 0){
            suma += i;
            cout << i << " + ";
        }
    }

    cout << " = " << suma;

    return 0;
}

int problema10(){

    int n;
    cout << "Ingrese el numero n: ";
    cin >> n;
    int cont = 0;
    int num = 2;

    while (cont<n) {
        bool primo = true;
        for (int i = 2; i * i <= num ; ++i) {
            if(num%i == 0){
                primo = false;
                break;
            }
        }

        if(primo){
            cont++;
        }

        if(cont < n){
            num++;
        }

    }
    cout << endl << "El primo numero " << n << " es: " << num << endl;
    return 0;
}

int problema12() {

    int mayorPrimo;
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    int aux = n;

    while (n % 2 == 0) {
        mayorPrimo = 2;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            mayorPrimo = i;
            n /= i;
        }
    }

    if (n > 2) {
        mayorPrimo = n;
    }

    cout << "El mayor factor primo de " << aux << " es: " << mayorPrimo << endl;
    return 0;
}

int problema14() {
    int maxPalindromo = 0, factor1 = 0, factor2 = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int producto = i * j;
            if (producto > maxPalindromo && ejercicio20(producto)) {
                maxPalindromo = producto;
                factor1 = i;
                factor2 = j;
            }
        }
    }

    cout << endl << factor1 << "*" << factor2 << "=" << maxPalindromo << endl;
    return 0;
}

int problema16(){

    int k;
    cout << "Ingrese un numero k: ";
    cin >> k;

    int mejorSemilla = 0;
    int maxLongitud = 0;


    for (int j = 1; j < k; ++j) {

        int n = j;
        int contador = 1;
        cout << "Serie para la semilla " << j << ": ";

        while (n != 1) {
            cout << n << " ";
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            contador++;
        }
        cout << "1" << endl;


        if (contador > maxLongitud) {
            maxLongitud = contador;
            mejorSemilla = j;
        }
    }

    cout << endl << "La serie mas larga es con la semilla: " << mejorSemilla << ", teniendo " << maxLongitud << " terminos." << endl;
    return 0;
}

int main()
{
    problema16();

    return 0;
}
