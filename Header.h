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

struct duomuo {
    string vardas;
    string pav;
    vector <int> nd;
    int egz;
    float paz_vid;
    float paz_med;
};

using container = list<duomuo>;

void teisingasIvedimas();
void ivedamiND(container&,int,int);
void naudojantMediana(duomuo&);
void naudojantVidurki(duomuo&);
void ivedimasRanka(container&);
void isvedimasEkrane(container&,string = "(Vid.)" );
int gautiStulpeliuKieki(string);
void nuskaitytiFaila(container&, string);
bool palyginti(duomuo, duomuo);
void isvestiFaila(container&,string);
bool arIslaike(duomuo&, string);
container padalinti(container&, string = "(Vid.)");
void mySort(vector<duomuo>&);
void mySort(list<duomuo>&);
