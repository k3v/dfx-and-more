#include <math.h>

#include "dfxam.h"

using namespace dfxam::ast;

Constant::Constant(double val)
    : value(val) {}

double Constant::getValue() const {
    return value;
}

Expression* Constant::derivative(Variable* respect) {
    return new Constant(0);
}

Expression* Constant::simplify() {
//    std::cout << "Simplifying: " << this << std::endl;

    return clone();
}

std::string Constant::toString() const {
    std::stringstream s;
    s << value;

    return s.str();
}

Expression* Constant::clone() {
    return new Constant(getValue());
}

bool Constant::isConstant() const {
    return true;
}

E::E() 
    : Constant(exp(1)) {}

std::string E::toString() const {
    return "e";
}

Expression* E::clone() {
    return new E();
}