#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
protected:
    std::string name;
    double price;

public:
    Product(std::string name = "", double price = 0.0);
    virtual ~Product() = default;

    std::string getName() const;
    void setName(const std::string& name);

    double getPrice() const;
    void setPrice(double price);

    virtual void display() const = 0;
};

class Shoe : public Product {
private:
    std::string size;
public:
    Shoe(std::string name = "", double price = 0.0, std::string size = "42");
    void display() const override;
};

class Toy : public Product {
private:
    int ageRecommendation;
public:
    Toy(std::string name = "", double price = 0.0, int age = 3);
    void display() const override;
};

#endif
