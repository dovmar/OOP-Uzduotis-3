#include "Header.h"


void ivedimasRanka(container& A) {
    // Studentu duomenu ivedimas rankiniu budu
    int n;
    int m;
    cout << "Kiek studentu norite ivesti? ";
    while (!(cin >> n)) {
        teisingasIvedimas();
    }
    cout << "Kiek namu darbu buvo uzduota? ";
    while (!(cin >> m)) {
        teisingasIvedimas();
    }
    for (int i = 0; i < n; i++) {
        A.push_back(Studentas(m));
    }
}


void isvedimasEkrane(container& A) {
    // Isveda galutinius pazymius i ekrana
    cout << setw(15) << left << "Pavarde";
    cout << setw(15) << left << "Vardas";
    cout << setw(15) << left << "Galutinis (Vid.) ";
    cout << "Galutinis (Med.)" << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    for (auto& stud : A) {
        cout << stud << endl;
    }
}


void nuskaitytiFaila(container& A, string failoPav) {
    // Nuskaito duomenis is failo
    ifstream skait;
    string pirmaEil;
    string zodis;
    int m=0;
    skait.open(failoPav);
    if (skait.fail()) {
        std::cerr << "Klaida atidarant faila";
        exit(0);
    }
    getline(skait, pirmaEil);
    istringstream iss(pirmaEil);
    try {
        while (iss >> zodis) {
            ++m;
        }
        if (m < 3) throw (m);
    }
    catch (int m) {
        cout << "Nepavyko nustatyti tinkamo stulpeliu kiekio" << endl;
        cout << "Rasta stulpeliu: " << m;
    }
    while (!skait.eof()) {
        getline(skait, pirmaEil);
        istringstream iss(pirmaEil);
        A.push_back(Studentas(iss, m - 3));
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
    for (auto& stud : A) {
       isvest << stud << endl;
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
    string kelias;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    cout << "Pasirinkite direktorija, kurioje bus sukurti failai: " << endl;
    cout << "1. Instaliavimo direktorija (gali reiketi paleisti programa kaip administratoriui)" << endl;
    cout << "2. Kita direktorija" << endl; 
    cin >> n;
    while (true) {
        if (n == 1) {
            kelias = "";
            break; 
        }
        else if (n == 2) {
            cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
            cout << "Iveskite direktorijos, kurioje bus sukurti faila absoliutini kelia (absolute path): " << endl;
            cin >> kelias;
            kelias = kelias + "\\" ;
            break;
        }
        else {
            cout << "Tokio pasirinkimo nera. Iveskite is naujo" << endl;
        }
    }
    while (true) {
        cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
        cout << "Kokiu budu norite pateikti studentu duomenis?" << endl;
        cout << "1. Nuskaityti is failo" << endl;
        cout << "2. Ivesti" << endl;
        cin >> n;
        if (n == 1) {
            cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
            cout << "1. Pateikti esamo failo pavadinima" << endl;
            cout << "2. Sugeneruoti faila" << endl;
            cin >> n;
            if (n == 1) {
                cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
                cout << "Iveskite pilna failo pavadinima (iskaitant .txt)" << endl;
                cin >> failoPav;
                cout << "Siek tiek palaukite!" << endl;
                nuskaitytiFaila(A, failoPav);
                break;
            }
            else if (n == 2) {
                cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
                cout << "Kokio dydzio faila norite sugeneruoti? " << endl;
                cin >> m;
                cout << endl;
                cout << "Siek tiek palaukite!" << endl;
                sugeneruotiFaila(m,10, kelias+"generuotas.txt");
                failoPav = "generuotas.txt";
                nuskaitytiFaila(A, failoPav);
                break;
            }
            else {
                cout << "Tokio pasirinkimo nera. Iveskite is naujo" << endl;
            }
        }
        else if (n == 2) {
            cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
            ivedimasRanka(A);
            break;
        }
        else {
            cout << "Tokio pasirinkimo nera. Iveskite is naujo" << endl;
        }
    }
    A2 = padalinti(A);
    isvestiFaila(A, kelias+"islaike.txt");
    isvestiFaila(A2, kelias+"neislaike.txt");
    cout << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    cout << "Rezultatai isvesti i failus 'islaike.txt' ir 'neislaike.txt'!";
    cin.ignore(256, '\n');
    cin.get();
}
