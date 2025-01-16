
/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <limits>
#include "PreTriage.h"
#include "Utils.h"
#include "Time.h"
#include "Patient.h"
#include "TriagePatient.h"
#include "Menu.h"

using namespace std;

namespace seneca {

    PreTriage::PreTriage(const char* dataFilename) : m_numPatients(0) {
        if (dataFilename) {
            m_dataFilename = new char[strlen(dataFilename) + 1];
            my_strcpy(m_dataFilename, dataFilename);
        }
        else {
            m_dataFilename = nullptr;
        }
        m_averWaitTimeContagion = Time(15);
        m_averWaitTimeTriage = Time(5);
        load();
    }

    PreTriage::~PreTriage() {
        save();
        for (int i = 0; i < m_numPatients; ++i) {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
    }

    void PreTriage::run() {
        int choice;
        do {
            cout << "General Healthcare Facility Pre-Triage Application" << endl;
            cout << "1- Register" << endl;
            cout << "2- Admit" << endl;
            cout << "3- View Lineup" << endl;
            cout << "0- Exit" << endl;
            cout << "> ";
            cin >> choice;

            switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                admitPatient();
                break;
            case 3:
                viewLineup();
                break;
            case 0:
                break;
            default:
                cout << "error" << endl;
            }
        } while (choice != 0);
    }


    void PreTriage::setAverageWaitTime(Patient& p) {
        int index = (p.type() == 'C') ? 0 : 1; 
        int waitTime = (Time() - p.time()) + (m_averWaitTimeContagion * (p.number() - 1));
        if (index == 1) {
            waitTime = (Time() - p.time()) + (m_averWaitTimeTriage * (p.number() - 1));
        }
        m_averWaitTimeContagion = waitTime / p.number();
        if (index == 1) {
            m_averWaitTimeTriage = waitTime / p.number();
        }
    }

    int PreTriage::getWaitTime(Patient& p) const {
        int index = (p.type() == 'C') ? 0 : 1;
        if (index == 0) {
            return m_averWaitTimeContagion * indexOfFirstInLine(p.type());
        }
        else {
            return m_averWaitTimeTriage * indexOfFirstInLine(p.type());
        }
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        for (int i = 0; i < m_numPatients; ++i) {
            if (*m_lineup[i] == type) {
                return i;
            }
        }
        return -1;
    }

    void PreTriage::load() {
        cout << "Loading data..." << endl;
        ifstream file(m_dataFilename);
        if (!file.is_open()) {
            cout << "No data or bad data file!" << endl << endl;
            return;
        }

        file >> m_averWaitTimeContagion;
        file.ignore();
        file >> m_averWaitTimeTriage;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        char type;
        while (file >> type) {
            Patient* patient = nullptr;
            if (type == 'C') {
                patient = new ContagionPatient;
            }
            else if (type == 'T') {
                patient = new TriagePatient;
            }

            if (patient) {
                file.ignore();
                file >> *patient;
                if (m_numPatients < maximumLineupValue) {
                    m_lineup[m_numPatients++] = patient;
                }
            }
        }

        file.close();

        if (m_numPatients > 0) {
            cout << m_numPatients << " Records imported..." << endl << endl;
        }
        else {
            cout << "No data or bad data file!" << endl << endl;
        }
    }



    void PreTriage::save() const {
        ofstream file(m_dataFilename);

        cout << "Saving lineup..." << endl;
        file << m_averWaitTimeContagion << "," << m_averWaitTimeTriage << endl;

        int countContagion = 0, countTriage = 0;
        for (int i = 0; i < m_numPatients; ++i) {
            if (m_lineup[i]->type() == 'C') {
                ++countContagion;
            }
            else if (m_lineup[i]->type() == 'T') {
                ++countTriage;
            }
            file << *m_lineup[i] << endl;
        }

        cout << countContagion << " Contagion Tests and " << countTriage << " Triage records were saved!" << endl;

        file.close();
    }



    void PreTriage::registerPatient() {
        Menu patientTypeMenu("Select Type of Registration:\n1- Contagion Test\n2- Triage\n0- Exit", 1);
        int choice;
        patientTypeMenu >> choice;

        Patient* patient = nullptr;
        switch (choice) {
        case 1:
            patient = new ContagionPatient;
            break;
        case 2:
            patient = new TriagePatient;
            break;
        case 0:
            return;
        default:
            cout << "error" << endl;
            return;
        }

        patient->setArrivalTime();
        cout << "Please enter patient information: " << endl;

        cin >> *patient;
        cin.ignore(10000, '\n');

        cout << "******************************************" << endl;
        cout << *patient << endl;
        cout << "Estimated Wait Time: " << getWaitTime(*patient) << endl;
        cout << "******************************************" << endl << endl;

        m_lineup[m_numPatients++] = patient;
    }



    void PreTriage::admitPatient() {
        cout << "Select Type of Admittance:" << endl;
        cout << "1- Contagion Test" << endl;
        cout << "2- Triage" << endl;
        cout << "0- Exit" << endl;
        cout << "> ";

        int choice;
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 0) {
            return;
        }

        char type = (choice == 1) ? 'C' : 'T';
        int index = indexOfFirstInLine(type);

        cout << "******************************************" << endl;
        cout << "Call time [" << Time() << "]" << endl;
        cout << "Calling for " << *m_lineup[index] << endl;
        cout << "******************************************" << endl << endl;

        setAverageWaitTime(*m_lineup[index]);
        removeDynamicElement(m_lineup, index, m_numPatients);
    }

    void PreTriage::viewLineup() const {
        cout << "Select The Lineup:" << endl;
        cout << "1- Contagion Test" << endl;
        cout << "2- Triage" << endl;
        cout << "0- Exit" << endl;
        cout << "> ";

        int choice;
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 0) {
            return;
        }

        char type = (choice == 1) ? 'C' : 'T';
        cout << "Row - Patient name                                          OHIP     Tk #  Time" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < m_numPatients; ++i) {
            if (*m_lineup[i] == type) {
                cout << i + 1 << " - " << *m_lineup[i] << endl;
            }
        }
        cout << "-------------------------------------------------------------------------------" << endl;
    }
}