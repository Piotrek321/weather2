#include "../inc/WeatherYahoo.h"

std::string WeatherYahoo::getTemperature(std::string cityName)
{
	std::transform(cityName.begin(), cityName.end(), cityName.begin(), ::tolower);	
	std::stringstream ss;
//item.forecast to get 3-5 days forecast/ item.condition for one day condition
	std::string yahooQuery = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22";
	yahooQuery += cityName.c_str();
	yahooQuery += "%2C%20pl%22)%20and%20u%3D%27c%27%20limit%203&format=json";
  return sendHttpRequest(yahooQuery , "query.results.channel.item.condition.temp", ss);
		//std::cout << getTemperatureFromJSON(ss, "query.created");
}
