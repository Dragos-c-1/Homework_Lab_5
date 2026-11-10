#include "Order.h"
#include <iostream>

using namespace std;

Order::Order(int id) {
    this->orderId = id;
}

void Order::addProduct(Product* p) {
    this->orderedProducts.push_back(p);
}

double Order::calculateTotal() const {
    double total = 0.0;
    for (auto p : this->orderedProducts) {
        total += p->getPrice();
    }
    return total;
}

void Order::displayOrder() const {
    cout << "Comanda #" << this->orderId << " contine:\n";
    for (auto p : this->orderedProducts) {
        cout << "   - ";
        p->display();
    }
    cout << "   Total comanda: " << this->calculateTotal() << " RON\n";
}

const vector<Product*>& Order::getOrderedProducts() const {
    return this->orderedProducts;
}

int Order::getId() const {
    return this->orderId;
}