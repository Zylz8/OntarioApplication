/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#include <iostream>

namespace seneca {
    class IOAble {
    public:
        virtual std::ostream& write(std::ostream& ostr) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual ~IOAble() {}
    };

    std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
    std::istream& operator>>(std::istream& istr, IOAble& obj);
}

#endif 
