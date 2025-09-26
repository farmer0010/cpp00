#include "Contact.hpp"

void Contact::setContact(std::string first, std::string last, std::string nick, std::string phonenum, std::string dark)
{
	this->firstname = first;
	this->lastname = last;
	this->nickname = nick;
	this->phonenumber = phonenum;
	this->darkestSecret = dark;
}

std::string Contact::GetFirstName() const{
	return this->firstname;
}

std::string Contact::GetLastName() const{
	return this->lastname;
}

std::string Contact::GetNickName() const{
	return this->nickname;
}

std::string Contact::GetPhoneNumber() const{
	return this->phonenumber;
}

std::string Contact::GetDarkestSecret() const{
	return this->darkestSecret;
}
