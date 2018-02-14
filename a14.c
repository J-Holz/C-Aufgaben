/* Berechnung der einzelnen Werte einer Zinsberechnung mit Einzahlungen pro Periode in n Perioden */

#include <stdio.h>
#include <math.h>

/* Funktionen zur Berechnung */
double calcR();
double calcZ();
double calcK();
int calcN();

/* Funktionen für Eingabe */
double getR();
double getZ();
double getK();
int getN();

int i;
char plh;

int main()
{
    char serFor;
    double solDoub;
    int solInt;

        /* Abfrage, welche Berechnung durchgeführt wird */
        printf(
            "Es wird ein fehlender Wert (r, z, k, n) einer Zinseszinsberechnung mit regelmäßiger Einzahlung ermittelt.\n"
            "Welcher Wert soll berechnet werden?\n"
            "Betrag[r] - Zins[z] - Endkapital[k] - Perioden[n]\n"
        );
    do{
        fseek(stdin,0,SEEK_END);
        serFor = getchar();
        getchar();

        switch(serFor)
        {
            case 'r':
                solDoub = calcR();
                break;

            case 'z':
                solDoub = calcZ();
                break;

            case 'k':
                solDoub = calcK();
                break;

            case 'n':
                solInt = calcN();
                break;

            default:
                printf("\n\nDie Eingabe ist ungültig, bitte versuche es erneut.\n\n\n");
                printf("Betrag[r] - Zins[z] - Endkapital[k] - Perioden[n]\n");
                break;
        }
    }while(serFor != 'r' && serFor != 'z' && serFor != 'k' && serFor != 'n');

    /* Ausgabe sol int */
    if(serFor == 110){
        printf("Es müssen mindestens %i Periode(n) durchlaufen werden, damit das gewünschte Kapital erreicht oder überschritten wird.\n", solInt);

    /* Ausgabe sol double */
    }else if(serFor == 114 || serFor == 107 || serFor == 122){
        printf("Das Ergebnis lautet %c = %.2lf\n", serFor, solDoub);
    }
    return 0;
}


 


/* Funktion zur Berechnung des Betrags */
double calcR()
{
    printf("Gebe nun die Werte an.\n");
    double z = getZ();
    double k = getK();
    double nk = 0;
    int n = getN();
    double r = k/n;


    do{
        nk = 0;
        for (i=1; i<=n; i++){
            nk = (nk + r) * (1 + (z/100));
        }

        if(nk < k-0.05){
            r = r*1.5;
        }else if(nk > k+0.05){
            r = r*0.5;
        }

    }while(nk < k-0.05 || nk > k+0.05);

    return r;
}

/* Funktion zur Berechnung des Zinses */
double calcZ()
{
    restart:

    printf("Gebe nun die Werte an.\n");
    double r = getR();
    double k = getK();
    double nk;
    double z = (k/r) * 100;
    int n = getN();
    double abw = k/1000;

    /* Problemfall */
    if(r*n > k){
        printf("\nEingabe unzuläsig, versuche es erneut.\n\n");
        goto restart;
    }

    do{
        /* Kapital in Abhängigkeit von z berechnen */
        nk = 0;
        if(z<1){
            for (i=1; i<=n; i++){
                nk = (nk + r) * (1 + (z/100));
            }   
        }else{
            for (i=1; i<=n; i++){
                nk = (nk + r) * (z/100);
            }   
        }

        /* z annähern */
        if(nk < k - abw){
            z = z * 1.1;
        }else if(nk > k + abw){
            z = z * 0.9;
        }else{
            break;
        }
        
    }while(nk < k - abw || nk > k + abw);

    return z - 100;

}

/* Funktion zur Berechnung des Endkapitals */
double calcK()
{
    printf("Gebe nun die Werte an.\n");
    double r = getR();
    double z = getZ();
    double k = 0;
    int n = getN();

    for (i=1; i<=n; i++){
        k = (k + r) * (1 + (z/100));
    }

    return k;

}

/* Funktion zur Berechnung der Perioden */

int calcN()
{
    printf("Gebe nun die Werte an.\n");
    double r = getR();
    double z = getZ();
    double k = getK();
    double x = 0;
    int n = 0;

    while(x<=k){
        n++;
        x = (x+r) * (1 +(z/100));
    }
    
    return n;

}




/* Funktionen für Eingabe von Werten */

double getR()
{
    double r;
    do{
        printf("r = ");
        scanf("%lf", &r);
        if(r<=0){
            printf("Ungültige Eingabe, bitte versuche es erneut.\n");
        }
    }while(r<=0);
    return r;
}

double getZ()
{
    double z;
    do{
        printf("z [%%] = ");
        scanf("%lf", &z);
        if(z<=0){
            printf("Ungültige Eingabe, bitte versuche es erneut.\n");
        }
    }while(z<=0);
    return z;
}

double getK()
{
    double k;
    do{
        printf("k = ");
        scanf("%lf", &k);
        if(k<=0){
            printf("Ungültige Eingabe, bitte versuche es erneut.\n");
        }
    }while(k<=0);
    return k;
}

int getN()
{
    int n;
    do{
        printf("n = ");
        scanf("%i", &n);
        if(n<1){
            printf("Ungültige Eingabe, bitte versuche es erneut.\n");
        }
    }while(n<=0);
    return n;
}




/* a14.In einen Fonds wird zu Beginn einer jeden Periode der Betrag R eingezahlt. 
Am Ende einer jeden Periode wird das Fondsvermögen K mit dem Satz Z(%) verzinst. 
Die Einzahlungen laufen über N Perioden. Berechnen Sie aus 3 frei vom Benutzer 
eingebbaren Größen die vierte. Alle Größen sind positiv, die Periodenzahl zudem noch 
ganzzahlig. 
 */