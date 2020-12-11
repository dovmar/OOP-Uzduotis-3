#include "Header.h"
#include "Generator.h"
#include "Studentas.h"


void ivedimasRanka(container& A) {
    // Studentu duomenu ivedimas rankiniu budu
    int n;
    int m;
    Studentas stud;
    cout << "Kiek studentu norite ivesti? ";
    while (!(cin >> n)) {
        teisingasIvedimas();
    }
    cout << "Kiek namu darbu buvo uzduota? ";
    while (!(cin >> m)) {
        teisingasIvedimas();
    }
    for (int i = 0; i < n; i++) {
        ivestiStudenta(stud, m);
        A.push_back(stud);
    }
}


void isvedimasEkrane(container& A, string tipas) {
    // Isveda galutinius pazymius i ekrana
    cout << setw(15) << left << "Pavarde";
    cout << setw(15) << left << "Vardas";
    cout << "Galutinis " << tipas << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    if (tipas == "(Vid.)") {
        for (container::iterator it = A.begin(); it != A.end(); it++) {
            cout << setw(15) << left << it->vardas() << setw(15) << left << it->pavarde() << std::setprecision(3) << it->paz_vid() << endl;
        }
    }
    else {
        for (container::iterator it = A.begin(); it != A.end(); it++) {
            cout << setw(15) << left << it->vardas() << setw(15) << left << it->pavarde() << std::setprecision(3) << it->paz_med() << endl;
        }
    }
}


int gautiStulpeliuKieki(string s) {
    //Analizuoja pirma nuskaityto failo eilute norint gauti namu darbu kieki
    bool praeitas = 0; // Ar praeitas simbolis nebuvo tarpas
    int kiekis = 0; // Stulpeliu kiekio skaitiklis
    for (int i = 0; i < s.size(); i++) {
        if (praeitas == 1 & (s[i] == (char)' ' | s[i] == '\t') ) kiekis = kiekis + 1;
        if (s[i] == (char)' ' | s[i] == '\t') praeitas = 0;
        else praeitas = 1;
    }
    return kiekis+1;
}


void nuskaitytiFaila(container& A, string failoPav) {
    // Nuskaito duomenis is failo
    ifstream skait;
    string pirmaEil;
    skait.open(failoPav);
    if (skait.fail()) {
        std::cerr << "Klaida atidarant faila";
        exit(0);
    }
    int input;
    int m;
    Studentas stud;
    getline(skait, pirmaEil);
    try {
        m = gautiStulpeliuKieki(pirmaEil);
        if (m < 3) throw (m);
    }
    catch (int m) {
        cout << "Nepavyko nustatyti tinkamo stulpeliu kiekio" << endl;
        cout << "Rasta stulpeliu: " << m;
    }
    while (!skait.eof()) {
        nuskaitytiStudenta(skait, stud, m-3);
        A.push_back(stud);
    }
    skait.close();
}


void isvestiFaila(container& A,string failoPav = "rezultatai.txt") {
    // Isveda studentu rezultatus i faila
    ofstream isvest;
    isvest.open(failoPav);
    mySort(A);
    isvest << setw(15) << left << "Pavarde";
    isvest << setw(15) << left << "Vardas";
    isvest << setw(15) << left << "Galutinis (Vid.) ";
    isvest << "Galutinis (Med.)" << endl;
    isvest << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    for (container::iterator it = A.begin(); it != A.end(); it++) {
        isvest << setw(15) << left << it->pavarde() << setw(15) << left << it->vardas()
            << setw(15) << left << std::setprecision(3) << it->egzaminas() << std::setprecision(3) << it->paz_med() << endl;
    }
    isvest.close();
}

container padalinti(container& A, bool(*tipas)(Studentas&)) {
    // Padalijimas i 2 konteinerius perkopijuojant i abu
    container islaike, neislaike;
    for (Studentas& stud : A) {
        if (!tipas(stud)) neislaike.push_back(stud);
        else islaike.push_back(stud);
    }
    A.clear();
    A = islaike;
    return neislaike;
}


void mySort(vector<Studentas>& A) {
    // Rusiuoja vektorius
    sort(A.begin(), A.end(), palyginti);
}


void mySort(list<Studentas>& A) {
    // Rusiuoja sarasus
    A.sort(palyginti);
}


void paleisti(container& A,container& A2) {
    // Budas paleisti programa su pagrindiniais pasirinkimais
    int n;
    int m;
    string failoPav;
    while (true) {
        cout << "Kokiu budu norite pateikti studentu duomenis?" << endl;
        cout << "1. Nuskaityti is failo" << endl;
        cout << "2. Ivesti" << endl;
        cin >> n;
        if (n == 1) {
            cout << "1. Pateikti esamo failo pavadinima" << endl;
            cout << "2. Sugeneruoti faila" << endl;
            cin >> n;
            if (n == 1) {
                cout << "Iveskite pilna failo pavadinima (iskaitant .txt)" << endl;
                cin >> failoPav;
                nuskaitytiFaila(A, failoPav);
                break;
            }
            else if (n == 2) {
                cout << "Kokio dydzio faila norite sugeneruoti? " << endl;
                cin >> m;
                sugeneruotiFaila(m,10,"generuotas.txt");
                failoPav = "generuotas.txt";
                nuskaitytiFaila(A, failoPav);
                break;
            }
            else {
                cout << "Tokio pasirinkimo nera. Iveskite is naujo" << endl;
            }
        }
        else if (n == 2) {
            ivedimasRanka(A);
            break;
        }
        else {
            cout << "Tokio pasirinkimo nera. Iveskite is naujo" << endl;
        }
    }
    A2 = padalinti(A);
    isvestiFaila(A, "islaike.txt");
    isvestiFaila(A2, "neislaike.txt");
    cout << "Rezultatai isvesti i failus 'islaike.txt' ir 'neislaike.txt'!";
}
