#include "Header.h"
#include "Timer.h"
#include "Generator.h"

int main()
{
    int n;
    container Stud;
    container Stud2; //vektorius laikyti neislaikiusiems studentams
    /*
    nuskaitytiFaila(Stud,"generuotas1000.txt");
    for (duomuo& stud : Stud) {
        naudojantMediana(stud);
        naudojantVidurki(stud);
    }
    Stud2 = padalinti(Stud);
    isvestiFaila(Stud, "islaike.txt");
    isvestiFaila(Stud2, "neislaike.txt");
    */
    //cout << "1000 dydzio" << endl;
    //sugeneruotiFaila(1000, 10, "generuotas1000.txt");
    //visasLaikas(Stud, Stud2,"generuotas1000.txt");
    /*cout << "10000 dydzio" << endl;
    sugeneruotiFaila(10000, 10, "generuotas10000.txt");
    visasLaikas(Stud, Stud2, "generuotas10000.txt");
    cout << "100000 dydzio" << endl;
    sugeneruotiFaila(100000, 10, "generuotas100000.txt");
    visasLaikas(Stud, Stud2, "generuotas100000.txt");
    cout << "1000000 dydzio" << endl;
    */
    //sugeneruotiFaila(1000000, 10, "generuotas1000000.txt");
    visasLaikas(Stud, Stud2, "generuotas1000000.txt");
    return 0;
}
