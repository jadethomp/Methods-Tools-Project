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
//vector<Item> cart::getCurrentCart(string username){
//    vector<Item> currentItems;
//    for (int i = 0; i < this->allCarts.size(); i++){
//        if (this->allCarts[i][0] == username){
//            vector<string> userCart = this->allCarts[i];
//            for (int j = 0; j < userCart.size(); j++)
//            {
//                for(int k = 0; k < this->allItems.size(); k++){
//                    if (this->allItems[k].getTitle() == userCart[j])
//                    {
//                            currentItems.push_back(this->allItems[k]);
//                    }
//                }
//
//            }
//
//        }
//    }
//    return currentItems;
//}

cart::cart(){

}

cart::cart(User user){
    this->user = user;
}

cart::cart(User user, vector<Item> items){
    this->user = user;
    this->items = items;
}

string cart::getUsername(){
    return this->user.getUsername();
}
vector<Item> cart::viewCart(){
    return this->items;
}
void cart::addItem(Item item, int quantity){//temparly changing this to a string
    for(int i = 0; i < quantity; i++) {
        this->items.push_back(item);
    }
}

void cart::removeItem(Item item){
    for (int i = 0; i < this->items.size(); i++){
        if(items[i].getTitle() == item.getTitle()){
            items.erase(items.begin() + i);
        }
    }

}

void cart::checkout(User &user, Inventory &inventory){
    vector<Item> temp = this->viewCart();
    for (int i = 0; i < temp.size(); i++) {
        inventory.removeInventory(temp[i],1);
        user.addToHistory(temp[i].getTitle());
    }
    this->emptyCart();
}

void cart::emptyCart(){
    items.clear();
}
