
#include <iostream>
#include <iomanip>
#include <string>


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setfill;
using std::left;
using std::setw;

struct duomuo {
    string vardas;
    string pav;
    int nd[10];
    int egz;
    float paz = 0;
};

void isvedimas(duomuo A[], int n) {
    cout << setw(15) << left << "Pavarde";
    cout << setw(15) << left << "Vardas";
    cout << "Galutinis (Vid.)" << endl;
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
        cout << "Iveskite studento namu darbu pazymius: \n";
        for (int j = 0; j < m; j++) {
            cin >> Stud[i].nd[j];
            Stud[i].paz = Stud[i].paz + Stud[i].nd[j];
        }
        cout << "Iveskite studento egzamino pazymi: \n";
        cin >> Stud[i].egz;
        Stud[i].paz = 0.4 * Stud[i].paz / m + Stud[i].egz * 0.6;
        cout << endl;
    }
    isvedimas(Stud, n);
 
}

