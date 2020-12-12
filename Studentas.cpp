#include "Studentas.h"


void teisingasIvedimas() {
    // Skirtas patikrinti ar ivestas sveikas skaicius
    cin.clear();
    cin.ignore(80, '\n');
    cout << "Iveskite tinkama sveikaji skaiciu: ";
}


Studentas::Studentas(std::istringstream& iss, int m) {
    // Nuskaito studenta is eilutes srauto
    int input;
    iss >> vardas_ >> pavarde_;
    if (m > 0) {
        for (int j = 0; j < m; j++) {
            iss >> input;
            this->addNd(input);
        }
    }
    iss >> egzaminas_;
    this->setVidurkis();
    this->setMediana();
}


Studentas::Studentas(int m) {
    // Ivesti studenta rankiniu budu
    int input;
    cout << "Iveskite studento varda: \n";
    cin >> vardas_;
    cout << "Iveskite studento pavarde: \n";
    cin >> pavarde_;
    if (m > 0) {
        cout << "Iveskite studento namu darbu pazymius: \n";
        for (int j = 0; j < m; j++) {
            while (!(cin >> input && input > 0 && input <= 10)) {
                teisingasIvedimas();
            }
            this->addNd(input);
        }
    }
    cout << "Iveskite studento egzamino pazymi: \n";
    while (!(cin >> input)) {
        teisingasIvedimas();
    }
    egzaminas_ = input;
    this->setVidurkis();
    this->setMediana();
}


void Studentas::setMediana() {
    // Apskaiciuoja galutini pazymi naudojant namu darbu mediana
    int m = this->nd_.size();
    if (m == 0) this->paz_med_ = 0;
    else if (m == 1) this->paz_med_ = this->nd_[0];
    else {
        sort(this->nd_.begin(), this->nd_.end());
        if (m % 2 != 0) {
            this->paz_med_ = this->nd_[m / 2];
        }
        else {
            this->paz_med_ = (this->nd_[m / 2] + this->nd_[m / 2 - 1]) / 2;
        }
    }
    this->paz_med_ = this->paz_med_ * 0.4 + this->egzaminas_ * 0.6;
}


void Studentas::setVidurkis() {
    // Apskaiciuoja galutini pazymi naudojant namu darbu vidurki
    int m = this->nd_.size();
    if (m == 0) this->paz_vid_ = this->egzaminas_ * 0.6;
    else {
        this->paz_vid_ = 0;
        for (auto paz : this->nd_) {
            this->paz_vid_ = this->paz_vid_ + paz;
        }
        this->paz_vid_ = this->paz_vid_ * 0.4 / m + this->egzaminas_ * 0.6;
    }
}


ostream& operator<<(std::ostream& isves, const Studentas& stud) {
    // Studento isvedimas
    isves << setw(15) << left << stud.pavarde() << setw(15) << left << stud.vardas()
        << setw(15) << left << std::setprecision(3) << stud.paz_vid() << std::setprecision(3) << stud.paz_med();
    return isves;
}


Studentas::Studentas(const Studentas& stud) : Zmogus(stud), nd_{ stud.nd_ }, egzaminas_{ stud.egzaminas_ }, paz_vid_{ stud.paz_vid_ }, paz_med_{stud.paz_med_} {}


Studentas& Studentas::operator=(const Studentas& stud) {
	if (&stud == this) return *this;
	else {
		vardas_ = stud.vardas_;
		pavarde_ = stud.pavarde_;
		nd_ = stud.nd_;
		egzaminas_ = stud.egzaminas_;
	}
    return *this;
}


bool palyginti(Studentas& a, Studentas& b) {
    // Skirta palyginti du studentus pagal pavardes
	if (a.pavarde() < b.pavarde())
        return 1;
    else
        return 0;
}


bool arIslaikeVid(Studentas& stud) {
    // Patikrina ar studento galutinis pazymis didesnis uz tam tikra riba
    return stud.paz_vid() >= 5;
}


bool arIslaikeMed(Studentas& stud) {
    // Patikrina ar studento galutinis pazymis didesnis uz tam tikra riba
    return stud.paz_med() >= 5;
}
