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

string Item::getGenre() {
    return genre;
}

double Item::getPrice() {
    return price;
}

string Item::getPublisher() {
    return publisher;
}

string Item::getPlatform() {
    return platform;
}

int Item::getYear() {
    return yearReleased;
}
