//
//  main.c
//  AvanceProyecto
//
//  Created by CarlosGutierrez on 10/28/14.
//  Copyright (c) 2014 Carlos. All rights reserved.
//  El código es algo hermoso, se le necesita dedicar tiempo.
//  A01360231

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int llenar();
int barajear();
int imprime();
int mano1();
int mano2();
int mano3();
int mano4();
int checarCorrida();
int checarCorrida2();
int checarCorrida3();
int checarCorrida4();
int ordenar();
int submain();

int main()
{
    submain();
    return 0;
}

int submain()
{
    int baraja[52];     //Se crea la baraja con todas las cartas del deck
    int mano[5];        // Se crea el arreglo para todas las cartas en la mano
    int jugador1[5];
    int aux = 0;
    llenar(baraja);
    while(aux == 0)
    {
        barajear(baraja);
        imprime(baraja);
        mano1(baraja, jugador1);
        mano2(baraja, mano);
        mano3(baraja, mano);
        mano4(baraja, mano);
        checarCorrida(mano);
        checarCorrida2(mano);
        checarCorrida3(mano);
        checarCorrida4(mano);
        printf("\nDesea seguir jugando? En caso afirmativo ingresa 0, en caso negativo ingresa 1\n");
        scanf("%d",&aux);
    }
    
    return 0;
    
}

int llenar(int bar[])
{      //FunciÃ³n para llenar la baraja con nÃºmeros del arreglo
    int i;
    for(i = 0; i < 52; i++) {
        bar[i] = i;
    }
    return 0;
}


/*
int llenar(int bar[])
{      //Función para llenar la baraja con números del arreglo
    int j,i;
    int inicio = 0;         //Variable para determinar cuando inicia el número del índice del arreglo para agregarle los 4 números necesarios de la baraja
    int termino = 4;        //Variable para determinar cuando termina el número del índice del arreglo
    for(i = 1; i < 14; i++)
    {        //For loop para i que va a sumar de uno en uno para poder llegar del 1 al 13
        for(j = inicio; j < termino; j++)       //For loop para poder ir sumando de 4 en 4 para poder asignar los valores adecuados a cada índice
            bar[j] = i;
        inicio += 4;
        termino += 4;
    }
    return 0;
}*/

int imprime(int bar[])
{         //FunciÃ³n para imprimir los valores de las cartas
    printf("Valores de Cartas:\n");
    int i;
    for(i = 0; i < 52; i++)     //Con un for loop, vamos imprimiendo cada Ã­ndice en el arreglo
    {
        char* number;
        char* suit;
        
        if(bar[i] % 13 == 0) {
            number = "Ace";
        } else if(bar[i] % 13 == 1) {
            number = "2";
        } else if(bar[i] % 13 == 2) {
            number = "3";
        } else if(bar[i] % 13 == 3) {
            number = "4";
        } else if(bar[i] % 13 == 4) {
            number = "5";
        } else if(bar[i] % 13 == 5) {
            number = "6";
        } else if(bar[i] % 13 == 6) {
            number = "7";
        } else if(bar[i] % 13 == 7) {
            number = "8";
        } else if(bar[i] % 13 == 8) {
            number = "9";
        } else if(bar[i] % 13 == 9) {
            number = "10";
        } else if(bar[i] % 13 == 10) {
            number = "Jack";
        } else if(bar[i] % 13 == 11) {
            number = "Queen";
        } else if(bar[i] % 13 == 12) {
            number = "King";
        }
        
        if(bar[i] / 13 == 0) {
            suit = "Diamonds";
        } else if(bar[i] / 13 == 1) {
            suit = "Hearts";
        } else if(bar[i] / 13 == 2) {
            suit = "Spades";
        } else if(bar[i] /13 == 3) {
            suit = "Clubs";
        }
        printf("Valor en %d : %s de %s\n",i,number, suit);
    }
    
    return 0;
}


/*
int imprime(int bar[])
{         //Función para imprimir los valores de las cartas
    printf("Valores de Cartas:\n");
    int i;
    for(i = 0; i < 52; i++)     //Con un for loop, vamos imprimiendo cada índice en el arreglo
        printf("Valor en %d : %d\n",i,bar[i]);
    return 0;
}
*/


