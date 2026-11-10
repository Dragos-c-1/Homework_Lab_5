#include <iostream>
#include <vector>
#include "Product.h"
#include "Department.h"
#include "Order.h"

using namespace std;

void searchProductInOrders(const string& productName, const vector<Order*>& ordersList) {
    cout << "\n[Cauta produsul '" << productName << "' in lista de comenzi]:\n";
    bool found = false;
    for (auto order : ordersList) {
        for (auto p : order->getOrderedProducts()) {
            if (p->getName() == productName) {
                cout << " -> Gasit in Comanda #" << order->getId() << " | ";
                p->display();
                found = true;
            }
        }
    }
    if (!found) {
        cout << " Produsul nu a fost gasit in nicio comanda.\n";
    }
}

int main() {
    

    // 1. Creare departamente
    Department shoesDept("Shoes Department");
    Department toysDept("Toys Department");

    // 2. Adaugare produse
    shoesDept.addProduct(new Shoe("Nike Air Max", 550.0, "43"));
    shoesDept.addProduct(new Shoe("Adidas Superstar", 400.0, "41"));

    vector<Product*> newToys = {
        new Toy("Lego City", 250.0, 6),
        new Toy("Rubik Cube", 50.0, 8),
        new Toy("Teddy Bear", 120.0, 2)
    };
    toysDept.addMultipleProducts(newToys);

    shoesDept.displayDepartment();
    toysDept.displayDepartment();

    // 3. Cautare produs
    cout << "\n--- Test Cautare Produs ---";
    Product* foundProd = shoesDept.findProduct("Nike Air Max");
    if (foundProd) {
        cout << "\nGasit in Shoes: ";
        foundProd->display();
    }

    // 4. Sortare produse
    cout << "\n--- Sortare Produse Toys dupa Nume ---";
    vector<Product*> sortedByName = toysDept.getSortedByName();
    for (auto p : sortedByName) { p->display(); }

    cout << "\n--- Sortare Produse Toys dupa Pret ---";
    vector<Product*> sortedByPrice = toysDept.getSortedByPrice();
    for (auto p : sortedByPrice) { p->display(); }

    // 5. Stergere produs
    cout << "\n--- Test Stergere Produs ---";
    shoesDept.removeProduct("Adidas Superstar");

    // 6. Gestionare comenzi
    cout << "\n--- Gestionare Comenzi ---";
    Order* order1 = new Order(101);
    order1->addProduct(shoesDept.findProduct("Nike Air Max"));
    order1->addProduct(toysDept.findProduct("Lego City"));

    Order* order2 = new Order(102);
    order2->addProduct(toysDept.findProduct("Teddy Bear"));

    vector<Order*> storeOrders = { order1, order2 };

    for (auto ord : storeOrders) {
        cout << "\n";
        ord->displayOrder();
    }

    // 7. Cautare produs in comenzi
    searchProductInOrders("Lego City", storeOrders);
    searchProductInOrders("Pantof Inexistent", storeOrders);

    for (auto ord : storeOrders) {
        delete ord;
    }

    cout << "\n=== Program finalizat cu succes! ===\n";
    return 0;
}