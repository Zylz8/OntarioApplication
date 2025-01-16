/*
Name: Jackey Zhou
Student ID: 164431223
Email: jzhou200@myseneca.ca
Section: NBB

Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#include "Menu.h"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

namespace seneca {

    // Custom string copy function
    void copyString(const char* source, char* destination) {
        while (*source != '\0') {
            *destination = *source;
            ++source;
            ++destination;
        }
        *destination = '\0';
    }

    Menu::Menu(const char* menuContent, int numberOfTabs)
        : m_text(new char[strlen(menuContent) + 1]), m_numOptions(0), m_numTabs(numberOfTabs) {
        copyString(menuContent, m_text);

        const char* p = m_text;
        while (*p != '\0') {
            if (*p == '\n') {
                ++m_numOptions;
            }
            ++p;
        }
    }

    Menu::~Menu() {
        delete[] m_text;
    }

    void Menu::display() {
        string indentation(m_numTabs * 3, ' ');

        const char* p = m_text;
        while (*p != '\0') {
            const char* lineStart = p;
            while (*p != '\n' && *p != '\0') {
                ++p;
            }
            cout << indentation;
            for (const char* c = lineStart; c != p; ++c) {
                cout << *c;
            }
            cout << std::endl;
            if (*p == '\n') {
                ++p;
            }
        }

        cout << indentation << "0- Exit\n" << indentation << "> ";
    }

    int& Menu::operator>>(int& Selection) {
        bool badIntegerPrinted = false;
        display();

        while (true) {
            string input;
            getline(cin, input);

            bool valid = true;
            for (size_t i = 0; i < input.size(); ++i) {
                char c = input[i];
                if (!isdigit(c) && !(c == '-' && i == 0 && input.find('-', i + 1) == string::npos)) { // Use string::npos because its the biggest number in the element size_t
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                if (!badIntegerPrinted) {
                    cout << "Bad integer value, try again: ";
                    badIntegerPrinted = true;
                }
                else {
                    cout << "Only enter an integer, try again: ";
                }
                continue;
            }

            int value = stoi(input);

            if (value < 0 || value > m_numOptions) {
                cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
                continue;
            }

            Selection = value;

            return Selection;
        }
    }
}