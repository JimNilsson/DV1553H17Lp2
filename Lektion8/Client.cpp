#include "Client.h"
#include <sstream> //stringstream


Client::Client(const std::string & identificationNumber, const std::string & name, const std::string & address, const std::string & email, const std::string & phoneNumber)
{
	this->identificationNumber = identificationNumber;
	this->name = name;
	this->address = address;
	this->email = email;
	this->phoneNumber = phoneNumber;
	this->balance = 0;
}

Client::~Client()
{
	//Tom... Vi har ju inga pekare till dynamiskt allokerat minne i denna klass.
}

Client::Client(const Client & other)
{
	this->identificationNumber = other.identificationNumber;
	this->name = other.name;
	this->address = other.address;
	this->email = other.email;
	this->phoneNumber = other.phoneNumber;
	this->balance = other.balance;
}

Client & Client::operator=(const Client & other)
{
	this->identificationNumber = other.identificationNumber;
	this->name = other.name;
	this->address = other.address;
	this->email = other.email;
	this->phoneNumber = other.phoneNumber;
	this->balance = other.balance;
	return *this;
}

bool Client::operator==(const Client & other) const
{
	return this->identificationNumber == other.identificationNumber;
}

bool Client::operator==(const std::string & identificationNumber) const
{
	return this->identificationNumber == identificationNumber;
}

void Client::ChangeBalance(int amount)
{
	this->balance += amount;
}


std::string Client::GetIdentificationNumber() const
{
	return identificationNumber;
}

std::string Client::GetContactInformation() const
{
	std::string retString;
	retString += "Name:\t\t" + name + "\n";
	retString += "Address:\t" + address + "\n";
	retString += "Email:\t\t" + email + "\n";
	retString += "Phone Nr:\t" + phoneNumber + "\n";

	return retString;
}

std::string Client::ToString() const
{
	std::stringstream ss;
	ss << ToStringSpecific(); //Här anropar vi en ÖVERSKUGGAD medlemsfunktion. 
	ss << "Balance:\t" << balance << "\n";
	ss << GetContactInformation() << "\n";
	
	return ss.str();
}

int Client::GetBalance() const
{
	return balance;
}

std::string Client::GetName() const
{
	return name;
}
