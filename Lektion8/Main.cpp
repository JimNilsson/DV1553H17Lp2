#include "ClientRegister.h"
#include <iostream>


int main(int argc, char** argv)
{
	Client* business = new BusinessClient("552343-4423", 1000, "Karlskrona Blommor", "Grengatan 6 371 44 Karlskrona", "kontakt@karlksronablommor.se", "076-12345678");
	Client* priv = new PrivateClient("19900114-1234", "Karl Olsson", "Gunggatan 5, 32245 Oslo NORGE", "karlolsson@norge.no", "070-123123123");

	std::cout << "Trying to make a purchase of 1200 kr...\n";
	if (!priv->MakePurchase(1200))
	{
		std::cout << "The customer cant afford that.\n";
		std::cout << priv->GetName() << " only has " << priv->GetBalance() << "kr in his/her account\n\n";
	}
	std::cin.get();

	std::cout << "Adding 2200 kr to account.\n";
	priv->ChangeBalance(2200);
	if (priv->MakePurchase(1200))
	{
		std::cout << "The purchase was made.\n";
		std::cout << priv->GetName() << " now has a balance of: " << priv->GetBalance() << " kr\n\n";
	}
	std::cin.get();

	std::cout << "Printing information about client.\n";
	std::cout << priv->ToString();
	std::cin.get();

	std::cout << "The company " << business->GetName() << " wants to make a purchase of 900kr...\n";
	std::cout << "The company has a balance of " << business->GetBalance() << "kr.\n";
	if (business->MakePurchase(900))
	{
		std::cout << business->GetName() << " made a purchase of 900kr and now has a balance of " << business->GetBalance() << "kr.\n";
	}
	std::cin.get();
	std::cout << "Printing information about client.\n";
	std::cout << business->ToString();
	std::cin.get();

	delete business;
	delete priv;

	std::cin.get();
	return 0;
}
