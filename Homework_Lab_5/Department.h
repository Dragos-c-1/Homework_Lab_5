#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include "Product.h"

class Department {
private:
    std::string departmentName;
    std::vector<Product*> productsList;

public:
    Department(std::string name = "General");
    ~Department();

    std::string getDepartmentName() const;

    void addProduct(Product* p);
    void addMultipleProducts(const std::vector<Product*>& list);
    void removeProduct(const std::string& name);

    Product* findProduct(const std::string& name) const;

    std::vector<Product*> getSortedByName() const;
    std::vector<Product*> getSortedByPrice() const;

    void displayDepartment() const;
    const std::vector<Product*>& getProducts() const;
};

#endif
