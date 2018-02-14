#include <stdio.h>

int main()
{
    char plh;
    double r;
    int i;
    int n;
    int mult = 1;
    double sol;

    /*Einlesen der Werte*/
    printf("Gebe die zu rundende Zahl ein.\n");
    scanf("%lf%c", &r, &plh);

    printf("Gebe die zu behaltenden Nachkommastellen an.\n");
    scanf("%i%c", &n, &plh);

    /*Sonderfälle*/
    if(n <= 0){
        printf("Ungültige Eingabe, bitte versuche es erneut.\n");
        return 0;
    }

    /*Multiplikator / Dividend für Kommaverschiebung*/
    for(i=1; i<=n; i++){
        mult = mult*10;
    }

    /*Rundungsvorgang*/
    sol = (double)((int) (r * mult)) / mult;

    printf("Der gerundete Wert beträgt %lf.\n", sol);

    return 0;
}



/*a06.Nachkommastellen
Eingabe einer reellen Zahl r und einer positiven ganzen Zahl n.
Ausgabe von r auf n Nachkommastellen gerundet mit 20 Nachkommastellen.
z.B. Eingabe 3.1415926 und 4 -> Ausgabe: 3.14160000000000000000*/