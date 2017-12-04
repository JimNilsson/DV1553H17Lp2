#include "ClientRegister.h"

ClientRegister::ClientRegister(int initialCapacity)
{
	this->nrOfClients = 0;
	this->capacity = initialCapacity;
	this->clients = new Client*[this->capacity];
}

ClientRegister::~ClientRegister()
{
	ClearMemory();
}

ClientRegister::ClientRegister(const ClientRegister & other)
{
	MakeCopy(other);
}

ClientRegister & ClientRegister::operator=(const ClientRegister & other)
{
	if (this != &other)
	{
		ClearMemory();
		MakeCopy(other);
	}
	return *this;
}

bool ClientRegister::AddClient(const std::string & organisationNumber, int maximumCredit, const std::string & name, const std::string & address, const std::string & email, const std::string & phoneNumber)
{
	bool added = false;
	BusinessClient toAdd(organisationNumber, maximumCredit, name, address, email, phoneNumber);
	if (Find(toAdd) == -1)
	{
		if (nrOfClients == capacity)
			Expand();
		clients[nrOfClients++] = new BusinessClient(toAdd);
		added = true;
	}
	return added;

}

bool ClientRegister::AddClient(const std::string & socialSecurityNumber, const std::string & name, const std::string & address, const std::string & email, const std::string & phoneNumber)
{
	//Att g�ra.
	return false;
}

bool ClientRegister::RemoveClient(const std::string & identificationNumber)
{
	//Att g�ra.
	return false;
}

bool ClientRegister::RegisterPurchase(const std::string & identificationNumber, int amount)
{
	//Att g�ra...
	return false;
}

bool ClientRegister::AllClientsAsStrings(std::string * stringArr, int capOfStringArr) const
{
	if (capOfStringArr >= nrOfClients)
	{
		for (int i = 0; i < nrOfClients; i++)
		{
			stringArr[i] = clients[i]->ToString();
		}
	}
	return capOfStringArr >= nrOfClients;
}

bool ClientRegister::AllPrivateClientsAsStrings(std::string * stringArr, int capOfStringArr) const
{
	int index = 0;
	bool retVal = false;
	if (capOfStringArr >= GetNrOfPrivateClients())
	{
		retVal = true;
		for (int i = 0; i < nrOfClients; i++)
		{
			if (dynamic_cast<PrivateClient*>(clients[i]) != nullptr)
				stringArr[index++] = clients[i]->ToString();
		}
	}
	return retVal;
}

bool ClientRegister::AllBusinessClientsAsStrings(std::string * stringArr, int capOfStringArr) const
{
	//Att g�ra.
	return false;
}

int ClientRegister::GetNrOfClients() const
{
	return nrOfClients;
}

int ClientRegister::GetNrOfPrivateClients() const
{
	int counter = 0;
	for (int i = 0; i < nrOfClients; i++)
	{
		if (dynamic_cast<PrivateClient*>(clients[i]) != nullptr)
			++counter;
	}
	return counter;
}

int ClientRegister::GetNrOfBusinessClients() const
{
	int counter = 0;
	for (int i = 0; i < nrOfClients; i++)
	{
		if (typeid(BusinessClient) == typeid(*clients[i]))
			++counter;
	}
	return 0;
}

bool ClientRegister::RedeemBonusPoints(const std::string & idNumber)
{
	int index = -1;
	bool retVal = false;
	for (int i = 0; i < nrOfClients; i++)
	{
		if (*clients[i] == idNumber)
		{
			index = i;
			i = nrOfClients;
		}
	}
	if (index != -1)
	{
		PrivateClient* temp = dynamic_cast<PrivateClient*>(clients[index]);
		if (temp != nullptr)
		{
			temp->RedeemBonusPoints();
			retVal = true;
		}
	}
	return retVal;
}

int ClientRegister::Find(const Client & client) const
{
	int index = -1;
	for (int i = 0; i < nrOfClients; i++)
	{
		//OBS! Notera avreferering av clients[i] ty clients[i] �r av typen Client*, d.v.s. Client-pekare
		//Vi kan inte j�mf�re en Client med en Client-pekare, d�rf�r m�ste vi avreferera clients[i] f�r att
		//f� en j�mf�relse p� formen "Client == Client" och inte "Client == Client*".
		if (client == *clients[i])
		{
			index = i;
			i = nrOfClients; //Avbryt loopen.
		}
	}
	return index;
}

void ClientRegister::Expand()
{
	//Expandering blir likadan, oavsett om det �r en arvshierarki eller inte.
	this->capacity += 5;
	Client** temp = new Client*[this->capacity];
	for (int i = 0; i < nrOfClients; i++)
	{
		//Ytkopierar pekarna �ver till den nya st�rre arrayen.
		//Ty h�r beh�ver vi inte djupkopiera d� den gamla arrayen �nd� "f�rsvinner"
		//D.v.s. vi kommer inte ha n�gra "dangling pointers"
		temp[i] = clients[i];
	}
	delete[] clients; //Avallokera gammal array.
	clients = temp; //L�t medlemsvariabeln clients peka p� den nya st�rre arrayen ist�llet.
}

void ClientRegister::MakeCopy(const ClientRegister & other)
{
	this->nrOfClients = other.nrOfClients;
	this->capacity = other.capacity;
	this->clients = new Client*[this->capacity];
	for (int i = 0; i < this->nrOfClients; i++)
	{
		BusinessClient* temp = dynamic_cast<BusinessClient*>(other.clients[i]);
		if (temp != nullptr) //other.clients[i] pekar p� en businessClient
		{
			//this->clients[i] = new BusinessClient(*temp);
			this->clients[i] = new BusinessClient(*(BusinessClient*)other.clients[i]);
		}
		else
		{
			this->clients[i] = new PrivateClient(*(PrivateClient*)other.clients[i]);
		}
	}
}

void ClientRegister::ClearMemory()
{
	//Avallokera varje _enskilt objekt_
	for (int i = 0; i < nrOfClients; i++)
	{
		delete clients[i];
	}
	//Avallokera _arrayen av pekare_
	delete[] clients;
}
