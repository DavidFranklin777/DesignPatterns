#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

using namespace std;

/*
Implementation of Factory design pattern
Factory Design pattern creates a pointer to the user requested object of a class and returns it
*/


// enum is used to choose an object of a class
// charNaruto is used to choose an object of class naruto
enum charName
{
    charNaruto,
    charSasuke,
    charSakura,
};

// Abstract class
class character
{
public:
    virtual void printChar() = 0;
    character()
    {
        cout << "Character\n";
    }

    virtual ~character()
    {}
};

class naruto: public character
{
public:
    void printChar() override
    {
        cout << "Naruto " << endl;
    }

    naruto()
    {
        cout << "naruto " << endl;
    }

//    virtual ~naruto()
//    {
//        cout << "deleted naruto\n";
//    }
};

class sasuke: public character
{
public:
    void printChar() override
    {
        cout << "Sasuke " << endl;
    }
    sasuke()
    {
        cout << "sasuke " << endl;
    }
};

class sakura: public character
{
public:
    void printChar() override
    {
        cout << "Sakura " << endl;
    }
    virtual ~sakura()
    {
        cout << "deleted sakura\n";
    }
};

// Factor class contains a static function which returns a pointer to an object of a child class
class factory
{
public:
    factory()
    {
        cout << "factory\n\n";
    }

    // If name = charNaruto, the function returns a pointer to an object of class naruto
    static character* create(charName name)
    {
        if(name == charNaruto)
        {
            return new naruto();
        }
        else if(name == charSasuke)
        {
            return new sasuke();
        }
        else if(name == charSakura)
        {
            return new sakura();
        }
        else
        {
            cout << "Character not found!\n";
            return nullptr;
        }
    }
};

#endif // FACTORY_H

