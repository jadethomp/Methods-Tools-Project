#include "item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item() {
    title = nullptr;
    genre = nullptr;
    price = NULL;
    publisher = nullptr;
    platform = nullptr;
    yearReleased = NULL;
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
