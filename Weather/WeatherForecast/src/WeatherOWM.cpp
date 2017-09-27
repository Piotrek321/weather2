#include "../inc/WeatherOWM.h"

std::string WeatherOWM::getTemperature(std::string cityName)
{
	std::stringstream ss;
	std::string OWMQuery = "api.openweathermap.org/data/2.5/weather?id=";
	std::string cityId =  getCityID(cityName).c_str();
	
	if(cityId == "") 
	{	
		return "";
	}

	OWMQuery += getCityID(cityName).c_str();
	OWMQuery += "&appid=b5df5912a869b5cf1cfa4899b10da754&units=metric";

  return sendHttpRequest( OWMQuery, "main.temp", ss); //&mode=xml
}


std::string WeatherOWM::getInfoAboutCity(std::stringstream &cityInfo)
{
  boost::property_tree::ptree pt;
  boost::property_tree::read_json(cityInfo, pt);
  return pt.get<std::string>("_id");
}

std::string WeatherOWM::getCityID(std::string cityName)
{
    FileHandler fh("../../Weather/WeatherForecast/data/owm.city.list.json");
	fh.openFile();
	std::stringstream info (fh.findLineWithData(cityName));
	if(info.str() == "") 
	{
		return "";
	}
  std::string id = getInfoAboutCity(info);
  putCityIntoMap(cityName, id);
	return id;
}



