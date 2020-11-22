#include "Timer.h"


void pradeti(time_point& start) {
    // Issaugo dabartini laika
    start = hrClock::now();
}

double praejoLaiko(time_point start) {
    // Apskaiciuoja kiek praejo laiko
    return durationDouble(hrClock::now() - start).count();
}

void visasLaikas(container &A, container &A2, string failoPav) {
    // Skirta matuoti kiek laiko uztrunka atlikti tam tikrus veiksmus nurodytam studentu duomenu failui
    time_point start;
    time_point task_start;
    pradeti(start);
    nuskaitytiFaila(A, failoPav);
    cout << "Nuskaityti faila uztruko: " << praejoLaiko(start) << "s" << endl;
    pradeti(task_start);
    A2 = padalinti(A);
    cout << "Padalinti i dvi grupes uztruko: " << praejoLaiko(task_start) << "s" << endl;
    pradeti(task_start);
    isvestiFaila(A, "islaike.txt");
    isvestiFaila(A2, "neislaike.txt");
    //cout << "Isvesti i failus uztruko: " << praejoLaiko(task_start) << "s" << endl;
    //cout << "Viso uztruko: " << praejoLaiko(start) << "s" << endl << endl;
}


void dalijimoLaikas(container& A, container& A2, string failoPav) {
    // Skirta matuoti kiek laiko uztrunka padalinti studentus i 2 dalis pagal tam tikra strategija
    time_point start;
    container Temp, Temp2; //naudojami tik del to kad skirtingoms dalijimo i 2 dalis strategijoms nereiketu is naujo nuskaityti failo
    nuskaitytiFaila(A, failoPav);
    Temp2 = Temp = A;
    pradeti(start);
    A2 = padalinti(A);
    cout << "Padalinti 1 budu (perkopijuojant i 2 konteinerius) uztruko: " << praejoLaiko(start) << "s" << endl;
    pradeti(start);
    A2 = padalinti2(Temp);
    cout << "Padalinti 2 butu (perkopijuojant i 1 ir istrinant is kito) uztruko: " << praejoLaiko(start) << "s" << endl;
    pradeti(start);
    A2 = padalinti3(Temp);
    cout << "Padalinti 3 butu (naudojant partition) uztruko: " << praejoLaiko(start) << "s" << endl;
}
