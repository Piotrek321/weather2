#ifndef WeatherAPI_H_
#define WeatherAPI_H_

#include <iostream>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sstream> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <map>

#define SHMSZ  100
#define KEY_VALUE 5678

class WeatherAPI
{

public:
    virtual std::string getTemperature(std::string cityName) =0;
    virtual ~WeatherAPI(){};
    virtual float printTemperature(std::string cityName) =0;
    virtual void init() =0;
    virtual void printMap() =0;
};

#endif

