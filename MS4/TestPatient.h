/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H

#include "Patient.h"

namespace seneca {

    class TestPatient : public Patient {
    public:
        TestPatient();

        ~TestPatient() = default;

        char type() const override;

        std::ostream& write(std::ostream& ostr) const override;

        std::istream& read(std::istream& istr) override;
    };

}

#endif 
