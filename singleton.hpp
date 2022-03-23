#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Logger
{
public:
    // We need a static function, because we are returning a static pointer to an object
    static Logger* getlogger()
    {
        if(loggerInstance == nullptr)
       {    // lock the instance creation via mutex, only if the loggerinstance is null
            mtx.lock();
            // Only create an instance of logger when it is null, otherwise just return the previous instance
            // Since loggerInstance is a static variable, its scope ends only at the end of the program
            // That means, other users can use the same loggerInstance
            if (loggerInstance == nullptr)
            {
                loggerInstance = new Logger();
            }
            mtx.unlock();
        }
        return loggerInstance;
    }

    void log(string msg)
    {
        cout << msg << endl;
    }

private:
    static mutex mtx;
    static Logger* loggerInstance;
    // ctr - counter to test how many instances are being created
    // static because we dont want it to reset
    static int     ctr;
    Logger()
    {
       // If ctr is more than one, our singleton has failed
       // cout to test how many instances are created
       ctr++;
       cout << "New instance created " << ctr << endl;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////
// Static variables must be instantiated/initialized outside of class,
// since they are not bound to any class to be initialized inside them
////////////////////////////////////////////////////////////////////////////////////////
Logger* Logger::loggerInstance = nullptr;
int Logger::ctr = 0;
mutex Logger::mtx;

#endif // SINGLETON_HPP
