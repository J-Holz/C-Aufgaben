/* Vektorberechnung um Länge zweier Vektoren und Winkel dazwischen zu berechnen */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define PI 3.14159265358979323846

int calcAngle();
double calcLen(int v);

/*Initialisierung globaler Variablen*/
double aVek[2][3];
double aLen[2];

int main()
{
    char plc;
    int v;
    int z;

    printf("Es wird die Länge zwischen zwei Vektoren und der Winkel zwischen diesen berechnet.\n\n");


    /*Vektoren einlesen*/
    for(v=0; v<=1; v++){
        for(z=0; z<=2; z++){
            printf("Gib den %i. Wert für Vektor %i ein.\n", z+1, v+1);
            scanf("%lf%c", &aVek[v][z], &plc);
        }
        if(aVek[v][0] == 0 && aVek[v][1] == 0 && aVek[v][2] == 0){
            printf("Es wurde ein Nullvektor eingegeben. Dieser ist ungültig und nicht zur Berechnung geeignet. Bitte versuche es erneut.\n");
            return 1;
        }
        aLen[v] = calcLen(v);
    }



    calcAngle();

    return 0;
}

/*Funktion für die Berechnung der Länge*/
double calcLen(int v){
    aLen[v] = (aVek[v][0]*aVek[v][0]) 
            + (aVek[v][1]*aVek[v][1]) 
            + (aVek[v][2]*aVek[v][2]);

    printf("Die Länge des %i. Vektors beträgt %lf.\n\n", v+1, sqrt(aLen[v]));

    return sqrt(aLen[v]);
}

/*Funktion für die Berechnung des Winkels*/
int calcAngle(){

    /*Skalarprodukt*/
    double skal = (aVek[0][0]*aVek[1][0])
                + (aVek[0][1]*aVek[1][1])
                + (aVek[0][2]*aVek[1][2]);

    /*Winkel berechnen*/
    double x = skal / (aLen[0] * aLen[1]);
    if(x < -1 || x > 1){
        printf("Der Arkuskosinus konnte nicht berechnet werden, bitte versuche es erneut.");
        return 1;
    }
    double sol =  (acos (x)) * (180 / PI);
    

    printf("Der Winkel zwischen beiden Vektoren beträgt %lf Grad.\n", sol);
    return 0;
}


/*a11.Die Komponenten zweier dreidimensionaler Vektoren sind einzulesen. Die
Länge der beiden Vektoren und der Winkel zwischen ihnen sind zu berechnen.*/