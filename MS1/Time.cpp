/***********************************************************************
// OOP244 Project ms1
//
// File  time.cpp
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

#include "Time.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>
using namespace std;

namespace seneca {

    Time& Time::reset() {
        if (debug) {
            minutes = U.getTime();
         }
         else {
             minutes = U.getTime();
         }
         return *this;
    }

    void Time::write(std::ostream& os) const {
        unsigned int hours = minutes / 60;
        unsigned int mins = minutes % 60;
        os << (hours < 10 ? "0" : "") << hours << ":" << (mins < 10 ? "0" : "") << mins;
    }


    void Time::read(std::istream& istr) {
        unsigned int hours, mins;
        char colon;

        istr >> hours;

        if (istr.fail()) {
            istr.clear(std::ios::failbit);
            istr.setstate(std::ios::failbit);
            return;
        }
        // fallbit if hours is equal to 12
        if (hours == 12) {
            istr.setstate(std::ios::failbit);
            return;
        }

        istr.get(colon);

        if (istr.fail() || colon != ':') {
            istr.setstate(std::ios::failbit);
            return;
        }

        istr >> mins;

        minutes = hours * 60 + mins;
    }



    Time::operator unsigned int() const {
        return minutes;
    }

    Time& Time::operator*=(int val) {
        minutes *= val;
        return *this;
    }

    Time& Time::operator-=(const Time& D) {
        unsigned int totalMinutes = minutes + 1440;
        totalMinutes -= D.minutes;
        minutes = totalMinutes % 1440;
        return *this;
    }

    Time Time::operator-(const Time& T) const {
        Time result(*this);
        result -= T;
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Time& T) {
        T.write(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Time& T) {
        T.read(is);
        return is;
    }
}

