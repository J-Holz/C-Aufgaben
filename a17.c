/* Programm zur Berechnung des Durchschnitts zwischen X Werten und die Standardabweichung */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getXNums();
void getNumArray(int n);
void cpyArray(double *A1, double *A2, int n);
void calc(int n);

double *aNum, *tmpMem;
int *count;

int main()
{

    double s, m, x = 0;
    int n, i;
    char plh;
    count = &n;

    /* Unterscheidung, wie die Zahlen aufgenommen werden */
    printf("Wie viele Zahlen sollen eingegeben werden? (Wenn variabel 0 eingeben)");
    scanf("%i%c", &n, &plh);
    if(n == 0){
        aNum = (double *)calloc(1, sizeof(double));
        getXNums();
    }else{
        aNum = (double *)calloc(n, sizeof(double));
        getNumArray(n);
    }

    /* Berechnung der Werte */
    for(i=0;i<n;i++){
        m += aNum[i];
    }
    m /= n;
    for(i=0;i<n;i++){
        x += pow(aNum[i]-m, 2);
    }
    s=sqrt(x/n);

    printf("Der Durchschnitt beträgt %lf und die Standardabweichung beträgt %lf.\n", m, s);

    free(count);
    free(aNum);
    return 0;
}

void getNumArray(int n)
{
    char plh;
    int i;
    for(i=0;i<n;i++){
        printf("Gib den %i. Wert ein. ", i+1);
        scanf("%lf%c", &aNum[i], &plh);
    }
}
    
    
void getXNums()
{
    *count = 1;
    char bool;
    printf("Gib den 1. Wert ein. ");
    scanf("%lf%c", &aNum[0], &bool);

    do{
        /*Ein weiterer Wert?*/
        printf("Ein weiterer Wert? (y/n) ");
        switch(bool = getchar()){
            case 'y':
                while(getchar()!='\n'){}
                tmpMem = (double *)calloc(*count, sizeof(double));
                if(tmpMem == NULL){
                    printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.\n");
                    exit(1);
                }
                cpyArray(aNum, tmpMem, *count);
                free(aNum);

                *count = *count+1;
                aNum = (double *)calloc(*count, sizeof(double));
                if(aNum == NULL){
                    printf("Ein Speicherfehler ist aufgetreten, das Programm wird beendet.\n");
                    exit(1);
                }
                cpyArray(tmpMem, aNum, *count-1);
                free(tmpMem);

                /*Neue Zahl einlesen*/
                printf("Gib den %i. Wert ein. ", *count);
                scanf("%lf%c", &aNum[*count-1], &bool);
            break;

            default:
                while(getchar()!='\n'){}
            break;
        }
    }while(bool != 'n');
}

void cpyArray(double *A1, double *A2, int n)
{
    int i;
    for(i=0;i<n;i++){
        A2[i] = A1[i];
    }
}

/*a17.Mittelwert und Standardabweichung 
Eine beliebige Anzahl von double Werten soll eingelesen werden (siehe a05). 
Danach soll der Durchschnitt(m) und die Standardabweichung(s) nach der Formel
    _____________________ 
 s=√(1/N)*Σ[(xi-m)2]
 mit N:Anzahl der Eingaben, m=(1/N)*Σ(xi), xi: i-ter Eingabewert

 ausgegeben werden. 

- Zahl wird sicher eingegeben, kein Buchstaben Test erforderlich.*/