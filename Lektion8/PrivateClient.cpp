#include "PrivateClient.h"

PrivateClient::PrivateClient(const std::string & socialSecurityNumber, const std::string & name, const std::string & address, const std::string & email, const std::string & phoneNumber) : Client(socialSecurityNumber, name, address, email, phoneNumber)
{
	this->bonusPoints = 0;
}

PrivateClient::PrivateClient(const PrivateClient & other) : Client(other)
{
	this->bonusPoints = other.bonusPoints;
}

PrivateClient & PrivateClient::operator=(const PrivateClient & other)
{
	Client::operator=(other);
	this->bonusPoints = other.bonusPoints;
	return *this;
}

PrivateClient::~PrivateClient()
{
	//Tom...
}

bool PrivateClient::MakePurchase(int amount)
{
	bool canBuy = false;
	if (amount <= GetBalance())
	{
		canBuy = true;
		ChangeBalance(-amount);
		//Privatkunder får bonuspoäng för varje 500 kr de handlar för.
		bonusPoints += amount / 500;
	}
	return canBuy;
}

void PrivateClient::RedeemBonusPoints()
{
	//Privatkunder kan förvandla sina bonuspoäng till saldo
	//50 kr per poäng.
	ChangeBalance(bonusPoints * 50);
	this->bonusPoints = 0;
}

std::string PrivateClient::ToStringSpecific() const
{
	std::string retString;
	retString += "Client type:\tPrivate client.\n";
	retString += "Bonus pts.:\t" + std::to_string(bonusPoints) + "\n";
	return retString;
}
