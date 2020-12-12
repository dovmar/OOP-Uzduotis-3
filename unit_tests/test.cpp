#include "pch.h"
#include "../Zmogus.cpp"
#include "../Studentas.cpp"
#include "../Generator.cpp"
#include "../Header.cpp"



int failoDydis(string failoPav) {
	int n = 0;
	string eilute;
	ifstream skait(failoPav);
	while (getline(skait, eilute)) {
		if (eilute != "") ++n;
	}
	return n;
}


TEST(Generavimas, FailoDydis) {
	sugeneruotiFaila(1000, 10, "generuotas.txt");
	EXPECT_EQ(1000+1, failoDydis("generuotas.txt"));
}


TEST(Generavimas, StudentuDuomenys) {
	container Stud;
	sugeneruotiFaila(10, 10, "generuotas.txt");
	nuskaitytiFaila(Stud, "generuotas.txt");
	for (auto& studentas : Stud) {
		EXPECT_NE("", studentas.vardas());
		EXPECT_NE("", studentas.pavarde());
		EXPECT_GE(10, studentas.egzaminas());
		EXPECT_LE(0, studentas.egzaminas());
	}
}


TEST(Skaiciavimai, MedianaIrVidurkis) {
	container Stud;
	nuskaitytiFaila(Stud, "generuotas.txt");
	for (auto& studentas : Stud) {
		EXPECT_GE(10, studentas.paz_med());
		EXPECT_LE(0, studentas.paz_med());
		EXPECT_GE(10, studentas.paz_vid());
		EXPECT_LE(0, studentas.paz_vid());
	}
}


TEST(Skaiciavimai, Dalijimas) {
	container Stud,Stud2;
	sugeneruotiFaila(1000, 10, "generuotas.txt");
	nuskaitytiFaila(Stud, "generuotas.txt");
	Stud2 = padalinti(Stud);
	isvestiFaila(Stud, "islaike.txt");
	isvestiFaila(Stud2, "neislaike.txt");
	EXPECT_EQ(1004,
		failoDydis("islaike.txt") +
		failoDydis("neislaike.txt"));
	EXPECT_NE(2, failoDydis("islaike.txt"));
	EXPECT_NE(2, failoDydis("neislaike.txt"));
}

