#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


void numerosRomanos( char[20]);
void factoresPrimos(int);
void numerosEgolatras(int);
void nombrePropio(char[100]);
int countDigits(int);
bool friendsNumbers ( int , int );
char* convert (char*);
int pointProduct(int, int[], int[]);
void generarMatrizAleatoria(int filas, int columnas, int **matriz);
void imprimirMatriz(int filas, int columnas, int **matriz);
int **multiplicarMatrices(int filas1, int columnas1, int **matriz1, int filas2, int columnas2, int **matriz2);
void generateMagicMatrix(int n, int matriz[][n]);
void printMatrix(int n, int matriz[][n]);



int main() {
    char aux[50] ;
    char op;
    int a;
    int b;
    int c;
    char date[30];
    int size1;
    int size2;
    int n;


    while(op!=10) {

        printf("--------------------------"
               "\n1.Numeros romanos"
               "\n2.Factores primos"
               "\n3.Nombre propio"
               "\n4.Numeros egolatras"
               "\n5.Numeros amigos"
               "\n6.Fechas"
               "\n7.Producto punto"
               "\n8.Multiplicacion de matrices"
               "\n9.Matriz magica"
               "\n10.Salir\n"
               "Ingrese una opcion:\n");
        scanf("%c", &op);

        while (getchar() != '\n');
        switch (op) {
            case '1':
                printf("Ingrese el numero romano:\n");
                fgets(aux,20,stdin);
                numerosRomanos(aux);
                break;

            case '2':
                printf("Ingrese un numero:\n");
                scanf("%i", &a);
                factoresPrimos(a);
                break;

            case '3':
                printf("Ingrese una palabra:\n");
                fgets(aux,100,stdin);
                nombrePropio(aux);
                break;

            case '4':
                printf("Ingrese un numero:\n");
                scanf("%d", &a);
                numerosEgolatras(a);
                break;

            case '5':

                b= 0;
                c= 0;

                printf("\nIngrese el primer numero para comprobar: \n");
                scanf("%i", &b);

                    printf("Ingrese el segundo numero a comprobar: \n");
                    scanf("%i", &c);

                printf("Los numeros %i y %i", b, c);

                if(friendsNumbers(b, c)==true){
                    printf(" SI son amigos\n");
                }else{
                    printf(" NO son amigos\n");
                }
                getchar();
                getchar();

                break;
            case '6':

                printf("Ingrese la fecha en formato dd/mm/aaaa: ");
                fgets(date, sizeof(date), stdin);

                int len = strlen(date);
                if (len > 0 && date[len - 1] == '\n') {
                    date[len - 1] = '\0';
                }

                char* resultado= convert(date);
                printf("%s", resultado);

                getchar();

                break;
            case '7':


                printf("Ingrese el tamano del vector 1: ");
                scanf("%d", &size1);
                int resultadoo=0;

                printf("Ingrese el tamano del vector 2: ");
                scanf("%d", &size2);

                if(size1==size2){

                int vector1[size1];
                int vector2[size2];

                printf("\nIngrese los elementos del primer vector:\n");
                for (int i = 0; i < size1; i++) {
                    printf("Elemento %d: ", i + 1);
                    scanf("%d", &vector1[i]);
                }

                printf("\nIngrese los elementos del segundo vector:\n");
                for (int i = 0; i < size2; i++) {
                    printf("Elemento %d: ", i + 1);
                    scanf("%d", &vector2[i]);
                }

                resultadoo = pointProduct(size1, vector1, vector2);

                if (resultadoo != -1) {
                    printf("El producto punto de los vectores es: %d\n", resultadoo);
                }else{
                    printf("No fue posible hacer la operacion\n");
                }}else{
                    printf("Los vectores deben tener el mismo tamano\n");
                }
                getchar();getchar();

                break;
            case '8':

                printf("");
                int filas1, columnas1, filas2, columnas2;

                printf("Ingrese el numero de filas de la primera matriz: ");
                scanf("%d", &filas1);
                printf("Ingrese el numero de columnas de la primera matriz: ");
                scanf("%d", &columnas1);

                printf("\nIngrese el numero de filas de la segunda matriz: ");
                scanf("%d", &filas2);
                printf("Ingrese el numero de columnas de la segunda matriz: ");
                scanf("%d", &columnas2);

                if(filas1 ==0 || filas2 ==0 || columnas1== 0|| columnas2==0){

                    printf("El tamano de una fila o columna no puede ser 0\n");
                    while (getchar() != '\n');
                    break;
                }

                if (columnas1 != filas2) {
                    printf("No es posible multiplicar las matrices. El numero de columnas de la primera matriz "
                           "debe ser igual al numero de filas de la segunda matriz.\n");
                    while (getchar() != '\n');
                    break;
                }

                int **matriz1 = (int **)malloc(filas1 * sizeof(int *));
                int **matriz2 = (int **)malloc(filas2 * sizeof(int *));
                int **resultad;

                for (int i = 0; i < filas1; i++) {
                    matriz1[i] = (int *)malloc(columnas1 * sizeof(int));
                }

                for (int i = 0; i < filas2; i++) {
                    matriz2[i] = (int *)malloc(columnas2 * sizeof(int));
                }

                generarMatrizAleatoria(filas1, columnas1, matriz1);
                generarMatrizAleatoria(filas2, columnas2, matriz2);

                printf("\n\nPrimera Matriz:\n");
                imprimirMatriz(filas1, columnas1, matriz1);

                printf("\nSegunda Matriz:\n");
                imprimirMatriz(filas2, columnas2, matriz2);

                resultad = multiplicarMatrices(filas1, columnas1, matriz1, filas2, columnas2, matriz2);

                if (resultad != NULL) {

                    printf("\nResultado de la multiplicacion:\n");
                    imprimirMatriz(filas1, columnas2, resultad);

                    for (int i = 0; i < filas1; i++) {
                        free(resultad[i]);
                    }
                    free(resultad);
                } else {
                    printf("\nNo es posible realizar la multiplicacion.\n");
                    while (getchar() != '\n');
                }

                for (int i = 0; i < filas1; i++) {
                    free(matriz1[i]);
                }
                free(matriz1);

                for (int i = 0; i < filas2; i++) {
                    free(matriz2[i]);
                }
                free(matriz2);

                getchar();getchar();

                break;

            case '9':

                printf("Ingrese el orden de la matriz magica (impar): ");
                scanf("%d", &n);

                if (n % 2 == 0) {
                    printf("El orden debe ser un numero impar.\n");
                    while (getchar() != '\n');
                    break;

                }

                int **matriz = (int **)malloc(n * sizeof(int *));
                for (int i = 0; i < n; i++) {
                    matriz[i] = (int *)malloc(n * sizeof(int));
                }
                generateMagicMatrix(n, matriz);

                printf("\nMatriz Magica de Orden %d x %d:\n", n, n);
                printMatrix(n, matriz);

                getchar();getchar();

                break;
            case '10':
                printf("Gracias por utilizar nuestro software");
                break;
            default:
                printf("\nERROR Opcion invalida o dato invalido\n");
                break;
        }

    }
    return 0;
}

