#include <iostream>
#include <string>
using namespace std;

class shape
{
public:
    virtual void draw() = 0;    // Pure virtual function
    virtual ~shape() = default; // Virtual destructor
};

class rectangle : public shape
{
public:
    void draw() override
    {
        cout << "rect" << endl;
    }
};

class circle : public shape
{
public:
    void draw() override
    {
        cout << "circle" << endl;
    }
};

class square : public shape
{
public:
    void draw() override
    {
        cout << "square" << endl;
    }
};

class factory
{
public:
    shape *getShape(const string &s)
    {
        if (s == "circle")
            return new circle();
        if (s == "square")
            return new square();
        if (s == "rectangle")
            return new rectangle();
        return nullptr;
    }
};

int main()
{
    factory shapeFactory;
    shape *obj = shapeFactory.getShape("circle");
    if (obj)
    {
        obj->draw();
        delete obj; // Free the allocated memory
    }
    else
    {
        cout << "Invalid shape type" << endl;
    }
    return 0;
}
