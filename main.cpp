#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <errno.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

#include "User.h"
#include "item.h"
#include "inventory.h"
// #include "ShoppingCart.h"

// checks if the username is valid
bool checkUsername(string username, vector<User> users){
    if (isspace(username[0])){
        cout << "Invalid username. Please enter text or numbers.\n";
        return false;
    }
    for (int i = 0; i < username.length(); i++){
        if (!isalnum(username[i])){
            cout << "Invalid username. Please only enter letters or numbers.\n";
        }
    }
    if (username.length() < 2){
        cout << "Username must be at least two characters long.\n";
        return false;
    }
    for (int i = 0; i < users.size(); i++) {
        if (username == users[i].getUsername()) {
            cout << "This username already exists. Try again.\n";
            return false;
        }
    }
    return true;
}

// functions to read the .csv files into containers, the program works with these containers while running
// instead of trying to deal with in-file editing, then writes to files before program exits
// these are adapted from kortni's code (week 9)

int readItems(vector<Item> &items){
    ifstream infile;
    infile.open("items.csv");
    string line;
    while(getline(infile, line)){
        string title, genre, price, publisher, platform, yearReleased;
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
        yearReleased = line.substr(0, line.find(delimiter));
        Item temp(title, genre, stof(price), publisher, platform, stoi(yearReleased));
        items.push_back(temp);
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
            if (title == items[i].getTitle()){
                temp = items[i];
                tempItems.push_back(temp);
                break;
            }
        }
        tempQuantities.push_back(stoi(quantity));
    }
    Inventory tempInventory(tempItems, tempQuantities);
    inventory = tempInventory;
    infile.close();
    infile.clear();
    return 0;
}

