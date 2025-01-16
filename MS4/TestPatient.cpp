/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#include "TestPatient.h"

namespace seneca {

    int nextTestTicket = 1;

    TestPatient::TestPatient() : Patient(nextTestTicket++) {}

    char TestPatient::type() const {
        return 'C';
    }

    std::ostream& TestPatient::write(std::ostream& ostr) const {
        if (&ostr == &std::cout) {
            ostr << "Contagion TEST\n";
        }
        Patient::write(ostr);
        return ostr;
    }

    std::istream& TestPatient::read(std::istream& istr) {
        Patient::read(istr);
        if (&istr != &std::cin) {
            nextTestTicket = number() + 1;
        }
        return istr;
    }

}
