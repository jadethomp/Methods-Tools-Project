#include "item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item() {
    title = "";
    genre = "";
    price = -1;
    publisher = "";
    platform = "";
    yearReleased = -1;
}

Item::Item(string title, string genre, double price, string publisher, string platform, int yearReleased){
    this->title = title;
    this->genre = genre;
    this->price = price;
    this->publisher = publisher;
    this->platform = platform;
    this->yearReleased = yearReleased;
}

string Item::getTitle() {
    return title;
}

string Item::getGenre(string title) {
    return genre;
}

double Item::getPrice(string title) {
    return price;
}

string Item::getPublisher(string title) {
    return publisher;
}

string Item::getPlatform(string title) {
    return platform;
}

int Item::getYear(string title) {
    return yearReleased;
}
