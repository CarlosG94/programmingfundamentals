//
//  main.c
//  NumerosPascal
//
//  Created by CarlosGutierrez on 10/5/14.
//  Copyright (c) 2014 Carlos. All rights reserved.
//

#include <stdio.h>

/*
 *  Aquí se crea una función que imprime tres líneas vacías y los asterísticos que se piden en la tarea
 */

void separacion()
{
    printf("\n\n\n");   //Se imprimen tres enters
    printf("*********************************************\n");   //Se imprimen asteríscos que se usarán para separar el código
}


/*
 *  Se declara una función para crear el factorial
 */

long factorial(int x)   //Función para crear el factorial
{
    if(x == 0) return 1;    //Cuando x sea igual a 0, regresa 1;
    long result = 1;        //se crea una variable result y se le da un valor de uno
    while (x >= 1) {        //Cuando x sea mayor o igual a 1
        result *= x;        //Result por x
        x--;                //Se decrementa x menos uno
    }
    return result;
}

/*
 *  Triángulo de Pascal hecho con For Incremental
 */

void loopForIncremental(int n)
{
    int i, j;           //Se declran dos funciones, i y j
    printf("For Incremental Función\n");        //Título que saldrá en el output
    for(i = 0; i <= n; i++) {               //Se crea el loop para los renglones
        for(j = 0; j <= i; j++) {           //Se crea el loop para poder imprimir las sumas
            printf("%ld\t", factorial(i) / (factorial(i-j)*factorial(j)));      //Ecuación para factorial
        }
        printf("\n");
    }
    separacion();
}


/*
 *  Triángulo de Pascal hecho con For Decremental
 */

void loopForDecremental(int n)
{
    int i, j;
    printf("For Decremental Función\n");        //Título que saldrá en el output
    for(i = n; i >= 0; i--) {                   //Se crea el loop para los renglones
        for(j = (n-i); j >= 0; j--) {           //Se crea el loop para poder imprimir las sumas
            printf("%ld\t", factorial(n-i) / (factorial((n-i)-j)*factorial(j)));        //Ecuación para factorial
        }
        printf("\n");
    }
    separacion();
}

/*
 *  Triángulo de Pascal hecho con While Incremental
 */

void loopWhileIncremental(int n)
{
    int i = 0, j;
    printf("While Incremental Función\n");      //Título que saldrá en el output
    while (i <= n) {                            //Se crea el loop para los renglones
        j = 0;
        while(j <= i) {                         //Se crea el loop para poder imprimir las sumas
            printf("%ld\t", factorial(i) / (factorial(i-j)*factorial(j)));       //Ecuación para factorial
            j++;
        }
        i++;
        printf("\n");
    }
    separacion();
}

/*
 *  Triángulo de Pascal hecho con While Decremental
 */

void loopWhileDecremental(int n)
{
    int i = n, j;
    printf("While Decremental Función\n");      //Título que saldrá en el output
    while (i >= 0) {                            //Se crea el loop para los renglones
        j = (n - i);
        while(j >= 0) {                         //Se crea el loop para poder imprimir las sumas
            printf("%ld\t", factorial(n-i) / (factorial((n-i)-j)*factorial(j)));           //Ecuación para factorial
            j--;
        }
        i--;
        printf("\n");
    }
    separacion();
}

/*
 *  Triángulo de Pascal hecho con Do While Incremental
 */

void loopDoWhileIncremental(int n)
{
    int i = 0, j;
    printf("Do While Incremental Función\n");       //Título que saldrá en el output
    do {
        j = 0;
        do {
            printf("%ld\t", factorial(i) / (factorial(i-j)*factorial(j)));      //Ecuación para factorial
            j++;
        } while (j <= i);               //Se crea el loop para los renglones
        i++;
        printf("\n");
    } while(i <= n);                     //Se crea el loop para poder imprimir las sumas
    separacion();
}

/*
 *  Triángulo de Pascal hecho con Do While Decremental
 */

void loopDoWhileDecremental(int n)
{
    int i = n, j;
    printf("Do While Decremental Función\n");       //Título que saldrá en el output
    do {
        j = n-i;
        do {
            printf("%ld\t", factorial(n-i) / ((factorial((n-i)-j)*factorial(j))));      //Ecuación para factorial
            j--;
        } while (j >= 0);           //Se crea el loop para los renglones
        i--;
        printf("\n");
    } while(i >= 0);                //Se crea el loop para poder imprimir las sumas
    printf("\n");
    separacion();
}

/*
 *  Se mandan llamar todas las funciones
 */

void llamandoFunciones(int n)
{
    //for loop, incremental
    loopForIncremental(n);
    
    //for loop, decremental
    
    loopForDecremental(n);
    
    //while loop, incremental
    
    loopWhileIncremental(n);
    
    //while loop, decremental
    
    loopWhileDecremental(n);
    
    //do while loop, incremental
    
    loopDoWhileIncremental(n);
    
    //do while loop, decremental
    
    loopDoWhileDecremental(n);
}

/*
 *  Bonus
 */

void bonus(long n)
{
    int i, j;
    
    printf("BONUS\n");
    printf("Introduzca el número de líneas que le gustaría ver en el triángulo de pascal:\n");
    scanf("%ld",&n);
    
    for ( i = 0 ; i <= n ; i++ )
    {
        for( j = 0 ; j <= i ; j++ ) {
            printf("%ld \t",factorial(i)/(factorial(i-j)*factorial(j)));
        }
        printf("\n");
    }
}


/*
 *  Main
 */

int main()
{
    int n = 10;
    llamandoFunciones(n);       //Se le da un valor a n, que será ejecutado en la función llamandoFunciones
    
    bonus(n);       //Se llama la función de bonus
    
    /***************************************************************/
    
    unsigned int x, y, i, power; // define variables
    
    i = 1; // set i
    power = 1; // set power
    printf( "%s", "Enter first integer: " );
    scanf( "%u", &x ); // read value for x from user
    printf( "%s", "Enter second integer: " );
    scanf( "%u", &y ); // read value for y from user
    
    while ( i <= y ) { // loop while i is less than or equal to y
        power *= x; // multiply power by x
        ++i; // increment i
    } // end while
    
    printf( "%u\n", power );
    
    return 0;
}
