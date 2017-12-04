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
	//Att göra.
	return false;
}

bool ClientRegister::RemoveClient(const std::string & identificationNumber)
{
	//Att göra.
	return false;
}

bool ClientRegister::RegisterPurchase(const std::string & identificationNumber, int amount)
{
	//Att göra...
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
	//Att göra.
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
		//OBS! Notera avreferering av clients[i] ty clients[i] är av typen Client*, d.v.s. Client-pekare
		//Vi kan inte jämföre en Client med en Client-pekare, därför måste vi avreferera clients[i] för att
		//få en jämförelse på formen "Client == Client" och inte "Client == Client*".
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
	//Expandering blir likadan, oavsett om det är en arvshierarki eller inte.
	this->capacity += 5;
	Client** temp = new Client*[this->capacity];
	for (int i = 0; i < nrOfClients; i++)
	{
		//Ytkopierar pekarna över till den nya större arrayen.
		//Ty här behöver vi inte djupkopiera då den gamla arrayen ändå "försvinner"
		//D.v.s. vi kommer inte ha några "dangling pointers"
		temp[i] = clients[i];
	}
	delete[] clients; //Avallokera gammal array.
	clients = temp; //Låt medlemsvariabeln clients peka på den nya större arrayen istället.
}

void ClientRegister::MakeCopy(const ClientRegister & other)
{
	this->nrOfClients = other.nrOfClients;
	this->capacity = other.capacity;
	this->clients = new Client*[this->capacity];
	for (int i = 0; i < this->nrOfClients; i++)
	{
		BusinessClient* temp = dynamic_cast<BusinessClient*>(other.clients[i]);
		if (temp != nullptr) //other.clients[i] pekar på en businessClient
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
