#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <errno.h>
using namespace std;

#include "User.h"
#include "item.h"
#include "inventory.h"
// #include "ShoppingCart.h"

// functions to read the .csv files into containers, the program works with these containers while running
// instead of trying to deal with in-file editing, then writes to files before program exits
// these are adapted from kortni's code (week 9)

int readItems(vector<Item> &items){
    ifstream infile;
    infile.open("items.csv");
    string line;
    while(getline(infile, line)){
        string title, genre, price, publisher, platform, releaseYear;
        string delimiter = ",";
        title = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        genre = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        price = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        publisher = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        platform = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        releaseYear = line.substr(0, line.find(delimiter));
//        to-do: add a constructor for this, or setters
//        Item temp(title, genre, price, publisher, platform, releaseYear);

//        items.push_back(temp);
    }
    infile.close();
    infile.clear(); // might need this?
    return 0;
}

int readUsers(vector<User> &users){
    ifstream infile;
    infile.open("users.csv");
    string line;
    while(getline(infile, line)){
        string username, password, firstName, lastName, phoneNumber, emailAddress, billingAddress, billingCity, billingState, billingZip, 
        shippingAddress, shippingCity, shippingState, shippingZip, cardNumber, cardCVV, cardDate;
        vector<string> history;

        string delimiter = ",";

        username = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        password = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        firstName = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        lastName = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        phoneNumber = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        emailAddress = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        billingAddress = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        billingCity = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        billingState = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        billingZip = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        shippingAddress = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        shippingCity = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        shippingState = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        shippingZip = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cardNumber = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cardCVV = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cardDate = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        while(1){
            string temp;
            temp = line.substr(0, line.find(delimiter));
            if (temp == "END"){
                break;
            }
            line.erase(0, line.find(delimiter) + delimiter.length());
            history.push_back(temp);
        }
        vector<string> shippingInfo = {shippingAddress, shippingCity, shippingState, shippingZip};
        vector<string> billingInfo = {billingAddress, billingCity, billingState, billingZip};
        vector<string> cardInfo = {cardNumber, cardCVV, cardDate};

        User tempUser(username, password, firstName, lastName, phoneNumber, emailAddress, billingInfo, shippingInfo, cardInfo, history);
        users.push_back(tempUser);
    }
    infile.close();
    infile.clear();
    return 0;
}

int readInventory(Inventory &inventory, vector<Item> items){
    ifstream infile;
    infile.open("inventory.csv");
    string line;
    Item temp;
    vector<Item> tempItems;
    vector<int> tempQuantities;
    while(getline(infile, line)){
        string title, quantity;
        string delimiter = ",";
        title = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        quantity = line.substr(0, line.find(delimiter));
        for(int i = 0; i < items.size(); i++){
//            if (title == items[i].getTitle()){
//                temp = items[i];
//                tempItems.push_back(temp);
//                break;
//            }
        }
        tempQuantities.push_back(stoi(quantity));
    }
    Inventory tempInventory(tempItems, tempQuantities);
    inventory = tempInventory;
    infile.close();
    infile.clear();
}

/*
int readCart(vector<User> users, vector<Item> items, vector<ShoppingCart> &carts){
    ifstream infile;
    string line;
    vector<string> itemTitles;
    vector<Item> tempItems;
    User tempUser;
    Item tempItem;
    while(getline(infile, line)){
        string username;
        string delimiter = ",";
        username = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        while(1){
            string temp;
            temp = line.substr(0, line.find(delimiter));
            if (temp == "END"){
                break;
            }
            line.erase(0, line.find(delimiter) + delimiter.length());
            itemTitles.push_back(temp);
        }
        for (int i = 0; i < users.size(); i++){
            if (username == users[i].getUsername()){
                tempUser = users[i];
                break;
            }
        }
        for (int i = 0; i < itemTitles.size(); i++){
            for (int j = 0; j < items.size(); j++){
//                if (itemTitles[i] == items[j].getTitle()){
//                    tempItem = items[j];
//                    tempItems.push_back(tempItem);
//                    break;
//                }
            }
        }
//        ShoppingCart tempCart(tempUser, tempItems);
//        cart.push_back(tempCart);
    }
    infile.close();
    infile.clear();
}
*/

