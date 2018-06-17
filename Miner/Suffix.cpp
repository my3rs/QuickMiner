
#include "Suffix.h"
#include <ostream>

std::string Suffix::getSuffix() {
    return this->suffix;
}


int Suffix::getSupport() {
    return this->support;
}


void Suffix::setSuffix(std::string &suffix) {
    this->suffix = suffix;
}

void Suffix::setSupport(int support) {
    this->support = support;
}


std::ostream& operator<<(std::ostream &out, const Suffix &s) {
    out << s.suffix << "(" << s.support << ")";

    return out;
}

