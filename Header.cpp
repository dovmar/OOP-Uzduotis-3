#include "Header.h"

void teisingasIvedimas() {
    // Skirta naudoti kai tikrinima ar ivestas sveikas skaicius
    cin.clear();
    cin.ignore(80, '\n');
    cout << "Iveskite sveikaji skaiciu: ";
}

void ivedamiND(vector<duomuo>& A, int i, int m) {
    // Leidzia ivesti namu darbu pazymius rankiniu budu
    int input;
    cout << "Iveskite studento namu darbu pazymius: \n";
    for (int j = 0; j < m; j++) {
        while (!(cin >> input)) {
            teisingasIvedimas();
        }
        A[i].nd.push_back(input);
    }
}

void atsitiktiniaiND(vector<duomuo>& A, int i, int m) {
    // Sugeneruoja atsitiktinius namu darbu pazymius 
    for (int j = 0; j < m; j++) {
        A[i].nd.push_back((rand() % 10) + 1);
    }
}

void naudojantMediana(vector<duomuo>& A, int i) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu mediana
    int m = A[i].nd.size();
    if (m == 0) A[i].paz_med = 0;
    else if (m == 1) A[i].paz_med = A[i].nd[0];
    else {
        sort(A[i].nd.begin(), A[i].nd.end());
        if (m % 2 != 0) {
            A[i].paz_med = A[i].nd[m / 2];
        }
        else {
            A[i].paz_med = (A[i].nd[m / 2] + A[i].nd[m / 2 - 1]) / 2;
        }
    }
    A[i].paz_med = A[i].paz_med * 0.4 + A[i].egz * 0.6;
}

void naudojantVidurki(vector<duomuo>& A, int i) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu vidurki
    int m = A[i].nd.size();
    if (m == 0) A[i].paz_vid = A[i].egz;
    else {
        A[i].paz_vid = 0;
        for (auto paz : A[i].nd) {
            A[i].paz_vid = A[i].paz_vid + paz;
        }
        A[i].paz_vid = A[i].paz_vid * 0.4 / m + A[i].egz * 0.6;
    }
}

void ivedimasRanka(vector<duomuo>& A) {
    // Ivedimas rankiniu budu
    int m;
    int n;
    cout << "Kiek studentu norite ivesti? ";
    while (!(cin >> n)) {
        teisingasIvedimas();
    }
    cout << "Kiek namu darbu buvo uzduota? ";
    while (!(cin >> m)) {
        teisingasIvedimas();
    }
    for (int i = 0; i < n; i++) {
        A.push_back(duomuo());
        cout << "Iveskite studento varda ir pavarde: \n";
        cin >> A[i].vardas;
        cout << "Iveskite studento pavarde: \n";
        cin >> A[i].pav;
        /* Galima arba ivesti pazymius rankiniu budu naudojant ivedamiND()
        arba juos sugeneruoti atsitiktinai naudojant atsitiktiniaiND() */
        if (m != 0) ivedamiND(A, i, m);
        cout << "Iveskite studento egzamino pazymi: \n";
        while (!(cin >> A[i].egz)) {
            teisingasIvedimas();
        }
    }
}

void isvedimasEkrane(vector<duomuo> A, string tipas) {
    // Isveda galutinius pazymius i ekrana
    cout << setw(15) << left << "Pavarde";
    cout << setw(15) << left << "Vardas";
    cout << "Galutinis " << tipas << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    if (tipas == "(Vid.)") {
        for (int i = 0; i < A.size(); i++) {
            cout << setw(15) << left << A[i].vardas << setw(15) << left << A[i].pav << std::setprecision(3) << A[i].paz_vid << endl;
        }
    }
    else {
        for (int i = 0; i < A.size(); i++) {
            cout << setw(15) << left << A[i].vardas << setw(15) << left << A[i].pav << std::setprecision(3) << A[i].paz_med << endl;
        }
    }
}


int gautiStulpeliuKieki(string s) {
    //Analizuoja pirma nuskaityto failo eilute norint gauti namu darbu kieki
    bool praeitas = 0; // Ar praeitas simbolis nebuvo tarpas
    int kiekis = 0;
    for (int i = 0; i < s.size(); i++) {
        if (praeitas == 1 & (s[i] == (char)' ' | s[i] == '\t') ) kiekis = kiekis + 1;
        if (s[i] == (char)' ' | s[i] == '\t') praeitas = 0;
        else praeitas = 1;
    }
    return kiekis+1;
}

void nuskaitytiFaila(vector<duomuo>& A, string failoPav) {
    // Nuskaito duomenis is failo
    ifstream skait;
    string pirmaEil;
    skait.open(failoPav);
    if (skait.fail()) {
        std::cerr << "Klaida atidarant faila";
        exit(0);
    }
    int input;
    int m; //uzduociu kiekis
    int n = 0; // studentu kiekis
    getline(skait, pirmaEil);
    try {
        m = gautiStulpeliuKieki(pirmaEil);
        if (m < 3) throw (m);
    }
    catch (int m) {
        cout << "Nepavyko nustatyti stulpelio kiekio" << endl;
        cout << "Rasta stulpeliu: " << m;
    }
    while (!skait.eof()) {
        A.push_back(duomuo());
        skait >> A[n].vardas >> A[n].pav;
        for (int j = 0; j < m-3; j++) {
            skait >> input;
            A[n].nd.push_back(input);
        }
        skait >> A[n].egz;
        n++;
    }
    skait.close();
}

bool palyginti(duomuo a, duomuo b) {
    // Skirta palyginti du studentus pagal pavardes
    if (a.pav < b.pav)
        return 1;
    else
        return 0;
}

void isvestiFaila(vector<duomuo> A,string failoPav = "rezultatai.txt") {
    // Isveda studentu rezultatus i faila
    ofstream isvest;
    isvest.open(failoPav);
    sort(A.begin(), A.end(), palyginti);
    isvest << setw(15) << left << "Pavarde";
    isvest << setw(15) << left << "Vardas";
    isvest << setw(15) << left << "Galutinis (Vid.) ";
    isvest << "Galutinis (Med.)" << endl;
    isvest << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    for (int i = 0; i < A.size(); i++) {
        isvest << setw(15) << left << A[i].pav << setw(15) << left << A[i].vardas
            << setw(15) << left << std::setprecision(3) << A[i].paz_vid << std::setprecision(3) << A[i].paz_med << endl;
    }
    isvest.close();
}


bool arIslaike(duomuo stud,string tipas) {
    // Patikrina ar studento galutinis pazymis didesnis uz tam tikra riba
    if (tipas == "(Vid.)") return stud.paz_vid < 5;
    else return stud.paz_med < 5;
}

vector<duomuo> padalinti(vector<duomuo>& A, string tipas) {
    // Padalija studentus i dvi grupes pagal pazymius
    vector<duomuo> islaike, neislaike;
    for (auto stud : A) {
        if (arIslaike(stud, tipas)) neislaike.push_back(stud);
        else islaike.push_back(stud);
    }
    A = islaike;
    return neislaike;
}