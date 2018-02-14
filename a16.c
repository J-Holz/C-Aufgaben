/*  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessNum();
void giveNum();
int i;
int ii;
int iii;

int main()
{
    _Bool boolean = 1;
    printf(
        "\n********** Dies ist das Mastermind Spiel **********\n\n"
        "Es wird eine 5-stellige Ziffernkombination vom Geber gewählt und der Rater muss nach und nach die Kombination erraten.\n"
        "Es gibt 12 Versuche, nach jedem Versuch gibt es eine s:w Auswertung der Zahlen. \n"
        "S steht für die Anzahl der Ziffern, welche richtig erraten wurden und w für die Anzahl der Ziffern, die in dem Ergebnis vorkommen, aber an der falschen Stelle stehen.\n\n"
        "Welche Rolle möchtest du übernehmen?\na) Selbst eine Zahl erraten, welche vom Computer gewähl wird.\nb) Zahl geben  und Computer erraten lassen\n\n"
        "[a / b]\n"
    );
    
    /* Welche Rolle wird übernommen? */
    do{
        switch (getchar()){

            case 'a':
                guessNum();
                boolean = 0;
                break;

            case 'b':
                giveNum();
                boolean = 0;
                break;

            case '\n':
                break;

            default:
                printf("Eingabe ungültig, bitte versuche es erneut.\n");
                break;
        }
    }while(boolean == 1);

    return 0;
}

/* Der Spieler muss die Zahl erraten */
/* ToDo: gibt es den Fall, dass weniger als 5 Zahlen eingegeben werden? */
void guessNum(){
    int aNum[5];
    char givenNum[] = "00000";
    int aGivNum[5];
    int s, w;

    /* Zufällige Zahl für Array */
    for(i=0; i<=4; i++){
        srand(time(NULL)+i);
        aNum[i] = rand()%10;
        printf("%i", aNum[i]);
    }

    for(i=1;i<=12;i++){
        if(s == 5){
            break;
        }
        s = 0;
        w = 0;
        printf("\nGib die %i. Kombination ein.\n", i);
        scanf("%s", givenNum);
        
        for(ii=0;ii<=4;ii++){
            aGivNum[ii] = (int)(givenNum[ii])-48;
            if(aGivNum[ii] == aNum[ii]){
                s++;
            }else{
                for(iii=0;iii<=4;iii++){
                    if(aGivNum[ii] == aNum[iii]){
                        w++;
                        break;
                    }
                }
            }
        }
        printf("\nDas Ergebnis lautet s/w\n       - %i : %i -\n\n", s, w);

    }
}


/* Der Spieler gibt eine Zahl an */
void giveNum(){}


/* 

a16.Mastermind. 
Mastermind ist ein Spiel zu zweit. Einer denkt sich eine 5-stellige Ziffernkombination, 
die der andere in höchstens 12 Versuchen knacken muss. Jeder 
Rateversuch wird mit s:w bewertet, wobei s die Anzahl der Ziffern ist, die 
an der richtigen Stelle stehen, während w angibt, wieviele Ziffern im Versuch 
zwar richtig enthalten sind, aber an der falschen Stelle stehen. Der Rater hat 
daher die Kombination erraten, wenn sein Versuch mit 5:0 bewertet wurde. 
Realisieren Sie dieses Spiel, wobei der Anwender entscheidet, welchen Part er 
übernimmt. 

- Algorythmus schreiben, der immer Lösung findet, wenn Zahl angegeben wird.

 */