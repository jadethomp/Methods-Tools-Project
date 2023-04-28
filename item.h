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

    //getters
    string getTitle();
    string getGenre(string title);
    double getPrice(string title);
    string getPublisher(string title);
    string getPlatform(string title);
    int getYear(string title);
};
