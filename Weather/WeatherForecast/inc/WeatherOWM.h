#ifndef WeatherOWM_H_
#define WeatherOWM_H_

#include "WeatherGeneral.h"

class WeatherOWM :public WeatherGeneral
{
	public:

		std::string getTemperature(std::string cityName);
		std::string getCityID(std::string cityName);

    WeatherOWM() : WeatherGeneral("OWM"){};

	  virtual ~WeatherOWM(){};
		std::string getInfoAboutCity(std::stringstream &cityInfo);


	protected:
		std::string fileWithCitiesID;//needed??

};

#endif
