#include "Generator.h"

void sugeneruotiFaila(int n, int nd, string failoPav) {
	// Sugeneruoja atsitiktini pasirinkto dydzio studentu duomenu faila
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, 10);
	int skaitmenys = std::to_string(n).length();
	string s;
	s.resize(skaitmenys + 1);
	ofstream isvest;
	isvest.open(failoPav);
	for (int i = -1; i < n - 1; i++) {
		if (i < 0) {
			isvest << "Vardas" << s << "\t" << "Pavarde" << s << "\t";
			for (int j = 1; j <= nd; j++) {
				isvest << "ND" << j << "\t";
			}
			isvest << "Egz." << endl;
		}
		else {
			isvest << "Vardas" << 0 << i << "\t" << "Pavarde" << 0 << i << "\t";
			for (int j = 1; j <= nd; j++) {
				isvest << dist(rd) << "\t";
			}
			isvest << dist(rd) << endl;
		}
	}
	isvest << "Vardas" << 0 << n << "\t" << "Pavarde" << 0 << n << "\t";
	for (int j = 1; j <= nd; j++) {
		isvest << dist(rd) << "\t";
	}
	isvest << dist(rd);
	isvest.close();
}