/* Simulation eines schiefen Wurfes */

#include <stdio.h>
#include <math.h>


extern const double G;
extern const double R;
extern const double CW;
extern const double RHO;
extern const double HB;
extern const double PI;
extern void simstep(double s[2],double v[2],double m,double d,double dt); 


void calcClassic(double d, double m, double alp, double v0);
void calcDetailed(double d, double m, double alp, double v0);



int main()
{ 
    /* _Bool boolean = 1; */

    double d;       /* Durchmesser */
    double m;       /* Masse */
    double alp;     /* Winkel Alpha */
    double v0;      /* Gechwindigkeit */

    

    printf(
        "Eine Kugel wird vom Erdboden aus geschossen.\n" 
        "Es wird die Reichweite, Gipfelhöhe und Flugzeit berechnet.\n\n"
    );

    /* Werte einlesen */

    printf("Gib die gewünschten Werte für die Berechnung an.");

    printf("Durchmesser d der Kugel [0 < d <= 1] [m] = ");
    scanf("%lf", &d);
    if(d<0 || d>=1){
        printf("Eingabe ungültig\n\n\n");
    }

    printf("Masse m der Kugel [0 < m <= 10] [kg] = ");
    scanf("%lf", &m);

    printf("Winkel α des Wurfes [0 < a <= 90] [°] = ");
    scanf("%lf", &alp);

    printf("Geschwindigkeit v des Wurfes [0 < v <= 5000] [m/s] = ");
    scanf("%lf", &v0);

    calcClassic(d, m, alp, v0);
    calcDetailed(d, m, alp, v0);

    return 0;
}

void calcClassic(double d, double m, double alp, double v0){
    double vx;
    double vy;
    double claHeight;
    double claDistance;
    double claTime;
    /* Klassische Berechnung */
    printf("Klassische Berechnung:");

    vx = v0 * cos(alp);
    vy = v0 * sin(alp);

    claHeight = pow(vy, 2) / (2 * G);
    printf("Die Gipfelhöhe beträgt: %lf m", claHeight);

    claDistance = 2*vx * vy / G;
    printf("Die Reichweite beträgt: %lf m", claDistance);

    claTime = 2 * vy / G;
    printf("Die Flugdauer beträgt: %lf s", claTime);


    /* 
    Gipfelhöhe H=v y2 /(2*G)
    Reichweite W=2*v x *v y /G
    Flugdauer T=2*v y /G

    */



}
void calcDetailed(double d, double m, double alp, double v0){
    double s[2], v[2], dt;
    extern void simstep(double s[2],double v[2],double m,double d,double dt); 
}

/* 
a15.Simulieren Sie eine schiefen Wurf. 
Eine Kugel mit Durchmesser 0<=d<=1m und einer Masse 0<m<=10kg wird unter einem 
Winkel 0<α<=90° mit einer Geschwindigkeit 0<v<=5000 m/s vom Erdboden geschossen. 
Berechnen Sie die Reichweite, Gipfelhöhe und Flugzeit 

1. nach der klassischen Methode (flache Erde,luftleerer Raum), 
2. unter Berücksichtigung der Kugelform der Erde und des Luftwiderstands) 
mit einer Genauigkeit von 1m bzw. 1s. Weitere Infos in a15doc.pdf.

- Physikalische Details im VZ (a15doc)
- Funktion simpStep im VZ
 */