#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
private:
	std::string identificationNumber;
	std::string name;
	std::string address;
	std::string email;
	std::string phoneNumber;
	int balance;
	virtual std::string ToStringSpecific() const = 0; //Subklasserna implementerar denna, men inte basklassen.
public:
	Client(const std::string& identificationNumber, const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber);
	virtual ~Client();

	//Cctor och operator= i arvshierarki.
	Client(const Client& other);
	Client& operator=(const Client& other);

	//Vi kan j�mf�ra mot ett annat objekt
	bool operator==(const Client& other) const;
	//Eller mot n�got annat, i detta fall en str�ng
	bool operator==(const std::string& identificationNumber) const;

	virtual bool MakePurchase(int amount) = 0;
	void ChangeBalance(int amount);


	std::string GetIdentificationNumber() const;
	std::string GetContactInformation() const;
	std::string ToString() const; //Endast basklassen implementerar denna
	int GetBalance() const;
	std::string GetName() const;

	//F�r att slippa dynamic_cast/typeid i cctor/op= f�r containerklass.
	//virtual Client* Clone() const = 0;
	

};


#endif
