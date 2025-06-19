#include <iostream>

class Car {
    public:
    std::string brand;
    std::string model;
    std::string engine;
    std::string fuel;
    unsigned  power;
    unsigned price;
    unsigned year;

    Car(std::string b, std::string m,std::string e, std::string f,  unsigned pow, unsigned pri, unsigned y){
        brand = b;
        model = m;
        engine = e;
        fuel = f;
        power = pow; 
        price = pri;
        year = y;
    }

    Car (const Car &p){
        brand = p.brand;
        model = "Corolla-E";
        engine = "E-Core";
        fuel = "Electric";
        power = p.power + 30;
        price = p.price + 5000;
        year = p.year + 4;
    }

    void show(){
        std::cout << "\nBrand: " << brand << "\nModel: " << model << "\nEngine: " << engine << "\nFuel type: " << fuel << "\nPower: " << power << "\nPrice: " << price << "\nRelease year: " << year << std::endl;
    }
};

int main(){
    Car toyota2021 {"Toyota", "Corolla", "TDE-6", "Diesel", 300, 20000, 2021};
    toyota2021.show();
    Car toyota2025 {toyota2021};
    toyota2025.show();
}