#include <iostream>
#include "Factory.h"
#include "singleton.hpp"
using namespace std;

void user1log()
{
    // Even though we created logger1 and logger2, we see that only one instance of logger is created and that is used among
    // every user who uses it
    Logger* logger1  = Logger::getlogger();
    logger1->log("User1");
}

void user2log()
{
    Logger* logger2  = Logger::getlogger();
    logger2->log("User2");
}

int main()
{
//    charName name = charNaruto;
//    character* pChar = nullptr;
//    pChar = factory::create(name);
//    pChar->printChar();
//    delete pChar;
//    cout << "Hello World!" << endl;

    thread t1(user1log);
    thread t2(user2log);

    t1.join();
    t2.join();
    return 0;
}
