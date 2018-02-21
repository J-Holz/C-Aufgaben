/* Das Programm stapelt Strings aufeinander. 
Es ist erlaubt neue Strings zu erstellen, den Obersten zu löschen und anzuzeigen, die Stackgröße auszugeben und den verwendeten Specher frei zu geben. */

/* valgrind ./a20 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addStack();
void remStack();
void showSize();
void freeMem();
void insertString(int length);
struct stack* getCurrent();

struct stack{
    char *string;
    int zNum;
    int stackNum;
    struct stack *next;
};
struct stack *new;
struct stack *first = NULL;
struct stack *current;
struct stack *currentTmp;

int i = 0, n = 0, remStackNum;
char plh;

int main()
{
    char charin;

        printf("Das Programm stapelt Stings.\nWelche Aktion möchtest du ausführen?\n\n"
        "'+': Ablegen des einzulesenden Strings auf den Stack.\n"
        "'-': Anzeigen und entfernen des obersten Stackelements.\n"
        "'?': Ausgabe der Stackgröße (Anzahl der Elemente und Zeichen).\n" 
        "'q': Beenden des Programms und Entfernen des Stacks.\n\n\n\n");

    do{
        printf("Kommando [ + | - | ? | q ]:");
        charin = getchar();
        switch(charin)
        {
            case '+':
                addStack();
                break;

            case '-':
                remStack();
                while((charin=getchar())!='\n');
                break;

            case '?':
                showSize();
                while((charin=getchar())!='\n');
                break;

            case 'q':
                freeMem();
                while((charin=getchar())!='\n');
                charin = 'q';
                break;
            
            case '\n':
                break;

            default:
                while((charin=getchar())!='\n');
                printf("Ungültige Eingabe.\n");
                break;
        }

    }while(charin != 'q');
    return 0;
}






/* Hauptfunktionen */


/* Fügt Stack hinzu */
void addStack()
{
    int length = 1;
    i++;

    /* Ersten String ablegen */
    if(getCurrent() == NULL){
        first = (struct stack *)malloc(sizeof(struct stack));
        if(first == NULL){
            printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current = first;
        current->string = (char *)calloc(length, sizeof(char));
        if(current->string == NULL){
            printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current->stackNum = i;
        current->next = NULL;
        insertString(length);

    /* Weitere Strings */
    }else{
        new = (struct stack *)malloc(sizeof(struct stack));
        if(new == NULL){
            printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current->next = new;
        current = new;
        current->string = (char *)calloc(length, sizeof(char));
        if(current->string == NULL){
            printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.");
            exit(1);
        }
        current->stackNum = i;
        current->next = NULL;
        insertString(length);
    }
}

/* Entfernt aktuellen Stack und gibt dessen String aus */
void remStack()
{
    n = -1;
    if(getCurrent() == NULL){
        printf("Der Stack ist bereits leer, du kannst nichts mehr löschen.\n");
    }else{
        current = getCurrent();
        do{
            n++;
            putchar(current->string[n]);
        }while(current->string[n] != '\n');
        remStackNum = current->stackNum;
        free(current->string);
        free(current);

        if(remStackNum > 1){
            current = first;
            while(current->stackNum != remStackNum-1){
                current = current->next;
            }
            current->next = NULL;
        }else{
            first = NULL;
        }
        i--;
    }
}

/* Gibt Stack Größe aus */
void showSize()
{
    int z = 0;
    if(getCurrent() == NULL){
        printf("Der Stack umfasst aktuell 0 String(s) und 0 Zeichen.\n");
    }else{
        current = first;
        do{
            z = z + current->zNum;
            if(current->next == NULL)
                break;
            current = current->next;
        }while(1);

        printf("Der Stack umfasst aktuell %i String(s) und %i Zeichen.\n", current->stackNum, z);
    }
}

/* Entfernt ggf alle Stacks */
void freeMem()
{
    while(getCurrent() != NULL){
        current = getCurrent();
        remStackNum = current->stackNum;
        free(current->string);
        free(current);
        if(remStackNum > 1){
            current = first;
            while(current->stackNum != remStackNum-1){
                current = current->next;
            }
            current->next = NULL;
        }else{
            first = NULL;
        }
    }
}






/* Unterfunktionen */


/* Gibt zuletzt eingegebenen Stack zurück */
struct stack* getCurrent()
{
    if(first!=NULL){
        current = first;
        while(current->next!=NULL){
            current = current->next;
        }
        return current;
    }else{
        return NULL;
    }
}

/* Fügt String in aktuellen Stack ein */
void insertString(int length)
{
    char *tmpMem;
    n = -1;
    current = getCurrent();

    /* Speicher mit String füllen */
    do{
        n++;
        if(n<length){
            current->string[n] = getchar();

        /* Wenn Speicher zu klein */
        }else{
            n--;

            /* current->string in tmp schieben, Speicher neu vergeben und zurück schieben */
            tmpMem = (char *)calloc(length, sizeof(char));
            if(tmpMem == NULL){
                printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.\n");
                exit(1);
            }
            memcpy(tmpMem, current->string, length);

            free(current->string);
            length += 1;
            current->string = (char *)calloc(length, sizeof(char));
            if(current->string == NULL){
                printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.\n");
                exit(1);
            }
            memcpy(current->string, tmpMem, length-1);
            free(tmpMem);
        }
    }while(current->string[n]!='\n');
    current->zNum = n;
}

/* a20.Simulieren Sie einen Stack für strings: 
Folgende Eingaben soll das Programm erlauben: 

'+': Ablegen des einzulesenden Strings auf den Stack. 
'-': Anzeigen und entfernen des obersten Stackelements. 
'?': Ausgabe der Stackgröße (Anzahl der Elemente und Zeichen). 
'q': Beenden des Programms und Entfernen des Stacks.  */