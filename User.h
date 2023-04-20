#ifndef METHODS_TOOLS_PROJECT_USER_H
#define METHODS_TOOLS_PROJECT_USER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
private:
    string firstName, lastName;
    string username, password;
    string phoneNumber, emailAddress;
    vector<string> billingInfo;
    vector<string> shippingInfo;
    vector<string> cardInfo;
    vector<string> orderHistory;
public:
    //constructors
    User();
    User(string username, string password);

    //getters
    string getPassword(string username);
    vector<string> getName();
    vector<string> getContactInformation();
    vector<string> getBillingInfo();
    vector<string> getShippingInfo();
    vector<string> getCardInfo();

    //setters
    void setRealName(string firstName, string lastName);
    void setUsername(string username);
    void setPassword(string password);
    void setContactInfo(string phoneNumber, string emailAddress);
    void setBillingInfo(string billingAddress, string city, string state, string zipCode);
    void setShippingInfo(string shippingAddress, string city, string state, string zipCode);
    void setCardInfo(string cardNumber, string cardCVV, string cardExpirationDate);

    //order history
    vector<string> getHistory();
    void addToHistory(string title);
    void deleteFromHistory(string title);
    void clearHistory();

    //delete user
    void deleteUser(); //changed from design document, don't need parameter?
};

#endif //METHODS_TOOLS_PROJECT_USER_H
