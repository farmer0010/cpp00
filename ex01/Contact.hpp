#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
	private:
		std::string firstname;
		std::string lastname;
		std::string	nickname;
		std::string phonenumber;
		std::string darkestSecret;
	public:
		void setContact(std::string first, std::string last, std::string nick, std::string phonenum, std::string dark);
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickName() const;
		std::string GetPhoneNumber() const;
		std::string GetDarkestSecret() const;

};

#endif
