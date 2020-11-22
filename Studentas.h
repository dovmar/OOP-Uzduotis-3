#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;

#pragma once
class Studentas
{
private:
	string vardas_;
	string pavarde_;
	vector<int> nd_;
	int egzaminas_;
	float paz_vid_;
	float paz_med_;
public:
    Studentas() : vardas_{ "" }, pavarde_{ "" }, egzaminas_{ 1 }, paz_vid_{ 1 }, paz_med_{1} {}
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
    int egzaminas() const { return egzaminas_; }
	float paz_vid() const { return paz_vid_; }
	float paz_med() const { return paz_med_; }
	void setVardas(string vardas) { vardas_ = vardas; }
	void setPavarde(string pavarde) { pavarde_ = pavarde; }
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
