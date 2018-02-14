#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    double nNum[2], sol;
    char plh;
    int i;
    _Bool bScan;
    

    /* for(i=0; i<=anzWerte-1; i++){
        int test = getchar();

        scanf("%lf%c", &nNum[i], &plh);
        printf("%i", test);
        
        if (test >= 48 || test <= 58){
            sol = sol + nNum[i];
        }else{
            printf("Die Eingabe ist unzulässig, bitte versuche es erneut.");
            return 0;

        } */

        /*Addition*/
        
    for(i=0;i<=1;i++){
        firstChar = getchar();
        if(isDigit(firstChar) || firstChar == '.'){
            printf("Gib den %i. Wert ein.\n", i+1);


            bScan = scanf("%lf%c", &nNum[i], &plh) != 2;
            if(!bScan){
                if(i==1){
                    sol = nNum[0] + nNum[1];
                }
            }else{
                printf("Die Eingabe ist unzulässig, bitte versuche es erneut.\n");
                return 1;
            }
            if(plh != '\n'){
                printf("Die Eingabe ist unzulässig, bitte versuche es erneut.\n");
                return 1;
            }
        }else if(firstChar == '\n'){
                printf("Leere Eingabe, bitte versuche es erneut.\n");
                return 1;

        }else if(firstChar == '\'){
                printf("Voran gegangenes Whitespace, bitte versuche es erneut.\n");
        
    
    }

    /*Rückgabe der Lösung*/
    printf("Die Summe zwischen den Werten beträgt %lf.\n", sol);
    return 0;
}


/*a13.Das Programm soll 2 double Werte einlesen und deren Summe ausgeben. Die
beiden Werte sollen einzeln eingelesen werden. Eine gültige Eingabe besteht
dabei aus dem double-Wert gefolgt von einem RETURN. Ungültige Eingaben werden
mit einer entsprechenden Fehlermeldung quittiert.

- gültige Eingabe: doublewert und Return, kein Space oder sonstige Zeichen nach double. Entsprechende Fehlermeldung bei falschem Zeichen. Beliebige Eingabe möglich -> Fehlermeldung implementieren

*/






firstChar = getchar();

if(isdigit(firstChar) || firstChar == '.'){
    ungetc()
    if(scanf("%lf%c", &x, &c) == 2){
        if(c != '\n'){
            Fehler
        }
    }

}
