/***********************************************************************
// OOP244 Project ms1
//
// File  time.h
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name    Jackey Zhou             Date    March 12, 2024        Reason
***********************************************************************/

/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include <iostream>

namespace seneca {
    class Time {
    private:
        unsigned int minutes;

    public:
        Time() : minutes(0) {}
        Time(unsigned int min) : minutes(min) {}
        Time& reset();
        void write(std::ostream& os) const;
        void read(std::istream& istr);
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;

        friend std::ostream& operator<<(std::ostream&, const Time&);
        friend std::istream& operator>>(std::istream&, Time&);
    };
}

#endif 
