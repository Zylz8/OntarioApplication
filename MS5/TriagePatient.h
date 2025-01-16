/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H

#include "Patient.h"

namespace seneca {

    class TriagePatient : public Patient {
    private:
        char* m_symptoms;

    public:
        TriagePatient();
        ~TriagePatient();

        char type() const override;
        std::istream& read(std::istream& istr) override;
        std::ostream& write(std::ostream& ostr) const override;
    };

    class ContagionPatient : public Patient {
    public:
        // Constructors
        ContagionPatient();
        ContagionPatient(const char* name, int ohip, int ticketNumber);
        // Destructor
        virtual ~ContagionPatient();
        // Other member functions specific to ContagionPatient
        virtual char type() const override;
    };

}

#endif 
