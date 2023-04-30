#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"
#include "item.h"
#include "inventory.h"

using namespace std;

class cart
{
    private:
        string user;
        vector<string> items;
        vector<Item> allItems;
        vector<vector<string>> allCarts;
        bool changed = false;
        
        
    public:
        cart(vector<vector<string>> &everyCart,vector<Item> &aItems);
        string getUsername();
        vector<Item> getCurrentCart(string username);
        vector<Item> viewCart(string username);
        void addItem(string username, Item items, int quantity);
        void removeItem(string username,Item items);
        void checkout(Inventory invTory,string name, User user);
        void emptyCart(string username);
        //~cart();
};


#endif //CART
