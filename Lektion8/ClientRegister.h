#ifndef CLIENT_REGISTER_H
#define CLIENT_REGISTER_H

#include "BusinessClient.h"
#include "PrivateClient.h"

class ClientRegister
{
private:
	Client** clients;
	int capacity;
	int nrOfClients;
public:
	ClientRegister(int initialCapacity = 2);
	~ClientRegister();
	ClientRegister(const ClientRegister& other);
	ClientRegister& operator=(const ClientRegister& other);

	//Två överlagrade funktioner AddClient.

	/*Lägger till en företagskund.
	* Returnerar true om det gick att lägga in
	* Retunerar false om kunden redan fanns.
	*/
	bool AddClient(const std::string& organisationNumber, int maximumCredit, const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber);
	
	/*Lägger till en privatkund
	* Returnerar true om det gick att lägga in
	* Retunerar false om kunden redan fanns.
	*/
	bool AddClient(const std::string& socialSecurityNumber, const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber);

	/* Tar bort en kund, kan antingen vara en privatkund eller företagskund.
	 * Returnerar false om kunden inte hittades.
	 * Returnerar true om kunden hittades och togs bort.
	*/
	bool RemoveClient(const std::string& identificationNumber);

	/* Registrerar ett köp för en kund.
	* Returnerar false om kunden inte hittades.
	* Returnerar false om köpet inte gick igenom
	* Returnerar true om köpet registrerades
	*/
	bool RegisterPurchase(const std::string& identificationNumber, int amount);

	/* Fyller arrayen stringArr med returvärdena från anrop till Client::ToString för varje kund.
	 * Returnerar true om stringArr's kapacitet var tillräckligt stor för att hålla alla strängar
	 * som ska läggas in. Annars returneras false.
	*/
	bool AllClientsAsStrings(std::string* stringArr, int capOfStringArr) const;
	bool AllPrivateClientsAsStrings(std::string* stringArr, int capOfStringArr) const;
	bool AllBusinessClientsAsStrings(std::string* stringArr, int capOfStringArr) const;

	/*Returnerar antalet inlagda kunder/privatkunder/företagskunder
	*/
	int GetNrOfClients() const;
	int GetNrOfPrivateClients() const;
	int GetNrOfBusinessClients() const;

private:
	//Privata hjälpfunktioner
	/*Letar igenom arrayen clients.
	* Returnerar indexed för kunden i arrayen om kunden hittades
	* Returnerar -1 om kunden inte hittades
	*/
	int Find(const Client& client) const;
	void Expand();
	void MakeCopy(const ClientRegister& other);
	void ClearMemory();

};

#endif
