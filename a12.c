#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char rplc[2], charIn, charFile, charOut;
    int i = 0;
    _Bool bOut = 1;

    /* Überprüfen der Argumente */
    if(argc < 2){
        printf("Bitte gib mindestens den Pfad zur Codetabelle an.\n");
        return 1;
    }else if(argc > 2){
        printf("Zu viele Argumente angegeben. Bitte gib nur den Pfad zu der Codetabelle an.\n");
        return 1;
    }
    if(!fopen(argv[1], "r")){
        printf("Der angegebene Pfad ist ungültig. Bitte versuche es erneut.\n Angegebener Pfad: %s", argv[1]);
    }

    
    while((charIn = getchar()) != EOF){
        
        /* Codetabelle einlesen */
        FILE *codeTable = fopen(argv[1], "r");

        /* Ausgabe des neuen Zeichens */
        while((charFile = fgetc(codeTable)) != EOF){
            
            /* Bei Zeilenumbruch in Codetabelle und zutreffendem Ergebnis wird neues Zeichen ausgegeben */
            if(charFile == '\n'){
                if(charIn == rplc[0] && i != 1){
                    charOut = rplc[1];
                    bOut = 0;
                }
                i = 0;

            /* Falls zweites Zeichen Zeilenumbruch */
            }else if(charFile == '\n' && i == 1){
                rplc[1] = rplc[0];
                i = 0;

            /* Die ersten beiden Zeichen der Zeile werden in rplc[] geschrieben */
            }else if(charFile != '\n'){
                if(i<2){
                    rplc[i] = charFile;
                }
                i++;
            }
        }

        /* Falls kein Zeichen gefunden wurde */
        if(bOut == 1){
            putchar(charIn);
        }else if(charIn == '\n'){
            putchar('\n');
        }else{
            putchar(charOut);
            bOut = 1;
        }
        fclose(codeTable);
        
    }
    return 0;
}


/*
    a12.Das Programm soll jedes Zeichen gegen ein anderes Zeichen ersetzen. Aufruf 
    des Programms: z.B. a12 Codetabelle < Klartext > Verschluesselung 
    a12 ist ihr Programm, Codetabelle ist ein File, der Zeilen der Form kv 
    enthält. Das Zeichen k im Klartext wird durch v in der Verschlüsselung 
    ersetzt. 

    - parameter Codetabelle starten
    - zu verschlüsselnder Text in externer Datei
    - neue Datei mit Namen Verschlüsselung
    - Sowohl Dateieingabe, als auch Tastatur Eingabe
    - Codetabelle in eigener Datei. (Datei im Schusser VZ)
    - getchar liest Zeichen für Zeichen aus
    - putchar gibt Zeichen für Zeichen aus
*/