/****************************************************************************************
 * Copyright: VolcanicWinterStudios
 * Name: Guy Lapensee
 * Script: main.cpp
 * Date: October 11th, 2024
 * Description: Holds all the variables and functions for merchant inventory
 * TODO: Create a merchant inventory where a player can buy and sell items
 * Known Bugs: *known problems with script*
 ****************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int itemPrice = 0;
char response = ' ';
bool soldOut = false;
int playerWallet = 200;
int merchantWallet = 300;

string itemName = "";
string playerName = "";
string& GetItem(vector<string>& inventoryVector, int itemPosition);
vector<string> playerInventory;
vector<string> merchantInventory;
vector<string>::iterator myIterator;
vector<string>::const_iterator iter;

void ShopMenu();
void DisplayWallets();
void GetPlayerInventory();
void GetMerchantInventory();
int PlayerInput(int high, int low);

int main()
{
	playerInventory.push_back("sword = $150");
	merchantInventory.push_back("dagger = $50");
	merchantInventory.push_back("dagger = $50");
	merchantInventory.push_back("dagger = $50");
	merchantInventory.push_back("sword = $200");
	merchantInventory.push_back("helmet = $150");


	cout << "Hello stranger, welcome to my shop!\n" << endl;
	cout << "What is your name?\n" << endl;
	cin >> playerName;
	
	cout << "\nNice to meet you " << playerName << "\n" << endl;

	do
	{
		DisplayWallets();
		ShopMenu();

		if (response == 'b')
		{
			GetMerchantInventory();

			switch (PlayerInput(5, 1))
			{
			case 1:
				itemPrice = 50;
				GetItem(merchantInventory, 0);
				if (GetItem(merchantInventory, 0) == "Sold Out")
				{
					cout << "\nSorry sold out\n" << endl;
				}
				if (playerWallet < itemPrice)
				{
					cout << "\nInsufficient funds\n" << endl;
				}
				if (playerWallet >= itemPrice)
				{
					cout << "You purchased a dagger\n" << endl;
					merchantInventory.erase(merchantInventory.begin());
					merchantInventory.insert(merchantInventory.begin(), "Sold Out");
					playerWallet -= itemPrice;
					merchantWallet += itemPrice;
					playerInventory.push_back("dagger = $ 30");
				}
				break;
			case 2:
				itemPrice = 50;
				GetItem(merchantInventory, 1);
				if (GetItem(merchantInventory, 1) == "Sold Out")
				{
					cout << "\nSorry sold out\n" << endl;
				}
				if (playerWallet < itemPrice)
				{
					cout << "\nInsufficient funds\n" << endl;
				}
				if (playerWallet >= itemPrice)
				{
					cout << "You purchased a dagger\n" << endl;
					merchantInventory.erase(merchantInventory.begin() + 1);
					merchantInventory.insert(merchantInventory.begin() + 1, "Sold Out");
					playerWallet -= itemPrice;
					merchantWallet += itemPrice;
					playerInventory.push_back("dagger = $ 30");					
				}
				break;
			case 3:
				itemPrice = 50;
				GetItem(merchantInventory, 2);
				if (GetItem(merchantInventory, 2) == "Sold Out")
				{
					cout << "\nSorry sold out\n" << endl;
				}
				if (playerWallet < itemPrice)
				{
					cout << "\nInsufficient funds\n" << endl;
				}
				if (playerWallet >= itemPrice)
				{
					cout << "You purchased a dagger\n" << endl;
					merchantInventory.erase(merchantInventory.begin() + 2);
					merchantInventory.insert(merchantInventory.begin() + 2, "Sold Out");
					playerWallet -= itemPrice;
					merchantWallet += itemPrice;
					playerInventory.push_back("dagger = $ 30");
				}
				break;
			case 4:
				itemPrice = 200;
				GetItem(merchantInventory, 3);
				if (GetItem(merchantInventory, 3) == "Sold Out")
				{
					cout << "\nSorry sold out\n" << endl;
				}
				if (playerWallet < itemPrice)
				{
					cout << "\nInsufficient funds\n" << endl;
				}
				if (playerWallet >= itemPrice)
				{
					cout << "You purchased a sword\n" << endl;
					merchantInventory.erase(merchantInventory.begin() + 3);
					merchantInventory.insert(merchantInventory.begin() + 3, "Sold Out");
					playerWallet -= itemPrice;
					merchantWallet += itemPrice;
					playerInventory.push_back("sword = $ 160");
				}
				break;
			case 5:
				itemPrice = 150;
				GetItem(merchantInventory, 4);
				if (GetItem(merchantInventory, 4) == "Sold Out")
				{
					cout << "\nSorry sold out\n" << endl;
				}
				if (playerWallet < itemPrice)
				{
					cout << "\nInsufficient funds\n" << endl;
				}
				if (playerWallet >= itemPrice)
				{
					cout << "You purchased a helmet\n" << endl;
					merchantInventory.erase(merchantInventory.begin() + 3);
					merchantInventory.insert(merchantInventory.begin() + 3, "Sold Out");
					playerWallet -= itemPrice;
					merchantWallet += itemPrice;
					playerInventory.push_back("helmet = $ 100");
				}
				break;
			default:
				cout << "\nInvalid number, Please try again\n" << endl;
			}
		}

		if (response == 's')
		{
			GetPlayerInventory();

			for (int i = 0; i < playerInventory.size(); ++i)
			{

			}

			/*switch (PlayerInput(5, 1))
			{
			case 1:
				itemPrice = 150;
				break;
			case 2:

				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				cout << "\nInvalid number, Please try again\n" << endl;
			}*/
		}
	} while (response != 'l');
}

void GetMerchantInventory()
{
	cout << "\nThese are the items I have for sale\n" << endl;

	for (iter = merchantInventory.begin(); iter != merchantInventory.end(); ++iter)
	{
		cout << *iter << endl;
	}
}

int PlayerInput(int high, int low)
{
	int number;
	do
	{
		cout << "\nSelect an item from: \n" << low << " - " << high << endl;
		cin >> number;
	} while (number > high || number < low);

	return number;
}

string& GetItem(vector<string>& inventoryVector, int itemPosition)
{
	return inventoryVector[itemPosition];
}

void ShopMenu()
{
	cout << "\nWhat can I do for you today?\n " << endl;
	cout << "[b]uy [s]ell [l]eave\n" << endl;
	cin >> response;	
}

void DisplayWallets()
{
	cout << "Merchant wallet: $" << merchantWallet << endl;
	cout << "Player wallet: $" << playerWallet << "\n" << endl;
}

void GetPlayerInventory()
{
	cout << "\nThese are your current items: \n" << endl;

	for (iter = playerInventory.begin(); iter != playerInventory.end(); ++iter)
	{
		cout << *iter << endl;
	}
}

