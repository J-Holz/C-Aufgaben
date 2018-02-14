#include <stdio.h>

int main()
{
    int z1;
    int z2;
    int i = 0;
    int b = 0;

    /*Zahlen einlesen*/
    printf("Erste Zahl eingeben:");
    scanf("%i", &z1);
    
    printf("Zweite Zahl eingeben:");
    scanf("%i", &z2);

    /*Sonderfälle*/
    if((z1<=0) | (z2<=0)){
        printf("\nInvalide Eingabe, Zahlen bitte neu eingeben.");
        return 0;
    }

    /*GGT*/
    while(b==0){
        i++;
        if(z1 % (z2 / i) == 0){
            printf("Der größte gemeinsame Teiler beträgt %i.\n", z2/i);
            i=0;
            b=1;
        }
        if(i==z2){
            printf("Für die angegebenen Zahlen existiert kein größter gemeinsamer Teiler.");
            b=1;
        }
    }b=0;
    
    /*KGV*/
    while(b==0){
        i++;
        if((z2 * i) % z1 == 0){
            printf("Das kleinste gemeinsame Vielfache beträgt %i.", z2*i);
            b=1;
        }
    }
    return 0;
}


/*a04.GGT/KGV
Zwei positive ganze Zahlen einlesen. Größten gemeinsamen Teiler (GGT)
und kleinstes gemeinsames Vielfaches (KGV) ausgeben.
*/