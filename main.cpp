
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setfill;
using std::left;
using std::setw;
using std::sort;

struct duomuo {
    string vardas;
    string pav;
    int nd[10];
    int egz;
    float paz = 0;
};


void ivedamiND(duomuo A[],int i, int m) {
    cout << "Iveskite studento namu darbu pazymius: \n";
    for (int j = 0; j < m; j++) {
        cin >> A[i].nd[j];
    }
}


void atsitiktiniaiND(duomuo A[], int i, int m) {
    for (int j = 0; j < m; j++) {
        A[i].nd[j] = (rand() % 10) + 1;
    }
}

void naudojantMediana(duomuo A[], int m, int n) {
    for (int i = 0; i < n; i++) {
        if (m == 1) A[i].paz = A[i].nd[0];
        else {
            sort(A[i].nd, A[i].nd + m);
            if (m % 2 != 0) {
                A[i].paz = A[i].nd[m / 2];
            }
            else {
                A[i].paz = A[i].nd[m / 2] + A[i].nd[m / 2 - 1] / 2;
            }
        }
        A[i].paz = A[i].paz * 0.4 + A[i].egz * 0.6;
    }
}

void naudojantVidurki(duomuo A[], int m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i].paz = A[i].paz + A[i].nd[j];
        }
        A[i].paz = A[i].paz * 0.4 / m + A[i].egz * 0.6;
    }
}


void isvedimas(duomuo A[], int n, string tipas) {
    cout << setw(15) << left << "Pavarde";
    cout << setw(15) << left << "Vardas";
    cout << "Galutinis " << tipas << endl;
    cout << setfill('-')<< setw(50) << "-" << setfill(' ') << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(15) << left << A[i].pav << setw(15) << left << A[i].vardas << std::setprecision(3) << A[i].paz << endl;
    }
}


int main()
{
    duomuo *Stud;
    int n,m;
    cout << "Kiek studentu norite ivesti? ";
    cin >> n;
    cout << "Kiek namu darbu buvo uzduota? ";
    cin >> m;
    Stud = new duomuo[n];
    for (int i = 0; i < n; i++) {
        cout << "Iveskite studento varda ir pavarde: \n";
        cin >> Stud[i].vardas;
        cout << "Iveskite studento pavarde: \n";
        cin >> Stud[i].pav;
        /*atsitiktiniaiND(Stud, i, m);*/
        if(m != 0) ivedamiND(Stud, i, m);
        cout << "Iveskite studento egzamino pazymi: \n";
        cin >> Stud[i].egz;
        /*if (m > 0) naudojantVidurki(Stud, m, n)*/
        if (m > 0) naudojantMediana(Stud, m, n);
        else Stud[i].paz =  Stud[i].egz * 0.6;
    }
    isvedimas(Stud, n, "(Med.)");
}

