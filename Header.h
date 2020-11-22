#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <fstream>
#include <exception>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::list;
using std::endl;
using std::setfill;
using std::left;
using std::setw;
using std::sort;
using std::ifstream;
using std::ofstream;

struct Studentas {
    string vardas;
    string pav;
    vector <int> nd;
    int egz;
    float paz_vid;
    float paz_med;
};

using container = vector<Studentas>;

void teisingasIvedimas();
void ivedamiND(container&,int,int);
void naudojantMediana(Studentas&);
void naudojantVidurki(Studentas&);
void ivedimasRanka(container&);
void isvedimasEkrane(container&,string = "(Vid.)" );
int gautiStulpeliuKieki(string);
void nuskaitytiFaila(container&, string);
bool palyginti(Studentas, Studentas);
void isvestiFaila(container&,string);
bool arIslaikeVid(Studentas&);
bool arIslaikeMed(Studentas&);
container padalinti(container&, bool(*tipas)(Studentas&) = arIslaikeVid);
container padalinti2(container&, bool(*tipas)(Studentas&) = arIslaikeVid);
container padalinti3(container&, bool(*tipas)(Studentas&) = arIslaikeVid);
void mySort(vector<Studentas>&);
void mySort(list<Studentas>&);