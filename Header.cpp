#include "Header.h"

void teisingasIvedimas() {
    // Skirtas patikrinti ar ivestas sveikas skaicius
    cin.clear();
    cin.ignore(80, '\n');
    cout << "Iveskite sveikaji skaiciu: ";
}


void naudojantMediana(Studentas& A) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu mediana
    int m = A.nd.size();
    if (m == 0) A.paz_med = 0;
    else if (m == 1) A.paz_med = A.nd[0];
    else {
        sort(A.nd.begin(), A.nd.end());
        if (m % 2 != 0) {
            A.paz_med = A.nd[m / 2];
        }
        else {
            A.paz_med = (A.nd[m / 2] + A.nd[m / 2 - 1]) / 2;
        }
    }
    A.paz_med = A.paz_med * 0.4 + A.egz * 0.6;
}


void naudojantVidurki(Studentas& A) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu vidurki
    int m = A.nd.size();
    if (m == 0) A.paz_vid = A.egz;
    else {
        A.paz_vid = 0;
        for (auto paz : A.nd) {
            A.paz_vid = A.paz_vid + paz;
        }
        A.paz_vid = A.paz_vid * 0.4 / m + A.egz * 0.6;
    }
}


void ivedimasRanka(container& A) {
    // Studentu duomenu ivedimas rankiniu budu
    int n;
    int m;
    int input;
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
        cout << "Iveskite studento varda ir pavarde: \n";
        cin >> stud.vardas;
        cout << "Iveskite studento pavarde: \n";
        cin >> stud.pav;
        if (m > 0) {
            cout << "Iveskite studento namu darbu pazymius: \n";
            for (int j = 0; j < m; j++) {
                while (!(cin >> input)) {
                    teisingasIvedimas();
                }
                stud.nd.push_back(input);
            }
        }
        cout << "Iveskite studento egzamino pazymi: \n";
        while (!(cin >> stud.egz)) {
            teisingasIvedimas();
        }
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
            cout << setw(15) << left << it->vardas << setw(15) << left << it->pav << std::setprecision(3) << it->paz_vid << endl;
        }
    }
    else {
        for (container::iterator it = A.begin(); it != A.end(); it++) {
            cout << setw(15) << left << it->vardas << setw(15) << left << it->pav << std::setprecision(3) << it->paz_med << endl;
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
        stud.nd.clear();
        skait >> stud.vardas >> stud.pav;
        for (int j = 0; j < m-3; j++) {
            skait >> input;
            stud.nd.push_back(input);
        }
        skait >> stud.egz;
        A.push_back(stud);
    }
    skait.close();
}


bool palyginti(Studentas a, Studentas b) {
    // Skirta palyginti du studentus pagal pavardes
    if (a.pav < b.pav)
        return 1;
    else
        return 0;
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
        isvest << setw(15) << left << it->pav << setw(15) << left << it->vardas
            << setw(15) << left << std::setprecision(3) << it->paz_vid << std::setprecision(3) << it->paz_med << endl;
    }
    isvest.close();
}


bool arIslaikeVid(Studentas& stud) {
    // Patikrina ar studento galutinis pazymis didesnis uz tam tikra riba
    return stud.paz_vid >= 5;
}


bool arIslaikeMed(Studentas& stud) {
    // Patikrina ar studento galutinis pazymis didesnis uz tam tikra riba
    return stud.paz_med >= 5;
}

container padalinti(container& A, bool(*tipas)(Studentas&)) {
    // Padalijimas i 2 konteinerius perkopijuojant i abu
    container islaike, neislaike;
    for (Studentas& stud : A) {
        if (!tipas(stud)) neislaike.push_back(stud);
        else islaike.push_back(stud);
    }
    A = islaike;
    return neislaike;
}


container padalinti2(container& A, bool(*tipas)(Studentas&)) {
    // Padalijimas i 2 konteinerius i 1 perkopijuojant, o is 2 istrinant
    container neislaike;
    for (Studentas& stud : A) {
        if (!tipas(stud)) neislaike.push_back(stud);
    }
    A.erase(remove_if(A.begin(), A.end(), arIslaikeVid));
    return neislaike;
}


container padalinti3(container& A, bool(*tipas)(Studentas&)) {
    // Padalijimas i du konteinerius naudojant partition
    container::iterator it = std::partition(A.begin(), A.end(), tipas);
    container neislaike(it, A.end());
    A.erase(it, A.end());
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