/*
int readCart(vector<User> users, vector<Item> items, vector<ShoppingCart> &carts){
    ifstream infile;
    string line;
    vector<string> itemTitles;
    vector<Item> tempItems;
//    User tempUser;
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
//        for (int i = 0; i < users.size(); i++){
//            if (username == users[i].getUsername()){
//                tempUser = users[i];
//                break;
//            }
//        }
        for (int i = 0; i < itemTitles.size(); i++){
            for (int j = 0; j < items.size(); j++){
//                if (itemTitles[i] == items[j].getTitle()){
//                    tempItem = items[j];
//                    tempItems.push_back(tempItem);
//                    break;
//                }
            }
        }
//        ShoppingCart tempCart(username, tempItems);
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
    // ShoppingCart currentCart;
    // find current cart
    /*for (int i = 0; i < carts.size(); i++){
        if (carts[i].getUsername() == current.getUsername()){
            currentCart = carts[i];
            break;
        }
    }*/

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
                    "(1) Login\n(2) Create Account\n(3) Exit\n>>";
            cin >> numInput;
            if (numInput == 1) {
                //login loop
                while(1) {
                    input = "";
                    //prompt for login
                    cout << "Enter your username, or enter X to cancel.\n>>";
                    cin >> input;
                    if (input == "X"){
                        break;
                    }
                    //check if username is registered
                    for (int i = 0; i < users.size(); i++){
                        if (input == users[i].getUsername()){
                            loggedIn = 2; // i'm using 2 as an "in between" (indicates username exists)
                            current = users[i];
                            break;
                        }
                    }
                    //if username not registered
                    if (loggedIn != 2){
                        cout << "Username not registered.\n";
                        continue;
                    }
                    //enter password loop
                    while(loggedIn == 2){
                        input = "";
                        cout << "Enter your password, or enter X to cancel.\n>>";
                        cin >> input;
                        if (input == "X"){
                            loggedIn = 0;
                            break;
                        }
                        if (input == current.getPassword()){
                            loggedIn = 1;
                        }
                        else{
                            cout << "Incorrect password. Try again.\n";
                            continue;
                        }
                    }
                    // extra one to break completely out of login loop
                    if (input == "X"){
                        break;
                    }
                    else if (loggedIn == 1){
                        break;
                    }
                }
            }
            else if (numInput == 2) {
                // temp vars
                string username, password, firstName, lastName, phoneNumber,
                        emailAddress, billingAddress, billingCity, billingState, billingZip,
                        shippingAddress, shippingCity, shippingState, shippingZip, cardNum,
                        cardCVV, cardDate;
                vector<string> history = {};
                cout << "At any point in account creation, enter 'X' to cancel.\n";
                //username loop
                while(1){
                    input = "";
                    cout << "Enter a username.\n>>";
                    cin >> username;
                    if (username == "X"){
                        break;
                    }
                    if(checkUsername(username, users)){
                        break;
                    }
                    else{
                        // output handled in function
                        continue;
                    }
                }
                // this is so long i am so sorry
                cout << "Enter a password.\n>>";
                cin >> password;
                cout << "Enter your first name.\n>>";
                cin >> firstName;
                cout << "Enter your last name.\n>>";
                cin >> lastName;
                cout << "Enter your phone number - just numbers! No spaces, dashes, or parentheses.\n>>";
                cin >> phoneNumber;
                cout << "Enter your email address.\n>>";
                cin >> emailAddress;
                cout << "Enter your billing address (just the street!).\n>>";
                cin.ignore(); // lets you read a string with spaces
                getline(cin, billingAddress);
                cout << "Enter the city for your billing address.\n>>";
                cin >> billingCity;
                cout << "Enter the state for your billing address (initials).\n>>";
                cin >> billingState;
                cout << "Enter the zip code for your billing address.\n>>";
                cin >> billingZip;
                cout << "Enter your shipping address (just the street!).\n>>";
                cin.ignore();
                getline(cin, shippingAddress);
                cout << "Enter the city for your shipping address.\n>>";
                cin >> shippingCity;
                cout << "Enter the state for your shipping address (initials).\n>>";
                cin >> shippingState;
                cout << "Enter the zip code for your shipping address.\n>>";
                cin >> shippingZip;
                cout << "Enter your credit card number - no spaces or dashes!\n>>";
                cin >> cardNum;
                cout << "Enter your credit card's CVV.\n>>";
                cin >> cardCVV;
                cout << "Enter your credit card's expiration date, in the format MM/YY.\n>>";
                cin >> cardDate;
                vector<string> shipping = {shippingAddress, shippingCity, shippingState, shippingZip};
                vector<string> billing = {billingAddress, billingCity, billingState, billingZip};
                vector<string> card = {cardNum, cardCVV, cardDate};
                User newGuy(username, password, firstName, lastName, phoneNumber, emailAddress, billing, shipping, card, history);
                users.push_back(newGuy);
//                ShoppingCart newCart(username);
//                carts.push_back(newCart);
                cout << "New user created! Please log in.\n";
                loggedIn = 0; //just to make sure
                continue;
            }
            else if (numInput == 3) {
                cout << "Thank you for shopping with us. Please come back soon!\nExiting...\n";
                return 0;
            }
            else{
                cout << "Invalid input, please try again.\n";
                continue;
            }
            break; //temporary
        }
        //they made it through! post-login menu goes below...
        while(loggedIn == 1){
            // resets input
            input = "";
            cout << "Select an option:\n"
                    "(1) View all games\n(2) View your cart\n"
                    "(3) View order history\n(4) Edit account\n"
                    "(5) Exit\n>>";
            cin >> numInput;

            // view all video games -- akira
            if (numInput == 1){
                // Displaying the current inventory
                inventory.displayInventory();

                while (1)
                {
                    // Asks the user if they would like to add a game to the cart
                    cout << "Would you like to add a game to your shopping cart?" << endl;
                    cout << "Select an option\n"
                            "(1) Add to cart\n(2) Exit\n>>";

                    // Resetting input
                    numInput = -1;

                    // Prompting user for input
                    cin >> numInput;

                    // Adding to cart
                    if (numInput == 1)
                    {
                        while(1)
                        {
                            cout << "Which game would you like to purchase?" << endl;
                            cout << "Input the number found at the beginning of the line. Select 0 to exit.\n>>";

                            // Resetting input
                            numInput = -1;

                            // Prompting user for input
                            cin >> numInput;
                            if (numInput == 0){
                                break;
                            }

                            // Making sure that the item is in stock
                            Item temp = inventory.getItems()[numInput - 1];
                            if (inventory.getAmount(temp) > 0)
                            {
//                                currentCart.addItem(temp, 1);
                                cout << "Added to cart.\n";
                                // doesn't remove from inventory until checkout
                                break;
                            }

                            else
                            {
                                cout << "Sorry, that item is currently not in stock. Check back later." << endl;
                                break;
                            }
                        }
                        break;
                    }

                        // Exiting
                    else if (numInput == 2)
                    {
                        break;
                    }

                    else
                    {
                        cout << "Invalid input, please try again.\n";
                        continue;
                    }
                }
                continue;
            }

                // view cart -- samarra
            else if (numInput == 2){
                // displays cart
//                vector<Item> temp = currentCart.viewCart();
                /*for (int i = 0; i < temp.size(); i++){
                    cout << "Item " << i + 1 << " --- Name: " << temp[i].getTitle() << "\tPlatform: " << temp[i].getPlatform() << "\tPrice: " << temp[i].getPrice() << endl;
                }*/
                //cart editing loop
                while(1){
                    input = "";
                    cout << "Select an option:\n"
                            "(1) Go back\n(2) Remove Item from Cart\n"
                            "(3) Checkout\n(4) Clear Cart\n>>";
                    cin >> numInput;
                    if (numInput == 1){ // go back
                        // break out of editing loop, back to main loop
                        break;
                    }
                    else if (numInput == 2){ //Remove item from cart
                        // display cart again
                        /*for (int i = 0; i < temp.size(); i++){
                            cout << "Item " << i + 1 << " --- Name: " << temp[i].getTitle() << "\tPlatform: " << temp[i].getPlatform() << "\tPrice: " << temp[i].getPrice() << endl;
                        }*/
                        cout << "Which game would you like to remove?" << endl;
                        cout << "Input the number found at the beginning of the line. Select 0 to exit.\n>>";
                        cin >> numInput;
                        if (numInput == 0){
                            break;
                        }
                        cout << "Select an option:\n(1) Confirm\n(2) Cancel.\n";
                        cin >> numInput;
                        if (numInput = 1){
//                        currentCart.removeItem(temp[numInput - 1]);
                        }
                        else if (numInput = 2){
                            break;
                        }
                        else{
                            cout << "Invalid input, please try again.\n";
                            continue;
                        }
                    }
                    else if (numInput == 3){ //Check out
                        cout << "Select an option:\n(1) Confirm\n(2) Cancel.\n";
                        cin >> numInput;
                        if (numInput = 1){
//                            currentCart.checkout();
                            // if not included in checkout, update inventory and order history
                        }
                        else if (numInput = 2){
                            break;
                        }
                        else{
                            cout << "Invalid input, please try again.\n";
                            continue;
                        }
                    }
                    else if (numInput == 4){ //Clear cart
//                        currentCart.emptyCart();
                        cout << "Clearing cart.\n";
                        break;
                    }
                    else{
                        cout << "Invalid input, please try again.\n";
                        continue;
                    }
                }
            }
                // view order history -- edward
            else if (numInput == 3) {

            }
                // edit account -- jade
            else if (numInput == 4){
                // account editing loop
                while(1){
                    input = "";
                    cout << "Select an option:\n"
                            "(1) Go back\n(2) Edit Contact Information\n"
                            "(3) Edit Shipping Address\n(4) Edit Billing Address\n"
                            "(5) Edit Payment Information\n(6) Delete Account\n>>";
                    cin >> numInput;
                    if (numInput == 1){ // go back
                        // break out of editing loop, back to main loop
                        break;
                    }
                    else if (numInput == 2){ // edit contact info
                        // display contact info
                        cout << "Current contact information on file:\n"
                                "Name: " << current.getName()[0] << " " << current.getName()[1] << endl <<
                             "Email: " << current.getContactInformation()[1] << endl <<
                             "Phone Number: " << current.getContactInformation()[0] << endl << endl;
                        cout << "What would you like to edit?\n" << "(1) Name\n(2) Email Address\n"
                                                                    "(3) Phone Number\n(4) Cancel\n>>";
                        cin >> numInput;
                        if (numInput == 1){
                            string firstName, lastName;
                            cout << "Enter your first name.\n>>";
                            cin >> firstName;
                            cout << "Enter your last name.\n>>";
                            cin >> lastName;
                            current.setRealName(firstName, lastName);
                            cout << "Name set.\n";
                            break;
                        }
                        else if (numInput == 2){
                            string emailAddress;
                            cout << "Enter your email address.\n>>";
                            cin >> emailAddress;
                            current.setContactInfo(current.getContactInformation()[0], emailAddress);
                            cout << "Email address set.\n";
                            break;
                        }
                        else if (numInput == 3){
                            string phoneNumber;
                            cout << "Enter your phone number (numbers only).\n>>";
                            cin >> phoneNumber;
                            current.setContactInfo(phoneNumber, current.getContactInformation()[1]);
                            cout << "Phone number set.\n";
                            break;
                        }
                        else if (numInput == 4){
                            break;
                        }
                        else{
                            cout << "Invalid input.\n";
                            continue;
                        }
                    }
                    else if (numInput == 3){ // edit shipping address
                        // display shipping info
                        cout << "Current shipping information on file:\n"
                                "Address: " << current.getShippingInfo()[0] << endl <<
                             "City: " << current.getShippingInfo()[1] << endl <<
                             "State: " << current.getShippingInfo()[2] << endl <<
                             "Zip: " << current.getShippingInfo()[3] << endl << endl;
                        cout << "What would you like to edit?\n" << "(1) Address\n(2) City\n"
                                                                    "(3) State\n(4) Zip Code\n(5) Cancel\n>>";
                        cin >> numInput;
                        if (numInput == 1){
                            string address;
                            cout << "Enter your address (just the street).\n>>";
                            cin.ignore();
                            getline(cin, address);
                            current.setShippingInfo(address, current.getShippingInfo()[1],
                                                    current.getShippingInfo()[2], current.getShippingInfo()[3]);
                            cout << "Address set.\n";
                            break;
                        }
                        else if (numInput == 2){
                            string city;
                            cout << "Enter your city.\n>>";
                            cin >> city;
                            current.setShippingInfo(current.getShippingInfo()[0], city,
                                                    current.getShippingInfo()[2], current.getShippingInfo()[3]);
                            cout << "City set.\n";
                            break;
                        }
                        else if (numInput == 3){
                            string state;
                            cout << "Enter your state (initials).\n>>";
                            cin >> state;
                            current.setShippingInfo(current.getShippingInfo()[0], current.getShippingInfo()[1],
                                                    state, current.getShippingInfo()[3]);
                            cout << "State set.\n";
                            break;
                        }
                        else if (numInput == 4){
                            string zip;
                            cout << "Enter your zip code.\n>>";
                            cin >> zip;
                            current.setShippingInfo(current.getShippingInfo()[0], current.getShippingInfo()[1],
                                                    current.getShippingInfo()[2], zip);
                            cout << "Zip code set.\n";
                            break;
                        }
                        else if (numInput == 5){
                            break;
                        }
                        else{
                            cout << "Invalid input.\n";
                            continue;
                        }
                    }
                    else if (numInput == 4){ // edit billing address
                        // display billing info
                        cout << "Current billing information on file:\n"
                                "Address: " << current.getBillingInfo()[0] << endl <<
                             "City: " << current.getBillingInfo()[1] << endl <<
                             "State: " << current.getBillingInfo()[2] << endl <<
                             "Zip: " << current.getBillingInfo()[3] << endl << endl;
                        cout << "What would you like to edit?\n" << "(1) Address\n(2) City\n"
                                                                    "(3) State\n(4) Zip Code\n(5) Cancel\n>>";
                        cin >> numInput;
                        if (numInput == 1){
                            string address;
                            cout << "Enter your address (just the street).\n>>";
                            cin.ignore();
                            getline(cin, address);
                            current.setBillingInfo(address, current.getBillingInfo()[1],
                                                   current.getBillingInfo()[2], current.getBillingInfo()[3]);
                            cout << "Address set.\n";
                            break;
                        }
                        else if (numInput == 2){
                            string city;
                            cout << "Enter your city.\n>>";
                            cin >> city;
                            current.setBillingInfo(current.getBillingInfo()[0], city,
                                                   current.getBillingInfo()[2], current.getBillingInfo()[3]);
                            cout << "City set.\n";
                            break;
                        }
                        else if (numInput == 3){
                            string state;
                            cout << "Enter your state (initials).\n>>";
                            cin >> state;
                            current.setBillingInfo(current.getBillingInfo()[0], current.getBillingInfo()[1],
                                                   state, current.getBillingInfo()[3]);
                            cout << "State set.\n";
                            break;
                        }
                        else if (numInput == 4){
                            string zip;
                            cout << "Enter your zip code.\n>>";
                            cin >> zip;
                            current.setBillingInfo(current.getBillingInfo()[0], current.getBillingInfo()[1],
                                                   current.getBillingInfo()[2], zip);
                            cout << "Zip code set.\n";
                            break;
                        }
                        else if (numInput == 5){
                            break;
                        }
                        else{
                            cout << "Invalid input.\n";
                            continue;
                        }
                    }
                    else if (numInput == 5){ // edit payment info
                        // display payment info
                        cout << "Current payment information on file:\n"
                                "Card Number: " << current.getCardInfo()[0] << endl <<
                             "CVV: " << current.getCardInfo()[1] << endl <<
                             "Expiration Date: " << current.getCardInfo()[2] << endl << endl;
                        cout << "What would you like to edit?\n" << "(1) Card Number\n(2) CVV\n"
                                                                    "(3) Expiration Date\n(4) Cancel\n>>";
                        cin >> numInput;
                        if (numInput == 1){
                            string number;
                            cout << "Enter your card number.\n>>";
                            cin >> number;
                            current.setCardInfo(number, current.getCardInfo()[1], current.getCardInfo()[2]);
                            cout << "Card number set.\n";
                            break;
                        }
                        else if (numInput == 2){
                            string cvv;
                            cout << "Enter your CVV.\n>>";
                            cin >> cvv;
                            current.setCardInfo(current.getCardInfo()[0], cvv, current.getCardInfo()[2]);
                            cout << "CVV set.\n";
                            break;
                        }
                        else if (numInput == 3){
                            string expiration;
                            cout << "Enter your expiration date (formatted as MM/YY).\n>>";
                            cin >> expiration;
                            current.setCardInfo(current.getCardInfo()[0], current.getCardInfo()[1], expiration);
                            cout << "Phone number set.\n";
                            break;
                        }
                        else if (numInput == 4){
                            break;
                        }
                        else{
                            cout << "Invalid input.\n";
                            continue;
                        }
                    }
                    else if (numInput == 6){ // delete account
                        for (int i = 0; i < users.size(); i++){
                            if (users[i].getUsername() == current.getUsername()){
                                users.erase(users.begin() + i);
                                break;
                            }
                        }
                        cout << "Account deleted. Exiting...\n";
                        break;
                    }
                    else{
                        cout << "Invalid input, please try again.\n";
                        continue;
                    }
                }
            }
            // exit program
                // exit
            else if (numInput == 5){
                break;
            }
            else{
                cout << "Invalid input, please try again.\n";
                continue; //maybe not necessary
            }
            if (numInput == 6){
                break;
            }
        }
        if (loggedIn == 0){
            continue;
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
    outfile.close();

    // write to items.csv
    //...turns out we do not need the title in the parameter for these getters
    //...no biggie
    outfile.open("items.csv", ios_base::out);
    for (int i = 0; i < items.size(); i++){
        if (i != 0){
            outfile << endl;
        }
        outfile << items[i].getTitle() << delimiter;
        outfile << items[i].getGenre("") << delimiter;
        outfile << items[i].getPrice("") << delimiter;
        outfile << items[i].getPublisher("") << delimiter;
        outfile << items[i].getPlatform("") << delimiter;
        outfile << items[i].getYear("");
    }
    outfile.close();

    // write to inventory.csv
    outfile.open("inventory.csv", ios_base::out);
    for (int i = 0; i < inventory.getItems().size(); i++){
        if (i != 0){
            outfile << endl;
        }
        Item temp = inventory.getItems()[i];
        outfile << temp.getTitle() << delimiter;
        outfile << inventory.getAmount(temp);
    }
    outfile.close();

    // write to carts.csv
    outfile.open("carts.csv", ios_base::out);
    /*
    for (int i = 0; i < carts.size(); i++){
        if (i != 0){
            outfile << endl;
        }
        outfile << carts[i].getUsername() << delimiter;
        for (int j = 0; j < carts.viewCart().size(); j++){
            Item temp = carts.viewCart()[j];
            outfile << temp.getTitle() << delimiter;
        }
        outfile << "END";
    }
    */
    outfile.close();

    cout << "Thank you for shopping with us. Please come back soon!\nExiting...\n";

    return 0;
}
