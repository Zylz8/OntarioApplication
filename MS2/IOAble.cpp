/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#include "IOAble.h"

namespace seneca {
    std::ostream& operator<<(std::ostream& ostr, const IOAble& obj) {
        return obj.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& obj) {
        return obj.read(istr);
    }
}
