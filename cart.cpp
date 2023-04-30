#include "cart.h" 
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

// void cart::update(){
//     string line, word;
//     vector<string> temp;
//     fstream fIN;
//     this->items = temp;
    
//     fIN.open("cart.csv",ios::in);
//     getline(fIN, line);

//     stringstream s(line);
    
    
//     while(getline(s, word, ',')){//commet here
//         temp.push_back(word);
//     }
//     this->user = temp[0];
//     for (int i = 1; i < temp.size() - 1; i++)// Commet her
//     {
//         this->items.push_back(temp[i]);
//     }
//     this->changed = false;
    
// }
vector<Item> cart::getCurrentCart(string username){
    vector<Item> currentItems;
    for (int i = 0; i < this->allCarts.size(); i++){
        if (this->allCarts[i][0] == username){
            vector<string> userCart = this->allCarts[i];
            for (int j = 0; j < userCart.size(); j++)
            {
                for(int k = 0; k < this->allItems.size(); k++){
                    if (this->allItems[k].getTitle() == userCart[j])
                    {
                            currentItems.push_back(this->allItems[k]);
                    }
                }
                
            }
                    
        }
    }
    return currentItems;
}
cart::cart(vector<vector<string>> &cC, vector<Item> &alItems){
    this->allItems = alItems;
    this->allCarts = cC;
}

string cart::getUsername(){//comment here
    return this->user;
}
vector<Item> cart::viewCart(string user){
    return this->getCurrentCart(user);
}
void cart::addItem(string username, Item items, int quantity){//temparly changing this to a string

   for (int i = 0; i < allCarts.size(); i++)
   {
        if (this->allCarts[i][0] == username)
        {
            allCarts[i].pop_back();
            allCarts[i].push_back(items.getTitle());
            allCarts[i].push_back("END");
        }
        
   }
    
}

void cart::removeItem(string username,Item items){
       for (int i = 0; i < allCarts.size(); i++)
       {
            if (this->allCarts[i][0] == username)
                {
                    for (int j = 0; j < allCarts[i].size(); j++)
                    {
                        if (allCarts[i][j] == items.getTitle())
                        {
                            allCarts[i].erase(allCarts[i].begin() +j);
                        }
                        
                    }
                    
                }
        
   }

}
void cart::emptyCart(string name){
    for (int i = 0; i < allCarts.size(); i++)
    {
        if (this->allCarts[i][0] == name){
            allCarts[i].erase(allCarts[i].begin() + 1, allCarts[i].end() - 1 );
            
        }
    }

}
void cart::checkout(Inventory invTory,string name, User user){
    vector<Item> temp = this->getCurrentCart(name);
    for (int i = 0; i < temp.size(); i++)
    {
        invTory.removeInventory(temp[i],1);
        user.addToHistory(temp[i].getTitle());
    }
    this->emptyCart(name);
}
