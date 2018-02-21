/* Das Programm soll 2 double Werte einlesen und deren Summe ausgeben, wobei keine Fehler entstehen dürfen, egal welche Zeichenkombinationen der Nutzer eingibt. */

#include <stdio.h>


int main()
{
    double nNum[2], sol;
    char plh, firstChar;
    int i;
    _Bool bScan;

    for(i=0;i<2;i++){
        printf("Gib den %i. Wert ein.\n", i+1);

        /* Eingabe überprüfen */
        firstChar = getchar();
        ungetc(firstChar, stdin);

        /* Erstes Zeichen wird überprüft */
        if((firstChar >= '0' && firstChar <= '9') || firstChar == '.' || firstChar == '-' || firstChar == '+'){
            bScan = scanf("%lf%c", &nNum[i], &plh) == 2;
            if(bScan){

                /* Zweifach erfolgreiche Eingabe */
                if(i==1){
                    sol = nNum[0] + nNum[1];
                }

                /* Fehler in scanf() */
            }else{
                printf("Die Eingabe enthält ein unzulässiges Zeichen, bitte versuche es erneut.\n");
                return 1;
            }

            if(plh != '\n'){
                printf("Die Eingabe enthält nachfolgende Zeichen, bitte versuche es erneut.\n");
                return 1;
            }

        /* Eingabe ohne Inhalt */
        }else if(firstChar == '\n'){
            printf("Leere Eingabe, bitte versuche es erneut.\n");
            return 1;
        
        /* Erstes Zeichen == Leerzeichen */
        }else if(firstChar == ' ' || firstChar == '\t' || firstChar == '\v'){
            printf("Vorangegangenes Whitespace, bitte versuche es erneut.\n");
            return 1;

        /* Undefinierter Fehler */
        }else{
            printf("Die Eingabe enthält ein unzulässiges Zeichen, bitte versuche es erneut.\n");
            return 1;
        }
        
    
    }

    /*Rückgabe der Lösung*/
    printf("Die Summe der Werte beträgt %lf.\n", sol);
    return 0;
}


/*
a13.Das Programm soll 2 double Werte einlesen und deren Summe ausgeben. Die12
beiden Werte sollen einzeln eingelesen werden. Eine gültige Eingabe besteht
dabei aus dem double-Wert gefolgt von einem RETURN. Ungültige Eingaben werden
mit einer entsprechenden Fehlermeldung quittiert.

- gültige Eingabe: doublewert und Return, kein Space oder sonstige Zeichen nach double. Entsprechende Fehlermeldung bei falschem Zeichen. Beliebige Eingabe möglich -> Fehlermeldung implementieren

*/