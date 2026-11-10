#include "Department.h"
#include <iostream>
#include <algorithm>

using namespace std;

Department::Department(string name) {
    this->departmentName = name;
}

Department::~Department() {
    for (auto p : this->productsList) {
        delete p;
    }
}

string Department::getDepartmentName() const { return this->departmentName; }

void Department::addProduct(Product* p) {
    this->productsList.push_back(p);
}

void Department::addMultipleProducts(const vector<Product*>& list) {
    for (auto p : list) {
        this->productsList.push_back(p);
    }
}

void Department::removeProduct(const string& name) {
    for (auto it = this->productsList.begin(); it != this->productsList.end(); ++it) {
        if ((*it)->getName() == name) {
            delete* it;
            this->productsList.erase(it);
            cout << "Produsul '" << name << "' a fost sters din departamentul " << this->departmentName << ".\n";
            return;
        }
    }
    cout << "Produsul '" << name << "' nu a fost gasit in departament.\n";
}

Product* Department::findProduct(const string& name) const {
    for (auto p : this->productsList) {
        if (p->getName() == name) {
            return p;
        }
    }
    return nullptr;
}

vector<Product*> Department::getSortedByName() const {
    vector<Product*> sortedList = this->productsList;
    sort(sortedList.begin(), sortedList.end(), [](Product* a, Product* b) {
        return a->getName() < b->getName();
        });
    return sortedList;
}

vector<Product*> Department::getSortedByPrice() const {
    vector<Product*> sortedList = this->productsList;
    sort(sortedList.begin(), sortedList.end(), [](Product* a, Product* b) {
        return a->getPrice() < b->getPrice();
        });
    return sortedList;
}

void Department::displayDepartment() const {
    cout << "\n--- Departament: " << this->departmentName << " ---\n";
    if (this->productsList.empty()) {
        cout << "  (Departamentul este gol)\n";
    }
    else {
        for (const auto& p : this->productsList) {
            p->display();
        }
    }
}

const vector<Product*>& Department::getProducts() const {
    return this->productsList;
}