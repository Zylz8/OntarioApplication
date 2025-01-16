
/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H

#include "Patient.h"
#include "Menu.h"
#include "Ticket.h"
#include "Time.h"

namespace seneca {

    const int maximumLineupValue = 100;

    class PreTriage {
        Time m_averWaitTimeContagion;
        Time m_averWaitTimeTriage;
        Patient* m_lineup[maximumLineupValue];
        char* m_dataFilename;
        int m_numPatients;

        void setAverageWaitTime(Patient& p);
        int getWaitTime(Patient& p) const;
        int indexOfFirstInLine(char type) const;
        void load();
        void save() const;
        void registerPatient();
        void admitPatient();
        void viewLineup() const;

    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run();
    };

}
#endif // !SENECA_PRETRIAGE_H
