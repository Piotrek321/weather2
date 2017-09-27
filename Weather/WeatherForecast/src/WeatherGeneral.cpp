#include "../inc/WeatherGeneral.h"	
#include <exception>
std::string WeatherGeneral::sendHttpRequest(std::string httpQuery , const char * getElement, std::stringstream &ss)
{
	std::string data ;
	CURL * crl = curl_easy_init();
	if(crl)
	{
		curl_easy_setopt(crl, CURLOPT_URL , httpQuery.c_str() );
		curl_easy_setopt(crl, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(crl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(crl, CURLOPT_WRITEDATA, &data);

		curl_easy_perform(crl);
		curl_easy_cleanup(crl);
		ss <<data;
		
		return getTemperatureFromJSON(ss, getElement);
	}
	return "";
}

void WeatherGeneral::printTemperature(std::string cityName)
{
				
	std::string temperature = getTemperature(cityName);
   
	if(temperature == "") return ;
  std::cout <<"Temperature from " << m_appName << ". City: " << cityName << " temperature: " << temperature << "\n" << std::flush;
}

size_t WeatherGeneral::write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	((std::string*)userdata)->append((char*)ptr, size * nmemb);
  return size * nmemb;
}

std::stringstream WeatherGeneral::getCurrentDate()
{
	std::stringstream currentDate;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	currentDate << (tm.tm_year + 1900) ;
	if( (tm.tm_mon + 1 ) <10)
	{
		currentDate << "0";
	}
	currentDate << tm.tm_mon + 1;
		 
	currentDate << tm.tm_mday << " " << tm.tm_hour <<":";
	if(tm.tm_min <10)
	{
		currentDate << "0";
	}
	currentDate << tm.tm_min;

	return currentDate;
}

void WeatherGeneral::init()
{
	pid_t pid = getpid();

	//Key should be either generated or hard coded (it must have the same value in every application that uses particular part of shared memory)
	key_t MyKey = KEY_VALUE; 

	//Prepare memory and write pid into it
	SharedMemoryID   = shmget(MyKey, SHMSZ, IPC_CREAT | 0666);
	SharedMemoryPtr  = (int *) shmat(SharedMemoryID, NULL, 0);
	*SharedMemoryPtr = pid; 
}

void WeatherGeneral::putCityIntoMap(std::string cityName , std::string id)
{
	if(cityNameID_m.count(cityName) == 0)
	{
		cityNameID_m.insert(std::pair<std::string, std::string>(cityName, id));
	}
}

std::string WeatherGeneral::getTemperatureFromJSON(std::stringstream &jsonData, const char * getElement)
{
	try
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_json(jsonData, pt);
		return pt.get<std::string>(getElement);
	}
 	catch (std::exception const& e)
  {
  	std::cerr << e.what() << std::endl;
		return "";
  }
}



void WeatherGeneral::printMap()
{
	auto iter = cityNameID_m.begin();
	std::cout <<"PrintMap \n";
	while(iter != cityNameID_m.end())
	{
		std::cout << "City: " << iter->first << " id: " << iter->second << "\n";
		++iter;
	}
}
