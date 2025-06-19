#include <iostream>

class Car {
    public:
    std::string brand;
    std::string model;
    unsigned price;
    unsigned year;

    Car(std::string b, std::string m, unsigned p, unsigned y){
        brand = b;
        model = m; 
        price = p;
        year = y;
    }

    Car (const Car &p){
        brand = p.brand;
        model = "Corolla-S";
        price = p.price + 5000;
        year = p.year + 4;
    }

    void show(){
        std::cout << "\n" << brand << "\n" << model << "\nPrice: " << price << "\nRelease year: " << year << std::endl;
    }
};

int main(){
    Car toyota2021 {"Toyota", "Corolla", 20000, 2021};
    toyota2021.show();
    Car toyota2025 {toyota2021};
    toyota2025.show();
}