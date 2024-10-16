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
int playerWallet = 200;
int merchantWallet = 300;

string itemName = "";
string playerName = "";
vector<string> playerInventory;
vector<string> merchantInventory;
vector<string>::iterator myIterator;
vector<string>::const_iterator iter;

void GetPlayerInventory();
void GetMerchantInventory();
void ShopMenu(string choice);

int main()
{
	merchantInventory.push_back("dagger");
	merchantInventory.push_back("dagger");
	playerInventory.push_back("sword");


	cout << "Hello stranger, welcome to my shop!" << endl;
	cout << "What is your name?" << endl;
	
	cin >> playerName;

	cout << "\nNice to meet you " << playerName << endl;
	

	return 0;
}

void GetMerchantInventory()
{
	for (iter = merchantInventory.begin(); iter != merchantInventory.end(); ++iter)
	{
		cout << *iter << endl;
	}
}

void ShopMenu(string choice)
{
	do
	{
		cout << "What can can I do for you today? " << endl;
		cout << choice << "[b]uy [s]ell [l]eave" << endl;
		cin >> response;
	} while (response != 'b' && response != 's' && response != 'l');
}		

void GetPlayerInventory()
{
	for (iter = playerInventory.begin(); iter != playerInventory.end(); ++iter)
	{
		cout << *iter << endl;
	}
}

