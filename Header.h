#pragma once

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
    float paz_vid;
    float paz_med;
};

void teisingasIvedimas();
void ivedamiND(vector<duomuo>&,int,int);
void atsitiktiniaiND(vector<duomuo>&, int, int);
void naudojantMediana(vector<duomuo>&, int);
void naudojantVidurki(vector<duomuo>&, int);
void ivedimasRanka(vector<duomuo>&);
void isvedimasEkrane(vector<duomuo>,string = "(Vid.)" );
int gautiNamuDarbuKieki(string);
void nuskaitytiFaila(vector<duomuo>&, string);
bool palyginti(duomuo, duomuo);
void isvestiFaila(vector<duomuo>,string);
bool arIslaike(duomuo, string);
vector<duomuo> padalinti(vector<duomuo>&, string = "(Vid.)");