#include "Zmogus.h"


bool Zmogus::operator<(const Zmogus& stud) {
    return pavarde_ <= stud.pavarde_ || (pavarde_ == stud.pavarde_ && vardas_ < stud.vardas_);
}

bool Zmogus::operator>(const Zmogus& stud) {
    return !operator<(stud);
}

bool Zmogus::operator==(const Zmogus& stud) {
    return vardas_ == stud.vardas_ && pavarde_ == stud.pavarde_;
}

bool Zmogus::operator!=(const Zmogus& stud) {
    return !operator==(stud);
}
