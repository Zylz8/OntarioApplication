
/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H

#include "Ticket.h"
#include "IOAble.h"

namespace seneca {

    class Patient : public IOAble {
    private:
        char* m_name; // Dynamically allocated C-string to store patient's name
        int m_OHIP;   // Patient's OHIP number
        Ticket m_ticket; // Patient's ticket object for queue management

        // Helper functions for deep copying and memory cleanup
        void copyFrom(const Patient& other);
        void clear();

    public:
        // Constructors and destructor
        Patient(int ticketNumber = 0);
        Patient(const Patient& other);
        Patient& operator=(const Patient& other);
        ~Patient();

        // Abstract method to return type of patient
        virtual char type() const = 0;

        // Overloaded comparison operators
        bool operator==(char c) const;
        bool operator==(const Patient& other) const;

        // Method to set arrival time of patient
        void setArrivalTime();

        // Methods to retrieve patient information
        Time time() const;
        int number() const;

        // Cast operators
        operator bool() const;               // Cast to boolean
        operator const char* () const;       // Cast to const char*

        // Input/output functions
        std::ostream& write(std::ostream& ostr) const override;
        std::istream& read(std::istream& istr) override;
    };

}

#endif // !SENECA_PATIENT_H