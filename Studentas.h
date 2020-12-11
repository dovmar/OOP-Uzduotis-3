#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Zmogus.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;

#pragma once

class Studentas : public Zmogus {
private:
	string vardas_;
	string pavarde_;
	vector<int> nd_;
	int egzaminas_;
	float paz_vid_;
	float paz_med_;
public:
	Studentas() :Zmogus{}, egzaminas_{ 1 }, paz_vid_{ 1 }, paz_med_{ 1 } {}
	Studentas(string vardas, string pavarde) : Zmogus{vardas,pavarde}, egzaminas_{ 1 }, paz_vid_{ 1 }, paz_med_{ 1 } {}
    int egzaminas() const { return egzaminas_; }
	float paz_vid() const { return paz_vid_; }
	float paz_med() const { return paz_med_; }
    void setEgzaminas(int egz) { egzaminas_ = egz; }
	void setMediana();
	void setVidurkis();
    void addNd(int nd) { nd_.push_back(nd); }
	friend void ivestiStudenta(Studentas& stud,int m);
	friend void nuskaitytiStudenta(std::ifstream& ifs, Studentas& stud, int m);
	Studentas(const Studentas& stud);
	Studentas& operator=(const Studentas& stud);
};


bool palyginti(Studentas&, Studentas&);
bool arIslaikeVid(Studentas&);
bool arIslaikeMed(Studentas&);
