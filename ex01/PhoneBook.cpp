#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() {
    this->contact_count = 0;
    this->oldest_idx = 0;
}

void PhoneBook::addContact() {
    std::string first, last, nick, phone, secret;

    std::cout << "Enter your first name: ";
    std::getline(std::cin, first);
    std::cout << "Enter your last name: ";
    std::getline(std::cin, last);
    std::cout << "Enter your nickname: ";
    std::getline(std::cin, nick);
    std::cout << "Enter your PhoneNumber: ";
    std::getline(std::cin, phone);
    std::cout << "Enter your darkest Secret: ";
    std::getline(std::cin, secret);

    this->contacts[this->oldest_idx].setContact(first, last, nick, phone, secret);
    this->oldest_idx = (this->oldest_idx + 1) % 8;

    if (this->contact_count < 8) {
        this->contact_count++;
    }
    std::cout << "\n---- Contact successfully added! ----\n" << std::endl;
}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;

    for (int i = 0; i < this->contact_count; i++) {
        std::cout << std::setw(10) << i << "|";

        std::string firstName = this->contacts[i].GetFirstName();
        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        std::cout << std::setw(10) << firstName << "|";

        std::string lastName = this->contacts[i].GetLastName();
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        std::cout << std::setw(10) << lastName << "|";

        std::string nickName = this->contacts[i].GetNickName();
        if (nickName.length() > 10)
            nickName = nickName.substr(0, 9) + ".";
        std::cout << std::setw(10) << nickName << std::endl;
    }

    if (this->contact_count == 0) {
        std::cout << "\n>> Phonebook is empty. <<\n" << std::endl;
        return;
    }

    std::string index_str;
    int         index_num;

    while (true) {
        std::cout << "\nEnter the index of the contact to display: ";
        if (!std::getline(std::cin, index_str)) {
            std::cout << "\nInput stream closed. Returning to main menu." << std::endl;
            return;
        }

        if (index_str.empty()) {
            continue;
        }

        std::stringstream ss(index_str);
        if (ss >> index_num && index_num >= 0 && index_num < this->contact_count) {
            break;
        } else {
            std::cout << "Error: Invalid index. Please try again." << std::endl;
        }
    }

    std::cout << "\n--- Contact Details (Index: " << index_num << ") ---" << std::endl;
    std::cout << "First Name:     " << this->contacts[index_num].GetFirstName() << std::endl;
    std::cout << "Last Name:      " << this->contacts[index_num].GetLastName() << std::endl;
    std::cout << "Nickname:       " << this->contacts[index_num].GetNickName() << std::endl;
    std::cout << "Phone Number:   " << this->contacts[index_num].GetPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index_num].GetDarkestSecret() << std::endl;
    std::cout << "-------------------------------------\n" << std::endl;
}
