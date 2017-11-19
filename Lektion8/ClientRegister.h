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

	//Tv� �verlagrade funktioner AddClient.

	/*L�gger till en f�retagskund.
	* Returnerar true om det gick att l�gga in
	* Retunerar false om kunden redan fanns.
	*/
	bool AddClient(const std::string& organisationNumber, int maximumCredit, const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber);
	
	/*L�gger till en privatkund
	* Returnerar true om det gick att l�gga in
	* Retunerar false om kunden redan fanns.
	*/
	bool AddClient(const std::string& socialSecurityNumber, const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber);

	/* Tar bort en kund, kan antingen vara en privatkund eller f�retagskund.
	 * Returnerar false om kunden inte hittades.
	 * Returnerar true om kunden hittades och togs bort.
	*/
	bool RemoveClient(const std::string& identificationNumber);

	/* Registrerar ett k�p f�r en kund.
	* Returnerar false om kunden inte hittades.
	* Returnerar false om k�pet inte gick igenom
	* Returnerar true om k�pet registrerades
	*/
	bool RegisterPurchase(const std::string& identificationNumber, int amount);

	/* Fyller arrayen stringArr med returv�rdena fr�n anrop till Client::ToString f�r varje kund.
	 * Returnerar true om stringArr's kapacitet var tillr�ckligt stor f�r att h�lla alla str�ngar
	 * som ska l�ggas in. Annars returneras false.
	*/
	bool AllClientsAsStrings(std::string* stringArr, int capOfStringArr) const;
	bool AllPrivateClientsAsStrings(std::string* stringArr, int capOfStringArr) const;
	bool AllBusinessClientsAsStrings(std::string* stringArr, int capOfStringArr) const;

	/*Returnerar antalet inlagda kunder/privatkunder/f�retagskunder
	*/
	int GetNrOfClients() const;
	int GetNrOfPrivateClients() const;
	int GetNrOfBusinessClients() const;

private:
	//Privata hj�lpfunktioner
	/*Letar igenom arrayen clients.
	* Returnerar indexed f�r kunden i arrayen om kunden hittades
	* Returnerar -1 om kunden inte hittades
	*/
	int Find(const Client& client) const;
	void Expand();
	void MakeCopy(const ClientRegister& other);
	void ClearMemory();

};

#endif
