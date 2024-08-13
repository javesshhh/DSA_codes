// https://www.youtube.com/watch?v=Ep9_Zcgst3U&list=PL6W8uoQQ2c61X_9e6Net0WdYZidm7zooW&index=5&pp=iAQB

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class notificationAlert
{
public:
    virtual void update() = 0;
    // virtual ~notificationAlert() = default;
};

class stockObservable
{
public:
    virtual void add(notificationAlert *observer) = 0;
    virtual void remove(notificationAlert *observer) = 0;
    virtual void notifyAll() = 0;
    virtual void setStockCount(int cnt) = 0;
};

class phoneObservable : public stockObservable
{
    unordered_set<notificationAlert *> observers;
    int tot = 0;

public:
    void add(notificationAlert *observer) override
    {
        observers.insert(observer);
    }

    void remove(notificationAlert *observer) override
    {
        observers.erase(observer);
    }

    void notifyAll() override
    {
        for (notificationAlert *observer : observers)
        {
            observer->update();
        }
    }

    void setStockCount(int cnt) override
    {
        if (tot == 0)
            notifyAll();
        tot += cnt;
    }

    void updateStockCount(int cnt)
    {
        if (cnt == 0)
            notifyAll();
        tot = cnt;
    }
};

class emailAlert : public notificationAlert
{
    string email;
    stockObservable *observable;

public:
    emailAlert(string email, stockObservable *observable)
    {
        this->email = email;
        this->observable = observable;
    }

    void update() override
    {
        sendMail(email, "product is in stock");
    }

private:
    void sendMail(string email, string msg)
    {
        cout << "mail sent to " << email << " with message: " << msg << endl;
    }
};

class mobileAlert : public notificationAlert
{
    string phoneNumber;
    stockObservable *observable;

public:
    mobileAlert(string phoneNumber, stockObservable *observable)
    {
        this->phoneNumber = phoneNumber;
        this->observable = observable;
    }

    void update() override
    {
        sendSMS(phoneNumber, "product is in stock");
    }

private:
    void sendSMS(string phoneNumber, string msg)
    {
        cout << "SMS sent to " << phoneNumber << " with message: " << msg << endl;
    }
};

int main()
{
    phoneObservable iphone;

    emailAlert *obs1 = new emailAlert("xyz@gmail.com", &iphone);
    emailAlert *obs2 = new emailAlert("xyz2@gmail.com", &iphone);
    mobileAlert *obs3 = new mobileAlert("xyz3", &iphone);

    iphone.add(obs1);
    iphone.add(obs2);
    iphone.add(obs3);
    iphone.add(obs1);

    iphone.setStockCount(10);

    delete obs1;
    delete obs2;
    delete obs3;

    return 0;
}
