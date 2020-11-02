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
    for (duomuo& stud : A) {
      naudojantMediana(stud);
       naudojantVidurki(stud);
    }
    cout << "Apskaiciuoti pazymius uztruko: " << praejoLaiko(task_start) << "s" << endl;
    pradeti(task_start);
    A2 = padalinti(A);
    cout << "Padalinti i dvi grupes uztruko: " << praejoLaiko(task_start) << "s" << endl;
    pradeti(task_start);
    isvestiFaila(A, "islaike.txt");
    isvestiFaila(A2, "neislaike.txt");
    cout << "Isvesti i failus uztruko: " << praejoLaiko(task_start) << "s" << endl;
    cout << "Viso uztruko: " << praejoLaiko(start) << "s" << endl << endl;
}