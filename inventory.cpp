#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "item.h"
#include "inventory.h"

using namespace std;

// Default Constructor (sets empty storage vectors)
Inventory::Inventory()
{
	items = {};
	itemAmounts = {};
}

// Parameter Constructor (passes in the inventory items/quantities to work with)
Inventory::Inventory(vector<Item> items, vector<int> itemAmounts)
{
	this->items = items;
	this->itemAmounts = itemAmounts;
}

// Gets the amount of the desired item
int Inventory::getAmount(Item item)
{
	// Looping through the item vector
	for (int i = 0; i < items.size(); i++)
	{
		// Checking to see if the items match
		if (items[i] = item)
		{
			// Returning the amount of the item if it matches
			return itemAmounts[i];
		}
	}
}

// Removes the desired quantity of the desired item
void Inventory::removeInventory(Item item, int quantity)
{
	// Looping through the item vector
	for (int i = 0; i < items.size(); i++)
	{
		// Checking to see if the items match
		if (items[i] = item)
		{
			// Removing from the item amount vector
			itemAmounts[i] = itemAmounts[i] - quantity;
			cout << "Inventory successfully updated." << endl;
		}
	}
}

// Displays relevant info about the current inventory
void Inventory::displayInventory()
{
	// Declaring the appropriate variables
	string gameName;
	string gamePlatform;
	int gamePrice;
	int gameQuantity;

	// Looping through the items vector
	for (int i = 0; i < items.size(); i++)
	{
		// Grabbing the appropriate information
		gameName = items[i].title; // TODO : Make sure this line works properly
		gamePlatform = items[i].getPlatform();
		gamePrice = items[i].getPrice();
		gameQuantity = itemAmounts[i];

		// Displaying the data
		cout << "Name: " << gameName << "\tPlatform: " << gamePlatform << "\tPrice: " << gamePrice << "\tQuantity: " << gameQuantity << endl;
	}
}
