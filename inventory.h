#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "item.h"

using namespace std;

class Inventory
{
	private:
		// Storage Vectors
		vector<Item> items;
		vector<int> itemAmounts;

	public:
		// Constructors
		Inventory();
		Inventory(vector<Item> items, vector<int> itemAmounts);

		// Class Functions
        vector<Item> getItems();
		int getAmount(Item item);
		void removeInventory(Item item, int quantity);
		void displayInventory();
};

#endif //INVENTORY_H
