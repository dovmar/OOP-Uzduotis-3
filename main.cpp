
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setfill;
using std::left;
using std::setw;
using std::sort;
using std::ifstream;
using std::ofstream;

struct duomuo {
    string vardas;
    string pav;
    vector <int> nd;
    int egz;
    float paz = 0;
};

void teisingasIvedimas() {
    // Skirta naudoti kai tikrinima ar ivestas sveikas skaicius
    cin.clear();
    cin.ignore(80, '\n');
    cout << "Iveskite sveikaji skaiciu: ";
}

void ivedamiND(vector<duomuo> &A, int i, int m) {
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


void atsitiktiniaiND(vector<duomuo> &A, int i, int m) {
    // Sugeneruoja atsitiktinius namu darbu pazymius 
    for (int j = 0; j < m; j++) {
        A[i].nd.push_back((rand() % 10) + 1);
    }
}

void naudojantMediana(vector<duomuo> &A, int i, int m) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu mediana
    if (m == 1) A[i].paz = A[i].nd[0];
    else {
        sort(A[i].nd.begin(),A[i].nd.end());
        if (m % 2 != 0) {
            A[i].paz = A[i].nd[m / 2];
        }
        else {
            A[i].paz = (A[i].nd[m / 2] + A[i].nd[m / 2 - 1]) / 2;
        }
    }
    A[i].paz = A[i].paz * 0.4 + A[i].egz * 0.6;
}

void naudojantVidurki(vector<duomuo> &A, int i, int m) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu vidurki
    for (int j = 0; j < m; j++) {
        A[i].paz = A[i].paz + A[i].nd[j];
    }
    A[i].paz = A[i].paz * 0.4 / m + A[i].egz * 0.6;
}


void ivedimas(vector<duomuo> &A, int &n) {
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
        /* Galima apskaiciuoti galutini pazymi naudojant namu darbu vidurki su naudojantVidurki()
        arba naudojant mediana su naudojantMediana() */
        if (m > 0) naudojantMediana(A, i, m);
        else A[i].paz = A[i].egz;
    }
}


void isvedimas(vector<duomuo> A, int n, string tipas) {
    // Isveda galutinius pazymius*/
    cout << setw(15) << left << "Pavarde";
    cout << setw(15) << left << "Vardas";
    cout << "Galutinis " << tipas << endl;
    cout << setfill('-')<< setw(50) << "-" << setfill(' ') << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(15) << left << A[i].pav << setw(15) << left << A[i].vardas << std::setprecision(3) << A[i].paz << endl;
    }
}


int gautiNamuDarbuKieki(string s) {
    /* Analizuoja pirma nuskaityto failo eilute norint gauti namu darbu kieki*/
    bool praeitas = 0; 
    int kiekis = 0;
    for (int i = 0; i < s.size(); i++) {
        if (praeitas == 1 & s[i] == (char)' ') kiekis = kiekis + 1;
        if (s[i] == (char)' ') praeitas = 0;
        else praeitas = 1;
    }
    return kiekis-2;
}


void nuskaitytiFaila(vector<duomuo> &A,int &n, string failoPav) {
    ifstream skait;
    string pirmaEil;
    skait.open(failoPav);
    if (skait.fail()) {
        std::cerr << "Klaida atidarant faila";
        exit(0);
    }
    int input;
    n = 0; // studentu kiekis
    int m; // namu darbu kiekis
    getline(skait, pirmaEil);
    m = gautiNamuDarbuKieki(pirmaEil);
    while(!skait.eof()) {
        A.push_back(duomuo());
        skait >> A[n].vardas >> A[n].pav;
        for (int j = 0; j < m; j++) {
            skait >> input;
            A[n].nd.push_back(input);
        }
        skait >> A[n].egz;
        if (m > 0) naudojantVidurki(A, n, m);
        else A[n].paz = A[n].egz;
        n++;
    }
    skait.close();
}

bool palyginti(duomuo a, duomuo b){
    if (a.pav < b.pav)
        return 1;
    else
        return 0;
}

void isvestiFaila(vector<duomuo> A,int n,string tipas) {
    ofstream isvest;
    isvest.open("rezultatai.txt");
    sort(A.begin(), A.end(),palyginti);
    isvest << setw(15) << left << "Pavarde";
    isvest << setw(15) << left << "Vardas";
    isvest << "Galutinis " << tipas << endl;
    isvest << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    for (int i = 0; i < n; i++) {
        isvest << setw(15) << left << A[i].pav << setw(15) << left << A[i].vardas << std::setprecision(3) << A[i].paz << endl;
    }
    isvest.close();
}

int main()
{
    int n;
    vector <duomuo> Stud;
    nuskaitytiFaila(Stud,n,"kursiokai.txt");
    isvestiFaila(Stud, n, "(Med.)");
    //ivedimas(Stud,n);
    //isvedimas(Stud, n,"(Med.)");
}
