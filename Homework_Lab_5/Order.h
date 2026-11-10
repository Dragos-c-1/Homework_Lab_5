#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Product.h"

class Order {
private:
    int orderId;
    std::vector<Product*> orderedProducts;

public:
    Order(int id);

    void addProduct(Product* p);
    double calculateTotal() const;
    void displayOrder() const;

    const std::vector<Product*>& getOrderedProducts() const;
    int getId() const;
};

#endif
