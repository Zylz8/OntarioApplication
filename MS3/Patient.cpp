
/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#include "Patient.h"
#include "Utils.h" 
#include "Ticket.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace seneca {

    Patient::Patient(int ticketNumber) : m_name(nullptr), m_OHIP(0), m_ticket(ticketNumber) {}

    Patient::Patient(const Patient& other) : m_name(nullptr), m_OHIP(0), m_ticket(0) {
        copyFrom(other);
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    Patient::~Patient() {
        clear();
    }

    void Patient::copyFrom(const Patient& other) {
        if (other.m_name) {
            m_name = new char[strlen(other.m_name) + 1];
            my_strcpy(m_name, other.m_name);
        }
        m_OHIP = other.m_OHIP;
        m_ticket = other.m_ticket;
    }

    void Patient::clear() {
        delete[] m_name;
        m_name = nullptr;
    }

    bool Patient::operator==(char c) const {
        return type() == c;
    }

    bool Patient::operator==(const Patient& other) const {
        return type() == other.type();
    }

    void Patient::setArrivalTime() {
        m_ticket.resetTime();
    }

    Time Patient::time() const {
        return m_ticket.time();
    }

    int Patient::number() const {
        return m_ticket.number();
    }

    Patient::operator bool() const {
        return m_name != nullptr && m_OHIP >= 100000000 && m_OHIP <= 999999999;
    }

    Patient::operator const char* () const {
        return m_name ? m_name : "Invalid Patient Record";
    }

    std::ostream& Patient::write(std::ostream& ostr) const {
        if (&ostr == &std::cout) {
            if (*this) {
                ostr << m_ticket << std::endl;
                ostr << m_name << ", OHIP: " << m_OHIP << std::endl;
            }
            else {
                ostr << "Invalid Patient Record" << std::endl;
            }
        }

        else if (&ostr == &std::clog) {
            if (*this) {

                if (m_name) {
                    ostr << std::setw(8) << std::left << m_name;
                    for (size_t i = strlen(m_name); i < 53; ++i) {
                        ostr << ".";
                    }
                }
                else {
                    ostr << std::setw(53) << std::left << "Invalid Patient Record";
                }

                ostr << m_OHIP << std::setw(5) << std::right << m_ticket.number() << " " << m_ticket.time();
            }
            else {

                ostr << "Invalid Patient Record";
            }
        }

        else {

            ostr << type() << ",";

            if (m_name) {
                ostr << m_name;
            }

            ostr << "," << m_OHIP << ",";

            m_ticket.write(ostr);
        }
        return ostr;
    }

    std::istream& Patient::read(std::istream& istr) {

        clear();


        if (&istr == &std::cin) {

            std::cout << "Name: ";
            char nameBuffer[51];
            istr.get(nameBuffer, 51, '\n');
            istr.ignore(10000, '\n');

            m_name = new char[strlen(nameBuffer) + 1];
            my_strcpy(m_name, nameBuffer);

            std::cout << "OHIP: ";
            int ohip;
            while (true) {
                if (!(istr >> ohip)) {
                    std::cerr << "Bad integer value, try again: ";
                    istr.clear();
                    istr.ignore(10000, '\n');
                    continue;
                }
                if (ohip < 100000000 || ohip > 999999999) {
                    std::cerr << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                    istr.ignore(10000, '\n');
                    continue;
                }
                break;
            }
            m_OHIP = ohip;
        }
        else {
            char nameBuffer[51];
            istr.get(nameBuffer, 51, ',');
            istr.ignore(10000, ',');
            m_name = new char[strlen(nameBuffer) + 1];
            my_strcpy(m_name, nameBuffer);


            int ohip;
            if (!(istr >> ohip)) {
                clear();
                return istr;
            }
            if (ohip < 100000000 || ohip > 999999999) {
                std::cerr << "Invalid OHIP number: " << ohip << std::endl;
                clear();
                return istr;
            }

            m_OHIP = ohip;

            int ticketNumber;
            char comma;
            istr >> comma >> ticketNumber >> comma;
            m_ticket.setNumber(ticketNumber);

            char colon;
            int hours, mins;
            istr >> hours >> colon >> mins;
            Time ticketTime(hours * 60 + mins);
            m_ticket.setTime(ticketTime);
        }

        return istr;
    }
}