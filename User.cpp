#include "User.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

User::User(){
    username = nullptr;
    password = nullptr;
}

User::User(string username, string password){
    this->username = username;
    this->password = password;
}

//getters
string User::getPassword(string username){
    return password;
}

vector<string> User::getName(){
    vector<string> vec = {firstName, lastName};
    return vec;
}

vector<string> User::getContactInformation(){
    vector<string> vec = {phoneNumber, emailAddress};
    return vec;
}

vector<string> User::getBillingInfo(){
    return billingInfo;
}
vector<string> User::getShippingInfo(){
    return shippingInfo;
}

vector<string> User::getCardInfo(){
    return cardInfo;
}

//setters
void User::setRealName(string firstName, string lastName){
    this->firstName = firstName;
    this->lastName = lastName;
}

void User::setUsername(string username){
    this->username = username;
}

void User::setPassword(string password){
    this->password = password;
}

void User::setContactInfo(string phoneNumber, string emailAddress){
    this->phoneNumber = phoneNumber;
    this->emailAddress = emailAddress;
}

void User::setBillingInfo(string billingAddress, string city, string state, string zipCode){
    billingInfo[0] = billingAddress;
    billingInfo[1] = city;
    billingInfo[2] = state;
    billingInfo[3] = zipCode;
}
void User::setShippingInfo(string shippingAddress, string city, string state, string zipCode){
    shippingInfo[0] = shippingAddress;
    shippingInfo[1] = city;
    shippingInfo[2] = state;
    shippingInfo[3] = zipCode;
}

void User::setCardInfo(string cardNumber, string cardCVV, string cardExpirationDate){
    cardInfo[0] = cardNumber;
    cardInfo[1] = cardCVV;
    cardInfo[2] = cardExpirationDate;
}

//order history
vector<string> User::getHistory(){
    return orderHistory;
}

void User::addToHistory(string title){
    orderHistory.push_back(title);
}

void User::deleteFromHistory(string title){
    orderHistory.erase(remove(orderHistory.begin(), orderHistory.end(), title), orderHistory.end());
}

void User::clearHistory(){
    orderHistory.clear();
}
