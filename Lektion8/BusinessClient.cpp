#include "BusinessClient.h"

std::string BusinessClient::ToStringSpecific() const
{
	//Att g�ra.
	return std::string();
}

BusinessClient::BusinessClient(const std::string & organisationNumber, int maximumCredit, const std::string & name, const std::string & address, const std::string & email, const std::string & phoneNumber) : Client(organisationNumber, name, address, email, phoneNumber)
{
	this->availableCredit = maximumCredit;
}

BusinessClient::~BusinessClient()
{
	//Tom...
}
//F�retagskunder har m�jlighet att handla p� kredit
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

