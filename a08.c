#include <stdio.h>

int main()
{
    double aNum[10];
    double aSol[10];
    char plh;
    int i;
    int ii;
    int z;
    int tLoop = 9;
    
    /*Einlesen der Wer'te*/
    for(i=0; i <=tLoop; i++){
        printf("Gebe die %i. Zahl ein.\n", i+1);
        scanf("%lf%c", &aNum[i], &plh);
    }

    /*Sortieren der Werte*/
    for(i=0; i<=tLoop; i++){
        z=i;
        for(ii=i; ii<=tLoop; ii++){
            if(aNum[z] > aNum[ii]){
                z=ii;
            }
            if(ii==tLoop){
                aSol[i] = aNum[z];
                aNum[z] = aNum[i];
            }
        }
    }
    
    
    
    /*Ausgeben der Lösung*/
    printf("Die Werte der Größe nach aufsteigend sortiert:\n");
    for(i=0; i<=tLoop; i++){
        printf("%i : %lf\n", i+1, aSol[i]);
    }

    return 0;
}

/*a08.Eingabe von 10 double-Werten. Ausgabe: die Eingabewerte der Größe nach
(aufsteigend) sortiert.*/