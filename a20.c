/* Das Programm stapelt Strings aufeinander. 
Es ist erlaubt neue Strings zu erstellen, den Obersten zu löschen und anzuzeigen, die Stackgröße auszugeben und den verwendeten Specher frei zu geben. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addStack();
void remStack();
void showSize();
void freeMem();
int insertString(int length);
struct stack* getCurrent();

struct stack{
    char *string;
    int zNum;
    int stackNum;
    struct stack *next;
};
struct stack *new;
struct stack *first;
struct stack *current;

int i = 0, n = 0;
char currChar, plh;

int main()
{
    int c;
    char charin;

        printf("Das Programm stapelt Stings.\nWelche Aktion möchtest du ausführen?\n\n"
        "'+': Ablegen des einzulesenden Strings auf den Stack.\n"
        "'-': Anzeigen und entfernen des obersten Stackelements.\n"
        "'?': Ausgabe der Stackgröße (Anzahl der Elemente und Zeichen).\n" 
        "'q': Beenden des Programms und Entfernen des Stacks.\n\n\n\n");

    do{
        printf("Kommando [ + | - | ? | q ]:");
        c = 0;
        charin = getchar();
        switch(charin)
        {
            case '+':
                addStack();
                break;

            case '-':
                remStack();
                getchar();
                break;

            case '?':
                showSize();
                break;

            case 'q':
                freeMem();
                break;

            default:
                c++;
                if(c==1){
                    printf("\nDas war eine ungültige Eingabe, bitte versuche es erneut.\n");
                }
                break;
        }


    }while(charin < 'q' || charin > 'q');
    return 0;
}






/* Hauptfunktionen */


/* Fügt Stack hinzu */
void addStack()
{
    int length = 16;
    i++;

    /* Ersten String ablegen */
    if(i==1){
        first=(struct stack *)malloc(sizeof(struct stack));
        if(first==NULL){
            printf("Ein Speicher Fehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current = first;
        current->string = (char *)calloc(length, sizeof(char));
        if(current->string==NULL){
            printf("Ein Speicher Fehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current->stackNum = i;
        length = insertString(length);
        current->next = NULL;

    /* Weitere Strings */
    }else{
        new=(struct stack *)malloc(sizeof(struct stack));
        if(new==NULL){
            printf("Ein Speicher Fehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current->next=new;
        current=new;
        current->string = (char *)calloc(length, sizeof(char));
        if(current->string==NULL){
            printf("Ein Speicher Fehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current->stackNum = i;
        length = insertString(length);
        current->next = NULL;
    }
}

/* Entfernt aktuellen Stack und gibt dessen String aus */
void remStack()
{
    n = -1;
    current = getCurrent();
    if(current==NULL){
        printf("\nDer Stack ist bereits leer, du kannst nichts mehr löschen.\n\n");
    }else{
        do{
            n++;
            putchar(current->string[n]);
        }while(current->string[n] != '\n');
        free(current->string);
        free(current->next);
        free(current);
    }
}

/* Gibt Stack Größe aus */
void showSize()
{
    int z = 0;
    current = first;
    do{
        printf("Stack %i enthält %i Zeichen\n", current->stackNum ,current->zNum);
        z = z + current->zNum;
        current = current->next;
    }while(current->next!=NULL);

    printf("Der Stack umfasst aktuell %i Strings und %i Zeichen.\n", current->stackNum, z);
}

/* Entfernt ggf alle Stacks */
void freeMem()
{
    do{
        current = getCurrent();
        free(current);
    }while(current!=NULL);
}






/* Unterfunktionen */


/* Gibt zuletzt eingegebenen Stack zurück */
struct stack* getCurrent(){
    current = first;
    while(current->next!=NULL){
        current = current->next;
    }
    return current;
}

/* Fügt String in aktuellen Stack ein */
int insertString(int length){
    char *tmpMem;
    n = -1;
    current = getCurrent();

    /* Speicher mit String füllen */
    do{
        n++;
        if(n<length){
            currChar = getchar();
            current->string[n] = currChar;
            printf("string[%i] = %c\n", n, current->string[n]);

        /* Wenn Speicher zu klein */
        }else{
            tmpMem = (char *)calloc(length, sizeof(char));
            memcpy(tmpMem, current->string, length);
            length *= 2;
            free(current->string);
            current->string = (char *)calloc(length, sizeof(char));
            memcpy(current->string, tmpMem, length/2);
            free(tmpMem);
            printf("Speicher erweitert!\nlength: %i\n", length);
        }
    }while(current->string[n]!='\n');
    current->zNum = n;
    return length;
}

/* a20.Simulieren Sie einen Stack für strings: 
Folgende Eingaben soll das Programm erlauben: 

'+': Ablegen des einzulesenden Strings auf den Stack. 
'-': Anzeigen und entfernen des obersten Stackelements. 
'?': Ausgabe der Stackgröße (Anzahl der Elemente und Zeichen). 
'q': Beenden des Programms und Entfernen des Stacks.  */