void numerosRomanos(char aux[20]) {
    double num=0;
    short int a=0;


    for (int i = 0; i <strlen(aux)-1; i++) {
        switch (aux[i]) {
            case 'I':
                num += 1;
                a=(aux[i+1]=='I' & aux[i+2]=='I' & aux[i+3]=='I') ? a=1:a;
                a=(aux[i-1]=='V' & aux[i+1]=='V'
                        ||aux[i-1]=='L' & aux[i+1]=='L'
                        ||aux[i-1]=='C' & aux[i+1]=='C'
                        ||aux[i-1]=='D' & aux[i+1]=='D'
                        ||aux[i-1]=='M' & aux[i+1]=='M') ? a=1:a;
                break;
            case 'V':
                num += 5;
                num=(aux[i-1]=='I') ? num-2:num;
                a=(aux[i-1]=='V') ? a=1:a;
                a=(aux[i-1]=='I' & aux[i+1]=='I'
                   || aux[i-1]=='X' & aux[i+1]=='X'
                   || aux[i-1]=='L' & aux[i+1]=='L'
                   ||aux[i-1]=='C' & aux[i+1]=='C'
                   ||aux[i-1]=='D' & aux[i+1]=='D'
                   ||aux[i-1]=='M' & aux[i+1]=='M') ? a=1:a;

                break;
            case 'X':
                num += 10;
                num=(aux[i-1]=='I') ? num-2:num;
                a=(aux[i+1]=='X' & aux[i+2]=='X' & aux[i+3]=='X') ? a=1:a;
                a=(aux[i-1]=='I' & aux[i+1]=='I'
                   || aux[i-1]=='V' & aux[i+1]=='V'
                   || aux[i-1]=='L' & aux[i+1]=='L'
                   ||aux[i-1]=='D' & aux[i+1]=='D'
                   ||aux[i-1]=='M' & aux[i+1]=='M') ? a=1:a;
                break;

            case 'L':
                num += 50;
                num=(aux[i-1]=='X') ? num-20:num;
                a=(aux[i-1]=='L') ? a=1:a;
                a=(aux[i-1]=='I') ? a=1:a;
                a=(aux[i-1]=='V') ? a=1:a;
                a=(aux[i-1]=='I' & aux[i+1]=='I'
                   || aux[i-1]=='V' & aux[i+1]=='V'
                   || aux[i-1]=='X' & aux[i+1]=='X'
                   ||aux[i-1]=='C' & aux[i+1]=='C'
                   ||aux[i-1]=='D' & aux[i+1]=='D'
                   ||aux[i-1]=='M' & aux[i+1]=='M') ? a=1:a;

                break;

            case 'C':
                num += 100;
                num=(aux[i-1]=='X') ? num-20:num;
                a=(aux[i+1]=='C' & aux[i+2]=='C' & aux[i+3]=='C') ? a=1:a;
                a=(aux[i-1]=='I' & aux[i+1]=='I'
                   || aux[i-1]=='V' & aux[i+1]=='V'
                   || aux[i-1]=='X' & aux[i+1]=='X'
                   ||aux[i-1]=='L' & aux[i+1]=='L'
                   ||aux[i-1]=='D' & aux[i+1]=='D')? a=1:a;
                break;

            case 'D':
                num += 500;
                num=(aux[i-1]=='X') ? num-20:num;
                num=(aux[i-1]=='C') ? num-200:num;
                a=(aux[i-1]=='I') ? a=1:a;
                a=(aux[i-1]=='D' ||aux[i-1]=='V' || aux[i-1]=='L') ? a=1:a;
                a=(aux[i-1]=='I' & aux[i+1]=='I'
                   || aux[i-1]=='V' & aux[i+1]=='V'
                   || aux[i-1]=='X' & aux[i+1]=='X'
                   ||aux[i-1]=='L' & aux[i+1]=='L'
                   ||aux[i-1]=='C' & aux[i+1]=='C'
                   ||aux[i-1]=='M' & aux[i+1]=='M') ? a=1:a;

                break;

            case 'M':
                num += 1000;
                num = (aux[i-1]=='C') ? num-200:num;
                a=(aux[i+1]=='M' & aux[i+2]=='M' & aux[i+3]=='M') ? a=1:a;
                a=(aux[i-1]=='I') ? a=1:a;
                a=(aux[i-1]=='I' & aux[i+1]=='I'
                   || aux[i-1]=='V' & aux[i+1]=='V'
                   || aux[i-1]=='X' & aux[i+1]=='X'
                   ||aux[i-1]=='L' & aux[i+1]=='L'
                   ||aux[i-1]=='C' & aux[i+1]=='C'
                   ||aux[i-1]=='D' & aux[i+1]=='D') ? a=1:a;
                break;

            default:
                a=1;
                break;
        }
    }
    if(a==1  || num==0){
        printf("null\n");
    }else{
        printf("El numero es : %.1f \n\n",num);
    }
}

