/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_

#include "IOAble.h"
#include <iostream>
#include "Time.h"

namespace seneca {
    class Ticket : public IOAble {
        Time m_time;
        int m_number;
    public:
        void setNumber(int number) {
            m_number = number;
        }
        Ticket(int number);

        void setTime(Time time) {
            m_time = time;
        }

        Time time()const;
        int number()const;
        void resetTime();
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
}
#endif // !SENECA_TICKET_H_
