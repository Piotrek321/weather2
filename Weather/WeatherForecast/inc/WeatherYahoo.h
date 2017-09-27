#ifndef WeatherYahoo_H_
#define WeatherYahoo_H_

#include "WeatherGeneral.h"
#include <algorithm>

class WeatherYahoo :public WeatherGeneral
{
	public:
		std::string getTemperature(std::string cityName);

    WeatherYahoo() : WeatherGeneral("Yahoo"){};
	  virtual ~WeatherYahoo(){std::cout <<"~WeatherYahoo\n" <<std::flush;};
};

#endif
