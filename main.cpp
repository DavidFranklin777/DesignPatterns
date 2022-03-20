#include <iostream>
#include "Factory.h"
using namespace std;

int main()
{
    charName name = charNaruto;
    character* pChar = nullptr;
    pChar = factory::create(name);
    pChar->printChar();
    delete pChar;
    cout << "Hello World!" << endl;
    return 0;
}
