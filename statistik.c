#include <stdlib.h>
#include <math.h>

double Median(int iI /*Variable fuer Gesamtanzahl*/, double *pdMedian/*Array fuer Median*/); //Parametertypliste
/*Rueckgabewert: Ergebnis*/
/*Die Funktion berechnet den Median */
/*
History:
    FS: 27.10.2014 erstellt
*/
double Arithmetischesmittel(int iI2 /*Variable fuer Gesamtanzahl*/, double *pdAmittel /*Array fuer Arithmetischesmittel*/); //Parametertypliste
/*Rueckgabewert: Ergebnis*/
/*Die Funktion berechnet das Arithmetischesmittel besser bekannt als Durchschnitt*/
/*
History:
    FS: 27.10.2014 erstellt
*/
double Standartabweichung(int iI3 /*Variable fuer Gesamtanzahl*/, double adDurch /*Durchschnitt*/, double *pdSabweich /*Array fuer Standartabweichung*/); //Parametertypliste
/*Rueckgabewert: Ergebnis*/
/*Die Funktion berechnet die Standartabweichung*/
/*
History:
    FS: 27.10.2014 erstellt
*/




double Median(int iI /*Variable fuer Gesamtanzahl*/, double *pdMedian/*Array fuer Median*/)  //Funktion
/*Rueckgabewert: Ergebnis*/
/*Die Funktion berechnet den Median */
{

    int iZ;
    int iZ2;
    double dTausch;
    double dMedian;

    for(iZ2 = 0; iZ2 < iI; iZ2 = iZ2 +1)           //Sortieren der Durchmesser
    {
        for(iZ = 0; iZ < iI -1; iZ = iZ +1)
        {
            if(*(pdMedian + iZ) > *(pdMedian + (iZ +1)))
            {
                dTausch = *(pdMedian+iZ);
                *(pdMedian + iZ) = *(pdMedian + (iZ +1));
                *(pdMedian + (iZ +1)) = dTausch;
            }
            else
            {
            }
        }
    }

    iZ = iI % 2;                                    //Schreibt die Mitte von der Gesamtanzahl in iZ

    if(iZ == 0)                                     //Wenn die Durchmesser grade sind
    {
        iZ2 = iI /2;                                //Schreibt die Hälfte von der Gesamtanzhal in iZ2
        dMedian = (*(pdMedian + iZ2) + *(pdMedian+ (iZ2 -1))) /2;       //Berechnet den Median
    }
    else                                            //Wenn die Durchmesser ungrade sind
    {
        iZ = iI /2;
        dMedian = *(pdMedian + iZ);
    }

    return(dMedian);
}

double Arithmetischesmittel(int iI2 /*Variable fuer Gesamtanzahl*/, double *pdAmittel /*Array fuer Arithmetischesmittel*/) //Funktion
/*Rueckgabewert: Ergebnis*/
/*Die Funktion berechnet das Arithmetischesmittel besser bekannt als Durchschnitt*/
{
    int iZ;
    double dDurch;

    dDurch = 0;
    for(iZ = 0; iZ < iI2; iZ = iZ +1)
    {
        dDurch = dDurch + *(pdAmittel + iZ);       //Addiert alle Werte
    }

    dDurch = dDurch / iI2;                    //Dividiert die addierten Werte durch die Gesamtanzahl der Werte (Formel des Durchmessers)

    return(dDurch);
}

double Standartabweichung(int iI3 /*Variable fuer Gesamtanzahl*/, double adDurch /*Durchschnitt*/, double *pdSabweich /*Array fuer Standartabweichung*/) //Funktion
/*Rueckgabewert: Ergebnis*/
/*Die Funktion berechnet die Standartabweichung*/
{
    double dZ;
    int iZ2;
    double dSta;


    dZ = 0;

    for(iZ2 = 0; iZ2 < iI3; iZ2 = iZ2 +1)
    {
        dZ = dZ + ((*(pdSabweich + iZ2) - adDurch) * (*(pdSabweich + iZ2) - adDurch));
    }

    dZ = dZ/(iI3-1);
    dSta = sqrt(dZ);                   //Wurzel ziehen

    return(dSta);
}