void factoresPrimos(int a){
   int con=0;
    for(int i=2; a > 1; i++){
        con=0;
        while(a%i==0){
            con++;
           a=a/i;
           if(a%i!=0){
               if(con > 1){
                   printf("%d^%d ",i,con);
               }else{
                   printf(" %d ",i);
               }
           }
        }
    }
    printf("\n");
}

void numerosEgolatras(int num){
    int originalNum = num;
    int n = countDigits(num);
    int sum = 0;

    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, n);
        num /= 10;
    }
    if(sum == originalNum ? printf("True\n"): printf("False\n"));
}

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

void nombrePropio(char aux[100]){
      int con=strlen(aux);
      char nuevo[100];
      char b;

      if(con==2){
          b= tolower(aux[0]);
          printf("%c",b);
      }else{
          nuevo[0]=toupper(aux[0]);

          for(int i=1; i <= con; i++){
              if(aux[i-1]==' '){
                  nuevo[i]= toupper(aux[i]);
              }else{
                  nuevo[i]= tolower(aux[i]);
              }
          }
          printf("%s",nuevo);
      }
}

bool friendsNumbers (int a, int b){

    int auxA;
    int auxB;

    for(int i=1; i<a-1;i++){

        if(a%i==0){
            auxA+=i;
        }
    }
    for(int i=1; i<b-1;i++){

        if(b%i==0){
            auxB+=i;
        }
    }

    if(auxA==b && auxB==a && a!=0 && b!=0){
        return true;
    }

    return false;
}

