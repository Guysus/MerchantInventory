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


	cout << "Hello stranger, welcome to my shop!" << endl;
	cout << "What is your name?" << endl;
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
				if (playerWallet >= itemPrice && !soldOut)
				{
					cout << "You purchased a dagger" << endl;
					merchantInventory.erase(merchantInventory.begin());
					merchantInventory.insert(merchantInventory.begin(), "Sold Out");
					playerWallet -= itemPrice;
					playerInventory.push_back("dagger = $ 30");
					soldOut = true;
				}
				else if (soldOut)
				{
					cout << "Sorry sold out" << endl;
				}
				else
				{
					cout << "Insufficient funds" << endl;
				}

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
				cout << "Invalid number, Please try again" << endl;
			}
		}

		if (response == 's')
		{
			GetPlayerInventory();
		}
	} while (response != 'l');
}

void GetMerchantInventory()
{
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
		cout << "Select an item from: " << high << " - " << low << endl;
		cin >> number;
	} while (number > high || number < low);

	return number;
}

void ShopMenu()
{
	cout << "What can I do for you today? " << endl;
	cout << "[b]uy [s]ell [l]eave" << endl;
	cin >> response;	
}

void DisplayWallets()
{
	cout << "Merchant wallet: $" << merchantWallet << endl;
	cout << "Player wallet: $" << playerWallet << "\n" << endl;
}

void GetPlayerInventory()
{
	for (iter = playerInventory.begin(); iter != playerInventory.end(); ++iter)
	{
		cout << *iter << endl;
	}
}

