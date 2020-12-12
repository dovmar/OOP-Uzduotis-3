#include "Zmogus.h"


bool Zmogus::operator<(const Zmogus& zm) {
    return pavarde_ <= zm.pavarde_ || (pavarde_ == zm.pavarde_ && vardas_ < zm.vardas_);
}


bool Zmogus::operator>(const Zmogus& zm) {
    return !operator<(zm);
}


bool Zmogus::operator==(const Zmogus& zm) {
    return vardas_ == zm.vardas_ && pavarde_ == zm.pavarde_;
}


bool Zmogus::operator!=(const Zmogus& zm) {
    return !operator==(zm);
}


Zmogus& Zmogus::operator=(const Zmogus& zm) {
	if (&zm == this) return *this;
	else {
		vardas_ = zm.vardas_;
		pavarde_ = zm.pavarde_;
	}
	return *this;
}


Zmogus::Zmogus(const Zmogus& zm) : vardas_{ zm.vardas_ }, pavarde_{ zm.pavarde_ } {}