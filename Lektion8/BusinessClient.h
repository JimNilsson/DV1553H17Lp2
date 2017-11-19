#ifndef BUSINESS_CLIENT_H
#define BUSINESS_CLIENT_H

#include "Client.h"

class BusinessClient : public Client
{
private:
	int availableCredit;

	std::string ToStringSpecific() const;
public:
	BusinessClient(const std::string& organisationNumber, int availableCredit, const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber);
	~BusinessClient();

	//Att implementera
	//BusinessClient(const BusinessClient& other);
	//BusinessClient& operator=(const BusinessClient& other);
	bool MakePurchase(int amount);

};


#endif
