/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H

namespace seneca {

    class Menu {
    private:
        char* const m_text;
        int m_numOptions;
        int m_numTabs;

    public:
        Menu(const char* menuContent, int numberOfTabs = 0);
        ~Menu();

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        void display();
        int& operator>>(int& Selection);

    };
}

#endif