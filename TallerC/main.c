#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


void numerosRomanos( char[20]);
void factoresPrimos(int);
void numerosEgolatras(int);
void nombrePropio(char[100]);
int countDigits(int);

int main() {
    char aux[50] ;
    char op;
    int a;

    while(op!=10) {
        printf("\n1.Numeros romanos"
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
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '10':
                printf("Gracias por utilizar nuestro software");
                break;
            default:
                printf("\nERROR Opcion invalida\n");
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
    if(a==1){
        printf("null\n");
    }else{
        printf("El numero es : %.1f \n\n",num);
    }
}

void factoresPrimos(int a){
   int con=0;
    for(int i=2; i > 1; i++){
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