#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(string name, double price) {
    this->name = name;
    this->price = price;
}

string Product::getName() const { return this->name; }
void Product::setName(const string& name) { this->name = name; }

double Product::getPrice() const { return this->price; }
void Product::setPrice(double price) { this->price = price; }

// Shoe
Shoe::Shoe(string name, double price, string size) : Product(name, price) {
    this->size = size;
}

void Shoe::display() const {
    cout << "[Shoe] " << this->name << " | Pret: " << this->price << " RON | Marime: " << this->size << "\n";
}

// Toy
Toy::Toy(string name, double price, int age) : Product(name, price) {
    this->ageRecommendation = age;
}

void Toy::display() const {
    cout << "[Toy] " << this->name << " | Pret: " << this->price << " RON | Varsta recomandata: " << this->ageRecommendation << "+\n";
}