bool esAnioBisiesto(int anio) {

    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool esFechaValida(int dia, int mes, int anio) {

    if (mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    int diasEnMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && esAnioBisiesto(anio)) {

        diasEnMes[2] = 29;
    }

    return dia <= diasEnMes[mes];
}

char* convert(char* fecha) {
    static char resultado[50];

    int dia, mes, anio;

    char* nombresMeses[] = {"", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    if (sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio) == 3 && esFechaValida(dia, mes, anio)) {

        snprintf(resultado, sizeof(resultado), "%d de %s de %d", dia, nombresMeses[mes], anio);
    } else {

        snprintf(resultado, sizeof(resultado), "Fecha no valida");
    }

    return resultado;
}

int pointProduct(int size, int vector1[size], int vector2[size]) {
    int resultado = 0;

    if (size <= 0) {
        printf("Error: Los tamanos de los vectores deben ser positivos y no nulos.\n");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        resultado += vector1[i] * vector2[i];
    }

    return resultado;
}

void generarMatrizAleatoria(int filas, int columnas, int **matriz) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void imprimirMatriz(int filas, int columnas, int **matriz) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
}

int **multiplicarMatrices(int filas1, int columnas1, int **matriz1, int filas2, int columnas2, int **matriz2) {
    int **resultado;

    resultado = (int **)malloc(filas1 * sizeof(int *));
    for (int i = 0; i < filas1; i++) {
        resultado[i] = (int *)malloc(columnas2 * sizeof(int));
    }

    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            for (int k = 0; k < columnas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

void generateMagicMatrix(int n, int matriz[][n]) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    i = 0;
    j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        matriz[i][j] = num;

        i--;
        j++;

        if (i < 0) {
            i = n - 1;
        }
        if (j == n) {
            j = 0;
        }

        if (matriz[i][j] != 0) {
            i += 2;
            j--;

            if (i >= n) {
                i -= n;
            }
            if (j < 0) {
                j = n - 1;
            }
        }
    }
}

void printMatrix(int n, int matriz[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%4d]", matriz[i][j]);
        }
        printf("\n");
    }
}






