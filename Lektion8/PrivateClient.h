#ifndef _PRIVATE_CLIENT_H
#define _PRIVATE_CLIENT_H
#include "Client.h"

class PrivateClient : public Client
{
private:
	int bonusPoints;
	std::string ToStringSpecific() const;
public:
	PrivateClient(const std::string& socialSecurityNumber, const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber);
	PrivateClient(const PrivateClient& other);
	PrivateClient& operator=(const PrivateClient& other);
	~PrivateClient();

	bool MakePurchase(int amount);
	void RedeemBonusPoints();
	
	
};



#endif

