#ifndef WeatherGeneral_H_
#define WeatherGeneral_H_

#include "WeatherAPI.h"
#include <boost/property_tree/json_parser.hpp>
#include "FileHandler.h"
#include <vector>
#include <curl/curl.h>

class WeatherGeneral : public WeatherAPI
{

	public:
		static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
		virtual std::string getTemperature(std::string cityName) =0;
		WeatherGeneral(std::string appName) :m_appName(appName) {};
		virtual void printTemperature(std::string cityName);
		virtual ~WeatherGeneral(){};
		virtual void init();

		void printMap();

  protected:
		virtual void putCityIntoMap(std::string cityName , std::string id);
		virtual std::string sendHttpRequest(std::string httpQuery , const char * getElement, std::stringstream &ss);
	
	private:
		std::string m_appName;
		int   SharedMemoryID;      
    int * SharedMemoryPtr;
		std::map<std::string, std::string> cityNameID_m;
		virtual std::string getTemperatureFromJSON(std::stringstream &jsonData, const char * getElement);
		virtual std::stringstream getCurrentDate();

};

#endif

