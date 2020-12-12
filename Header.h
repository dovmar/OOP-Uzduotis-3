#pragma once

#include "Studentas.h"
#include "Generator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <fstream>
#include <exception>
#include <sstream>

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
using std::istringstream;

using container = vector<Studentas>;

void teisingasIvedimas();
void ivedimasRanka(container&);
void isvedimasEkrane(container&);
void nuskaitytiFaila(container&, string);
void isvestiFaila(container&,string);
container padalinti(container&, bool(*tipas)(Studentas&) = arIslaikeVid);
void mySort(vector<Studentas>&);
void mySort(list<Studentas>&);
void paleisti(container&, container&);