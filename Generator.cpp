#include "Generator.h"

void sugeneruotiFaila(int n, int nd, string failoPav) {
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
		isvest << "Vardas" << 0 << i << "\t" << "Pavarde" << i << "\t";
		for (int j = 1; j <= nd; j++) {
			isvest << dist(rd) << "\t";
		}
		isvest << dist(rd) << "\t" << endl;
	}
}

/*void sugeneruotiFaila(int n, int nd, string failoPav) {
	ofstream isvest;
	string eilute;
	eilute = "Vardas";
	int skaitmenys = std::to_string(n).length();
	string tarpai(skaitmenys + 3, ' ');
	isvest.open(failoPav);
	eilute = eilute + tarpai + "Pavarde" + tarpai;
	for (int i = 0; i < nd; i++) {
		eilute = eilute + "ND" + std::to_string(i) + "\t";
	}
	eilute = eilute + "Egz." + "\n";
	for (int i = 0; i < n; i++) {
		eilute = eilute + "Vardas" + std::to_string(i) + tarpai + "Pavarde" + std::to_string(i) + tarpai;
		for (int j = 0; j < nd; j++) {
			eilute = eilute + std::to_string(dist(rd)) + "\t";
		}
		eilute = eilute + std::to_string(dist(rd)) + "\n";
	}
	isvest << eilute;
}*/