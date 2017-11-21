#include "BusinessClient.h"

std::string BusinessClient::ToStringSpecific() const
{
	std::string retString;
	retString += "Client Type:\tBusiness Client\n";
	retString += "Max credit:\t" + std::to_string(this->availableCredit) + "\n";
	return retString;
}

BusinessClient::BusinessClient(const std::string & organisationNumber, int maximumCredit, const std::string & name, const std::string & address, const std::string & email, const std::string & phoneNumber)
	: Client(organisationNumber, name, address, email, phoneNumber)
{
	this->availableCredit = maximumCredit;
}

BusinessClient::BusinessClient(const BusinessClient& other) : Client(other)
{
	this->availableCredit = other.availableCredit;
}

BusinessClient& BusinessClient::operator=(const BusinessClient& other)
{
	Client::operator=(other);
	this->availableCredit = other.availableCredit;
	return *this;
}

BusinessClient::~BusinessClient()
{
	//Tom...
}
//Företagskunder har möjlighet att handla på kredit
bool BusinessClient::MakePurchase(int amount)
{
	bool canBuy = false;
	if (GetBalance() - amount > -availableCredit)
	{
		canBuy = true;
		ChangeBalance(-amount);
	}
	return canBuy;
}

