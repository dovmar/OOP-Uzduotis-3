#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Zmogus.h"

using std::vector;
using std::string;
using std::ostream;
using std::ofstream;
using std::istringstream;
using std::cin;
using std::cout;
using std::setw;
using std::left;

#pragma once

class Studentas : public Zmogus {
protected:
	vector<int> nd_;
	int egzaminas_;
	float paz_vid_;
	float paz_med_;
public:
	Studentas() :Zmogus{}, egzaminas_{ 0 }, paz_vid_{ 0 }, paz_med_{ 0 } {}
	Studentas(string vardas, string pavarde) : Zmogus{vardas,pavarde}, egzaminas_{ 0 }, paz_vid_{ 0 }, paz_med_{ 0 } {}
	Studentas(istringstream& iss, int m);
	Studentas(int m);
	Studentas(const Studentas& stud);

    int egzaminas() const { return egzaminas_; }
	float paz_vid() const { return paz_vid_; }
	float paz_med() const { return paz_med_; }
	void setEgzaminas(int egz) { egzaminas_ = egz; }
	void setMediana();
	void setVidurkis();
    void addNd(int nd) { nd_.push_back(nd); }

	string pareigos() { return "studentas"; }

	Studentas& operator=(const Studentas& stud);

	friend ostream& operator<<(ostream& isves, const Studentas& stud);
	friend void ivestiStudenta(Studentas& stud, int m);
};


bool palyginti(Studentas&, Studentas&);
bool arIslaikeVid(Studentas&);
bool arIslaikeMed(Studentas&);