int checkError(int val, const char* msg){
    if (val == -1){
        perror(msg);
        cout << msg << endl;
    }
    return val;
}

int main(){
    int numInput;
    int loggedIn = 0;
    string input;
    User current;
    vector<User> users;
    vector<Item> items;
    Inventory inventory;
    // vector<ShoppingCart> carts;

    //read in files
    checkError(readItems(items), "readItems");
    checkError(readUsers(users), "readUsers");
    checkError(readInventory(inventory, items), "readInventory");
//    checkError(readCart(users, items, &carts), "readCart");


    cout << "Welcome to Totally Real Games - the best e-commerce store in town!" << endl;
    //main loop
    while(1) {
        //pre-login loop
        while (loggedIn == 0) {
            cout << "Please select an option to continue.\n"
                    "(1)Login\n(2)Register\n(3)Exit\n>>";
            cin >> numInput;
            if (numInput == 1) {
                //login loop
                while(1) {
                    //prompt for login
                    cout << "Enter your username, or enter X to cancel.\n>>";
                    cin >> input;
                    //check if username is registered
                        //if registered, keep going
                        //if not, go back to beginning of login loop
                        //if 'X', break loop and loop back to pre-login options
                    //enter password loop
                    while(1){
                        input = "";
                        cout << "Enter your password, or enter X to cancel.\n>>";
                        cin >> input;
                        //check if password is correct
                            //if correct, loggedIn = 1, break
                            //if incorrect, go back to beginning of password loop
                            //if 'X', break loop and loop back to pre-login options
                            break; //temporary
                    }
                    //if input == 'X', break
                    break; //temporary
                }
            }
            else if (numInput == 2) {
                //make a new user
            }
            else if (numInput == 3) {
                return 0;
            }
            break; //temporary
        }
        //they made it through! post-login menu goes below...
        while(1){
            // resets input
            input = "";
            cout << "Select an option:\n"
                    "(1) View all games\n(2)View your cart\n"
                    "(3) View order history\n(4) Edit account\n"
                    "(5) Exit\n>>";
            cin >> input;
            // view all video games
            if (input == "1"){

            }
            // view cart
            else if (input == "2"){

            }
            // view order history
            else if (input == "3"){

            }
            // edit account
            else if (input == "4"){

            }
            // exit
            else if (input == "5"){
                break;
            }
            else{
                cout << "Invalid input, please try again.\n";
                continue; //maybe not necessary
            }
        }
        break; //only executes upon exit
    }
    // after main loop - upon exit

    // write to .csv files
    ofstream outfile;
    outfile.open("users.csv", ios_base::out);
    string delimiter = ",";

    // write to users.csv
    for (int i = 0; i < users.size(); i++){
        if (i != 0){
            outfile << endl;
        }
        outfile << users[i].getUsername() << delimiter;
        outfile << users[i].getPassword() << delimiter;
        outfile << users[i].getName()[0] << delimiter;
        outfile << users[i].getName()[1] << delimiter;
        outfile << users[i].getContactInformation()[0] << delimiter;
        outfile << users[i].getContactInformation()[1] << delimiter;
        outfile << users[i].getBillingInfo()[0] << delimiter;
        outfile << users[i].getBillingInfo()[1] << delimiter;
        outfile << users[i].getBillingInfo()[2] << delimiter;
        outfile << users[i].getBillingInfo()[3] << delimiter;
        outfile << users[i].getShippingInfo()[0] << delimiter;
        outfile << users[i].getShippingInfo()[1] << delimiter;
        outfile << users[i].getShippingInfo()[2] << delimiter;
        outfile << users[i].getShippingInfo()[3] << delimiter;
        outfile << users[i].getCardInfo()[0] << delimiter;
        outfile << users[i].getCardInfo()[1] << delimiter;
        outfile << users[i].getCardInfo()[2] << delimiter;
        for (int j = 0; j < users[i].getHistory().size(); j++){
            outfile << users[i].getHistory()[j] << delimiter;
        }
        outfile << "END";
    }

    // write to items.csv

    // write to inventory.csv

    // write to carts.csv

    return 0;
}
