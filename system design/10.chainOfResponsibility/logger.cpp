#include <bits/stdc++.h>
using namespace std;

class logProcessor {
protected:
    logProcessor* nextLogProcessor;

public:
    logProcessor(logProcessor* nextLog) : nextLogProcessor(nextLog) {}

    virtual void log(string process, string msg) {
        if (nextLogProcessor != nullptr) {
            nextLogProcessor->log(process, msg);
        }
    }
};

class infoLogProcessor : public logProcessor {
public:
    infoLogProcessor(logProcessor* nextLog) : logProcessor(nextLog) {}

    void log(string process, string msg) override {
        if (process == "info") {
            cout << "Info: " << msg << endl;
        } else {
            logProcessor::log(process, msg);
        }
    }
};

class errorLogProcessor : public logProcessor {
public:
    errorLogProcessor(logProcessor* nextLog) : logProcessor(nextLog) {}

    void log(string process, string msg) override {
        if (process == "error") {
            cout << "Error: " << msg << endl;
        } else {
            logProcessor::log(process, msg);
        }
    }
};

class debugLogProcessor : public logProcessor {
public:
    debugLogProcessor(logProcessor* nextLog) : logProcessor(nextLog) {}

    void log(string process, string msg) override {
        if (process == "debug") {
            cout << "Debug: " << msg << endl;
        } else {
            logProcessor::log(process, msg);
        }
    }
};

int main() {
    logProcessor* obj1 = new infoLogProcessor(new debugLogProcessor(new errorLogProcessor(nullptr)));
    obj1->log("error", "memory exceed");
    obj1->log("debug", "debug this");
    obj1->log("info", "this is message");

    // Clean up memory
    delete obj1->nextLogProcessor->nextLogProcessor;
    delete obj1->nextLogProcessor;
    delete obj1;

    return 0;
}
