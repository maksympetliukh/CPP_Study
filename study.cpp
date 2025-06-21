#include <iostream>

class Car;
class Driver;

class Driver{
    std::string name;
    unsigned age;
    public:
    Driver(std::string n, unsigned a): name(n), age(a) {};
    friend bool age_review(const Driver& d, const Car& c);
    friend void show(const Driver& d, const Car& c);
    std::string get_name() const {return name;}
};

class Car{
    std::string model;
    unsigned legal_age = 18;
    public:
    Car(std::string m, unsigned l = 18): model(m), legal_age(l) {};
    friend bool  age_review(const Driver& d, const Car& c);
    friend void show(const Driver& d, const Car& c);
    std::string get_model() const {return model;}
};

bool age_review(const Driver& d, const Car& c){
    return d.age >= c.legal_age;
}

void show(const Driver& d, const Car& c){
    std::cout << d.get_name();
    if(age_review(d, c)){
        std::cout << " can drive a " << c.get_model() << std::endl;
    }else{
        std::cout << " is underage for driving" << std::endl;
    }
}

int main(){
    Car car {"Toyota"};

    Driver d1{"John", 17}, d2 {"Alex", 20}, d3 {"Mike", 33};
    show(d1, car);
    show(d2, car);
    show(d3, car);
}