int barajear(int bar[])
{        //Función para poner en aleatorio todos los valores del arreglo
    int i,z,aux;
    srand((unsigned int)time(NULL));        //Aquí se hacen aleatorios todos los valores, el time es para que con el tiempo podamos tener nuevos números aleatorios
    for(i = 0; i < 52; i++)
    {            //For loop para poder poner en aleatorio todos los números del arreglo
        z = rand() % 52;        //Se ponen en aleatorio los numeros de la variable z con un modular de 52 para poder tener siempre números diferentes
        aux = bar[i];           //Se asigna el valor de i en la baraja a aux
        bar[i] = bar[z];        //Se asigna el valor de z en la baraja a i
        bar[z] = aux;           //Se asigna el valor de aux a el valor de z en la baraja para poder asignar nuevos números a ella en cada indice del arreglo
    }
    return 0;
}

int ordenar(int man[])
{         //Algoritmo Selection Sort para ordenar los números
    int i,j,aux;
    for(i = 0; i < 5; i++)
    {     //For loop para poder subir en los 5 índices en el arreglo
        int min = man[i];       //Se asigna el valor de i en la mano a la variable que será el mínimo en este caso
        int pos = i;            //Se asigna i a la variable de la posición en la que va
        for(j = i+1; j < 5; j++)    //For loop para poder ir entre todos los valores de los índices en el arreglo
            if(man[j] < min)
            {       //Si El valor de j en la mano es menor al mínimo
                min = man[j];       //Se asigna el valor de la mano en j al mínimo
                pos = j;            //Se asigna el valor de j a la posición
            }
        aux = man[i];           //La variable i en la mano se asigna a la variable de auxiliar para poder cambiar los valores
        man[i] = min;           //El valor del i en el arreglod e la mano se asigna al mínimo
        man[pos] = aux;     //El aux se asigna a la posición del arreglo
    }
    return 0;
}

int mano1(int bar[], int jugador1[]){           //Función para poder rapartir la baraja a una mano
    int i,j;
    srand((unsigned int)time(NULL));        //Se randomiza
    j = rand() % 52;            //Se asigna el número random con un modular de 52 a j
    for(i = 0; i < 5; i++){     // For loop para poder ir de índice 0 a índice 4
        while(bar[j] == jugador1[0] || bar[j] == jugador1[1]|| bar[j] == jugador1[2] || bar[j] == jugador1[3] ||bar[j] == jugador1[4])      //While loop para poder asignar un índice en específico a algún índice en j
            j = rand() % 52;        //Se asigna el número random con un modular de 52 a j otra vez para poder repetir el procedimiento en el while
        jugador1[i] = bar[j];       //El índice de j se asigna al índice de i
    }
    printf("\nMano 1: %d,%d,%d,%d,%d",jugador1[0],jugador1[1], jugador1[2], jugador1[3],jugador1[4]);       // Imprimimos el valor de las cartas en la mano del jugador
    ordenar(jugador1);                                                              //Ordenamos números
    printf("\nMano 1: %d,%d,%d,%d,%d\n",jugador1[0],jugador1[1], jugador1[2], jugador1[3],jugador1[4]);
    return 0;
}

int mano2(int bar[], int mano2[]){           //Función para poder rapartir la baraja a una mano
    int i,k;
    srand((unsigned int)time(NULL));        //Se randomiza
    k = rand() % 52;            //Se asigna el número random con un modular de 52 a j
    for(i = 0; i < 5; i++){     // For loop para poder ir de índice 0 a índice 4
        while(bar[k] == mano2[0] || bar[k] == mano2[1]|| bar[k] == mano2[2] || bar[k] == mano2[3] ||bar[k] == mano2[4])      //While loop para poder asignar un índice en específico a algún índice en j
            k = rand() % 52;        //Se asigna el número random con un modular de 52 a j otra vez para poder repetir el procedimiento en el while
        mano2[i] = bar[k];       //El índice de j se asigna al índice de i
    }
    printf("\nMano 2: %d,%d,%d,%d,%d",mano2[0],mano2[1], mano2[2], mano2[3],mano2[4]);       // Imprimimos el valor de las cartas en la mano del jugador
    ordenar(mano2);                                                              //Ordenamos números
    printf("\nMano 2: %d,%d,%d,%d,%d\n",mano2[0],mano2[1], mano2[2], mano2[3],mano2[4]);
    return 0;
}

