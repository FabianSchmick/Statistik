/*statistik.c*/

/*
Projekt: statistik
*/

/*
History:
	FS 17.11.2014 erstellt
*/

#define MAX_WERTE 10

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "statistik.h"

int main(void);
int main()
{
    /*
    Dieses Modul ließt Werte aus einer .txt Datei ein,
    berechnet deren Median, Arithmetisches Mittel und
    Standartabweichung. Diese werden anschließend auf dem
    Bildschirm ausgegeben.
    */

    /*
    Variablen deklarationen
    */

    int iZ;                  //1. Zaehlvariable
    int iAnzahl1;            //1. Positionsvariable
    int iAnzahl2;            //2. Postionsavariable
    double dMedian1;         //Die 1. Variable für den Median von Test1
    double dMedian2;         //Die 1. Variable für den Median von Test2
    double dDurch1;          //Die 1. Variable für den Durchmesser Test1
    double dDurch2;          //Die 1. Variable für den Durchmesser Test2
    double dSta1;            //Die 1. Variable für die Standartabweichung Test1
    double dSta2;            //Die 1. Variable für die Standartabweichung Test2
    double adWerte1[MAX_WERTE]; //Werte aus Test 1
    double adWerte2[MAX_WERTE]; //Werte aus Test 2
    FILE *pfDatei;           //Datei




    /*
    Einlesen der Werte aus Test_1.txt und anschließendem Ausgaben auf dem Bildschirm
    */

    pfDatei = fopen("Test_1.txt","r");      //Öffnen der Datei Test_1.txt zum lesen

    printf("Test 1:\n\n");
    if(pfDatei != NULL)                     //Sicherrung
    {
        iZ = 0;
        do
        {
            iAnzahl1 = fscanf(pfDatei, "%lf", &adWerte1[iZ]); //Werte einlesen und die Gesamtanzahl
            iZ = iZ +1;
        }while(iAnzahl1 != -1);          //-1 ist end of file (EOF)
        iAnzahl1 = iZ -1;                //Weil abziehen wegen EOF

        for(iZ = 0; iZ < iAnzahl1; iZ = iZ +1)
        {
            printf("%.2lf\n", adWerte1[iZ]);
        }
    }
    else
    {
        printf("Fehler in der Dateiausgabe,\nueberpruefen Sie ob die Datei Test_1.txt vorhanden ist.\n");
        return(0);
    }

    fclose(pfDatei);                        //Schließt pfDatei




    /*
    Einlesen der Werte aus Test_2.txt und anschließendem Ausgaben auf dem Bildschirm
    */

    pfDatei = fopen("Test_2.txt","r");      //Öffnen der Datei Test_2.txt zum lesen


    printf("\n\n\nNun folgt Test 2\n\n");
    if(pfDatei != NULL)                     //Sicherrung
    {
        iZ = 0;
        do
        {
            iAnzahl2 = fscanf(pfDatei, "%lf", &adWerte2[iZ]); //Werte einlesen und die Gesamtanzahl
            iZ = iZ +1;
        }while(iAnzahl2 != -1);          //-1 ist end of file (EOF)
        iAnzahl2 = iZ -1;                //Weil abziehen wegen EOF

        for(iZ = 0; iZ < iAnzahl2; iZ = iZ +1)
        {
            printf("%.2lf\n", adWerte2[iZ]);
        }
    }
    else
    {
        printf("Fehler in der Dateiausgabe,\nueberpruefen Sie ob die Datei Test_2.txt vorhanden ist.\n");
        return(0);
    }

    fclose(pfDatei);                        //Schließt pfDatei




    /*
    Median bestimmen
    */

    dMedian1 = Median(iAnzahl1, &adWerte1[0]);    //Funktionsaufruf vom Durchmesser zur Berechnung des Median
    dMedian2 = Median(iAnzahl2, &adWerte2[0]);    //Funktionsaufruf von Massen zur Berechnung des Median

    printf("\n\nDer Median von Test1 lautet: %lf \n", dMedian1);         //Zur Kontrolle
    printf("Der Median von Test2 lautet: %lf \n\n", dMedian2);




    /*
    Arithmetisches Mittel bestimmen
    */

    dDurch1 = Arithmetischesmittel(iAnzahl1, &adWerte1[0]);       //Funtkionsaufruf
    dDurch2 = Arithmetischesmittel(iAnzahl2, &adWerte2[0]);

    printf("Das Arithmetisches Mittel von Test1 lautet: %lf \n", dDurch1);
    printf("Das Arithmetisches Mittel von Test2 lautet: %lf \n\n", dDurch2);




    /*
    Standartabweichung bestimmen
    */

    dSta1 = Standartabweichung(iAnzahl1, dDurch1, &adWerte1[0]);  //Funtkionsaufruf
    dSta2 = Standartabweichung(iAnzahl2, dDurch2, &adWerte2[0]);

    printf("Die Standartabweichung von Test1 lautet: %lf \n", dSta1);
    printf("Die Standartabweichung von Test2 lautet: %lf \n\n", dSta2);




    /*
    Die errechneten Werte werden in die Datei geschrieben
    */

    pfDatei = fopen("ergebnis.txt","wt");          //Öffnen der Datei ergebnis.txt zum reinschreiben

    if(pfDatei != NULL)
    {
        fprintf(pfDatei, "Test1\nMedian: %lf \n", dMedian1);                  //Schreibt das Ergebnis in pfDatei
        fprintf(pfDatei, "Arithmetische Mittel: %lf \n", dDurch1);
        fprintf(pfDatei, "Standartabweichung: %lf \n\n", dSta1);

        fprintf(pfDatei, "Test2\nMedian: %lf \n", dMedian2);
        fprintf(pfDatei, "Arithmetische Mittel: %lf \n", dDurch2);
        fprintf(pfDatei, "Standartabweichungt: %lf ", dSta2);
    }
    else
    {
        printf("Fehler beim Einschreiben der Ergebnisse in ergebnis.txt");
    }


    fclose(pfDatei);            //Schließen der Datei


    return 0;
}
