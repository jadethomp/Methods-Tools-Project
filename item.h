#ifndef METHODS_TOOLS_PROJECT_ITEM_H
#define METHODS_TOOLS_PROJECT_ITEM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
private:
    string title;
    string genre;
    double price;
    string publisher;
    string platform;
    int yearReleased;

public:
    //constructor
    Item();
    Item(string title, string genre, double price, string publisher, string platform,  int yearReleased);

    //getters
    string getTitle();
    string getGenre(string title);
    double getPrice(string title);
    string getPublisher(string title);
    string getPlatform(string title);
    int getYear(string title);
};

#endif //METHODS_TOOLS_PROJECT_ITEM_H