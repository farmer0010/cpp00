#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook   phonebook;
    std::string command;

    while (true)
    {
        std::cout << "\nEnter a command (ADD, SEARCH, EXIT): ";

        if (!std::getline(std::cin, command))
        {
            break;
        }

        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContacts();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }

    std::cout << "\nPhonebook closed." << std::endl;
    return 0;
}
