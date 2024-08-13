#include <iostream>
#include <string>
using namespace std;

class drivestratergy {
public:
    virtual void drive() = 0;
    virtual ~drivestratergy() = default; // Virtual destructor
};

class normalDrive : public drivestratergy {
public:
    void drive() override {
        cout << "Normal drive" << endl;
    }
};

class SpecialDrive : public drivestratergy {
public:
    void drive() override {
        cout << "fast drive" << endl;
    }
};

class vehicle {
private:
    drivestratergy *ds;

public:
    vehicle(drivestratergy *ds) {
        this->ds = ds;
    }

    virtual ~vehicle() {
        delete ds; // Free the allocated memory
    }

    void drive() {
        ds->drive();
    }
};

class sports : public vehicle {
public:
    sports() : vehicle(new SpecialDrive()) {}
};

class offroad : public vehicle {
public:
    offroad() : vehicle(new SpecialDrive()) {}
};

class passenger : public vehicle {
public:
    passenger() : vehicle(new normalDrive()) {}
};

int main() {
    offroad off;
    off.drive();

    passenger pass;
    pass.drive();

    return 0;
}
