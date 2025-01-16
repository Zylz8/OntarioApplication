/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#include "TriagePatient.h"
#include "Utils.h"
#include <iostream>
#include <cstring>

namespace seneca {

    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket++) {
        m_symptoms = nullptr;
    }


    TriagePatient::~TriagePatient() {
        delete[] m_symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    std::istream& TriagePatient::read(std::istream& istr) {
        delete[] m_symptoms;
        m_symptoms = nullptr;

        Patient::read(istr);

        if (&istr != &std::cin) {
            char comma;
            istr >> comma; 
        }

        char symptomsBuffer[512];
        if (&istr == &std::cin) {
            std::cout << "Symptoms: ";
            istr.ignore(); 
        }
        istr.getline(symptomsBuffer, 512);

        m_symptoms = new char[strlen(symptomsBuffer) + 1];
        my_strcpy(m_symptoms, symptomsBuffer);


        nextTriageTicket = std::max(nextTriageTicket, number() + 1);

        return istr;
    }


    std::ostream& TriagePatient::write(std::ostream& ostr) const {
        if (&ostr == &std::cout) {
            ostr << "TRIAGE" << std::endl; 
            Patient::write(ostr);  
            ostr << "Symptoms: " << m_symptoms << std::endl;
        }
        else if (&ostr == &std::clog) {
            Patient::write(ostr);  
        }
        else {
            Patient::write(ostr); 
            ostr << "," << m_symptoms;  
        }
        return ostr; 
    }


} 
