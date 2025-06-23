#include <iostream>

class Animal{
    std::string animal;
    std::string rase;
    unsigned weight;
    unsigned price;
public:
    Animal (std::string a, std::string r, unsigned w, unsigned p):
        animal(a), rase(r),
        weight(w), price(p) {};
        void show () const {
            std::cout << animal << "\nRase: " << rase << "\nWeigth: " << weight  << " kg" << "\nPrice: " << price << " USD"<< std::endl; 
        }

    std::string get_animal () const {return animal;}
    std::string get_rase () const {return rase;}
    unsigned get_weight () const {return weight;}
    unsigned get_price () const {return price;}
};

class Cat: private Animal {
public:
    Cat (std::string a, std::string r, unsigned w, unsigned p): Animal(a, r, w, p) {};

    using Animal::get_animal;
    using Animal::get_rase;
    using Animal::get_weight;
    using Animal::get_price;

    void show () const {
        std::cout << "Animal: " << get_animal () << std::endl;
        std::cout << "Rase: " << get_rase ()<< std::endl;
        std::cout << "Weight: " << get_weight ()<< " kg" << std::endl;
        std::cout << "Price: " << get_price ()<< " USD" << std::endl;
    }
};  

class Dog: private Animal {
public:
    Dog (std::string a, std::string r, unsigned w, unsigned p): Animal(a, r, w, p) {};

    using Animal::get_animal;
    using Animal::get_rase;
    using Animal::get_weight;
    using Animal::get_price;

    void show () const {
        std::cout << "\n" << "Animal: " << get_animal () << std::endl;
        std::cout << "Rase: " << get_rase () << std::endl;
        std::cout << "Weight: " << get_weight () << " kg" << std::endl;
        std::cout << "Price: " << get_price () << " USD" << std::endl;
    }
}; 


int main(){
    Cat cat {"Cat", "Manx", 4, 150};
    Dog dog {"Dog", "Doberman", 20, 250};

    cat.show ();
    dog.show ();
}