int mano3(int bar[], int mano[]){           //Función para poder rapartir la baraja a una mano
    int i,j;
    srand((unsigned int)time(NULL));        //Se randomiza con el tiempo
    j = rand() % 52;            //Se asigna el número random con un modular de 52 a j
    for(i = 0; i < 5; i++){     // For loop para poder ir de índice 0 a índice 4
        while(bar[j] == mano[0] || bar[j] == mano[1]|| bar[j] == mano[2] || bar[j] == mano[3] ||bar[j] == mano[4])      //While loop para poder asignar un índice en específico a algún índice en j
            j = rand() % 52;        //Se asigna el número random con un modular de 52 a j otra vez para poder repetir el procedimiento en el while
        mano[i] = bar[j];       //El índice de j se asigna al índice de i
    }
    printf("\nMano 3: %d,%d,%d,%d,%d",mano[0],mano[1], mano[2], mano[3],mano[4]);       // Imprimimos el valor de las cartas en la mano del jugador
    ordenar(mano);                                                              //Ordenamos números
    printf("\nMano 3: %d,%d,%d,%d,%d\n",mano[0],mano[1], mano[2], mano[3],mano[4]);
    return 0;
}

int mano4(int bar[], int mano[]){           //Función para poder rapartir la baraja a una mano
    int i,j;
    srand((unsigned int)time(NULL));        //Se randomiza
    j = rand() % 52;            //Se asigna el número random con un modular de 52 a j
    for(i = 0; i < 5; i++){     // For loop para poder ir de índice 0 a índice 4
        while(bar[j] == mano[0] || bar[j] == mano[1]|| bar[j] == mano[2] || bar[j] == mano[3] ||bar[j] == mano[4])      //While loop para poder asignar un índice en específico a algún índice en j
            j = rand() % 52;        //Se asigna el número random con un modular de 52 a j otra vez para poder repetir el procedimiento en el while
        mano[i] = bar[j];       //El índice de j se asigna al índice de i
    }
    printf("\nMano 4: %d,%d,%d,%d,%d",mano[0],mano[1], mano[2], mano[3],mano[4]);       // Imprimimos el valor de las cartas en la mano del jugador
    ordenar(mano);                                                              //Ordenamos números
    printf("\nMano 4: %d,%d,%d,%d,%d\n",mano[0],mano[1], mano[2], mano[3],mano[4]);
    return 0;
}

int checarCorrida(int mano[]){      //Función para poder revisar si es una corrida
    int i;
    int aux = 0;
    for(i = 4; i > 0; i--)              //For loop decremental para poder revisar todos los índices del arreglo
        if(mano[i] != mano[i-1]+1)      //si el valor de i en el arreglo de la mano no es igual al arreglo de i menos 1
            aux = 1;        //El valor del auxiliar es igual a uno para poder compararlo despues
    if(aux == 0)            //Si el valor del auxiliar es 0 se imprime la corrida
        printf("\nCorrida del %d al %d",mano[0],mano[4]);
    else
        printf("\nNo es corrida");
    return 0;
}

int checarCorrida2(int mano2[])
{      //Función para poder revisar si es una corrida
    int i;
    int aux = 0;
    for(i = 4; i > 0; i--)              //For loop decremental para poder revisar todos los índices del arreglo
        if(mano2[i] != mano2[i-1]+1)      //si el valor de i en el arreglo de la mano no es igual al arreglo de i menos 1
            aux = 1;        //El valor del auxiliar es igual a uno para poder compararlo despues
    if(aux == 0)            //Si el valor del auxiliar es 0 se imprime la corrida
        printf("\nCorrida del %d al %d",mano2[0],mano2[4]);
    else
        printf("\nNo es corrida");
    return 0;
}

int checarCorrida3(int mano[])
{      //Función para poder revisar si es una corrida
    int i;
    int aux = 0;
    for(i = 4; i > 0; i--)              //For loop decremental para poder revisar todos los índices del arreglo
        if(mano[i] != mano[i-1]+1)      //si el valor de i en el arreglo de la mano no es igual al arreglo de i menos 1
            aux = 1;        //El valor del auxiliar es igual a uno para poder compararlo despues
    if(aux == 0)            //Si el valor del auxiliar es 0 se imprime la corrida
        printf("\nCorrida del %d al %d",mano[0],mano[4]);
    else
        printf("\nNo es corrida");
    return 0;
}

int checarCorrida4(int mano[])
{      //Función para poder revisar si es una corrida
    int i;
    int aux = 0;
    for(i = 4; i > 0; i--)              //For loop decremental para poder revisar todos los índices del arreglo
        if(mano[i] != mano[i-1]+1)      //si el valor de i en el arreglo de la mano no es igual al arreglo de i menos 1
            aux = 1;        //El valor del auxiliar es igual a uno para poder compararlo despues
    if(aux == 0)            //Si el valor del auxiliar es 0 se imprime la corrida
        printf("\nCorrida del %d al %d",mano[0],mano[4]);
    else
        printf("\nNo es corrida");
    return 0;
}


