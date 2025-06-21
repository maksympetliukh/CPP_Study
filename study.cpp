#include <iostream>

class Heir {
    std::string name;
    unsigned age;
    unsigned primogeniture;
    public:
    Heir (std::string n, unsigned a, unsigned p): name(n), age(a), primogeniture(p) {};
    friend bool order_of_succession (Heir& h1, Heir& h2);
    friend void show (Heir& h1, Heir& h2);
};

bool order_of_succession(Heir& h1, Heir& h2){
    return h1.age > h2.age;
}

void show(Heir& h1, Heir& h2){
    if(order_of_succession(h1, h2)){
        std::cout << h1.name << " will be the next king because he is older than " << h2.name << std::endl;
    }
    else if(h1.age == h2.age){
        std::cout << "Since the sons are the same age, the successor is determined by primogeniture: ";
        if(h1.primogeniture < h2.primogeniture && h1.primogeniture != h2.primogeniture){
            std::cout << h1.name << " will be the next king" << std::endl;
        }else{
            std::cout << h2.name << " will be the next king" << std::endl;
        }
    }
}

int main(){
    Heir arthur {"Arthur", 19, 1};
    Heir charles {"Charles", 15, 2};
    Heir george {"George", 15, 1};

    show(arthur, charles);
    show(arthur, george);
    show(charles, george);
}
