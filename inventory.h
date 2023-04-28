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

		// Getters
        	vector<Item> getItems();
		vector<int> getItemAmounts();
		int getAmount(Item item);
	
		// Other Class Functions
		void removeInventory(Item item, int quantity);
		void displayInventory();
};

#endif //INVENTORY_H
