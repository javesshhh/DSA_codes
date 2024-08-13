#include <iostream>
using namespace std;

class BasePizza {
public:
    virtual int cost() = 0; // Make cost a pure virtual function
    // virtual ~BasePizza() = default; // Virtual destructor for proper cleanup
};

class margherita : public BasePizza {
public:
    int cost() override {
        return 200;
    }
};

class otc : public BasePizza {
public:
    int cost() override {
        return 250;
    }
};

class corn : public BasePizza {
public:
    int cost() override {
        return 220;
    }
};

class topping : public BasePizza {
protected:
    BasePizza* basePizza; // Raw pointer for base pizza
public:
    topping(BasePizza* pizza) {
        this->basePizza=pizza;
    } // Initialize the basePizza pointer

    // Destructor to free the memory allocated for basePizza
    // virtual ~topping() {
    //     delete basePizza;
    // }
};

class cheese : public topping {
public:
    cheese(BasePizza* pizza) : topping(pizza) {}

    int cost() override {
        return basePizza->cost() + 40;
    }
};

class flakes : public topping {
public:
    flakes(BasePizza* pizza) : topping(pizza) {}

    int cost() override {
        return basePizza->cost() + 20;
    }
};

int main() {
    BasePizza* p1 = new cheese(new margherita());
    cout << p1->cost() << endl;
    delete p1; // Free the memory

    BasePizza* p2 = new flakes(new cheese(new margherita()));
    cout << p2->cost() << endl;
    delete p2; // Free the memory

    return 0;
}
