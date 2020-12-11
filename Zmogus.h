#include <string>

using std::string;

#pragma once
class Zmogus {
protected:
	string vardas_;
	string pavarde_;
public:
	Zmogus() : vardas_{""}, pavarde_{""} {}
	Zmogus(string vardas, string pavarde) : vardas_{vardas}, pavarde_{pavarde} {}
	Zmogus(const Zmogus& zm);

	string vardas() const { return vardas_; };
	string pavarde() const { return pavarde_; };
	void setVardas(string vardas) { vardas_ = vardas; }
	void setPavarde(string pavarde) { pavarde_ = pavarde; }

	virtual string pareigos() = 0; // padaro klase abstrakcia

	Zmogus& operator=(const Zmogus& zm);
	bool operator<(const Zmogus& stud);
	bool operator>(const Zmogus& stud);
	bool operator==(const Zmogus& stud);
	bool operator!=(const Zmogus& stud);

};
