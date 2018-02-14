#include <stdio.h>

int a();
int b();

int main()
{
    char bool;

    /*Welche Aufgabenstellung?*/
    printf("Möchtest du die Anzahl der Zahlen direkt festlegen? (y/n)\n\n");
    scanf("%c", &bool);

    /*Aufgabe a)*/
    if(bool == 'y'){
        a();

    /*Aufgabe b)*/
    }else if(bool == 'n'){
        b();

    /*Invalide Eingaben*/
    }else{
        printf("%c ist eine invalide Eingabe, bitte Versuche es erneut.\n\n", bool);
        main();
    }
    return 0;
}



int a()
{
    int count;
    int i;
    float z;
    float solution = 0;

    /*Anzahl einzulesende Zahlen*/
    /*TO DO: Wenn Eingabe m, fällt alles auseinander.*/
    printf("Wie viele Zahlen möchtest du eingeben?");
    scanf("%i", &count);

    /*Soderfälle*/
    if(count<=0){
        printf("%i ist eine invalide Eingabe, bitte versuche es erneut.\n\n", count);
        a();
        return 0;
    }

    /*Einlesen der Zahlen*/
    for(i = 1; i<=count; i++){
        printf("Gib den %i. Wert ein.\n", i);
        scanf("%f", &z);
        solution = solution + z;
    }

    /*Auswerten des Durchschnitts*/
    printf("Der Durchschnitt beträgt %f", solution/count);

    return 0;
}

int b()
{
    int count = 0;
    float z;
    float solution = 0;
    char bool;

    while (1){
        count++;

        /*Neue Zahl einlesen*/
        printf("Gib den %i. Wert ein.", count);
        scanf("%f%c", &z, &bool);
        
        solution = solution + z;

        /*Ein weiterer Wert?*/
        printf("Möchtest du einen weiteren Wert eingeben? (y/n)");
        scanf("%c", &bool);


        /*Schleifenausbruch*/
        if(bool == 'n'){
            /*Auswerten des Durchschnitts*/
            printf("Der Durchschnitt beträgt %f", solution/count);

            return 0;
        }
    }
}

/*a05.Durchschnitt
Es sollen reelle Werte eingelesen werden und deren Durchschnitt ausgegeben
werden.
a) Eingabe, wieviel Zahlen einzulesen sind, danach Eingabe der Zahlen.
Nach der letzten Zahl Berechnung und Ausgabe des Durchschnitts.
b) Nach jeder eingegebenen Zahl, Abfrage, ob weitere Zahl eingegeben werden
soll. Wenn nein, Berechnung und Ausgabe des Durchschnitts.*/