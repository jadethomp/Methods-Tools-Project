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
        User user;
        vector<Item> items;
//        vector<Item> allItems;
//        vector<vector<string>> allCarts;
//        bool changed = false;
        
        
    public:
        cart();
        cart(User user);
        cart(User user, vector<Item> items);
        string getUsername();
//        vector<Item> getCurrentCart(string username);
        vector<Item> viewCart();
        void addItem(Item item, int quantity);
        void removeItem(Item item);
        void checkout(User &user, Inventory &inventory);
        void emptyCart();
        //~cart();
};


#endif //CART
