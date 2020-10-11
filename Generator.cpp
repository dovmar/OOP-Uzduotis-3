#include "Generator.h"

void sugeneruotiFaila(int n, int nd, string failoPav) {
	// Sugeneruoja atsitiktini studentu duomenu faila
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, 10);
	int skaitmenys = std::to_string(n).length();
	ofstream isvest;
	isvest.open(failoPav);
	isvest << setw(12 + skaitmenys) << std::left << "Vardas" << setw(12 + skaitmenys) << std::left << "Pavarde";
	for (int j = 1; j <= nd; j++) {
		isvest << "ND" << j << "\t";
	}
	isvest << "Egz." << endl;
	for (int i = 0; i < n; i++) {
		isvest << "Vardas" << 0 << i << "\t" << "Pavarde" << 0 << i << "\t";
		for (int j = 1; j <= nd; j++) {
			isvest << dist(rd) << "\t";
		}
		isvest << dist(rd) << "\t" << endl;
	}
	isvest.close();
}